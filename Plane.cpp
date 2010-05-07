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
    float Plane::hit(Ray& ray)
    {
        float d = ray.direction().dot(m_normal);
        if (d != 0.0) {
            float dist = -(ray.origin().dot(m_normal) + m_distance) / d;
            if (dist > 0) {
                return dist;
            }
        }
        return kNoHit;
    }
    
    Material Plane::materialAt(Vector3& pos)
    {
        float u = pos.dot(m_uAxis);
        float v = pos.dot(m_vAxis);
        float size = 0.08;
        int uInt = (u < 0 ? u / size : floor(-u / size));
        int vInt = (v < 0 ? v / size : floor(-v / size));
        return (uInt % 2) ^ (vInt % 2) ? m_material : m_alternateMaterial;
    }
}