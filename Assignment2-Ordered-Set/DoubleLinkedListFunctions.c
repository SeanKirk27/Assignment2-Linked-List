/** 
* @file DoubleLinkedListFunctions.c
* 
* @brief Implementation of functions for managing/operating on a double linked list.
*
* @details Includes the implemented functions for;
*  > Creating/deleting in the double linked list.
*  > Inserting, deleting and getting nodes.
*  > Moving to the next or previous node in the list.
*
* @note 
*
* @author Sean Kirk - 23376201
* @note Coding
* @author Mihail Bizjajevs - 23364734
* @note Documentation
* @date 30/11/2024
*/

#include "DoubleLinkedListTypeDefs.h"
#include "DoubleLinkedListFunctions.h"
#include <stdlib.h>
#include <stdio.h>

/**
* @brief Creates a new empty double linked list, consisting only of head and tail
* 
* @pre None
* @post Empty double linked list is created
*
* @details 
* > Allocates memory for the list and its head node.
* > Initialises the head node with no next or previous nodes. 
* > Head points to tail resulting in NULL.
* > Set the current pointer to the head node.
* 
* @return: Pointer to created DoubleLinkedList if successful,
*		   Pointer to NULL if it fails.
*/
DoubleLinkedList* createDoubleLinkedList() {
	DoubleLinkedList* list; // pointer variable 'list' declared of type 'DoubleLinkedList*' 
	list = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList)); // allocates enough memory to hold a 'DoubleLinkedList' structure
	
	if (list != NULL) { // Checks if list allocation was successful
		list->head = (Node*)malloc(sizeof(Node)); // Attempts to allocate memory for the head node.
		//Check if successful
		if (list->head != NULL) { // Checks if head allocation was successful
			list->head->next = NULL; // Head's next pointer set to NULL
			list->head->prev = NULL; // Head's previous pointer set to NULL
			list->current = list->head; // Set the current pointer to the head
		}
		//If it failed, deallocate the list and set it NULL
		else {
			free(list);  // If it failed, deallocate the list and
			list = NULL; // set it to NULL.
		}
	}
	return list; 
}


/**
* @brief Deletes the double linked list (including all its elements) and frees all associated memory.
* 
* @pre valid double linked list exists
* @post The entire list is deleted.
* 
* @details 
* This deletes all nodes in the 'DoubleLinkedList' and frees the memory allocated for the list structure itself.
* Iterates through all nodes and frees them one by one.
* 
* @param list - A pointer to the 'DoubleLinkedList' thats to be deleted
* 
* @note If the list pointer is 'NULL', the function does nothing.
* 
* @warning once called, all pointer referencing nodes will become invalid. 
*/
void *deleteDoubleLinkedList(DoubleLinkedList* list) {
	if (list == NULL) {
		return; // If the returned list is NULL, there is nothing to delete
	}
	
	Node* nextNode; // temporary pointer to hold the next node

	// Starting from beginning of the list
	list->current = list->head; // sets current pointer to head node.
	
	// Iterate through all nodes in list and delete all nodes until list is empty
	while (list->head->next != NULL) {
		nextNode = list->head->next;				// Store the pointer in the next node
		list->head->next = list->head->next->next;	// Update head's next node to skip the current node
		free(nextNode);								// Free the skipped node
	}
	free(list->head);	// Free the head node
	free(list);			// Free the list
}

/**
* @brief returns the data associated with current node. provided its not the tail.
* 
* @pre valid double linked list exists
* @post data of current node is returned 
* 
* @details
* Grabs the 'data' stored in the currently pointed at node.
* If its a NULL, it returns a NULL.
* 
* @param list - A pointer to the 'DoubleLinkedList' 
* 
* @return A pointer to the 'data' of the current node, or,
*		  NULL if current pointer is NULL (invalid)\
*
* @note no modification to the structure is done
*/
data* getData(DoubleLinkedList* list) {
	// is current tail?
	if (list->current != NULL) {
		return &(list->current->d); // If current node is valid, return the address of its data
	}
	else {
		return NULL; // If current pointer = NULL, return NULL
	}
}



/**
* @brief Sets the current node to the successor of current
* 
* @pre valid double linked lists exists
* @post if current node is other than tail, current node is set to successor of current node. Otherwise, list remains unchanged.
* 
* @details Moves the current pointer to the next node (thats if it exists).
* If the current node is the tail node (last node), returns an error.
* 
* @param list - A pointer to the 'DoubleLinkedList'
* 
* @return 'llError' status code:
* 
* @note no modification to the structure is done
*/
llError gotoNextNode(DoubleLinkedList* list) {
	llError result = ok; // indicates no errors

	// is successor of current a tail aka. does the next node exist?
	if (list->current->next != NULL) {
		// no -> move current to the next node
		list->current = list->current->next;
	}
	else {
		// yes -> the current node is the tail so...
		result = illegalNode; // display an illegal operation
	}
	return result;
}


/**
* @brief Sets current node to the predecessor of current
* 
* @pre valid double linked list exists
* @post if current node is other than head, current node is set to predecessor of current node. Otherwise, list remains unchanged.
* 
* @details updates the current pointer to previous node.
* That is if the current node is not the head.
* If it is, return an error.
* 
* @param list - A pointer to the 'DoubleLinkedList'
* 
* @return 'llError' status code
* 
* @note no modification to the structure is done.
*/
llError gotoPreviousNode(DoubleLinkedList* list) {
	llError result = ok; // indicates no errors

	// is the current node a head?
	if (list->current != list->head) {
		// no -> move the current node to the previous node
			list->current = list->current->prev;
	}
	else {
		// yes -> the current node is the head so...
		result = illegalNode;	// display an illegal operation
	}
	return result;
}


/**
* @brief Sets current node to head
* 
* @pre valid double linked list exists
* @post current node is set to head
* 
* @details updates the current pointer to point to the head node.
* 
* @param list - A pointer to the 'DoubleLinkedList'
* 
* @note no modification to the structure is done.
*/
void gotoHead(DoubleLinkedList* list) {
	list->current = list->head; // Set the curerent pointer to the head node
}


/**
* @brief sets the current node to tail
* 
* @pre valid double linked list exists.
* @post current node is set to tail.
* 
* @details updates the current pointer to point to last valid node before the tail. Not the tail because its often a placeholder and no further operations can be performed.
* 
* @param list - A pointer to the 'DoubleLinkedList'
* 
* @note no modifcaiton to the structure is done.
*/
void gotoTail(DoubleLinkedList* list) {
	// While loop selects the next node until the last valid node (nefore the tail) is selected.
	// If the tail was selected, nothing else could be done (no further operation could perform)
	while (list->current->next != NULL) {
		list->current = list->current->next; // Move current pointer to the next node
	}
}

/**
* @brief Creates a new node, associates newdata with it and inserts it after the current node.
* 
* @pre valid double linked lists exists and newdata is valid data
* @post if current node is not tail, new node is inserted after current node. Otherwise list remains unchanged and an error is returned.
* 
* @details Inserts a new node into the list right after the current node.
* Ensures that the new node is connected/linked with its previous and successor node.
* If the current node is NULL, returns an error.
* 
* @param d - A pointer to the 'data' 
* @param list - A pointer to the 'DoubleLinkedList'
* 
* @return 'llError' status code
* 
* @note Dynamically allocates memory for the new node.
*/
llError insertAfter(data* d, DoubleLinkedList* list) {
	llError returnvalue = ok; // indicates no errors
	Node* newnode;			  // temp pointer for new node

	//Can't insert a node after the tail or invalid current pointer.
	if (list->current == NULL) {
		returnvalue = illegalNode;
	}
	else {
		newnode = (Node*)malloc(sizeof(Node)); // allocates memory for new node

		// is allocation successful?
		if (newnode == NULL) {
			returnvalue = noMemory; // allocation failure
		}
		else {
			newnode->d = *d; // allocation successful and associate data d with new node

			// link newnode into double linked list
			// 1. set the next of newnode to current node's next
			newnode->next = list->current->next;
			// 2. Set the previous pointer of newnode to current node.
			newnode->prev = list->current;
			// 3. possible only if the next node is not the tail.
			if (list->current->next != NULL) {
				// 3. Set the previous pointer of next node to newnode.
				list->current->next->prev = newnode;
			}
			// 4. set next pointer of current node to point to the newnode
			list->current->next = newnode;
		}
	}
	return returnvalue;
}


/**
* @brief creates a new node, associates newdata with it and inserts it before the current node.
* 
* @pre valid double linked list exists and newdata is valid data.
* @post if current node is not head, new node is inserted before current node. Otherwise list remains unchanged and an error is returned
* 
* @details Inserts a new node into the list right before the current node.
* Ensures that the new node is connected/linked with its previous and successor node.
* If the current node is NULL, returns an error.
* 
* @param d - A pointer to the 'data'
* @param list - A pointer to the 'DoubleLinkedList'
* 
* @return ''llError' status code
* 
* @note Dynamically allocates memory for the new node.
*/
llError insertBefore(data* d, DoubleLinkedList* list) {
	llError returnvalue = ok; // indicates no errors
	Node* newnode;			  // temp pointer for new node

	// Can't insert a node before the head or invalid current pointer.
	if (list->current == list->head) {
		returnvalue = illegalNode;
	}
	else {
		newnode = (Node*)malloc(sizeof(Node)); // allocates memory for newnode

		// is allocation successful?
		if (newnode == NULL) {
			returnvalue = noMemory; // allocation failure
		}
		else {
			newnode->d = *d; // allocation successful and associate data d with newnode

			// link newnode into double linked list
			// 1. set the next pointer of newnode to current node
			newnode->next = list->current;
			//2. Set the previous pointer of newnode to previous node of current node
			newnode->prev = list->current->prev;
			// 3. set the next pointer of the previous node to point to the newnode
			list->current->prev->next = newnode;
			// 4. set the previous pointer of current node to point to the newnode
			list->current->prev = newnode;
		}
	}
	return returnvalue;
}

/**
* @brief Deletes the current node from list.
* 
* @pre valid double linked list exists.
* @post if current node is other than head or tail, the current node is removed from list. Otherwise, an error is returned.
* 
* @details
* Removes the node currently pointed to.
* The previous and next nodes are placed together.
* If the current node is the head or of NULL type, it does nothing and returns an error status.
* 
* @param list - A pointer to the 'DoubleLinkedList', thats where the current node is deleted from.
*
* @return 'llError' status code
* 
* @note cannot delete the head node
* 
* @warning after deleting a node, the current pointer is updated to the previous node.
*/
llError deleteCurrent(DoubleLinkedList* list) {
	llError result = ok;	// indicates no errors
	Node* todelete;			// creates a temp pointer

	if (list->current == NULL || list->current == list->head) {
		// Cannot delete current node if its NULL or the head
		result = illegalNode;
	}
	else if (list->current->next == NULL) {
		// 1. Keep the current node to be deleted.
		todelete = list->current;
		// 2. Set Successor of previous to successor of node to be deleted.
		list->current->prev->next = todelete->next;
		// 3. Set the current node to the previous node
		list->current = todelete->prev;
		// 4. Free the memory of the deleted node
		free(todelete);
	}
	else {
		// 1. Keep the current node to be deleted.
		todelete = list->current;
		// 2. Set Successor of previous to successor of node to be deleted.
		list->current->prev->next = todelete->next;
		// 3. Set Previous of next to previous of node to be deleted.
		list->current->next->prev = todelete->prev;
		// 4. Set the current node to the previous node
		list->current = todelete->prev;
		// 5. Free the memory of the deleted node
		free(todelete);
	}
	return result;
}

/**
int main() {
	DoubleLinkedList* list = createDoubleLinkedList();
	data d1 = { 1, "Sean", "Hello1" };
	data d2 ={ 2, "", "Hello2" };
	data d3 = { 3, "Sean", "Hello3" };
	data d4 = { 4, "Sean", "Hello4" };

	data* d1r = (data*)malloc(sizeof(data));
	data* d2r = (data*)malloc(sizeof(data));
	data* d3r = (data*)malloc(sizeof(data));
	data* d4r = (data*)malloc(sizeof(data));

	insertAfter(&d1, list);
	gotoNextNode(list);
	insertBefore(&d2, list);
	gotoPreviousNode(list);
	insertBefore(&d3, list);
	gotoPreviousNode(list);
	insertBefore(&d4, list);
	
	gotoHead(list);
	gotoNextNode(list);
	 d1r = getData(list);
	gotoNextNode(list);

	 d2r = getData(list);
	gotoNextNode(list);

	 d3r = getData(list);
	gotoNextNode(list);

	 d4r = getData(list);
	gotoNextNode(list);
	printf("%d\n%d\n%d\n%d\n", d1r->id, d2r->id, d3r->id, d4r->id);
	deleteDoubleLinkedList(list);
}
*/

// —————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// END OF DOUBLELINKEDLISTFUNCTIONS.C