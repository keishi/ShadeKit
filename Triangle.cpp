/*
 *  Triangle.cpp
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/7/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#include "Triangle.h"

namespace ShadeKit {
    
    const float kSmallValue = -0.000001;
    
    Triangle::Triangle(Vector3& v0, Vector3& v1, Vector3& v2)
    : m_v0(v0)
    , m_v1(v1)
    , m_v2(v2)
    , m_isDoubleSided(false)
    {
        Vector3 v02 = v2 - v0;
        Vector3 v01 = v1 - v0;
        m_normal = v02.cross(v01).normalize();
        
        Vector3 min = Vector3(MIN(MIN(v0.x(), v1.x()), v2.x()),
                              MIN(MIN(v0.y(), v1.y()), v2.y()),
                              MIN(MIN(v0.z(), v1.z()), v2.z()));
        Vector3 max = Vector3(MAX(MAX(v0.x(), v1.x()), v2.x()),
                              MAX(MAX(v0.y(), v1.y()), v2.y()),
                              MAX(MAX(v0.z(), v1.z()), v2.z()));
        
        m_boundingBox = BoundingBox(min, max);
    }
    
    bool Triangle::hit(Ray& ray, HitInfo* hitInfo)
    {
        if (!m_boundingBox.doesHit(ray)) {
            return false;
        }
        float vn = ray.direction().dot(m_normal);
        bool isRightSide = vn < 0;
        if (fabs(vn) < kSmallValue)
            return false;
        if (!isRightSide && !m_isDoubleSided) {
            return false;
        }
        Vector3 v0r = ray.origin() - m_v0;
        float xpn = m_normal.dot(v0r);
        float distance = -xpn / vn;
        if (distance < 0)
            return false;
        Vector3 hitPosition = ray.pointAtDistance(distance);
        
        Vector3 v0h = hitPosition - m_v0;
        Vector3 v01 = m_v1 - m_v0;
        Vector3 cross0 = v0h.cross(v01);
        if (cross0.dot(m_normal) < kSmallValue) {
            return false;
        }
        Vector3 v1h = hitPosition - m_v1;
        Vector3 v12 = m_v2 - m_v1;
        Vector3 cross1 = v1h.cross(v12);
        if (cross1.dot(m_normal) < kSmallValue) {
            return false;
        }
        Vector3 v2h = hitPosition - m_v2;
        Vector3 v20 = m_v0 - m_v2;
        Vector3 cross2 = v2h.cross(v20);
        if (cross2.dot(m_normal) < kSmallValue) {
            return false;
        }
        
        hitInfo->setDistance(distance);
        hitInfo->setMaterial(m_material);
        hitInfo->setNormal(m_normal);
        hitInfo->setPosition(hitPosition);
        hitInfo->setRay(&ray);
        hitInfo->setSurface(this);
        return true;
    }
}