#ifndef NEOMATRIX_H
#define NEOMATRIX_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"

using namespace std;

class NeoMatrix {
    public:
        PIO pio = pio0;
        const int sm = 0;
        uint8_t width, height;
        vector<uint32_t> mat;
        NeoMatrix(uint8_t width, uint8_t height);
        bool init(void);
        void set_pixel(uint8_t row, uint8_t col, uint32_t color);
        void clear_pixels(void);
        void write(void);
};

#endif