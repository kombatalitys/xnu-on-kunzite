#ifndef _IOSERVICE_H
#define _IOSERVICE_H

#include "OSK.h"

// Base class for all IOKit objects
class OSObject {
public:
    virtual ~OSObject() {}
};

// IOMemoryDescriptor handles physical memory mapping
class IOMemoryDescriptor : public OSObject {
public:
    static IOMemoryDescriptor* withPhysicalAddress(uintptr_t address, size_t size, uint32_t options);
    virtual void release();
};

// IOMemoryMap provides access to the mapped memory
class IOMemoryMap : public OSObject {
public:
    virtual void* getVirtualAddress();
    virtual void release();
};

// IOService is the base for all drivers
class IOService : public OSObject {
public:
    virtual bool start(IOService* provider);
    virtual void stop(IOService* provider);
    virtual void release();
};

#endif // _IOSERVICE_H
