/*
 *  Sphere.cpp
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/6/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#include "Sphere.h"

namespace ShadeKit {
    Sphere::Sphere(Vector3& center, float radius)
    {
        setCenter(center);
        setRadius(radius);
        updateBoundingBox();
    }
    float Sphere::hit(Ray& ray)
    {
        if (!m_boundingBox.doesHit(ray)) {
            return kNoHit;
        }
        /*
        // check that ray is even headed toward the sphere first
        if ((ray.direction().x() > 0.0 && ray.direction().x() > m_center.x() + m_radius) ||
            (ray.direction().x() < 0.0 && ray.direction().x() < m_center.x() - m_radius) ||
            (ray.direction().y() > 0.0 && ray.direction().y() > m_center.y() + m_radius) ||
            (ray.direction().y() < 0.0 && ray.direction().y() < m_center.y() - m_radius) ||
            (ray.direction().z() > 0.0 && ray.direction().z() > m_center.z() + m_radius) ||
            (ray.direction().z() < 0.0 && ray.direction().z() < m_center.z() - m_radius)) {
            return kNoHit;
        }*/
        
        Vector3 dist = m_center - ray.origin();
        float b = ray.direction().dot(dist);
        float discriminant = m_radiusSq - dist.normSq() + b * b;
        if (discriminant < 0.0) {
            return kNoHit;
        }
        
        // two possible intersections
        float t = kNoHit;
        float t0 = b - sqrt(discriminant);
        float t1 = b + sqrt(discriminant);
        if (t0 > 0.1) {
            t = t0;
        } else if (t1 > 0.1) {
            t = t1;
        }
        return t;
    }
    std::ostream& operator<<(std::ostream& out, const Sphere& a)
    {
        out << "Sphere(center:";
        out << a.center();
        out << ", radius:";
        out << a.radius();
        out << ")";
        return out;
    }
}