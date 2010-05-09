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
        Light(Vector3& pos) : m_position(pos), m_color(kColorWhite), m_attenuation(PKLightAttenuationLinear) { }
        
        const Vector3& position() const { return m_position; }
        const Color& color() const { return m_color; }
        const LightAttenuation attenuation() const { return m_attenuation; }
        const float intensityAt(const Vector3& position) const { return 1.0; }
        
        void setAttenuation(LightAttenuation attenuation) { m_attenuation = attenuation; }
        
    private:
        Vector3 m_position;
        Color m_color;
        LightAttenuation m_attenuation;
    };
}

#endif
