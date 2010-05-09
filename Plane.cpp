/*
 *  Plane.cpp
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/7/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#include "Plane.h"

namespace ShadeKit {
    bool Plane::hit(Ray& ray, HitInfo *hitInfo)
    {
        float d = ray.direction().dot(m_normal);
        if (d != 0.0) {
            float dist = -(ray.origin().dot(m_normal) + m_distance) / d;
            if (dist > 0) {
                Vector3 hitPosition = ray.pointAtDistance(dist);
                hitInfo->setDistance(dist);
                hitInfo->setNormal(m_normal);
                hitInfo->setMaterial(m_material);
                hitInfo->setPosition(hitPosition);
                hitInfo->setSurface(this);
                return true;
            }
        }
        return false;
    }
}