#ifndef KUNZITE_HAPTICS_HPP
#define KUNZITE_HAPTICS_HPP

#include "IOKit/IOService.h"

/* 
 * KunziteHaptics: XNU Kernel Extension for Redmi Note 15 5G Haptic Motor.
 * This driver provides a simple "Vibe Check" to prove kernel execution.
 */

class KunziteHaptics : public IOService {
    OSDeclareDefaultStructs(KunziteHaptics)

private:
    uintptr_t    _hapticBaseAddr;
    
    // Estimated offsets for a standard Qualcomm LRA controller
    static const uint32_t REG_HAPTIC_CTRL      = 0x00;
    static const uint32_t REG_HAPTIC_INTENSITY = 0x04;
    static const uint32_t REG_HAPTIC_DURATION   = 0x08;

public:
    virtual bool start(IOService* provider) override;
    virtual void stop(IOService* provider) override;
    
    // Trigger a short vibration pulse
    virtual void triggerPulse();
    virtual void writeRegister(uint32_t offset, uint32_t value);
};

#endif // KUNZITE_HAPTICS_HPP
