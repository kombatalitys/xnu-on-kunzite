#ifndef KUNZITE_DISPLAY_HPP
#define KUNZITE_DISPLAY_HPP

#include "IOKit/IOService.h"

/* 
 * KunziteDisplay: XNU Kernel Extension for Redmi Note 15 5G Display.
 * Targets the Qualcomm MDSS (Mobile Display Sub-System) and DSI controllers.
 */

class KunziteDisplay : public IOService {
    OSDeclareDefaultStructs(KunziteDisplay)

private:
    uintptr_t    _mdssBaseAddr;
    uintptr_t    _dsiBaseAddr;
    uintptr_t    _framebufferAddr;
    
    // Estimated offsets for Qualcomm MDSS/DSI
    static const uint32_t REG_MDSS_CTRL       = 0x00;
    static const uint32_t REG_DSI_CONFIG      = 0x100;
    static const uint32_t REG_PANEL_POWER    = 0x200;

public:
    virtual bool start(IOService* provider) override;
    virtual void stop(IOService* provider) override;
    
    // Initialize the display hardware
    virtual bool initializePanel();
    virtual void clearScreen(uint32_t color);
    virtual void writeRegister(uintptr_t base, uint32_t offset, uint32_t value);
};

#endif // KUNZITE_DISPLAY_HPP
