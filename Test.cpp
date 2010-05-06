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
#include "Plane.h"

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
        Camera camera(512, 512);
        
        Material sphereMaterial;
        sphereMaterial.setColor(kColorRed);
        sphereMaterial.setReflectivity(0.2);
        sphereMaterial.setShininess(3.3);
        sphereMaterial.setSpecular(kColorWhite);
        Vector3 spherePosition(-0.5f, -0.6f, 0.7f);
        Sphere sphere(spherePosition, 0.4f);
        sphere.setMaterial(sphereMaterial);
        camera.scene().surfaces()->push_back(&sphere);
        
        Vector3 planeNormal(0.0f, 0.0f, -1.0f);
        Plane plane(planeNormal, 2.0f);
        camera.scene().surfaces()->push_back(&plane);
        
        Material floorMaterial;
        floorMaterial.setColor(kColorBlack);
        Vector3 floorNormal(0.0f, 1.0f, 0.0f);
        Plane floor(floorNormal, 1.0f);
        floor.setMaterial(floorMaterial);
        camera.scene().surfaces()->push_back(&floor);
        
        Material ceilingMaterial;
        ceilingMaterial.setColor(kColorRed);
        Vector3 ceilingNormal(0.0f, -1.0f, 0.0f);
        Plane ceiling(ceilingNormal, 1.0f);
        ceiling.setMaterial(ceilingMaterial);
        ceiling.setAlternateMaterial(ceilingMaterial);
        camera.scene().surfaces()->push_back(&ceiling);
        
        Material leftWallMaterial;
        leftWallMaterial.setColor(kColorBlue);
        Vector3 leftWallNormal(1.0f, 0.0f, 0.0f);
        Plane leftWall(leftWallNormal, 1.0f);
        leftWall.setMaterial(leftWallMaterial);
        leftWall.setAlternateMaterial(leftWallMaterial);
        camera.scene().surfaces()->push_back(&leftWall);
        
        Material rightWallMaterial;
        rightWallMaterial.setColor(kColorGreen);
        Vector3 rightWallNormal(-1.0f, 0.0f, 0.0f);
        Plane rightWall(rightWallNormal, 1.0f);
        rightWall.setMaterial(rightWallMaterial);
        rightWall.setAlternateMaterial(rightWallMaterial);
        camera.scene().surfaces()->push_back(&rightWall);
        
        Vector3 lightPosition(0.3f, 0.9f, 0.0f);
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