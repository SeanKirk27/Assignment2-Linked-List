/** 
* @file DoubleLinkedListTypeDefs.c
* 
* @brief .c file used as a placeholder for typedef and enum definitons.
*
* @details Contains typedef structures and enum types for use in 'DoubleLinkedListFunctions.c'.
* This file is used to in support of the definitions declared in 'DoubleLinkedListTypeDefs.h' and is fully reliant on it.
* 
* @note All definitions are in the 'DoubleLinkedListTypeDefs.h'.
* 
* @author Sean Kirk - 23376201
* @note Coding
* @author Mihail Bizjajevs - 23364734
* @note Documentation
* @date 30/11/2024
*/

#include <stdio.h>
#include <stdlib.h>

// The typedef structures are fully defined in the 'DoubleLinkedListTypedefs.h'

/** 
* @struct Node
* 
* @brief Represents an element in the double linked list.
* 
* @details it has the following;
* > 'int data' - field to store user defined info.
* > Pointers
*/
typedef struct Node {
	int data;			///< Data stored in the node.
	struct Node *prev;	///< Pointer to previous node in the list.
	struct Node *next;	///< Pointer to the next node in the list.
} Node;

/**
* @struct DoubleLinkedList
* 
* @brief Represents the entire double linked list.
* 
* @details it has the following;
* > 'int size' - numberof elements in the list.
* > Pointers
*/
typedef struct DoubleLinkedList {
	int size;			///< Number of nodes in the list.
	Node *head;			///< Pointer to the first node.
	Node *current;		///< Pointer the the current node.
} DoubleLinkedList;

/**
* @enum llError
*
* @brief Enumeration for error codes in Double Linked List Operations.
*
* @details Identifies issues during runtime, like;
* > 'ok': Successful operation, aka. No error.
* > Errors.
*/
typedef enum { 
	ok,				///< Successful operation. No error.
	illegalNode,	///< Invalid node accessed/modified error
	noMemory		///< Failed memory allocation error
} llError;

// —————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// END OF DOUBLELINKEDLISTTYPEDEFS.C