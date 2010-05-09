/*
 *  HitInfo.h
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/9/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#ifndef HitInfo_h
#define HitInfo_h

#include "Vector3.h"
#include "Material.h"

namespace ShadeKit {
    class Ray;
    class Surface;
    
    class HitInfo {
    public:
        HitInfo() 
        : m_position()
        , m_normal()
        , m_distance(0.0f)
        , m_material(NULL)
        , m_surface(NULL) 
        , m_ray(NULL) 
        { }
        const Vector3& position() const { return m_position; }
        const Vector3& normal() const { return m_normal; }
        Material* material() const { return m_material; }
        float distance() const { return m_distance; }
        const Surface* surface() const { return m_surface; }
        const Ray* ray() const { return m_ray; }
        
        void setPosition(const Vector3& pos) { m_position = pos; }
        void setNormal(const Vector3& n) { m_normal = n; }
        void setMaterial(Material* material) { m_material = material; }
        void setDistance(const float d) { m_distance = d; }
        void setSurface(Surface* s) { m_surface = s; }
        void setRay(Ray* ray) { m_ray = ray; }
        
    private:
        Vector3 m_position;
        Vector3 m_normal;
        Material* m_material;
        float m_distance;
        Surface* m_surface;
        Ray* m_ray;
    };
}

#endif
