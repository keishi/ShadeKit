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
        , m_aspect((float)width / (float)height)
        , m_eye(0.0f, 0.0f, -8.0f)
        , m_xDirection(1.0f, 0.0f, 0.0f)
        , m_yDirection(0.0f, 1.0f, 0.0f)
        , m_zDirection(0.0f, 0.0f, 1.0f)
        , m_FOVY(20.0f)
        , m_zNear(3.0f)
        , m_renderShadow(1)
        , m_renderReflection(1)
        , m_renderHighlight(1)
        , m_backgroundColor(kColorBlack)
        { }
        
        Scene& scene() { return m_scene; }
        
        Surface *raytrace(Ray& ray, Color *acc, int level);
        Image render();
        
        void setZNear(float z) { m_zNear = z; }
        void setFOVY(float FOVY) { m_FOVY = FOVY; }
        void setEye(const Vector3& e) { m_eye = e; }
        void setLookat(const Vector3& c)
        {
            m_zDirection = c.normalized();
            m_xDirection = m_yDirection.cross(m_zDirection).normalize();
        }
        void setUp(const Vector3& u)
        {
            m_yDirection = u.normalized();
            m_xDirection = m_yDirection.cross(m_zDirection).normalize();
        }
        void setRenderShadow(bool b) { m_renderShadow = b; }
        void setRenderReflection(bool b) { m_renderReflection = b; }
        
    private:
        unsigned int m_width, m_height;
        float m_aspect;
        Vector3 m_eye;
        Vector3 m_xDirection;
        Vector3 m_yDirection;
        Vector3 m_zDirection;
        float m_FOVY;
        float m_zNear;
        Scene m_scene;
        bool m_renderShadow;
        bool m_renderReflection;
        bool m_renderHighlight;
        Color m_backgroundColor;
    };
}

#endif
