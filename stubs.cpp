#include "IOKit/IOService.h"
#include <stdint.h>
#include <stddef.h>

/*
 * stubs.cpp: The "Libc-Free" Symbol Blanket.
 * We remove all calls to malloc, free, and printf because those belong to 
 * user-space libc, and kernel extensions cannot link against libc.
 */

// --- OSObject Stubs ---
void OSObject::release() { }
void OSObject::retain() { }
void OSObject::~OSObject() { } // Define destructor to satisfy __ZdlPv

// --- IOMemoryDescriptor Stubs ---
IOMemoryDescriptor* IOMemoryDescriptor::withPhysicalAddress(uintptr_t address, size_t size, uint32_t options) {
    return (IOMemoryDescriptor*)0xDEADBEEF;
}

void IOMemoryDescriptor::release() { }

IOMemoryMap* IOMemoryDescriptor::map() {
    return (IOMemoryMap*)0xCAFEBABE;
}

// --- IOMemoryMap Stubs ---
void* IOMemoryMap::getVirtualAddress() {
    return (void*)0xFEEDFACE;
}

void IOMemoryMap::release() { }

// --- IOService Stubs ---
bool IOService::start(IOService* provider) { return true; }
void IOService::stop(IOService* provider) { }
void IOService::release() { }
void IOService::~IOService() { }

// --- Global XNU Kernel Symbols ---
extern "C" {
    // We use a no-op for IOLog to avoid dependency on printf/puts
    void IOLog(const char* fmt, ...) { }
    
    // Kernel Memory Management - No longer calling malloc/free
    void* IOMalloc(size_t size) { return (void*)0xBAADF00D; }
    void IOFree(void* ptr, size_t size) { }
    
    // Basic XNU kernel entries
    void __panic(const char* str) { while(1); }
}
