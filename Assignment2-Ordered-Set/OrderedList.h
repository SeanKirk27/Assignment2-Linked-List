#ifndef OrderedList_h
#define OrderedList_h
#include "DoubleLinkedListTypeDefs.h"
#include "DoubleLinkedListFunctions.h"
typedef struct orderedIntSet {
    int size;
    DoubleLinkedList *list;
} orderedIntSet;

typedef enum {
    NUMBER_ALREADY_IN_SET, /* 0 */
    NUMBER_NOT_IN_SET, /* 1 */
    NUMBER_ADDED, /* 2 */
    NUMBER_REMOVED, /* 3 */
    ALLOCATION_ERROR /* 4 */
} ReturnValues;

orderedIntSet* createOrderedSet();
ReturnValues deleteOrderedSet(orderedIntSet* s);
ReturnValues addElement(orderedIntSet* s, int elem);
ReturnValues removeElement(orderedIntSet* s, int elem);
orderedIntSet* setIntersection(orderedIntSet* s1, orderedIntSet* s2);
orderedIntSet* setUnion(orderedIntSet* s1, orderedIntSet* s2);
orderedIntSet* setDifference(orderedIntSet* s1, orderedIntSet* s2);
int printToStdout(orderedIntSet* s);
#endif
