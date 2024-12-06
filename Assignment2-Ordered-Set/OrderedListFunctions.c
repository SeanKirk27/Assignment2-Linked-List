/**
 * @file OrderedListFunctions.c
 *
 * @brief Implementation of functions for managing/operating on an ordered integer set.
 *
 * @details This file provides the implementation for:
 *   - Creating and deleting ordered sets.
 *   - Adding, removing, and searching elements.
 *   - Performing set operations such as union, intersection, and difference.
 *   - Printing set contents.
 *
 *
 * @author Rory Huynh - 23374624
 * @note Coding
 * @author Joseph Ennis - 23360798
 * @note Documentation
 * @date 06/12/2024
 * 
 * @note Additional group members include: Ali Farah (23380098), Sean Kirk (23376201), Mihail Bizjajevs (23364734)
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
 * - Allocates memory for a new `orderedIntSet` structure. 
 * - Initializes the set's size to zero and creates an underlying double linked list to manage the set elements.
 *
 * ***Pseudocode:***
 * 1. Allocate memory for `orderedIntSet`
 * 2. If memory allocation successful, then:
 *      - Initialize `size` to 0
 *      - Create a double-linked list and assign to `list`
 * 3. If list creation fails:
 *      - Print error message
 *      - Exit program
 * 4. Return `orderedIntSet`
 * 
 * @return A pointer to the newly created ordered set, or exits the program on allocation failure.
*/
orderedIntSet *createOrderedSet() {
    orderedIntSet *returnSet = (orderedIntSet *) malloc(sizeof(orderedIntSet));
    // Check if memory allocation failed
    if (returnSet == NULL) {
        // Print an error message and terminate the program if allocation fails
        printf("[ERROR] Could not allocate heap memory when creating ordered set. Exiting...\n");
        exit(-1);
    }

    // Initialize the size of the ordered set to 0 (empty set)
    returnSet->size = 0;
    // Initialize the list field with a newly created double linked list
    returnSet->list = createDoubleLinkedList();

    // Return the pointer to the newly created ordered set
    return returnSet;
}
/**
 * @brief Deletes an ordered integer set and frees associated memory.
 *
 * @pre The set `s` must be valid (non-NULL).
 * @post The set and its elements are deallocated.
 *
 * @details 
 * - Frees all memory associated with the set, including its underlying double linked list.
 *
 * ***Pseudocode:***
 * 1. If `s` is NULL:
 *      - Return `ALLOCATION_ERROR`
 * 2. Otherwise:
 *      - Delete the double-linked list in `s->list`
 *      - Free memory allocated for `s`
 * 3. Return `NUMBER_REMOVED`
 * 
 * @param s A pointer to the `orderedIntSet` to be deleted.
 *
 * @return `ALLOCATION_ERROR` if `s` is NULL, otherwise `NUMBER_REMOVED`.
*/
ReturnValues deleteOrderedSet(orderedIntSet *s) {
    // Check if the input set pointer is NULL
    if (s == NULL) {
        return ALLOCATION_ERROR;// Return an error if the set doesn't exist
    }

    // Delete the double-linked list associated with the set
    deleteDoubleLinkedList(s->list);
    // Free the memory allocated for the orderedIntSet structure
    free(s);

    return NUMBER_REMOVED;// Indicate successful deletion
}
/**
 * @brief Adds an integer element to the ordered set.
 *
 * @pre The set `s` must be valid (non-NULL).
 * @post The integer `elem` is inserted in sorted order if not already present.
 *
 * @details 
 * - Traverses the list to find the correct position for `elem`. 
 * - If `elem` already exists, the function returns an error code. 
 * - Otherwise, `elem` is inserted, and the set's size is incremented.
 * 
 * ***Pseudocode:***
 * 1. If `s` is NULL:
 *      - Return `ALLOCATION_ERROR`
 * 2. Move to the head of `s->list`
 * 3. Traverse list while `current->next` is not NULL:
 *      - If `currentElement` equals `elem`, return `NUMBER_ALREADY_IN_SET`
 *      - If `currentElement` is greater than `elem`, break loop
 * 4. Create `newData` for `elem`
 * 5. Insert `newData` after the current node:
 *      - If insertion fails, return `ALLOCATION_ERROR`
 * 6. Increment `s->size`
 * 7. Return `NUMBER_ADDED`
 *
 * @param s A pointer to the `orderedIntSet`.
 * @param elem The integer element to be added.
 *
 * @return `NUMBER_ADDED` if successful, `NUMBER_ALREADY_IN_SET` if `elem` exists, or `ALLOCATION_ERROR` on failure.
*/
ReturnValues addElement(orderedIntSet *s, int elem) {
    // Check if the input set pointer is NULL
    if (s == NULL) {
        return ALLOCATION_ERROR;// Return an error if the set doesn't exist
    }

    // Traverse the list to find the correct position for the new element
    gotoHead(s->list);
    while (s->list->current->next != NULL) {
        int currentElement = s->list->current->next->d.i;

        // If the element is already in the set, return a specific error
        if (currentElement == elem) {
            return NUMBER_ALREADY_IN_SET;
        }
        // Stop if we find an element greater than the one being added
        else if (currentElement > elem) {
            break;
        }

        // Move to the next node
        gotoNextNode(s->list);
    }

    // Prepare the new data to be inserted
    data newData = {elem};
    // Attempt to insert the new data into the list
    if (insertAfter(&newData, s->list) != ok) {
        return ALLOCATION_ERROR;// Return an error if insertion fails
    }

    s->size++;// Increment the set size

    return NUMBER_ADDED;// Indicate successful addition
}
/**
 * @brief Removes an integer element from the ordered set.
 *
 * @pre The set `s` must be valid (non-NULL).
 * @post If `elem` is present, it is removed and the set's size is decremented.
 *
 * @details 
 * - Searches for `elem` in the set.
 * - If found, it removes the corresponding node.
 * - If not found, an error code is returned.
 *
 * ***Pseudocode:***
 * 1. If `s` is NULL:
 *      - Return `ALLOCATION_ERROR`
 * 2. Move to the head of `s->list`
 * 3. Traverse list using `gotoNextNode()`:
 *      - If `currentData` equals `elem`:
 *          - Delete current node
 *          - Decrement `s->size`
 *          - Return `NUMBER_REMOVED`
 * 4. If element not found:
 *      - Return `NUMBER_NOT_IN_SET`
 * 
 * @param s A pointer to the `orderedIntSet`.
 * @param elem The integer element to be removed.
 *
 * @return `NUMBER_REMOVED` if `elem` was removed, `NUMBER_NOT_IN_SET` if not found, or `ALLOCATION_ERROR` on failure.
*/
ReturnValues removeElement(orderedIntSet *s, int elem) {
    // Check if the input set pointer is NULL
    if (s == NULL) {
        return ALLOCATION_ERROR;// Return an error if the set doesn't exist
    }

    // Traverse the list to find the element to remove
    gotoHead(s->list);
    while (gotoNextNode(s->list) == ok) {
        int currentData = s->list->current->d.i;

        // If the element is found, delete it
        if (currentData == elem) {
            if (deleteCurrent(s->list) != ok) {
                return ALLOCATION_ERROR;// Return an error if deletion fails
            }
            s->size--;// Decrement the set size
            return NUMBER_REMOVED;// Indicate successful removal
        }
    }

    return NUMBER_NOT_IN_SET;// Return a specific error if the element is not found
}

/**
 * @brief Computes the intersection of two ordered sets.
 *
 * @pre Both sets `s1` and `s2` must be valid (non-NULL).
 * @post Returns a new set containing elements common to both `s1` and `s2`.
 *
 * @details 
 * - Iterates over both sets to identify common elements and adds them to a new set.
 * 
 * Pseudocode:
 * 1. If `s1` or `s2` is NULL:
 *      - Return NULL
 * 2. If `s1` equals `s2`:
 *      - Return `s1`
 * 3. Create new ordered set `intersectionResult`
 * 4. Traverse `s1->list` from head:
 *      - For each element in `s1`, traverse `s2->list` from head:
 *          - If an element in `s1` equals an element in `s2`:
 *              - Add element to `intersectionResult`
 * 5. Return `intersectionResult`
 *
 * @param s1 A pointer to the first `orderedIntSet`.
 * @param s2 A pointer to the second `orderedIntSet`.
 *
 * @return A pointer to the resulting set, or `NULL` on failure.
*/
orderedIntSet *setIntersection(orderedIntSet *s1, orderedIntSet *s2) {
    // Check if either input set pointer is NULL
    if (s1 == NULL || s2 == NULL) {
        return NULL;// Return NULL if inputs are invalid
    }
    // If both sets are the same, return the original set
    else if (s1 == s2) {
        return s1;
    }

    // Create a new set to store the intersection result
    orderedIntSet *intersectionResult = createOrderedSet();
    
    // Traverse through the first set
    gotoHead(s1->list);
    while (s1->list->current->next != NULL) {
        int s1Data = s1->list->current->next->d.i;

        // Traverse through the second set
        gotoHead(s2->list);
        while (s2->list->current->next != NULL) {
            int s2Data = s2->list->current->next->d.i;

            // If a match is found, add it to the intersection result
            if (s1Data == s2Data) {
                if (addElement(intersectionResult, s1Data) == ALLOCATION_ERROR) {
                    // Clean up and return NULL if memory allocation fails
                    deleteOrderedSet(intersectionResult);

                    return NULL;
                }
            }

            // Move to the next node in the second set
            gotoNextNode(s2->list);
        }
        // Move to the next node in the first set
        gotoNextNode(s1->list);
    }

    return intersectionResult;// Return the resulting set
}
/**
 * @brief Computes the union of two ordered sets and returns the result as a new set.
 *
 * @pre Two valid ordered sets exist.
 * @post A new ordered set is created containing all unique elements from both input sets.
 *
 * @details
 * - The union operation combines all elements from set `s1` and set `s2`.
 * - The resulting set contains only unique elements, maintaining sorted order.
 * - Both input sets remain unchanged.
 * 
 * Pseudocode:
 * 1. If `s1` or `s2` is NULL:
 *      - Return NULL
 * 2. Create new ordered set `unionResult`
 * 3. Traverse `s1->list` from head:
 *      - Add each element to `unionResult`
 * 4. Traverse `s2->list` from head:
 *      - Add each element to `unionResult`
 * 5. Return `unionResult`
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
    // Check if either input set pointer is NULL
    if (s1 == NULL || s2 == NULL) {
        return NULL;// Return NULL if inputs are invalid
    }

    // Create a new set to store the union result
    orderedIntSet *unionResult = createOrderedSet();

    // Add all elements from the first set to the union result
    gotoHead(s1->list);
    while (s1->list->current->next != NULL) {
        int s1Data = s1->list->current->next->d.i;

        if (addElement(unionResult, s1Data) == ALLOCATION_ERROR) {
            // Clean up and return NULL if memory allocation fails
            deleteOrderedSet(unionResult);

            return NULL;
        }

        // Move to the next node in the first set
        gotoNextNode(s1->list);
    }

    // Add all elements from the second set to the union result
    gotoHead(s2->list);
    while (s2->list->current->next != NULL) {
        int s2Data = s2->list->current->next->d.i;

        if (addElement(unionResult, s2Data) == ALLOCATION_ERROR) {
            // Clean up and return NULL if memory allocation fails
            deleteOrderedSet(unionResult);
            return NULL;
        }

        // Move to the next node in the second set
        gotoNextNode(s2->list);
    }

    return unionResult;// Return the resulting set
}

/**
 * @brief Computes the difference between two ordered sets and returns the result as a new set.
 *
 * @pre Two valid ordered sets exist.
 * @post A new ordered set is created containing elements in `s1` that are not in `s2`.
 *
 * @details
 * - The difference operation returns a set containing all elements that are present in `s1` but not in `s2`.
 * - The resulting set is sorted, and both input sets remain unchanged.
 * 
 * Pseudocode:
 * 1. If `s1` or `s2` is NULL:
 *      - Return NULL
 * 2. Create new ordered set `differenceResult`
 * 3. Traverse `s1->list` from head:
 *      - For each element in `s1`, traverse `s2->list`:
 *          - If element is not found in `s2`, add it to `differenceResult`
 * 4. Return `differenceResult`
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
    // Check if either input set pointer is NULL
    if (s1 == NULL || s2 == NULL) {
        return NULL;// Return NULL if inputs are invalid
    }

    // Create a new set to store the difference result
    orderedIntSet *differenceResult = createOrderedSet();

    // Traverse through the first set
    gotoHead(s1->list);
    while (s1->list->current->next != NULL) {
        int s1Data = s1->list->current->next->d.i;
        int foundInS2 = 0;

        // Check if the current element is in the second set
        gotoHead(s2->list);
        while (s2->list->current->next != NULL) {
            int s2Data = s2->list->current->next->d.i;

            if (s1Data == s2Data) {
                foundInS2 = 1;// Mark as found and break the inner loop
                break;
            }

            // Move to the next node in the second set
            gotoNextNode(s2->list);
        }

        // If the element is not found in the second set, add it to the difference result
        if (!foundInS2) {
            if (addElement(differenceResult, s1Data) == ALLOCATION_ERROR) {
                // Clean up and return NULL if memory allocation fails
                deleteOrderedSet(differenceResult);
                
                return NULL;
            }
        }
        // Move to the next node in the first set
        gotoNextNode(s1->list);
    }

    return differenceResult;// Return the resulting set
}
/**
 * @brief Computes and prints the contents of the given ordered set to the standard output.
 *
 * @pre A valid ordered set exists.
 * @post The elements of the set are printed in ascending order.
 *
 * @details
 * - Iterates through all elements in the ordered set and prints their values.
 * - Elements are printed in the format `{e1, e2, e3, ...}`.
 * - If the set is empty or NULL, prints `{}`.
 * 
 * Pseudocode:
 * 1. If `s` is NULL:
 *      - Print "{}" and return
 * 2. Move to head of `s->list`
 * 3. Print "{"
 * 4. Traverse `s->list` and print each element:
 *      - If not last element, print ", "
 * 5. Print "}" and new line
 * 6. Return
 *
 * @param s - A pointer to the 'orderedIntSet' to be printed.
 *
 * @return The number of elements in the set.
 * 
 * @note This function does not modify the structure of the set.
*/
int printToStdout(orderedIntSet* s) {
    // Check if the input set pointer is NULL
    if (s == NULL) {
        printf("{}\n");// Print an empty set if the input is NULL
        return 0;
    }

    // Start iterating from the head of the list
    gotoHead(s->list);
    printf("{");
    // Traverse the list and print each element
    while (s->list->current->next != NULL) {
        printf("%d", s->list->current->next->d.i);// Print the current element
        // Print a comma if more elements follow
        if (s->list->current->next->next != NULL) {
            printf(", ");
        }
        // Move to the next node
        gotoNextNode(s->list);
    }
    printf("}\n");// Close the set representation

    return 0;// Indicate successful print
}
// —————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// END OF OREDEREDLISTFUNCTIONS.C