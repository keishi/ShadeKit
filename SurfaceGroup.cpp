/*
 *  SurfaceGroup.cpp
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/9/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#include "SurfaceGroup.h"

namespace ShadeKit {
    bool SurfaceGroup::hit(Ray& ray, HitInfo* hitInfo)
    {
        if (!m_boundingBox.doesHit(ray)) {
            return false;
        }
        
        float hitDistance = INFINITY;
        HitInfo intersectionInfo;
        // find nearest intersection
        for (unsigned int i = 0; i < m_surfaces.size(); i++) {
            Surface *s = m_surfaces[i];
            if (s->hit(ray, &intersectionInfo)) {
                if (intersectionInfo.distance() < hitDistance) {
                    hitDistance = intersectionInfo.distance();
                    *hitInfo = intersectionInfo;
                }
            }
        }
        return hitDistance != INFINITY;
    }
}