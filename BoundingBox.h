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
    private:
        Vector3 m_minPosition;
        Vector3 m_maxPosition;
    };
}

#endif
