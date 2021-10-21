#ifndef BASELIST_H
#define BASELIST_H

/**
 * Nodo della lista
 */
struct _node {
  int val;
  struct _node* link;   // prev xor next
};

/**
 * Cursore per scorrere la lista
 */
typedef struct _cursor {
    struct _node* a;
    struct _node* b;
} cursor;

/**
 * Crea nodo
 */
struct _node* _createNode(int val);

/**
 * Valorizza link del nodo
 */
void _linkNode(struct _node* node, struct _node* before, struct _node* after);

/**
 * Inserimento nodo, ritorna true se siamo nei casi di inizio o fine lista
 */
int _insertNode(cursor cursor, struct _node* new);

/**
 * Incrementa cursore
 */
int _nextCursor(cursor* cursor);

#endif // BASELIST_H
