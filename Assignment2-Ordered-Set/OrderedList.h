/**
 * @file OrderedList.h
 *
 * @brief Header file for defining the Ordered lists structure and its associated operations.
 *
 * @details
 * This header file contains declarations for managing ordered sets of integers using a double-linked list
 * as the underlying data structure. The functions support operations such as adding elements, removing elements,
 * computing set intersections, unions, and differences, as well as printing the set contents.
 *
 * The actual implementation of these functions is provided in a corresponding source file.
 * The double-linked list data structure and its associated types and functions are defined in
 * 'DoubleLinkedListTypeDefs.h' and 'DoubleLinkedListFunctions.h', which are included in this file.
 *
 * @note
 * - The `orderedIntSet` structure maintains the size of the set and a pointer to the double-linked list storing the elements.
 * - Return values for operations are represented by the `ReturnValues` enumeration.
 *
 * @author Rory Huynh - 23374624
 * @note Coding
 * @author Joseph Ennis - 23360798
 * @note Documentation
 * @date 04/12/2024
 *
 * @note Additional group members include: Ali Farah (23380098), Sean Kirk (23376201), Mihail Bizjajevs (23364734)
 */
#ifndef OrderedList_h
#define OrderedList_h
#include "DoubleLinkedListTypeDefs.h"
#include "DoubleLinkedListFunctions.h"
/**
 * @struct orderedIntSet
 * @brief Represents an ordered set of integers.
 *
 * Contains the size of the set and a pointer to a double-linked list that stores the elements.
 */
typedef struct orderedIntSet {
    int size;
    DoubleLinkedList *list;
} orderedIntSet;
/**
 * @enum ReturnValues
 * @brief Enumeration of possible return values for set operations.
 */
typedef enum {
    NUMBER_ALREADY_IN_SET, /* 0 */ /**< Element is already in the set. */
    NUMBER_NOT_IN_SET, /* 1 */ /**< Element is not found in the set. */
    NUMBER_ADDED, /* 2 */ /**< Element was successfully added to the set. */
    NUMBER_REMOVED, /* 3 */ /**< Element was successfully removed from the set. */
    ALLOCATION_ERROR /* 4 */ /**< Memory allocation error occurred. */
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
