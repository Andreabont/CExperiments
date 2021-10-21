#ifndef OBJECTS_H
#define OBJECTS_H

#include <stdarg.h>

/**
 * Base class struct
 */
struct Class {
    size_t size;
    void * (* constructor) (void * self, va_list * app);
    void * (* destructor) (void * self);
};

/**
 * Create object
 */
void* new(const void* type, ...);

/**
 * Destroy object
 */
void delete (void * item);

#endif // OBJECTS_H
