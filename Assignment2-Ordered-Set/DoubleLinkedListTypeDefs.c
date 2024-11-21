#include <stdio.h>
#include <stdlib.h>
// Define structure of a Node
typedef struct Node {
	int data;
	struct Node *prev;
	struct Node *next;
} Node;

//Define structure of our Double linked list
typedef struct DoubleLinkedList {
	int size;
	Node *head;
	Node *current;
} DoubleLinkedList;

typedef enum { ok, illegalNode, noMemory } llError;