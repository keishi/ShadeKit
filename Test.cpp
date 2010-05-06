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
#include "Camera.h"
#include "Sphere.h"

#include <cassert>

namespace ShadeKit {
    void Test::testVector3()
    {
        Vector3 v111(1, 1, 1);
        Vector3 v123(1, 2, 3);
        Vector3 v234(2, 3, 4);
        Vector3 v246(2, 4, 6);
        Vector3 v100(1, 0, 0);
        Vector3 v010(0, 1, 0);
        Vector3 v001(0, 0, 1);
        
        assert(v234 == v123 + v111);
        assert(v246 == v123 * 2);
        assert(14.0 == v123.dot(v123));
        assert(v001 == v100.cross(v010));
        printf(":-) PASS %s \n", __func__);
    }
    void Test::testImage()
    {
        Image image(128, 128);
        for (int y = 0; y < image.height(); y++) {
            for (int x = 0; x < image.width(); x++) {
                Color color = ((x / 16) % 2) ^ ((y / 16) % 2) ? ShadeKit::kColorWhite : ShadeKit::kColorBlack;
                image.setPixelColor(x, y, color);
            }
        }
        image.writeBMPFile("testImage.bmp");
        printf(":-| DONE %s     # Check testImage.bmp\n", __func__);
    }
    void Test::testCamera()
    {
        Camera camera(128, 128);
        
        Vector3 spherePosition(0.0f, 0.0f, 1.0f);
        Sphere sphere(spherePosition, 0.5f);
        camera.scene().surfaces()->push_back(&sphere);
        
        Vector3 lightPosition(0.0f, 1.0f, 1.0f);
        Light light(lightPosition);
        camera.scene().lights().push_back(&light);
        
        Image image = camera.render();
        image.writeBMPFile("testCamera.bmp");
        
        printf(":-) PASS %s \n", __func__);
    }
    void Test::runAll()
    {
        testVector3();
        testImage();
        testCamera();
    }
}