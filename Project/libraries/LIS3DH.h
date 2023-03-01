#ifndef LIS3DH_H
#define LIS3DH_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

class LIS3DH {
    public:
        float x,y,z;
        LIS3DH(void);
        bool init(void);
        void set_reg(uint8_t reg, uint8_t val);
        uint8_t read_reg(uint8_t reg);
        void update(void);
};

#endif