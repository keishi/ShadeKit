/*
 *  Plane.h
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/7/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#ifndef Plane_h
#define Plane_h

#include "Surface.h"

namespace ShadeKit {
    class Plane : public Surface {
    public:
        Plane(Vector3& normal, float distance)
        : m_normal(normal)
        , m_distance(distance)
        {
            m_uAxis = Vector3(normal.y, normal.z, -normal.x);
            m_vAxis = m_uAxis.cross(normal);
            m_material = new Material();
        }
        
        const Vector3& normal() const { return m_normal; }
        float distance() const { return m_distance; }
        Material* material() const { return m_material; }
        
        void setMaterial(Material* material) { m_material = material; }
        
        bool hit(Ray& ray, HitInfo *hitInfo);
        
    private:
        Vector3 m_normal;
        float m_distance;
        Material* m_material;
        Vector3 m_uAxis;
        Vector3 m_vAxis;
    };
}

#endif
