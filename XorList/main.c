#include "list.h"
#include <stdio.h>

void powNode(struct _node* node) {
    node->val = node->val * node->val;
}

int main() {

list* myList = createList();

pushAfter(myList,1);
pushAfter(myList,2);
pushAfter(myList,3);

puts("##### Lista inserita:\n");
scrollList(myList, 0, printNode);

puts("##### Calcolo il quadrato di ogni nodo:\n");
scrollList(myList, 0, powNode);
scrollList(myList, 0, printNode);

}
