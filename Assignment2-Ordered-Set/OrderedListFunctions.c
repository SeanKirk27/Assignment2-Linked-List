/**
* @file OrderedListFunctions.c
*
* @brief Implementation of functions for managing/operating on a double linked list.
*
* @details Includes the implemented functions for;
*  > Creating/deleting in the ordered list.
*  > Inserting, deleting and getting nodes.
*  > Moving to the next or previous node in the list.
*
* @note
*
* @author Rory Huynh - 23374624
* @note Coding
* @author Joseph Ennis - 23360798
* @note Documentation
* @date 05/12/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include "OrderedList.h"
/**
 * @brief Creates an empty ordered integer set.
 *
 * Allocates memory for an orderedIntSet structure and initializes it.
 *
 * @return Pointer to the newly created orderedIntSet, or exits on allocation failure.
 */
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
/**
 * @brief Deletes an ordered integer set and frees memory.
 *
 * Frees memory associated with the set's list and the set itself.
 *
 * @param s Pointer to the orderedIntSet to delete.
 * @return ReturnValues indicating success or error type.
 */
ReturnValues deleteOrderedSet(orderedIntSet *s) {
    if (s == NULL) {
        return ALLOCATION_ERROR;
    }

    deleteDoubleLinkedList(s->list);
    free(s);

    return NUMBER_REMOVED;
}
/**
 * @brief Adds an element to the ordered set.
 *
 * Inserts an integer into the set while maintaining the order.
 *
 * @param s Pointer to the orderedIntSet.
 * @param elem The integer to add.
 * @return ReturnValues indicating success or error type.
 */
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
/**
 * @brief Removes an element from the ordered set.
 *
 * Deletes a specified integer from the set if it exists.
 *
 * @param s Pointer to the orderedIntSet.
 * @param elem The integer to remove.
 * @return ReturnValues indicating success or error type.
 */
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



/**
 * @brief Computes the intersection of two ordered sets.
 *
 * Returns a new set containing elements common to both input sets.
 *
 * @param s1 Pointer to the first orderedIntSet.
 * @param s2 Pointer to the second orderedIntSet.
 * @return Pointer to the new orderedIntSet containing the intersection.
 */
orderedIntSet *setIntersection(orderedIntSet *s1, orderedIntSet *s2) {
    if (s1 == NULL || s2 == NULL) {
        return NULL;
    }
    else if (s1 == s2) {
        return s1;
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
/**
 * @brief Computes the union of two ordered sets.
 *
 * Returns a new set containing all unique elements from both input sets.
 *
 * @param s1 Pointer to the first orderedIntSet.
 * @param s2 Pointer to the second orderedIntSet.
 * @return Pointer to the new orderedIntSet containing the union.
 */
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
/**
 * @brief Computes the difference of two ordered sets.
 *
 * Returns a new set containing elements in the first set that are not in the second.
 *
 * @param s1 Pointer to the first orderedIntSet.
 * @param s2 Pointer to the second orderedIntSet.
 * @return Pointer to the new orderedIntSet containing the difference.
 */
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
/**
 * @brief Prints the elements of an ordered set to the standard output.
 *
 * Displays the set in the format {elem1, elem2, ...}.
 *
 * @param s Pointer to the orderedIntSet.
 * @return 0 on success.
 */
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
