/*
 *  Material.cpp
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/6/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#include "Material.h"

namespace ShadeKit {
    Material::Material()
    : m_color(kColorWhite)
    , m_ambient(Color(0.2f))
    , m_diffuse(Color(0.8f))
    , m_specular(Color(0.0f))
    , m_shininess(0.0f)
    , m_reflectivity(0.0f)
    { }
}