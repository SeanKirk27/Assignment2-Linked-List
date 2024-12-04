#include <stdio.h>
#include <stdlib.h>
#include "OrderedList.h"



orderedIntSet *createOrderedSet() {
    orderedIntSet *returnSet = (orderedIntSet *) malloc(sizeof(orderedIntSet));
    
    if (returnSet == NULL) {
        printf("[ERROR] Could not allocate heap memory when creating ordered set. Exiting...\n");
        exit(-1);
    }

    returnSet->size = 0;
    returnSet->head = NULL;
    
    return returnSet;
}

ReturnValues deleteOrderedSet(orderedIntSet *s) {
    if (s == NULL) {
        return ALLOCATION_ERROR;
    }
    
    Node *currentElement = s->head;
    Node *temp;

    while (currentElement != NULL) {
        temp = currentElement;
        currentElement = currentElement->next;
        free(temp);
    }

    free(s);

    return NUMBER_REMOVED;
}

ReturnValues addElement(orderedIntSet *s, int elem) {
    Node *currentElement = s->head;
    Node *newNode;

    while (currentElement != NULL) {
        if (currentElement->data == elem) {
            return NUMBER_ALREADY_IN_SET;
        }
        currentElement = currentElement->next;
    }

    newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return ALLOCATION_ERROR;
    }
    newNode->data = elem;

    if (s->head == NULL) {
        newNode->prev = NULL;
        newNode->next = NULL;
        s->head = newNode;
        s->size++;

        return NUMBER_ADDED;
    }

    currentElement = s->head;

    if (elem < currentElement->data) {
        newNode->prev = NULL;
        newNode->next = currentElement;
        currentElement->prev = newNode;
        s->head = newNode;
        s->size++;

        return NUMBER_ADDED;
    }

    while (currentElement->next != NULL) {
        if (currentElement->data < elem && elem < currentElement->next->data) {
            newNode->prev = currentElement;
            newNode->next = currentElement->next;
            currentElement->next->prev = newNode;
            currentElement->next = newNode;
            s->size++;

            return NUMBER_ADDED;
        }
        currentElement = currentElement->next;
    }

    newNode->prev = currentElement;
    newNode->next = NULL;
    currentElement->next = newNode;
    s->size++;

    return NUMBER_ADDED;
}

ReturnValues removeElement(orderedIntSet *s, int elem) {
    Node *currentElement = s->head;

    if (s->head == NULL) {
        return NUMBER_NOT_IN_SET;
    }

    while (currentElement != NULL) {
        if (currentElement->data == elem) {

            if (currentElement == s->head) {
                s->head = currentElement->next;
                
                if (s->head != NULL) {
                    s->head->prev = NULL;
                }
            } else if (currentElement->next == NULL) {
                currentElement->prev->next = NULL;
            } else {
                currentElement->prev->next = currentElement->next;
                currentElement->next->prev = currentElement->prev;
            }

            s->size--;
            free(currentElement);

            return NUMBER_REMOVED;
        }

        currentElement = currentElement->next;
    }

    return NUMBER_NOT_IN_SET;
}

orderedIntSet *setIntersection(orderedIntSet *s1, orderedIntSet *s2) {
    if ((s1 == NULL) || (s2 == NULL)) {
        return NULL;
    }

    Node *s1CurrentElement = s1->head;
    Node *s2CurrentElement = s2->head;
    
    orderedIntSet *intersectionResult = createOrderedSet();

    while (s1CurrentElement != NULL) {
        s2CurrentElement = s2->head;

        while (s2CurrentElement != NULL) {
            if (s1CurrentElement->data == s2CurrentElement->data) {
                if (addElement(intersectionResult, s1CurrentElement->data) == ALLOCATION_ERROR) {
                    deleteOrderedSet(intersectionResult);
                    return NULL;
                };
            }

            s2CurrentElement = s2CurrentElement->next;
        }

        s1CurrentElement = s1CurrentElement->next;
    }

    return intersectionResult;
}

orderedIntSet *setUnion(orderedIntSet *s1, orderedIntSet *s2) {
    if ((s1 == NULL) || (s2 == NULL)) {
        return NULL;
    }

    orderedIntSet *unionResult = createOrderedSet();
    Node *currentElement = s1->head;

    while (currentElement != NULL) {
        if (addElement(unionResult, currentElement->data) == ALLOCATION_ERROR) {
            deleteOrderedSet(unionResult);
            return NULL;
        };

        currentElement = currentElement->next;
    }

    currentElement = s2->head;
    while (currentElement != NULL) {
        if (addElement(unionResult, currentElement->data) == ALLOCATION_ERROR) {
            deleteOrderedSet(unionResult);
            return NULL;
        };
        
        currentElement = currentElement->next;
    }

    return unionResult;
}

orderedIntSet* setDifference(orderedIntSet *s1, orderedIntSet *s2) {
    if ((s1 == NULL) || (s2 == NULL)) {
        return NULL;
    }

    orderedIntSet *differenceResult = createOrderedSet();
    Node *currentElement = s1->head;
    Node *s2currentElement;

    while (currentElement != NULL) {
        int isInS2 = 0;
        s2currentElement = s2->head;

        while (s2currentElement != NULL) {
            if (s2currentElement->data == currentElement->data) {
                isInS2 = 1; 
                break;
            }
            s2currentElement = s2currentElement->next;
        }

        if (!isInS2) {
            if (addElement(differenceResult, currentElement->data) == ALLOCATION_ERROR) {
                deleteOrderedSet(differenceResult);
                return NULL;
            }
        }

        currentElement = currentElement->next;
    }

    return differenceResult;
}

int printToStdout(orderedIntSet *s) {
    if (s == NULL) {
        printf("{}\n");
        return 0;
    }

    Node *currentElement = s->head;

    printf("{");
    while (currentElement != NULL) {
        printf("%d", currentElement->data);
        if (currentElement->next) {
            printf(", ");
        }
        
        currentElement = currentElement->next;
    }
    printf("}\n");
}


