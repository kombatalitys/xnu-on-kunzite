#ifndef _SYS_SYSTM_H
#define _SYS_SYSTM_H

#include <stdint.h>
#include <stddef.h>

typedef uint32_t mach_vm_address_t;
typedef uint32_t mach_vm_size_t;
typedef int kern_return_t;

#define KERN_SUCCESS 0
#define KERN_FAILURE -1

#endif // _SYS_SYSTM_H
