/*
 *  Scene.cpp
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/6/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#include "Scene.h"
#include "Triangle.h"
#include "teapot.h"

namespace ShadeKit {
    Surface *Scene::findHit(Ray ray, float *distance)
    {
        float hitDistance = INFINITY;
        Surface *hitSurface = NULL;
        // find nearest intersection
        for (unsigned int i = 0; i < m_surfaces.size(); i++) {
            Surface *s = m_surfaces[i];
            float distance = s->hit(ray);
            if (distance > 0.0001) {
                if (distance < hitDistance) {
                    hitDistance = distance;
                    hitSurface = s;
                }
            }
        }
        if (distance) {
            *distance = hitDistance;
        }
        return hitSurface;
    }
    
    
    void Scene::loadCube()
    {
        for (int i = 0; i < Box_polygoncount; i++) {
            int *indices = Box_index[i];
            Vector3 v0(Box_vertex[indices[0]][5], Box_vertex[indices[0]][6], Box_vertex[indices[0]][7]);
            Vector3 v1(Box_vertex[indices[1]][5], Box_vertex[indices[1]][6], Box_vertex[indices[1]][7]);
            Vector3 v2(Box_vertex[indices[2]][5], Box_vertex[indices[2]][6], Box_vertex[indices[2]][7]);
            Triangle *t = new Triangle(v0, v1, v2);
            m_surfaces.push_back(t);
            
            Material mirrorMaterial;
            mirrorMaterial.setColor(kColorRed);
            t->setMaterial(mirrorMaterial);
        }
    }
}