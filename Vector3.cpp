/*
 *  Vector3.cpp
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/6/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#include "Vector3.h"

namespace ShadeKit {
    
    std::ostream& operator<<(std::ostream& out, const Vector3& a)
    {
        out << "<";
        out << a.x();
        out << ",";
        out << a.y();
        out << ",";
        out << a.z();
        out << ">";
        return out;
    }

}