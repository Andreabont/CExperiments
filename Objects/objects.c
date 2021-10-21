#include <assert.h>
#include <stdlib.h>
#include "objects.h"

void * new(const void * _class, ...) {
    const struct Class * class = _class;
    void* p = calloc(1, class->size);

    assert(p);
    
    * (const struct Class **) p = class;

    if (class->constructor) {
        va_list ap;
        va_start(ap, _class);
        p = class->constructor(p, & ap);
        va_end(ap);
    }

    return p;
}

void delete(void * self) {
    const struct Class ** cp = self;

    if (self && * cp && (* cp)->destructor) {
        self = (* cp)->destructor(self);
    }
    
    free(self);
}
