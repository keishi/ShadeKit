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
    HitInfo Camera::raytrace(Ray& ray, Color *acc, int level)
    {
        *acc = kColorBlack;
        if (level > kMaxTraceLevel) {
            return HitInfo();
        }
        HitInfo hitInfo = m_scene.findHit(ray);
        if (hitInfo.surface()) {
            Vector3 hitPosition = hitInfo.position();
            Vector3 hitNormal = hitInfo.normal();
            Material *hitMaterial = hitInfo.material();
            *acc = *acc + hitMaterial->ambient() * hitMaterial->color();
            
            std::vector<Light*> lights = m_scene.lights();
            for (unsigned int i = 0; i < lights.size(); i++) {
                Light *light = lights[i];
                Ray lightRay;
                lightRay.setOrigin(hitPosition);
                Vector3 lightRayDirection = (light->position() - hitPosition).normalize();
                lightRay.setDirection(lightRayDirection);
                float lightDistance = (light->position() - hitPosition).norm();
                float lightProjection = lightRayDirection.dot(hitNormal);
                lightProjection = 1.0 / (lightDistance * lightDistance) * lightProjection;
                
                bool isShadow = false;
                if (m_renderShadow) {
                    HitInfo obstructionHitInfo = m_scene.findHit(lightRay);
                    if (obstructionHitInfo.surface()) {
                        if (obstructionHitInfo.distance() < lightDistance) {
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
                Color lightColor = light->color() * light->intensityAt(hitPosition);
                Color c = hitMaterial->color() * lightColor * hitMaterial->diffuse() * shade;
                *acc = *acc + c;
                
                if (m_renderHighlight) {
                    float viewProjection = ray.direction().dot(hitNormal);
                    Vector3 blinnDirection = lightRay.direction() - ray.direction();
                    float temp = blinnDirection.normSq();
                    if (temp != 0.0) {
                        float blinn = (1.0 / sqrtf(temp)) * (lightProjection > viewProjection ? lightProjection - viewProjection : 0.0);
                        blinn = pow(blinn, hitMaterial->shininess());
                        *acc = *acc + lightColor * hitMaterial->specular() * blinn;
                    }
                }
                
                if (m_renderReflection && hitMaterial->reflectivity() > 0.0 && level < kMaxTraceLevel) {
                    float reflection = 2.0 * ray.direction().dot(hitNormal);
                    Vector3 reflectionDirection = (ray.direction() - (hitNormal * reflection)).normalize();
                    Ray reflectedRay;
                    reflectedRay.setOrigin(hitPosition);
                    reflectedRay.setDirection(reflectionDirection);
                    Color reflectedColor = kColorBlack;
                    raytrace(reflectedRay, &reflectedColor, level + 1);
                    reflectedColor = reflectedColor * hitMaterial->reflectivity();
                    *acc = *acc + reflectedColor;
                }
            }
         }
        
        return hitInfo;
    }
    Image Camera::render()
    {
        Image image(m_width, m_height);
        for (unsigned int y = 0; y < m_height; y++) {
            for (unsigned int x = 0; x < m_width; x++) {
                float FOYYRadian = m_FOVY * PI / 180.0f;
                float viewPortHeight = m_zNear * tanf(FOYYRadian / 2.0f) * 2.0f;
                float viewPortWidth = viewPortHeight * m_aspect;
                float xPos = (float)x / (float) m_width - 0.5f;
                float yPos = (float)y / (float) m_height - 0.5f;
                Vector3 viewRayV = Vector3(viewPortWidth * xPos, viewPortHeight * yPos, m_zNear);
                //Vector3 leftDirection = -(m_up.cross(m_lookat).normalize());
                viewRayV = m_xDirection * viewRayV.x + m_yDirection * viewRayV.y + m_zDirection * viewRayV.z;
                Vector3 viewRayOrigin = viewRayV + m_eye;
                Ray viewRay;
                viewRay.setOrigin(viewRayOrigin);
                Vector3 viewRayDirection = viewRayV.normalize();
                viewRay.setDirection(viewRayDirection);
                
                Color color;
                HitInfo raytraceHitInfo = raytrace(viewRay, &color, 0);
                if (!raytraceHitInfo.surface()) {
                    color = m_backgroundColor;
                }
                image.setPixelColor(x, y, color);
            }
            printf("%d/%d\n", y, m_height);
        }
        return image;
    }
}