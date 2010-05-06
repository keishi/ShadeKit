/*
 *  Color.h
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/6/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#ifndef Color_h
#define Color_h

#include <iostream>

namespace ShadeKit {
    class Color {
    public:
        Color() : m_red(0.0f), m_green(0.0f), m_blue(0.0f) { }
        Color(float r, float g, float b) : m_red(r), m_green(g), m_blue(b) { }
        
        float red() const { return m_red; }
        float green() const { return m_green; }
        float blue() const { return m_blue; }
        
        void setRed(float r) { m_red = r; }
        void setGreen(float g) { m_green = g; }
        void setBlue(float b) { m_blue = b; }
        void setRGB(float r, float g, float b) { m_red = r; m_green = g; m_blue = b; }
        
        Color clipped()
        {
            return Color((m_red > 1.0) ? 1.0 : (m_red < 0.0) ? 0.0 : m_red,
                         (m_green > 1.0) ? 1.0 : (m_green < 0.0) ? 0.0 : m_green,
                         (m_blue > 1.0) ? 1.0 : (m_blue < 0.0) ? 0.0 : m_blue);
        }
        
        
        
    private:
        float m_red;
        float m_green;
        float m_blue;
    };
    
    inline Color operator+(const Color& a, const Color& b)
    {
        return Color(a.red() + b.red(), a.green() + b.green(), a.blue() + b.blue());
    }
    
    inline Color operator*(const Color& a, const Color& b)
    {
        return Color(a.red() * b.red(), a.green() * b.green(), a.blue() * b.blue());
    }
    
    inline Color operator*(const Color& a, const float m)
    {
        return Color(a.red() * m, a.green() * m, a.blue() * m);
    }
    
    inline Color operator*(const float m, const Color& a)
    {
        return Color(a.red() * m, a.green() * m, a.blue() * m);
    }
    
    std::ostream& operator<<(std::ostream& out, const Color& a);
}

#endif
