/*
 *  Vector4.h
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/7/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#ifndef Vector4_h
#define Vector4_h

#include "Vector3.h"

#include <iostream>
#include <cmath>

namespace ShadeKit {
    class Vector4 {
    public:
        Vector4() : m_x(0.0f), m_y(0.0f), m_z(0.0f), m_w(0.0f) { }
        Vector4(float x, float y, float z, float w) : m_x(x), m_y(y), m_z(z), m_w(w) { }
        Vector4(const Vector4& v) : m_x(v.x()), m_y(v.y()), m_z(v.z()), m_w(v.w()) { }
        Vector4(const Vector3& v) : m_x(v.x()), m_y(v.y()), m_z(v.z()), m_w(0.0f) { }
        
        float x() const { return m_x; }
        float y() const { return m_y; }
        float z() const { return m_z; }
        float w() const { return m_w; }
        
        void setX(float x) { m_x = x; }
        void setY(float y) { m_y = y; }
        void setZ(float z) { m_z = z; }
        void setW(float w) { m_w = w; }
        void set(Vector4 &v) { m_x = v.x(); m_y = v.y(); m_z = v.z(); m_w = v.w(); }
        
        inline float operator[](int i) const;
        Vector4 operator-() const { return Vector4(-m_x, -m_y, -m_z, -m_w); }
        Vector4& operator=(const Vector4& a)
        {
            m_x = a.x();
            m_y = a.y();
            m_z = a.z();
            m_w = a.w();
            return *this;
        }
        
        float dot(Vector4 &v) const { return m_x * v.x() + m_y * v.y() + m_z * v.z() + m_w * v.w(); }
        
        float norm() const { return sqrtf(m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w); }
        float normSq() const { return (m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w); }
        Vector4& normalize() 
        {
            float normInv = 1.0f / norm();
            m_x = m_x * normInv;
            m_y = m_y * normInv;
            m_z = m_z * normInv;
            m_w = m_w * normInv;
            return *this;
        }
        
    private:
        float m_x;
        float m_y;
        float m_z;
        float m_w;
    };
    
    inline Vector4& operator+=(Vector4& a, const Vector4& b)
    {
        a.setX(a.x() + b.x());
        a.setY(a.y() + b.y());
        a.setZ(a.z() + b.z());
        a.setW(a.w() + b.w());
        return a;
    }
    
    inline Vector4& operator-=(Vector4& a, const Vector4& b)
    {
        a.setX(a.x() - b.x());
        a.setY(a.y() - b.y());
        a.setZ(a.z() - b.z());
        a.setW(a.w() - b.w());
        return a;
    }
    
    inline Vector4& operator*=(Vector4& a, const Vector4& b)
    {
        a.setX(a.x() * b.x());
        a.setY(a.y() * b.y());
        a.setZ(a.z() * b.z());
        a.setW(a.w() * b.w());
        return a;
    }
    
    inline Vector4& operator*=(Vector4& a, const float m)
    {
        a.setX(a.x() * m);
        a.setY(a.y() * m);
        a.setZ(a.z() * m);
        a.setW(a.w() * m);
        return a;
    }
    
    inline Vector4& operator/=(Vector4& a, const Vector4& b)
    {
        a.setX(a.x() / b.x());
        a.setY(a.y() / b.y());
        a.setZ(a.z() / b.z());
        a.setW(a.w() / b.w());
        return a;
    }
    
    inline Vector4& operator/=(Vector4& a, const float m)
    {
        float mInv = 1.0f / m;
        return (a *= mInv);
    }
    
    inline float Vector4::operator[](int i) const
    {
        switch (i) {
            case 0:
                return m_x;
            case 1:
                return m_y;
            case 2:
                return m_z;
            case 3:
                return m_w;
        }
        return 0.0f;
    }
    
    inline Vector4 operator+(const Vector4& a, const Vector4& b)
    {
        return Vector4(a.x() + b.x(), a.y() + b.y(), a.z() + b.z(), a.w() + b.w());
    }
    
    inline Vector4 operator-(const Vector4& a, const Vector4& b)
    {
        return Vector4(a.x() - b.x(), a.y() - b.y(), a.z() - b.z(), a.w() - b.w());
    }
    
    inline Vector4 operator*(const Vector4& a, const Vector4& b)
    {
        return Vector4(a.x() * b.x(), a.y() * b.y(), a.z() * b.z(), a.w() * b.w());
    }
    
    inline Vector4 operator*(const Vector4& a, const float m)
    {
        return Vector4(a.x() * m, a.y() * m, a.z() * m, a.w() * m);
    }
    
    inline Vector4 operator*(const float m, const Vector4& a)
    {
        return Vector4(a.x() * m, a.y() * m, a.z() * m, a.w() * m);
    }
    
    inline Vector4 operator/(const Vector4& a, const float m)
    {
        float mInv = 1.0f / m;
        return (a * mInv);
    }
    
    inline Vector4 operator/(const float m, const Vector4& a)
    {
        return Vector4(m / a.x(), m / a.y(), m / a.z(), m / a.w());
    }
    
    inline int operator==(const Vector4& a, const Vector4& b)
    {
        return (a.x() == b.x() && a.y() == b.y() && a.z() == b.z() && a.w() == b.w());
    }
    
    std::ostream& operator<<(std::ostream& out, const Vector4& a);
}

#endif
