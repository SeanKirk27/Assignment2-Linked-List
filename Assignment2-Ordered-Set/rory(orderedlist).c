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
    returnSet->list = createDoubleLinkedList();

    return returnSet;
}

ReturnValues deleteOrderedSet(orderedIntSet *s) {
    if (s == NULL) {
        return ALLOCATION_ERROR;
    }

    deleteDoubleLinkedList(s->list);
    free(s);

    return NUMBER_REMOVED;
}

ReturnValues addElement(orderedIntSet *s, int elem) {
    if (s == NULL) {
        return ALLOCATION_ERROR;
    }

    gotoHead(s->list);
    while (s->list->current->next != NULL) {
        int currentElement = s->list->current->next->d.i;

        if (currentElement == elem) {
            return NUMBER_ALREADY_IN_SET;
        } else if (currentElement > elem) {
            break;
        }

        gotoNextNode(s->list);
    }

    data newData = {elem};
    if (insertAfter(&newData, s->list) != ok) {
        return ALLOCATION_ERROR;
    }

    s->size++;

    return NUMBER_ADDED;
}

ReturnValues removeElement(orderedIntSet *s, int elem) {
    if (s == NULL) {
        return ALLOCATION_ERROR;
    }

    gotoHead(s->list);
    while (gotoNextNode(s->list) == ok) {
        int currentData = s->list->current->d.i;

        if (currentData == elem) {
            if (deleteCurrent(s->list) != ok) {
                return ALLOCATION_ERROR;
            }
            s->size--;
            return NUMBER_REMOVED;
        }
    }

    return NUMBER_NOT_IN_SET;
}




orderedIntSet *setIntersection(orderedIntSet *s1, orderedIntSet *s2) {
    if (s1 == NULL || s2 == NULL) {
        return NULL;
    }

    orderedIntSet *intersectionResult = createOrderedSet();
    
    gotoHead(s1->list);
    while (s1->list->current->next != NULL) {
        int s1Data = s1->list->current->next->d.i;

        gotoHead(s2->list);
        while (s2->list->current->next != NULL) {
            int s2Data = s2->list->current->next->d.i;

            if (s1Data == s2Data) {
                if (addElement(intersectionResult, s1Data) == ALLOCATION_ERROR) {
                    deleteOrderedSet(intersectionResult);

                    return NULL;
                }
            }

            gotoNextNode(s2->list);
        }
        gotoNextNode(s1->list);
    }

    return intersectionResult;
}

orderedIntSet *setUnion(orderedIntSet *s1, orderedIntSet *s2) {
    if (s1 == NULL || s2 == NULL) {
        return NULL;
    }

    orderedIntSet *unionResult = createOrderedSet();

    gotoHead(s1->list);
    while (s1->list->current->next != NULL) {
        int s1Data = s1->list->current->next->d.i;

        if (addElement(unionResult, s1Data) == ALLOCATION_ERROR) {
            deleteOrderedSet(unionResult);

            return NULL;
        }

        gotoNextNode(s1->list);
    }

    gotoHead(s2->list);
    while (s2->list->current->next != NULL) {
        int s2Data = s2->list->current->next->d.i;

        if (addElement(unionResult, s2Data) == ALLOCATION_ERROR) {
            deleteOrderedSet(unionResult);
            return NULL;
        }

        gotoNextNode(s2->list);
    }

    return unionResult;
}

orderedIntSet *setDifference(orderedIntSet *s1, orderedIntSet *s2) {
    if (s1 == NULL || s2 == NULL) {
        return NULL;
    }

    orderedIntSet *differenceResult = createOrderedSet();

    gotoHead(s1->list);
    while (s1->list->current->next != NULL) {
        int s1Data = s1->list->current->next->d.i;
        int foundInS2 = 0;

        gotoHead(s2->list);
        while (s2->list->current->next != NULL) {
            int s2Data = s2->list->current->next->d.i;

            if (s1Data == s2Data) {
                foundInS2 = 1;
                break;
            }

            gotoNextNode(s2->list);
        }

        if (!foundInS2) {
            if (addElement(differenceResult, s1Data) == ALLOCATION_ERROR) {
                deleteOrderedSet(differenceResult);
                
                return NULL;
            }
        }
        gotoNextNode(s1->list);
    }

    return differenceResult;
}

int printToStdout(orderedIntSet* s) {
    if (s == NULL) {
        printf("{}\n");
        return 0;
    }

    gotoHead(s->list);
    printf("{");
    while (s->list->current->next != NULL) {
        printf("%d", s->list->current->next->d.i);
        if (s->list->current->next->next != NULL) {
            printf(", ");
        }
        gotoNextNode(s->list);
    }
    printf("}\n");

    return 0;
}
