/*
 *  Ray.h
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/6/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#ifndef Ray_h
#define Ray_h

#include <iostream>
#include "Vector3.h"

namespace ShadeKit {
    class Ray {
    public:
        const Vector3& origin() const { return m_origin; }
        const Vector3& direction() const { return m_direction; }
        
        void setOrigin(Vector3 &origin) { m_origin = origin; }
        void setDirection(Vector3 &direction) { m_direction = direction; }
        
        Vector3 pointAtDistance(float distance) const { return m_origin + m_direction * distance; }
        
    private:
        Vector3 m_origin;
        Vector3 m_direction;
    };
    
    std::ostream& operator<<(std::ostream& out, const Vector3& a);
}

#endif
