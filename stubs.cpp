#include "IOKit/IOService.h"
#include <cstdlib>

/*
 * stubs.cpp: Provides minimal implementations of XNU kernel functions
 * to allow the linker to produce a binary on the build runner.
 * These symbols will be resolved by the actual XNU kernel at load-time.
 */

IOMemoryDescriptor* IOMemoryDescriptor::withPhysicalAddress(uintptr_t address, size_t size, uint32_t options) {
    // Return a dummy pointer to satisfy the linker
    return (IOMemoryDescriptor*)0xDEADBEEF;
}

void IOMemoryDescriptor::release() {
    // Stub implementation
}

IOMemoryMap* IOMemoryDescriptor::map() {
    // Return a dummy pointer to satisfy the linker
    return (IOMemoryMap*)0xCAFEBABE;
}

void* IOMemoryMap::getVirtualAddress() {
    // Return a dummy pointer to satisfy the linker
    return (void*)0xFEEDFACE;
}

void IOMemoryMap::release() {
    // Stub implementation
}
