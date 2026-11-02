#ifndef KUNZITE_TOUCH_HPP
#define KUNZITE_TOUCH_HPP

#include "IOKit/IOService.h"

/* 
 * KunziteTouch: XNU Kernel Extension for Redmi Note 15 5G Touch Controller.
 * This driver handles I2C communication with the digitizer to provide touch input.
 */

class KunziteTouch : public IOService {
    OSDeclareDefaultStructs(KunziteTouch)

private:
    uintptr_t    _i2cBaseAddr;
    uint8_t      _i2cAddr;
    
    // Estimated offsets for a standard touch controller
    static const uint32_t REG_TOUCH_STATUS   = 0x00;
    static const uint32_t REG_TOUCH_X       = 0x02;
    static const uint32_t REG_TOUCH_Y       = 0x04;
    static const uint32_t REG_TOUCH_CONFIG   = 0x10;

public:
    virtual bool start(IOService* provider) override;
    virtual void stop(IOService* provider) override;
    
    // Read raw coordinates from the hardware
    virtual bool readTouchCoords(int* x, int* y);
    virtual void writeRegister(uint8_t reg, uint8_t value);
    virtual uint8_t readRegister(uint8_t reg);
};

#endif // KUNZITE_TOUCH_HPP
