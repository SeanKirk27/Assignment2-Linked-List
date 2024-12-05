/**
 * @file OrderedListFunctions.c
 *
 * @brief Implementation of functions for managing/operating on an ordered integer set.
 *
 * @details This file provides the implementation for:
 *   > Creating and deleting ordered sets.
 *   > Adding, removing, and searching elements.
 *   > Performing set operations such as union, intersection, and difference.
 *   > Printing set contents.
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
 * @brief Creates a new ordered integer set.
 *
 * @pre None.
 * @post A new ordered set is initialized and ready for operations.
 *
 * @details 
 * > Allocates memory for a new `orderedIntSet` structure. 
 * > Initializes the set's size to zero and creates an underlying double linked list to manage the set elements.
 *
 * @return A pointer to the newly created ordered set, or exits the program on allocation failure.
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
 * @brief Deletes an ordered integer set and frees associated memory.
 *
 * @pre The set `s` must be valid (non-NULL).
 * @post The set and its elements are deallocated.
 *
 * @details 
 * > Frees all memory associated with the set, including its underlying double linked list.
 *
 * @param s A pointer to the `orderedIntSet` to be deleted.
 *
 * @return `ALLOCATION_ERROR` if `s` is NULL, otherwise `NUMBER_REMOVED`.
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
 * @brief Adds an integer element to the ordered set.
 *
 * @pre The set `s` must be valid (non-NULL).
 * @post The integer `elem` is inserted in sorted order if not already present.
 *
 * @details 
 * > Traverses the list to find the correct position for `elem`. 
 * > If `elem` already exists, the function returns an error code. 
 * > Otherwise, `elem` is inserted, and the set's size is incremented.
 *
 * @param s A pointer to the `orderedIntSet`.
 * @param elem The integer element to be added.
 *
 * @return `NUMBER_ADDED` if successful, `NUMBER_ALREADY_IN_SET` if `elem` exists, or `ALLOCATION_ERROR` on failure.
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
 * @brief Removes an integer element from the ordered set.
 *
 * @pre The set `s` must be valid (non-NULL).
 * @post If `elem` is present, it is removed and the set's size is decremented.
 *
 * @details 
 * > Searches for `elem` in the set.
 * > If found, it removes the corresponding node.
 * > If not found, an error code is returned.
 *
 * @param s A pointer to the `orderedIntSet`.
 * @param elem The integer element to be removed.
 *
 * @return `NUMBER_REMOVED` if `elem` was removed, `NUMBER_NOT_IN_SET` if not found, or `ALLOCATION_ERROR` on failure.
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
 * @pre Both sets `s1` and `s2` must be valid (non-NULL).
 * @post Returns a new set containing elements common to both `s1` and `s2`.
 *
 * @details 
 * > Iterates over both sets to identify common elements and adds them to a new set.
 *
 * @param s1 A pointer to the first `orderedIntSet`.
 * @param s2 A pointer to the second `orderedIntSet`.
 *
 * @return A pointer to the resulting set, or `NULL` on failure.
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
* @brief Computes the union of two ordered sets and returns the result as a new set.
*
* @pre Two valid ordered sets exist.
* @post A new ordered set is created containing all unique elements from both input sets.
*
* @details
* > The union operation combines all elements from set `s1` and set `s2`.
* > The resulting set contains only unique elements, maintaining sorted order.
* > Both input sets remain unchanged.
*
* @param s1 - A pointer to the first 'orderedIntSet'.
* @param s2 - A pointer to the second 'orderedIntSet'.
*
* @return A pointer to a new 'orderedIntSet' representing the union of `s1` and `s2`.
*         Returns NULL if both input sets are NULL.
*
* @note Memory allocation is performed for the new set. The caller is responsible for freeing this memory.
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
* @brief Computes the difference between two ordered sets and returns the result as a new set.
*
* @pre Two valid ordered sets exist.
* @post A new ordered set is created containing elements in `s1` that are not in `s2`.
*
* @details
* > The difference operation returns a set containing all elements that are present in `s1` but not in `s2`.
* > The resulting set is sorted, and both input sets remain unchanged.
*
* @param s1 - A pointer to the first 'orderedIntSet' (the minuend set).
* @param s2 - A pointer to the second 'orderedIntSet' (the subtrahend set).
*
* @return A pointer to a new 'orderedIntSet' representing the difference of `s1` and `s2`.
*         Returns NULL if `s1` is NULL. If `s2` is NULL, the result is a copy of `s1`.
*
* @note Memory allocation is performed for the new set. The caller is responsible for freeing this memory.
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
* @brief Computes and prints the contents of the given ordered set to the standard output.
*
* @pre A valid ordered set exists.
* @post The elements of the set are printed in ascending order.
*
* @details
* > Iterates through all elements in the ordered set and prints their values.
* > Elements are printed in the format `{e1, e2, e3, ...}`.
* > If the set is empty or NULL, prints `{}`.
*
* @param s - A pointer to the 'orderedIntSet' to be printed.
*
* @return The number of elements in the set.
*
* @note This function does not modify the structure of the set.
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
// —————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// END OF OREDEREDLISTFUNCTIONS.C