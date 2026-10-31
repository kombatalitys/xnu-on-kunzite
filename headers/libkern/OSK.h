#ifndef _OSK_H
#define _OSK_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

// Basic XNU Kernel Types
typedef uint32_t OSSize;
typedef uint32_t OSObjectRef;

// Macros for XNU class structure
#define OSDeclareDefaultStructs(ClassName) \
    static void __OSObject_init(); \
    static void __OSObject_free();

#define OSDefineDefaultStructs(ClassName, SuperClass, BaseClass) \
    /* Implementation for XNU class structure */

// Essential Kernel-space macros
#define IOLog(...) printf(__VA_ARGS__)
#define kIOMemoryDirectionInOut 0x0

#endif // _OSK_H
