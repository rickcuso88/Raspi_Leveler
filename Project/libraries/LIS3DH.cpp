#include "LIS3DH.h"

const int ADDRESS = 0x18;
const uint8_t CTRL_REG_1 = 0x20;
const uint8_t CTRL_REG_4 = 0x23;
const uint8_t TEMP_CFG_REG = 0xC0;
const uint8_t x_accel_reg = 0x28;
const uint8_t y_accel_reg = 0x2A;
const uint8_t z_accel_reg = 0x2C;
const float sensitivity = 0.004f;



LIS3DH::LIS3DH(void) {
    this->x = 0;
    this->y = 0;
    this->z = 0;

    i2c_init(i2c1, 100 * 1000);

    gpio_set_function(3, GPIO_FUNC_I2C);
    gpio_set_function(2, GPIO_FUNC_I2C);
    gpio_pull_up(3);
    gpio_pull_up(2); 
    // Make the I2C pins available to picotool
    bi_decl(bi_2pins_with_func(2, 3, GPIO_FUNC_I2C));
}

bool LIS3DH::init(void) {
    uint8_t buf[2];
    set_reg(CTRL_REG_1, 0x97);
    set_reg(CTRL_REG_4, 0x80);
    return true;
}

void LIS3DH::set_reg(uint8_t reg, uint8_t val) {
    
    uint8_t buf[2];
    buf[0] = reg;
    buf[1] = val;
    i2c_write_blocking(i2c1, 0x18, buf, 2, false);
}

uint8_t LIS3DH::read_reg(uint8_t reg) {
    uint8_t data;
    i2c_write_blocking(i2c1, ADDRESS, &reg, 1, true);
    i2c_read_blocking(i2c1, ADDRESS, &data, 1, false);
    return data;

}

void LIS3DH::update(void) {
    uint8_t reg;
    float scaling = 64/sensitivity;

    uint8_t lsb;
    uint8_t msb;
    uint16_t raw_accel;

    lsb = read_reg(0x28);
    msb = read_reg(0x29);
    raw_accel = (msb << 8) | lsb;
    this->x = (float) ((int16_t) raw_accel)/scaling;
    
    sleep_ms(10);

    lsb = read_reg(0x2A);
    msb = read_reg(0x2B);
    raw_accel = (msb << 8) | lsb;
    this->y = (float) ((int16_t) raw_accel)/scaling;

    sleep_ms(10);

    lsb = read_reg(0x2C);
    msb = read_reg(0x2D);
    raw_accel = (msb << 8) | lsb;
    this->z = (float) ((int16_t) raw_accel)/scaling;

    sleep_ms(10);
}
