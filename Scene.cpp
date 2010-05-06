/*
 *  Scene.cpp
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/6/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#include "Scene.h"

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
}