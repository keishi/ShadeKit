/*
 *  Surface.h
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/6/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#ifndef Surface_h
#define Surface_h

#include "Material.h"
#include "BoundingBox.h"
#include "HitInfo.h"

const float kNoHit = -1.0;

namespace ShadeKit {
    class Surface {
    public:
        Surface() 
        {
            m_boundingBox.setToInfinite();
        }
        
        const BoundingBox& boundingBox() const { return m_boundingBox; }
        
        virtual bool hit(Ray& ray, HitInfo* hitInfo) = 0;
        
    protected:
        BoundingBox m_boundingBox;
    };
}

#endif
