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

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

#include "Ray.h"

namespace ShadeKit {
    class BoundingBox {
    public:
        BoundingBox() { }
        BoundingBox(const Vector3& min, const Vector3& max) : m_minPosition(min), m_maxPosition(max) { }
        void setToInfinite() {
            m_minPosition = Vector3(1.0f, 1.0f, 1.0f);
            m_maxPosition = Vector3(-1.0f, -1.0f, -1.0f);
            BoundingBox(m_minPosition, m_maxPosition);
        }
        
        const Vector3& minPosition() const { return m_minPosition; }
        const Vector3& maxPosition() const { return m_maxPosition; }
        
        bool isInfinite() const { return m_minPosition.x() - m_maxPosition.x() || m_minPosition.y() - m_maxPosition.y() || m_minPosition.z() - m_maxPosition.z(); }
        bool doesHit(const Ray& ray) const
        {
            if (isInfinite()) {
                return true;
            }
            return !((ray.direction().x() > 0.0 && ray.direction().x() > m_maxPosition.x()) ||
                     (ray.direction().x() < 0.0 && ray.direction().x() < m_minPosition.x()) ||
                     (ray.direction().y() > 0.0 && ray.direction().y() > m_maxPosition.y()) ||
                     (ray.direction().y() < 0.0 && ray.direction().y() < m_minPosition.y()) ||
                     (ray.direction().z() > 0.0 && ray.direction().z() > m_maxPosition.z()) ||
                     (ray.direction().z() < 0.0 && ray.direction().z() < m_minPosition.z()));
        }
        BoundingBox unionBox(BoundingBox& box) const
        {
            Vector3 maxPos(MAX(m_minPosition.x(), m_maxPosition.x()), 
                           MAX(m_minPosition.y(), m_maxPosition.y()), 
                           MAX(m_minPosition.z(), m_maxPosition.z()));
            Vector3 minPos(MIN(m_minPosition.x(), m_maxPosition.x()), 
                           MIN(m_minPosition.y(), m_maxPosition.y()), 
                           MIN(m_minPosition.z(), m_maxPosition.z()));
            return BoundingBox(minPos, maxPos);
        }
    private:
        Vector3 m_minPosition;
        Vector3 m_maxPosition;
    };
}

#endif
