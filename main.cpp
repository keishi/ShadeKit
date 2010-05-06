#include <iostream>
#include "Image.h"

void testImage()
{
    
    ShadeKit::Image image(256, 256);
    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            ShadeKit::Color color = ((x / 16) % 2) ^ ((y / 16) % 2) ? ShadeKit::kColorWhite : ShadeKit::kColorBlack;
            image.setPixelColor(x, y, color);
        }
    }
    image.writeBMPFile("testImage.bmp");
}

int main (int argc, char * const argv[]) {
    ShadeKit::Vector3 v(1.0, 2.0, 3.0);
    std::cout << v << "\n";
    testImage();
    return 0;
}
