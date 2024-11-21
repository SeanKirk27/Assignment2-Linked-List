#ifndef DoubleLinkedListTypeDefs_h
#define DoubleLinkedListTypeDefs_h

/**
* Defines error codes for linked list
*/
typedef enum { ok,///> No error
illegalNode, ///> Attempt to access an illegal node was made
noMemory ///>Error allocating memory
} llError;


/**
* Define structure of the data to be stored in the list
*/
typedef struct {
	int id;           ///< id number of item
	char name[50];    ///< name of item
	char description[255]; ///< description of item
} data;
/**
* Define structure of a node
*/
typedef struct n {
	data d;
	struct n* prev;
	struct n* next;
} Node;


/**
* Define structure of our Double linked list
*/
typedef struct {
	Node* head;
	Node* current;
	Node* tail;
} DoubleLinkedList;


#endif