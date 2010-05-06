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
    
    const float kSmallValue = 0.0;
    
    Triangle::Triangle(Vector3& v0, Vector3& v1, Vector3& v2)
    : m_v0(v0)
    , m_v1(v1)
    , m_v2(v2)
    {
        Vector3 v02 = v2 - v0;
        Vector3 v01 = v1 - v0;
        m_normal = v02.cross(v01).normalize();
    }
    
    float Triangle::hit(Ray& ray)
    {
        float vn = ray.direction().dot(m_normal);
        //bool isRightSide = vn < 0;
        if (fabs(vn) < kSmallValue)
            return kNoHit;
        /*if (!isRightSide && !isDoubleSided) {
         return kNoHit;
         }*/
        Vector3 v0r = ray.origin() - m_v0;
        float xpn = m_normal.dot(v0r);
        float distance = -xpn / vn;
        if (distance < 0)
            return kNoHit;
        Vector3 hitPosition = ray.pointAtDistance(distance);
        
        Vector3 v0h = hitPosition - m_v0;
        Vector3 v01 = m_v1 - m_v0;
        Vector3 cross0 = v0h.cross(v01);
        if (cross0.dot(m_normal) < kSmallValue) {
            return kNoHit;
        }
        Vector3 v1h = hitPosition - m_v1;
        Vector3 v12 = m_v2 - m_v1;
        Vector3 cross1 = v1h.cross(v12);
        if (cross1.dot(m_normal) < kSmallValue) {
            return kNoHit;
        }
        Vector3 v2h = hitPosition - m_v2;
        Vector3 v20 = m_v0 - m_v2;
        Vector3 cross2 = v2h.cross(v20);
        if (cross2.dot(m_normal) < kSmallValue) {
            return kNoHit;
        }
        
        return distance;
    }
}