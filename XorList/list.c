#include "list.h"
#include "base_list.h"
#include <malloc.h>
#include <stdio.h>
#include <stdint.h>

list * createList() {
    list* temp = (list *) malloc( sizeof(list) );
    temp->begin = NULL;
    temp->end = NULL;
    return temp;
}

void scrollList(list* list, int dir, void (*scrollAction)(struct _node* node)) {
    cursor cur;
    cur.a = NULL;
    cur.b = (!dir)? list->begin : list->end;
    while (1) {
        scrollAction(cur.b);
        if(_nextCursor(&cur)) {
            break;
        }
    }
}

void printNode(struct _node* node) {
    printf("Address: %p\n", (void*)node);
    printf("Value:   %d\n", (int)node->val);
    printf("Link:    %p\n\n", (void*)node->link);
}

cursor getCursor(list* list, int dir, int position) {
    int count = 0;
    cursor cur;
    cur.a = NULL;
    cur.b = (!dir)? list->begin : list->end;
    while (count < position) {
        if(_nextCursor(&cur)) {
            break;
        }
        count++;
    }
    return cur;
}

cursor getEndCursor(list* list) {
    cursor cur;
    cur.b = list->end;
    cur.a =  (list->begin == list->end)? NULL : (struct _node *)((uintptr_t)NULL ^ (uintptr_t)list->end->link);
    return cur;
}

void pushAfter(list* list, int value) {
    
    struct _node* new = _createNode(value);
    
    // Caso lista vuota
    if(list->begin == NULL && list->end == NULL) {
        list->begin = new;
        list->end = new;
        return;
    }
    
    cursor endCursor = getEndCursor(list);
    _insertNode(endCursor, new);
    list->end = new;
}
