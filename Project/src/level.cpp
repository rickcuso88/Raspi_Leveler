
#include "../libraries/LIS3DH.h"
#include "../libraries/neomatrix.h"
#include <stdio.h>
#include <cmath>
#include <time.h>

#define GREEN 0xFF0000
#define BLUE 0x0000FF
#define RED 0x00FF00

int main() {
    stdio_init_all();
    sleep_ms(500);

    NeoMatrix neo(8,8);
    LIS3DH accmeter;

    accmeter.init();
    neo.init();

    while(true) {
        
        accmeter.update();
        
        if(abs(accmeter.x) < .1 && abs(accmeter.y) < .1) {
            neo.set_pixel(3,3,GREEN);
            neo.set_pixel(3,4,GREEN);
            neo.set_pixel(4,3,GREEN);
            neo.set_pixel(4,4,GREEN);
        } else {
            neo.clear_pixels();
            int col = (accmeter.x*4)+4;
            int row = (accmeter.y*4)+4;
            neo.set_pixel(row,col,RED);
        }
        
        neo.write();
    }
    return 0;
}