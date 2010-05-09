/*
 *  SheetLaser.h
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/9/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#ifndef SheetLaser_h
#define SheetLaser_h

#include "Light.h"

namespace ShadeKit {
    class SheetLaser : public Light {
    public:
        SheetLaser(Vector3& pos) : Light(pos) {
            this->setAttenuation(LightAttenuationNone);
        }
        const float intensityAt(const Vector3& pos) const
        {
            Vector3 direction = position() - pos;
            float x = m_sheetNormal.dot(direction);
            return (fabs(x) > 0.01f) ? 0.0f : 1.0f;
        }
        
        void setSheetNormal(const Vector3 &n) 
        {
            m_sheetNormal = n.normalized();
        }
        
    private:
        Vector3 m_sheetNormal;
    };
}

#endif
