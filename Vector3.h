/*
 *  Vector3.h
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/6/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#ifndef Vector3_h
#define Vector3_h

#include <iostream>
#include <cmath>

namespace ShadeKit {
    class Vector3 {
    public:
        Vector3() : m_x(0.0f), m_y(0.0f), m_z(0.0f) { }
        Vector3(float x, float y, float z) : m_x(x), m_y(y), m_z(z) { }
        Vector3(const Vector3&);
        
        float x() const { return m_x; }
        float y() const { return m_y; }
        float z() const { return m_z; }
        
        void setX(float x) { m_x = x; }
        void setY(float y) { m_y = y; }
        void setZ(float z) { m_z = z; }
        void set(Vector3 &v) { m_x = v.x(); m_y = v.y(); m_z = v.z(); }
        
        inline float operator[](int i) const;
        Vector3 operator-() const { return Vector3(-m_x, -m_y, -m_z); }
        Vector3& operator=(const Vector3& a)
        {
            m_x = a.x();
            m_y = a.y();
            m_z = a.z();
            return *this;
        }
        
        float dot(Vector3 &v) const { return m_x * v.x() + m_y * v.y() + m_z * v.z(); }
        float dot(Vector3 v) const { return m_x * v.x() + m_y * v.y() + m_z * v.z(); }
        Vector3 cross(Vector3 &v) const
        {
            return Vector3(m_y * v.z() - m_z * v.y(),
                           m_z * v.x() - m_x * v.z(),
                           m_x * v.y() - m_y * v.x());
        }
        Vector3 cross(Vector3 v) const
        {
            return Vector3(m_y * v.z() - m_z * v.y(),
                           m_z * v.x() - m_x * v.z(),
                           m_x * v.y() - m_y * v.x());
        }
        
        float norm() const { return sqrtf(m_x * m_x + m_y * m_y + m_z * m_z); }
        float normSq() const { return (m_x * m_x + m_y * m_y + m_z * m_z); }
        Vector3& normalize() 
        {
            float normInv = 1.0f / norm();
            m_x = m_x * normInv;
            m_y = m_y * normInv;
            m_z = m_z * normInv;
            return *this;
        }
        
    private:
        float m_x;
        float m_y;
        float m_z;
    };
    
    inline Vector3& operator+=(Vector3& a, const Vector3& b)
    {
        a.setX(a.x() + b.x());
        a.setY(a.y() + b.y());
        a.setZ(a.z() + b.z());
        return a;
    }
    
    inline Vector3& operator-=(Vector3& a, const Vector3& b)
    {
        a.setX(a.x() - b.x());
        a.setY(a.y() - b.y());
        a.setZ(a.z() - b.z());
        return a;
    }
    
    inline Vector3& operator*=(Vector3& a, const Vector3& b)
    {
        a.setX(a.x() * b.x());
        a.setY(a.y() * b.y());
        a.setZ(a.z() * b.z());
        return a;
    }
    
    inline Vector3& operator*=(Vector3& a, const float m)
    {
        a.setX(a.x() * m);
        a.setY(a.y() * m);
        a.setZ(a.z() * m);
        return a;
    }
    
    inline Vector3& operator/=(Vector3& a, const Vector3& b)
    {
        a.setX(a.x() / b.x());
        a.setY(a.y() / b.y());
        a.setZ(a.z() / b.z());
        return a;
    }
    
    inline Vector3& operator/=(Vector3& a, const float m)
    {
        float mInv = 1.0f / m;
        return (a *= mInv);
    }
    
    inline float Vector3::operator[](int i) const
    {
        switch (i) {
            case 0:
                return m_x;
            case 1:
                return m_y;
            case 2:
                return m_z;
        }
        return 0.0f;
    }
    
    inline Vector3 operator+(const Vector3& a, const Vector3& b)
    {
        return Vector3(a.x() + b.x(), a.y() + b.y(), a.z() + b.z());
    }
    
    inline Vector3 operator-(const Vector3& a, const Vector3& b)
    {
        return Vector3(a.x() - b.x(), a.y() - b.y(), a.z() - b.z());
    }
    
    inline Vector3 operator*(const Vector3& a, const Vector3& b)
    {
        return Vector3(a.x() * b.x(), a.y() * b.y(), a.z() * b.z());
    }
    
    inline Vector3 operator*(const Vector3& a, const float m)
    {
        return Vector3(a.x() * m, a.y() * m, a.z() * m);
    }
    
    inline Vector3 operator*(const float m, const Vector3& a)
    {
        return Vector3(a.x() * m, a.y() * m, a.z() * m);
    }
    
    inline Vector3 operator/(const Vector3& a, const float m)
    {
        float mInv = 1.0f / m;
        return (a * mInv);
    }
    
    inline Vector3 operator/(const float m, const Vector3& a)
    {
        return Vector3(m / a.x(), m / a.y(), m / a.z());
    }
    
    inline int operator==(const Vector3& a, const Vector3& b)
    {
        return (a.x() == b.x() && a.y() == b.y() && a.z() == b.z());
    }
    
    std::ostream& operator<<(std::ostream& out, const Vector3& a);
}

#endif
