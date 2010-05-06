/*
 *  Test.cpp
 *  ShadeKit
 *
 *  Created by Keishi Hattori on 5/6/10.
 *  Copyright 2010 Keishi Hattori. All rights reserved.
 *
 */

#include "Test.h"
#include "Vector3.h"
#include "Image.h"

#include <cassert>

namespace ShadeKit {
    void Test::testVector3()
    {
        assert(Vector3(2, 3, 4) == Vector3(1, 2, 3) + Vector3(1, 1, 1));
        assert(Vector3(2, 4, 6) == Vector3(1, 2, 3) * 2);
        assert(14.0 == Vector3(1, 2, 3).dot(Vector3(1, 2, 3)));
        assert(Vector3(0, 0, 1) == Vector3(1, 0, 0).cross(Vector3(0, 1, 0)));
        printf(":-) PASS %s \n", __func__);
    }
    void Test::testImage()
    {
        Image image(256, 256);
        for (int y = 0; y < image.height(); y++) {
            for (int x = 0; x < image.width(); x++) {
                Color color = ((x / 16) % 2) ^ ((y / 16) % 2) ? ShadeKit::kColorWhite : ShadeKit::kColorBlack;
                image.setPixelColor(x, y, color);
            }
        }
        image.writeBMPFile("testImage.bmp");
        printf(":-| DONE %s     # Check testImage.bmp\n", __func__);
    }
    void Test::runAll()
    {
        testVector3();
        testImage();
    }
}