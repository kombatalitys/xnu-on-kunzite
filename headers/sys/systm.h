#ifndef _SYS_SYSTM_H
#define _SYS_SYSTM_H

#include <stdint.h>
#include <stddef.h>

/* 
 * Stub for sys/systm.h to satisfy the compiler.
 * These are the core kernel types required for basic XNU driver compilation.
 */

typedef uint32_t mach_vm_address_t;
typedef uint32_t mach_vm_size_t;
typedef int kern_return_t;

#define KERN_SUCCESS 0
#define KERN_FAILURE -1

#endif // _SYS_SYSTM_H
