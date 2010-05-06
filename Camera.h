/*
 *  Camera.h
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/6/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#ifndef Camera_h
#define Camera_h

#include "Scene.h"
#include "Image.h"

namespace ShadeKit {
    class Camera {
    public:
        Camera(unsigned int width, unsigned int height)
        : m_width(width)
        , m_height(height)
        , m_renderShadow(1)
        , m_renderReflection(0)
        , m_renderHighlight(0)
        , m_backgroundColor(kColorBlack)
        { }
        
        Scene& scene() { return m_scene; }
        
        Surface *raytrace(Ray& ray, Color *acc, int level);
        Image render();
        
    private:
        unsigned int m_width, m_height;
        Scene m_scene;
        bool m_renderShadow;
        bool m_renderReflection;
        bool m_renderHighlight;
        Color m_backgroundColor;
    };
}

#endif
