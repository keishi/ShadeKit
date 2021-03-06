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
    bool Sphere::hit(Ray& ray, HitInfo* hitInfo)
    {
        if (!m_boundingBox.doesHit(ray)) {
            return false;
        }
        
        Vector3 dist = m_center - ray.origin();
        float b = ray.direction().dot(dist);
        float discriminant = m_radiusSq - dist.normSq() + b * b;
        if (discriminant < 0.0) {
            return false;
        }
        
        // two possible intersections
        float t = kNoHit;
        float t0 = b - sqrt(discriminant);
        float t1 = b + sqrt(discriminant);
        if (t0 > 0.0001) {
            t = t0;
        } else if (t1 > 0.0001) {
            t = t1;
        }
        
        Vector3 hitPosition = ray.pointAtDistance(t);
        Vector3 hitNormal = (hitPosition - m_center) * m_radiusInv;
        hitInfo->setDistance(t);
        hitInfo->setNormal(hitNormal);
        hitInfo->setMaterial(m_material);
        hitInfo->setPosition(hitPosition);
        hitInfo->setSurface(this);
        hitInfo->setRay(&ray);
        
        return true;
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