#include "neomatrix.h"

#define IS_RGBW false
#define NUM_PIXELS 150
//power pin 10
//neo pin 7
//sm assigned to 0
#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 2
#endif

NeoMatrix::NeoMatrix(uint8_t width, uint8_t height) {
    this->width=width;
    this->height=height;
    for (int i = 0; i < width*height; i++){
        mat.push_back(0);
    }
}

bool NeoMatrix::init(void) {
    //drive power high
    gpio_init(10);
    gpio_set_dir(10, GPIO_OUT);
    gpio_put(10, 1);
    
    int offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio0, sm, offset, 7, 800000, false);
    return true;
}

void NeoMatrix::set_pixel(uint8_t row, uint8_t col, uint32_t color) {
    int index = row*width + col;
    mat[index] = color;
}

void NeoMatrix::clear_pixels(void) {
    for (int i = 0; i < width*height; i++) {
        mat[i] = 0;
    }
}

void NeoMatrix::write(void) {
    for (int i = 0; i < width*height; i++) {
        pio_sm_put_blocking(pio0, 0, mat[i] << 8u);
    }
    sleep_ms(100);
}