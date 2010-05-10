/*
 *  BoundingBox.h
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/9/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#ifndef BoundingBox_h
#define BoundingBox_h

#define MIN(a,b)  ( ((a)<(b)) ? (a) : (b) )
#define MAX(a,b)  ( ((a)>(b)) ? (a) : (b) )

#include "Ray.h"

namespace ShadeKit {
    class BoundingBox {
    public:
        BoundingBox() { }
        BoundingBox(const Vector3& min, const Vector3& max) : m_minPosition(min), m_maxPosition(max) { }
        void setToInfinite() {
            m_minPosition = Vector3(2.0f, 2.0f, 2.0f);
            m_maxPosition = Vector3(-2.0f, -2.0f, -2.0f);
            BoundingBox(m_minPosition, m_maxPosition);
        }
        void setToNull() {
            m_minPosition = Vector3(1.0f, 1.0f, 1.0f);
            m_maxPosition = Vector3(-1.0f, -1.0f, -1.0f);
            BoundingBox(m_minPosition, m_maxPosition);
        }
        
        const Vector3& minPosition() const { return m_minPosition; }
        const Vector3& maxPosition() const { return m_maxPosition; }
        
        bool isNull() const { return m_minPosition == Vector3(1.0f, 1.0f, 1.0f) && m_maxPosition == Vector3(-1.0f, -1.0f, -1.0f); }
        bool isInfinite() const { return m_minPosition == Vector3(2.0f, 2.0f, 2.0f) && m_maxPosition == Vector3(-2.0f, -2.0f, -2.0f); }
        bool doesHit(const Ray& ray) const
        {
            if (isInfinite()) {
                return true;
            }
            if (isNull()) {
                return false;
            }
            return !((ray.direction().x > 0.0 && ray.origin().x > m_maxPosition.x) ||
                     (ray.direction().x < 0.0 && ray.origin().x < m_minPosition.x) ||
                     (ray.direction().y > 0.0 && ray.origin().y > m_maxPosition.y) ||
                     (ray.direction().y < 0.0 && ray.origin().y < m_minPosition.y) ||
                     (ray.direction().z > 0.0 && ray.origin().z > m_maxPosition.z) ||
                     (ray.direction().z < 0.0 && ray.origin().z < m_minPosition.z));
        }
        BoundingBox unionBox(const BoundingBox& box) const
        {
            Vector3 maxPos(MAX(m_maxPosition.x, box.maxPosition().x), 
                           MAX(m_maxPosition.y, box.maxPosition().y), 
                           MAX(m_maxPosition.z, box.maxPosition().z));
            Vector3 minPos(MIN(m_minPosition.x, box.minPosition().x), 
                           MIN(m_minPosition.y, box.minPosition().y), 
                           MIN(m_minPosition.z, box.minPosition().z));
            return BoundingBox(minPos, maxPos);
        }
    private:
        Vector3 m_minPosition;
        Vector3 m_maxPosition;
    };
}

#endif
