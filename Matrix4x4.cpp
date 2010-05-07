/*
 *  Matrix4x4.cpp
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/7/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#include "Matrix4x4.h"

namespace ShadeKit {
    Matrix4x4& Matrix4x4::translate(float tx, float ty, float tz)
    {
        Matrix4x4 trans(1.0f, 0.0f, 0.0f, tx, 
                                    0.0f, 1.0f, 0.0f, ty, 
                                    0.0f, 0.0f, 1.0f, tz, 
                                    0.0f, 0.0f, 0.0f, 1.0f);
        return *this *= trans;
    }
    Matrix4x4& Matrix4x4::translate(const Vector3& t)
    {
        Matrix4x4 trans(1.0f, 0.0f, 0.0f, t.x(), 
                        0.0f, 1.0f, 0.0f, t.y(), 
                        0.0f, 0.0f, 1.0f, t.z(), 
                        0.0f, 0.0f, 0.0f, 1.0f);
        return *this *= trans;
    }
    Matrix4x4& Matrix4x4::scale(float sx, float sy, float sz)
    {
        Matrix4x4 trans(  sx, 0.0f, 0.0f, 0.0f,  
                        0.0f,   sy, 0.0f, 0.0f, 
                        0.0f, 0.0f,   sz, 0.0f,  
                        0.0f, 0.0f, 0.0f, 1.0f);
        return *this *= trans;
    }
    Matrix4x4& Matrix4x4::scale(const Vector3& s)
    {
        Matrix4x4 trans(s.x(),  0.0f,  0.0f, 0.0f, 
                        0.0f, s.y(),  0.0f, 0.0f, 
                        0.0f,  0.0f, s.z(), 0.0f, 
                        0.0f,  0.0f,  0.0f, 1.0f);
        return *this *= trans;
    }
    Matrix4x4& Matrix4x4::rotate(float rx, float ry, float rz)
    {
        Matrix4x4 transX(1.0f,     0.0f,      0.0f, 0.0f, 
                         0.0f, cosf(rx), -sinf(rx), 0.0f, 
                         0.0f, sinf(rx),  cosf(rx), 0.0f, 
                         0.0f,     0.0f,      0.0f, 1.0f);
        Matrix4x4 transY(cosf(ry), 0.0f, -sinf(ry), 0.0f, 
                             0.0f, 1.0f,      0.0f, 0.0f, 
                         sinf(ry), 0.0f,  cosf(ry), 0.0f, 
                         0.0f, 0.0f,      0.0f, 1.0f);
        Matrix4x4 transZ(cosf(rz), -sinf(rz), 0.0f, 0.0f, 
                         sinf(rz),  cosf(rz), 0.0f, 0.0f, 
                             0.0f,      0.0f, 1.0f, 0.0f,  
                             0.0f,      0.0f, 0.0f, 1.0f);
        return *this *= transX * transY * transZ;
    }
    Matrix4x4& Matrix4x4::rotate(const Vector3& r)
    {
        float rx = r.x();
        float ry = r.y();
        float rz = r.z();
        Matrix4x4 transX(1.0f,     0.0f,      0.0f, 0.0f, 
                         0.0f, cosf(rx), -sinf(rx), 0.0f, 
                         0.0f, sinf(rx),  cosf(rx), 0.0f, 
                         0.0f,     0.0f,      0.0f, 1.0f);
        Matrix4x4 transY(cosf(ry), 0.0f, -sinf(ry), 0.0f, 
                         0.0f, 1.0f,      0.0f, 0.0f, 
                         sinf(ry), 0.0f,  cosf(ry), 0.0f, 
                         0.0f, 0.0f,      0.0f, 1.0f);
        Matrix4x4 transZ(cosf(rz), -sinf(rz), 0.0f, 0.0f, 
                         sinf(rz),  cosf(rz), 0.0f, 0.0f, 
                         0.0f,      0.0f, 1.0f, 0.0f,  
                         0.0f,      0.0f, 0.0f, 1.0f);
        return *this *= transX * transY * transZ;
        
    }
}
