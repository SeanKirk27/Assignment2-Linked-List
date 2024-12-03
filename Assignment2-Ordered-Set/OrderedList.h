#ifndef OrderedList_h
#define OrderedList_h

typedef struct Node { /* Rory Huynh: I am just copying Sean's node structure to keep the code consistent. */
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct orderedIntSet { /* Rory Huynh: Conventionally, structures should be defined with an upper camel case naming scheme but he specifically wanted it to be this so we will go with that :| */
    int size;
    Node* head;
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