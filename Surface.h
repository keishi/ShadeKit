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

const float kNoHit = -1.0;

namespace ShadeKit {
    class Surface {
    public:
        Surface() 
        {
            m_boundingBox.setToInfinite();
        }
        
        virtual float hit(Ray& ray) = 0;
        virtual Vector3 normalAt(Vector3& pos) = 0;
        virtual Material materialAt(Vector3& pos) = 0;
        
    protected:
        BoundingBox m_boundingBox;
    };
}

#endif
