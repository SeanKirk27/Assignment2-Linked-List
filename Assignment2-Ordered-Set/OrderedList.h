#ifndef OrderedList_h
#define OrderedList_h

typedef struct orderedIntSet {
    int size;
    DoubleLinkedList *list;
} orderedIntSet;

orderedIntSet* createOrderedSet();
ReturnValues deleteOrderedSet(orderedIntSet* s);
ReturnValues addElement(orderedIntSet* s, int elem);
ReturnValues removeElement(orderedIntSet* s, int elem);
orderedIntSet* setIntersection(orderedIntSet* s1, orderedIntSet* s2);
orderedIntSet* setUnion(orderedIntSet* s1, orderedIntSet* s2);
orderedIntSet* setDifference(orderedIntSet* s1, orderedIntSet* s2);
int printToStdout(orderedIntSet* s);
#endif
