/*
 *  SurfaceGroup.h
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/9/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#ifndef SurfaceGroup_h
#define SurfaceGroup_h

#include "Surface.h"

#include <vector>

namespace ShadeKit {
    class SurfaceGroup : public Surface {
    public:
        std::vector<Surface*>& surfaces() { return m_surfaces; };
        
        bool hit(Ray& ray, HitInfo* hitInfo);
        
    private:
        std::vector<Surface*> m_surfaces;
    };
}

#endif
