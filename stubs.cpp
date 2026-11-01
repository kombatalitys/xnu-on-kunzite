#include "IOKit/IOService.h"
#include <cstdlib>
#include <iostream>

/*
 * stubs.cpp: The "Symbol Blanket".
 * We remove all calls to malloc, free, and printf because those belong to 
 * user-space libc, and kernel extensions cannot link against libc.
 */

// --- OSObject Stubs ---
// We only implement the methods that are NOT defined inline in the header.
void OSObject::release() { }
void OSObject::retain() { }

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

// --- Global XNU Kernel Symbols ---
extern "C" {
    void xnu_kernel_log_stub(const char* fmt, ...) { }
    void* IOMalloc(size_t size) { return (void*)0xBAADF00D; }
    void IOFree(void* ptr, size_t size) { }
    void __panic(const char* str) { while(1); }
}
