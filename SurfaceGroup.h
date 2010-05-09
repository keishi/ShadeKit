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
        SurfaceGroup()
        {
            m_boundingBox.setToNull();
        }
        std::vector<Surface*>& surfaces() { return m_surfaces; };
        void addSurface(Surface* s)
        {
            m_surfaces.push_back(s);
            if (m_boundingBox.isNull()) {
                m_boundingBox = s->boundingBox();
            } else {
                m_boundingBox = m_boundingBox.unionBox(s->boundingBox());
            }
        }
        
        bool hit(Ray& ray, HitInfo* hitInfo);
        
    private:
        std::vector<Surface*> m_surfaces;
    };
}

#endif
