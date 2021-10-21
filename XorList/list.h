#ifndef LIST_H
#define LIST_H

#include "base_list.h"

/**
 * Oggetto lista (puntatori inizio e fine)
 */
typedef struct _list {
    struct _node* begin;
    struct _node* end;
} list;

/**
 * Crea lista
 */
list* createList();

/**
 * Scorri la lista eseguendo callback su ogni nodo
 */
void scrollList(list* list, int dir, void (*scrollAction)(struct _node* node));

/**
 * Callback per stampare il nodo
 */
void printNode(struct _node* node);

/**
 * Ottieni cursore della posizione scelta
 */
cursor getCursor(list* list, int dir, int position);

/**
 * Ritorna cursore finale
 */
cursor getEndCursor(list* list);

/**
 * Inserisci nodo in coda
 */
void pushAfter(list* list, int value);

#endif // LIST_H
