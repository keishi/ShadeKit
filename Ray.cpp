/*
 *  Ray.cpp
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/6/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#include "Ray.h"

namespace ShadeKit {
    
    std::ostream& operator<<(std::ostream& out, const Ray& a)
    {
        out << "Ray(origin:";
        out << a.origin();
        out << ", direction:";
        out << a.direction();
        out << ")";
        return out;
    }
    
}