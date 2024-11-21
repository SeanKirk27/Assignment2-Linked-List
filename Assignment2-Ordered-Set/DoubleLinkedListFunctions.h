#ifndef DoubleLinkedListFunctions_h
#define DoubleLinkedListFunctions_h
/**
*Function declarations
*/
DoubleLinkedList* createDoubleLinkedList();
void* deleteDoubleLinkedList(DoubleLinkedList* list);
data* getData(DoubleLinkedList* list);
llError gotoNextNode(DoubleLinkedList* list);
llError gotoPreviousNode(DoubleLinkedList* list);
void gotoHead(DoubleLinkedList* list);
void gotoTail(DoubleLinkedList* list);
llError insertAfter(data* d, DoubleLinkedList* list);
llError insertBefore(data* d, DoubleLinkedList* list);
void deleteCurrent(DoubleLinkedList* list);
#endif
