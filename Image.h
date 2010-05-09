/*
 *  Image.h
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/6/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#ifndef Image_h
#define Image_h

#include <iostream>
#include "Vector3.h"
#include "Color.h"

namespace ShadeKit {
    class Image {
        typedef struct {
            unsigned char r, g, b;
        } Pixel;
    public:
        Image(unsigned int width, unsigned int height);
        virtual ~Image();
        
        const unsigned int width() const { return m_width; }
        const unsigned int height() const { return m_height; }
        const unsigned int pixelCount() const { return m_width * m_height; }
        
        Color pixelColorAt(int x, int y) const
        {
            Pixel p = m_pixels[x + y * m_width];
            return Color(p.r / 255.0f, p.g / 255.0f, p.b / 255.0f);
        }
        Color sampleColorAt(float x, float y) const
        {
            int left = (int)x;
            int top = (int)y;
            Color topColor = pixelColorAt(left, top) * (x - left) + pixelColorAt(left + 1, top) * (1.0f - x + left);
            Color bottomColor = pixelColorAt(left, top + 1) * (x - left) + pixelColorAt(left + 1, top + 1) * (1.0f - x + left);
            return topColor * (y - top) + bottomColor * (1.0f - x + top);
        }
        
        void setPixel(int x, int y, const Pixel& p) { m_pixels[x + y * m_width] = p; }
        void setPixelColor(int x, int y, const Color& c)
        {
            Color d = c.clipped();
            Pixel p = {d.red() * 255, d.green() * 255, d.blue() * 255};
            m_pixels[x + y * m_width] = p;
        }
        
        void loadBMPFile(const char *filename);
        void writeBMPFile(const char *filename) const;
        
    private:
        unsigned int m_width;
        unsigned int m_height;
        Pixel *m_pixels;
    };
    
    std::ostream& operator<<(std::ostream& out, const Image& image);
}

#endif
