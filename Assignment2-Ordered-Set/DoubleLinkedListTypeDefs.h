/** 
* @file DoubleLinkedListFunctions.h
* 
* @brief Defines the data structures and error codes functions for managing and operating the double linked list.
*
* @details
* This file contains the core definitons for list operations using typedef structures and enumertions functions for:
*  - creating, deleting, and managing a double linked list.
*  - performing insertion, deletion and moving across a list.
*  - handling runtime errors.
*
* @author Sean Kirk - 23376201
* @note Coding
* @author Mihail Bizjajevs - 23364734
* @note Documentation
* @date 04/12/2024
* 
* @note Additional group members include: Ali Farah (23380098), Rory Huynh (23374624), Joseph Ennis (23360798)  
*/

#ifndef DoubleLinkedListTypeDefs_h
#define DoubleLinkedListTypeDefs_h

/**
* @enum llError
*
* @brief Enumeration for error codes in Double Linked List Operations.
*
* @details Identifies issues during runtime, like;
* > 'ok': Successful operation, aka. No error.
* > Errors.
*/
typedef enum { ok,		///< Successful operation. No error.
illegalNode,			///< Invalid node accessed/modified error
noMemory				///< Failed memory allocation error
} llError;


/**
* @struct data
* 
* @brief Defines the user-defined data to be stored in each node in the list
* 
* @details Contains 1 integer, i
*/
typedef struct {
	int i;			
} data;

/**
* @struct Node
*
* @brief Represents an element (single node) in the double linked list.
*
* @details it has the following;
* > 'data d' - object to store user info
* > Pointers
*/
typedef struct n {		// dummy name (n) before declaring Node name
	data d;				///< data stored in node
	struct n* prev;		///< Pointer to previous node in the list.
	struct n* next;		///< Pointer to the next node in the list.
} Node;


/**
* @struct DoubleLinkedList
*
* @brief Represents the entire double linked list.
*
* @details It keeps track of the 'head' and 'current' node.
*/
typedef struct {
	Node* head;			///< Pointer to the first node.
	Node* current;		///< Pointer the the current node.
} DoubleLinkedList;


#endif //DoubleLinkedListTypeDefs_h

// —————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// END OF DOUBLELINKEDLISTTYPEDEFS.H