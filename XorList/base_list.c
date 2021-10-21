#include "base_list.h"
#include <malloc.h>
#include <stdio.h>
#include <stdint.h> 

struct _node * _createNode(int val) {
    struct _node* temp = (struct _node *) malloc( sizeof(struct _node) );
    temp->val = val;
    temp->link = NULL;
    return temp;
}

void _linkNode(struct _node* node, struct _node* before, struct _node* after) {
    node->link = (struct _node*)((uintptr_t)before ^ (uintptr_t)after);
}

int _insertNode(cursor cursor, struct _node* new) {
    struct _node* next = (void *)((uintptr_t)cursor.a ^ (uintptr_t)cursor.b->link);
    _linkNode(new, cursor.b, next);
    _linkNode(cursor.b, cursor.a, new);
    return next == NULL;
}

int _nextCursor(cursor* cursor) {
    struct _node* next = (struct _node*)((uintptr_t)cursor->a ^ (uintptr_t)cursor->b->link);
    if(next == NULL) {
        return 1;
    }
    cursor->a = cursor->b;
    cursor->b = next;
    return 0;
}
