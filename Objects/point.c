#include <stdio.h>
#include "point.h"
#include "objects.h"

/* Point method implementation */

static void * Point_ctor (void * _self, va_list * app) {
    struct Point * self = _self;
    self->x = va_arg(* app, int);
    self->y = va_arg(* app, int);
    printf("Create Point(%d,%d)\n", self->x, self->y);
    return self;
}

static void * Point_dtor (void * _self) {
    struct Point * self = _self;
    printf("Delete Point(%d,%d)\n", self->x, self->y);
    return self;
}

/* Point class initializazion */

static const struct Class _Point = {
    sizeof(struct Point), // Object size
    Point_ctor,           // Constructor pointer
    Point_dtor            // Destructor pointer
};

const void * Point = & _Point; // Link to class name (used in new)
