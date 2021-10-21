#ifndef POINT_H
#define POINT_H

#include <stdarg.h>

/* Definition on Point class */
struct Point {
    const void * class; // Mandatory
    int x, y;
};

extern const void * Point; // Name of the class (used in new)

/**
 * Point constructor
 */
static void * Point_ctor (void * _self, va_list * app);

/**
 * Point destructor
 */
static void * Point_dtor (void * _self);

#endif // POINT_H
