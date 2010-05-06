/*
 *  Image.cpp
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/6/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#include "Image.h"
#include <iostream>
#include <fstream>

namespace ShadeKit {
    
    void Image::writeBMPFile(const char *filename)
    {
        std::ofstream fs (filename, std::ios::out | std::ios::binary);
        if (!fs)
            fprintf(stderr, "Couldn't open BMP file %s for writing\n", filename);
        
        int linebyte = m_width * 3;
        int linemod = linebyte % 4;
        if(linemod != 0) {
            linebyte += (4 - linemod);
        }
        const int kFileHeaderSize = 14;
        const int kInfoHeaderSize = 40;
        
        char bfType[3] = "BM";
        unsigned int bfSize = kFileHeaderSize + kInfoHeaderSize + m_height * linebyte;
        unsigned short int bfReserved1 = 0;
        unsigned short int bfReserved2 = 0;
        unsigned int bfOffBits = kFileHeaderSize + kInfoHeaderSize;
        
        
        fs.write((char *)bfType, 2);
        fs.write((char *)&bfSize, 4);
        fs.write((char *)&bfReserved1, 2);
        fs.write((char *)&bfReserved2, 2);
        fs.write((char *)&bfOffBits, 4);
        
        unsigned int biSize = kInfoHeaderSize;
        unsigned int biWidth = m_width;
        unsigned int biHeight = m_height;
        unsigned short int biPlanes = 1;
        unsigned short int biBitCount = 24;
        unsigned int biCompression = 0;
        unsigned int biSizeImage = linebyte * m_height;
        unsigned int biXPelsPerMeter = 0; // horizontal resolution in pixels per meter (unreliable)
        unsigned int biYPelsPerMeter = 0; // vertical resolution in pixels per meter (unreliable)
        unsigned int biClrUsed = 0; // number of colors in image, or zero
        unsigned int biClrImportant = 0; // number of important colors, or zero
        
        fs.write((char *)&biSize, 4);
        fs.write((char *)&biWidth, 4);
        fs.write((char *)&biHeight, 4);
        fs.write((char *)&biPlanes, 2);
        fs.write((char *)&biBitCount, 2);
        fs.write((char *)&biCompression, 4);
        fs.write((char *)&biSizeImage, 4);
        fs.write((char *)&biXPelsPerMeter, 4);
        fs.write((char *)&biYPelsPerMeter, 4);
        fs.write((char *)&biClrUsed, 4);
        fs.write((char *)&biClrImportant, 4);
        
        int i, j;
        int padvalue = 0;
        Pixel *ptr = m_pixels;
        for (j = 0; j < m_height; ++j) {
            for (i = 0; i < m_width; ++i) {
                Pixel pixel = *ptr;
                fs.put(pixel.b);
                fs.put(pixel.g);
                fs.put(pixel.r);
                ptr++;
            }
            if (linemod != 0) {
                fs.write((char *)&padvalue, 4 - linemod);
            }
        }
    }
    
    std::ostream& operator<<(std::ostream& out, const Image& image)
    {
        out << "Ray(";
        out << image.width();
        out << ", ";
        out << image.height();
        out << ")";
        return out;
    }
}
