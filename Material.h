/*
 *  Material.h
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/6/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#ifndef Material_h
#define Material_h

#include "Color.h"

namespace ShadeKit {
    class Material {
    public:
        Material();
        
        const Color& color() const { return m_color; }
        const Color& diffuse() const { return m_diffuse; }
        const Color& ambient() const { return m_ambient; }
        const Color& specular() const { return m_specular; }
        const float shininess() const { return m_shininess; }
        const float reflectivity() const { return m_reflectivity; }
        
        void setColor(Color& color) { m_color = color; }
        void setDiffuse(Color& diffuse) { m_diffuse = diffuse; }
        void setAmbient(Color& ambient) { m_ambient = ambient; }
        void setSpecular(Color& specular) { m_specular = specular; }
        void setShininess(float shininess) { m_shininess = shininess; }
        void setReflectivity(float reflectivity) { m_reflectivity = reflectivity; }
        
    private:
        Color m_color;
        Color m_diffuse;
        Color m_ambient;
        Color m_specular;
        float m_shininess; // specular exponent
        float m_reflectivity;
    };
}

#endif
