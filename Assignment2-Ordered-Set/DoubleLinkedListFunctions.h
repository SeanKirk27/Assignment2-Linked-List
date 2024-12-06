/** 
* @file DoubleLinkedListFunctions.h
* 
* @brief Header file for defining function declaration for managing a double linked list.
* 
* @details
* This header file includes function declarations only, while function definitions are implemented in 'DoubleLinkedListFunctions.c'. Used for functions like to manipulate and operate the double linked list.
* 
* @note data structures ('DoubleLinkedList', 'Node', 'data') and error codes ('llError') used by these functions are defined in 'DoubleLinkedListTypeDefs.h'
* 
* @author Sean Kirk - 23376201
* @note Coding
* @author Mihail Bizjajevs - 23364734
* @note Documentation
* @date 04/12/2024
* 
* @note Additional group members include: Ali Farah (23380098), Rory Huynh (23374624), Joseph Ennis (23360798)  
*/

#ifndef DoubleLinkedListFunctions_h
#define DoubleLinkedListFunctions_h

DoubleLinkedList* createDoubleLinkedList();
void deleteDoubleLinkedList(DoubleLinkedList* list);
data* getData(DoubleLinkedList* list);
llError gotoNextNode(DoubleLinkedList* list);
llError gotoPreviousNode(DoubleLinkedList* list);
void gotoHead(DoubleLinkedList* list);
void gotoTail(DoubleLinkedList* list);
llError insertAfter(data* d, DoubleLinkedList* list);
llError insertBefore(data* d, DoubleLinkedList* list);
llError deleteCurrent(DoubleLinkedList* list);

#endif //DoubleLinkedListFunctions_h

// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// END OF DOUBLELINKEDLISTFUNCTIONS.H