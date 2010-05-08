/*
 *  Scene.h
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/6/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#ifndef Scene_h
#define Scene_h

#include "Light.h"
#include "Surface.h"

#include <vector>

namespace ShadeKit {
    class Scene {
    public:
        std::vector<Light*>& lights() { return m_lights; };
        std::vector<Surface*> *surfaces() { return &m_surfaces; };
        
        Surface *findHit(Ray ray, float *distance);
        void loadCube();
        
    private:
        std::vector<Light*> m_lights;
        std::vector<Surface*> m_surfaces;
    };
}

#endif
