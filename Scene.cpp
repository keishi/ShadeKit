/*
 *  Scene.cpp
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/6/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#include "Scene.h"
#include "Triangle.h"
#include "teapot.h"
#include "Matrix4x4.h"
#include "SurfaceGroup.h"
#include "Sphere.h"

namespace ShadeKit {
    HitInfo Scene::findHit(Ray& ray)
    {
        float hitDistance = INFINITY;
        HitInfo hitInfo;
        HitInfo intersectionInfo;
        // find nearest intersection
        for (unsigned int i = 0; i < m_surfaces.size(); i++) {
            Surface *s = m_surfaces[i];
            if (s->hit(ray, &intersectionInfo)) {
                if (intersectionInfo.distance() < hitDistance) {
                    hitDistance = intersectionInfo.distance();
                    hitInfo = intersectionInfo;
                }
            }
        }
        return hitInfo;
    }
    
    
    void Scene::loadCube()
    {
        Matrix4x4 trans;
        trans.setToIndentity();std::cout << trans;
        trans.translate(0.0f, 0.5f, 0.0f);std::cout << trans;
        //trans.rotate(0.0f, 1.0f, 0.0f);std::cout << trans;
        
        SurfaceGroup *group = new SurfaceGroup;
        for (int i = 0; i < Teapot_polygoncount; i++) {
            int *indices = Teapot_index[i];
            Vector3 v0(Teapot_vertex[indices[0]][5], Teapot_vertex[indices[0]][6], Teapot_vertex[indices[0]][7]);
            Vector3 v1(Teapot_vertex[indices[1]][5], Teapot_vertex[indices[1]][6], Teapot_vertex[indices[1]][7]);
            Vector3 v2(Teapot_vertex[indices[2]][5], Teapot_vertex[indices[2]][6], Teapot_vertex[indices[2]][7]);
            v0 = trans * v0;
            v1 = trans * v1;
            v2 = trans * v2;
            Triangle *t = new Triangle(v0, v1, v2);
            group->surfaces().push_back(t);
            
            Material *mirrorMaterial = new Material();
            mirrorMaterial->setColor(kColorRed);
            t->setMaterial(mirrorMaterial);
        }
        m_surfaces.push_back(group);
    }
}