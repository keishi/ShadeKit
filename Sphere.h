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
        const Material& material() const { return m_material; }
        
        void setCenter(const Vector3& v) { m_center = v; }
        void setRadius(const float f) { m_radius = f; m_radiusSq = f * f; m_radiusInv = 1.0f / f; }
        void setMaterial(const Material& material) { m_material = material; }
        
        Vector3 normalAt(Vector3& pos) { return (pos - m_center) * m_radiusInv; };
        Material materialAt(Vector3& pos) { return m_material; };
        float hit(Ray& ray);
        
    private:
        Vector3 m_center;
        float m_radius;
        float m_radiusSq;
        float m_radiusInv;
        Material m_material;
    };
}

#endif
