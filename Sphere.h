/*
 *  Sphere.h
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/6/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#ifndef Sphere_h
#define Sphere_h

#include "Surface.h"

namespace ShadeKit {
    class Sphere : public Surface {
    public:
        Sphere(Vector3& center, float radius);
        
        const Vector3& center() const { return m_center; }
        float radius() const { return m_radius; }
        const Material* material() const { return m_material; }
        
        void updateBoundingBox()
        {
            Vector3 r = Vector3(m_radius);
            Vector3 min = m_center - r;
            Vector3 max = m_center + r;
            m_boundingBox = BoundingBox(min, max);
        }
        
        void setCenter(const Vector3& v) 
        {
            m_center = v;
            updateBoundingBox();
        }
        void setRadius(const float f) { m_radius = f; m_radiusSq = f * f; m_radiusInv = 1.0f / f; updateBoundingBox(); }
        void setMaterial(Material* material) { m_material = material; }
        
        virtual bool hit(Ray& ray, HitInfo *hitInfo);
        
    private:
        Vector3 m_center;
        float m_radius;
        float m_radiusSq;
        float m_radiusInv;
        Material* m_material;
    };
}

#endif
