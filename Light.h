/*
 *  Light.h
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/6/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#ifndef Light_h
#define Light_h

#include "Color.h"
#include "Vector3.h"

namespace ShadeKit {
    typedef enum {
        PKLightAttenuationNone = 0,
        PKLightAttenuationLinear = 1,
        PKLightAttenuationQuadratic = 2
    } LightAttenuation;
    class Light {
    public:
        Light(Vector3& pos) : m_position(pos), m_color(kColorWhite), m_intensity(1.0f), m_attenuation(PKLightAttenuationNone) { }
        
        const Vector3& position() const { return m_position; }
        const Color& color() const { return m_color; }
        const float intensity() const { return m_intensity; }
        const LightAttenuation attenuation() const { return m_attenuation; }
        
    private:
        Vector3 m_position;
        Color m_color;
        float m_intensity;
        LightAttenuation m_attenuation;
    };
}

#endif
