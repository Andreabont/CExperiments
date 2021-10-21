#include <stdio.h>
#include "objects.h"
#include "point.h"

int main() {
        
    struct Point* p = new(Point, 2, 2);
    
    printf("Read Point(%d,%d)\n", p->x, p->y);
    
    delete(p);
    
    return 0;
    
}
