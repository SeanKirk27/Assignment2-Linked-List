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
			list->head->next = NULL;
			list->head->prev = NULL;
			list->current = list->head;
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
	free(list);
}


/**
*deletes the current node
* 
* @return error status
*/
llError deleteCurrent(DoubleLinkedList* list) {
	llError result = ok;
	Node* todelete;
	if (list->current == NULL || list->current == list->head) {
		// Current node is tail or head => Cannot remove node
		result = illegalNode;	
	}
	else {
		//1. Keep pointer to node to be deleted.
		todelete = list->current;
		//2. Set Successor of prev to successor of node to be deleted.
		list->current->prev->next = todelete->next;
		//3. Set Prev of next to prev of node to be deleted.
		list->current->next->prev = todelete->prev;
		//4. Set the current node to the previous node
		list->current = todelete->prev;
		//5. Free the memory
		free(todelete);
	}
	return result;
}

/**
* Returns the data stored inside the current node. Provided it is not the tail.
*/
data* getData(DoubleLinkedList* list) {
	// is current tail?
	if (list->current != NULL) {
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
	// is successor of current tail?
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
	// is current head?
	if (list->current != list->head) {
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
	//While loop selects the next node until the last node is selected, which is not the tail, but the node just before it.
	//If I were to select the tail itself, nothing else could be done, so we'll go with this.
	while (list->current->next != NULL) {
		list->current = list->current->next;
	}
}

/**
* Inserts a new node, with data d, after the current node
*/
llError insertAfter(data* d, DoubleLinkedList* list) {
	llError returnvalue = ok;
	Node* newnode;
	//Can't insert a node after the tail.
	if (list->current == NULL) {
		returnvalue = illegalNode;
	}
	else {
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
			//2. Set prev of newnode to current node.
			newnode->prev = list->current;
			//Step 3 possible only if the next node is not the tail.
			if (list->current->next != NULL) {
				//3. Set prev of next node to newnode.
				list->current->next->prev = newnode;
			}
			// 4. set next of current node to newnode
			list->current->next = newnode;
		}
	}
	return returnvalue;
}


/**
* Inserts data before the current node
*/
llError insertBefore(data* d, DoubleLinkedList* list) {
	llError returnvalue = ok;
	Node* newnode;
	//Can't insert a node before the head
	if (list->current == list->head) {
		returnvalue = illegalNode;
	}
	else {
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
			//2. Set prev of newnode to prev of current node
			newnode->prev = list->current->prev;
			// 3. set next of prev of current node to newnode
			list->current->prev->next = newnode;
			// 4. set prev of current node to newnode
			list->current->prev = newnode;
		}
	}
	return returnvalue;
}

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