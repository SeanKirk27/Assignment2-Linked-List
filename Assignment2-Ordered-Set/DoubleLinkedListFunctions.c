#include "DoubleLinkedListTypeDefs.h"
#include "DoubleLinkedListFunctions.h"
#include <stdlib.h>
#include <stdio.h>
/**
* Creates an empty linked list, head points to tail which is NULL.
* 
* @return: Pointer to list if successful.
*			Pointer to NULL if failed.
*/
DoubleLinkedList* createDoubleLinkedList() {
	DoubleLinkedList* list;
	list = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
	// Check for success of allocation
	if (list != NULL) {
		//Attempt to allocate memory for head
		list->head = (Node*)malloc(sizeof(Node));
		//Check if successful
		if (list->head != NULL) {
			list->head->next = list->tail;
			list->head->prev = NULL;
			list->current = list->head;
			list->tail->next = NULL;
		}
		//If it failed, deallocate the list and set it NULL
		else {
			free(list);
			list = NULL;
		}
	}
	return list;
}


/**
* Deletes the double linked list passed to it.  
*/
void *deleteDoubleLinkedList(DoubleLinkedList* list) {
	Node* nextNode;

	//Deletes all nodes until the list is empty
	//Starting from beginning of list
	list->current = list->head;
	//Iterate through all nodes in list and delete them
	while (list->head->next != NULL) {
		nextNode = list->head->next;
		list->head->next = list->head->next->next;
		free(nextNode);
	}
	free(list->head);
	free(list->current);
	free(list->tail);
	free(list);
}


/**
*deletes the current node
* 
* @return error status
*/
void deleteCurrent(DoubleLinkedList* list) {
	llError result = ok;
	Node* todelete;
		//1. Keep pointer to node to be deleted.
		todelete = list->current;
		//if The head is being deleted, make the next node the head.
		if (todelete == list->head) {
			list->head = todelete->next;
		}
		//if the tail is being deleted, make the prev node the tail
		else if (todelete == list->tail) {
			list->tail = todelete->prev;
		}
		if (todelete != list->tail) {
			//2. Set next of prev to next of node to be deleted.
			list->current->prev->next = todelete->next;
		}
		if (todelete != list->head) {
			//3. Set prev of next to prev of node to be deleted.
			list->current->next->prev = todelete->prev;
		}
		list->current = todelete->prev;
		//4. Free the memory
		free(todelete);
	}

/**
* Returns the data stored inside the current node. Provided it is not the head or tail.
*/
data* getData(DoubleLinkedList* list) {
	// is current head or tail?
	if (list->current != list->head && list->current != list->tail) {
		// no, return data
		return &(list->current->d);
	}
	else {
		// yes, return NULL
		return NULL;
	}
}



/**
* Changes to the next node in the list
*/
llError gotoNextNode(DoubleLinkedList* list) {
	llError result = ok;
	// is successor of current NULL?
	if (list->current->next != NULL) {
		// no -> move forward
		list->current = list->current->next;
	}
	else {
		// reached end of list, cannot move any further
		result = illegalNode;
	}
	return result;
}


/**
* Changes to the previous node in the list
*/
llError gotoPreviousNode(DoubleLinkedList* list) {
	llError result = ok;
	// is prev of current head?
	if (list->current->prev != list->head) {
		// no -> move backward
		list->current = list->current->prev;
	}
	else {
		// reached end of list, cannot move any further
		result = illegalNode;
	}
	return result;
}


/**
* Changes current node to the head
*/
void gotoHead(DoubleLinkedList* list) {
	list->current = list->head;
}


/**
* Changes current node to the node just before tail
*/
void gotoTail(DoubleLinkedList* list) {
	list->current = list->tail;
}

/**
* Inserts data after the current node
*/
llError insertAfter(data* d, DoubleLinkedList* list) {
	llError returnvalue = ok;
	Node* newnode;

	// create new node
	newnode = (Node*)malloc(sizeof(Node));
	// allocation successful?
	if (newnode == NULL) {
		// allocation failure
		returnvalue = noMemory;
	}
	else {
		// allocation successful
		// associate data d with newnode
		newnode->d = *d;
		// link newnode into double linked list
		// 1. set next of newnode to current nodes's next
		newnode->next = list->current->next;
		// 2. set next of current node to newnode
		list->current->next = newnode;
	}
	return returnvalue;
}


/**
* Inserts data before the current node
*/
llError insertBefore(data* d, DoubleLinkedList* list) {
	llError returnvalue = ok;
	Node* newnode;

	// create new node
	newnode = (Node*)malloc(sizeof(Node));
	// allocation successful?
	if (newnode == NULL) {
		// allocation failure
		returnvalue = noMemory;
	}
	else {
		// allocation successful
		// associate data d with newnode
		newnode->d = *d;
		// link newnode into double linked list
		// 1. set next of newnode to current node
		newnode->next = list->current;
		// 2. set prev of current node to newnode
		list->current->prev = newnode;
	}
	return returnvalue;
}