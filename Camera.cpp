/*
 *  Camera.cpp
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/6/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#include "Camera.h"

const int kMaxTraceLevel = 10;

namespace ShadeKit {
    Surface *Camera::raytrace(Ray& ray, Color *acc, int level)
    {
        *acc = kColorBlack;
        if (level > kMaxTraceLevel) {
            return NULL;
        }
        float hitDistance = INFINITY;
        Surface *hitSurface = m_scene.findHit(ray, &hitDistance);
        if (hitSurface) {
            Vector3 hitPosition = ray.pointAtDistance(hitDistance);
            Vector3 hitNormal = hitSurface->normalAt(hitPosition);
            Material hitMaterial = hitSurface->materialAt(hitPosition);
            *acc = *acc + hitMaterial.ambient() * hitMaterial.color();
            
            std::vector<Light*> lights = m_scene.lights();
            for (unsigned int i = 0; i < lights.size(); i++) {
                Light *light = lights[i];
                Ray lightRay;
                lightRay.setOrigin(hitPosition);
                Vector3 lightRayDirection = (light->position() - hitPosition).normalize();
                lightRay.setDirection(lightRayDirection);
                float lightDistance = (light->position() - hitPosition).norm();
                
                bool isShadow = false;
                if (m_renderShadow) {
                    Surface *obstruction;
                    float obstructionDistance = INFINITY;
                    if (obstruction = m_scene.findHit(lightRay, &obstructionDistance)) {
                        if (obstructionDistance < lightDistance) {
                            isShadow = true;
                        }
                    }
                }
                
                float shade = lightRay.direction().dot(hitNormal) / pow(lightDistance, light->attenuation());
                if (shade < 0) {
                    shade = 0.0;
                }
                if (isShadow) {
                    shade = 0.0;
                }
                Color lightColor = light->color() * light->intensity();
                Color c = hitMaterial.color() * lightColor * hitMaterial.diffuse() * shade;
                *acc = *acc + c;
            }
            if (m_renderReflection && hitMaterial.reflectivity() > 0.0 && level < kMaxTraceLevel) {
                float reflection = 2.0 * ray.direction().dot(hitNormal);
                Vector3 reflectionDirection = (ray.direction() - (hitNormal * reflection)).normalize();
                Ray reflectedRay;
                reflectedRay.setOrigin(hitPosition);
                reflectedRay.setDirection(reflectionDirection);
                Color reflectedColor = kColorBlack;
                raytrace(reflectedRay, &reflectedColor, level + 1);
                reflectedColor = reflectedColor * hitMaterial.reflectivity();
                *acc = *acc + reflectedColor;
            }
            
        }
        return hitSurface;
    }
    Image Camera::render()
    {
        Image image(m_width, m_height);
        for (unsigned int y = 0; y < m_height; y++) {
            for (unsigned int x = 0; x < m_width; x++) {
                Ray viewRay;
                Vector3 viewRayOrigin(2.0f * x / m_width - 1.0f, 2.0f * y / m_height - 1.0f, 0.0f);
                viewRay.setOrigin(viewRayOrigin);
                Vector3 viewRayDirection = (viewRayOrigin - Vector3(0.0, 0.0, -2.0)).normalize();

                viewRay.setDirection(viewRayDirection);
                
                Color color;
                if (!raytrace(viewRay, &color, 0)) {
                    color = m_backgroundColor;
                }
                image.setPixelColor(x, y, color);
            }
        }
        return image;
    }
}