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
        
        void setPixel(int x, int y, const Pixel& p) { m_pixels[x + y * m_width] = p; }
        void setPixelColor(int x, int y, const Color& c)
        {
            Pixel p = {c.red()*255, c.green()*255, c.blue()*255};
            m_pixels[x + y * m_width] = p;
        }
        
        void writeBMPFile(const char *filename);
        
    private:
        unsigned int m_width;
        unsigned int m_height;
        Pixel *m_pixels;
    };
    
    std::ostream& operator<<(std::ostream& out, const Image& image);
}

#endif
