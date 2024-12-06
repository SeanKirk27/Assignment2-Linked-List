/**
* @file main.c
* 
* @brief ...
* 
* @details
* 
* @notes
* This project work load was split as follows:
* Sean Kirk (23376201) - Coded the data Structure - Double Linked List section and their header files.
* Mihail Bizjajevs (23364734) - Documented (doxygen, comments, etc.) Sean Kirk's files.
* Rory Huynh (23374624) - Coded the Data Type Ordered Set section and their header files.
* Joseph Ennis (23360798) - Documented (doxygen, comments, etc.) Rory Huynh's fies.
* Ali Farah (23380098) - Coded and Documented the Test Program main file
* 
* @author Ali Farah - 23380098
* @date 30/11/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include "OrderedList.h"
#define _CRT_SECURE_NO_WARNINGS
#define MAX_SETS 10 // Maximum number of ordered sets.


/**
 * @file main.c
 * @brief A menu-driven program for managing ordered sets.
 *
 * This program provides operations to create, delete, add, and remove elements
 * from ordered sets. Additionally, it includes set operations such as intersection,
 * union, and difference.
 */

 // Placeholder functions for the actual operations (to be implemented elsewhere) -- ********Commented out******** ******Move the relevant documentation to rory(orderedlist).c********

 /**
  * @brief Creates an ordered set at the specified index.
  * @param index Index of the ordered set to be created.
  */
// createOrderedSet(int index);

/**
 * @brief Deletes the ordered set at the specified index.
 * @param index Index of the ordered set to be deleted.
 */
//void deleteOrderedSet(int index);

/**
 * @brief Adds elements to the ordered set at the specified index.
 * @param index Index of the ordered set to add elements to.
 */
//void addElementsToSet(int index);

/**
 * @brief Removes elements from the ordered set at the specified index.
 * @param index Index of the ordered set to remove elements from.
 */
//void removeElementsFromSet(int index);

/**
 * @brief Computes the intersection of two sets and stores the result in a third set.
 * @param i1 Index of the first input set.
 * @param i2 Index of the second input set.
 * @param i3 Index of the set to store the intersection result.
 */
//void setIntersection(int i1, int i2, int i3);

/**
 * @brief Computes the union of two sets and stores the result in a third set.
 * @param i1 Index of the first input set.
 * @param i2 Index of the second input set.
 * @param i3 Index of the set to store the union result.
 */
//void setUnion(int i1, int i2, int i3);

/**
 * @brief Computes the difference of two sets and stores the result in a third set.
 * @param i1 Index of the first input set.
 * @param i2 Index of the second input set.
 * @param i3 Index of the set to store the difference result.
 */
//void setDifference(int i1, int i2, int i3);



/**
 * @brief Displays the menu options for the user.
 *
 * This function prints a list of available operations for managing ordered sets.
 */
void displayMenu() {
    // Print the menu options
    printf("\nMenu Options:\n");
    printf("1. Create an Ordered Set\n");
    printf("2. Delete an Ordered Set\n");
    printf("3. Add Elements to an Ordered Set\n");
    printf("4. Remove Elements from an Ordered Set\n");
    printf("5. Set Intersection\n");
    printf("6. Set Union\n");
    printf("7. Set Difference\n");
    printf("8. Terminate Program\n");
}

/**
 * @brief Main function to handle user input and menu operations.
 *
 * This function provides a loop to handle user input, validate indices,
 * and invoke the appropriate functions for managing ordered sets and
 * performing set operations.
 *
 * @return Returns 0 on successful program termination.
 */
int main() {
    orderedIntSet* sets[MAX_SETS] = { NULL }; // Array to hold up to 10 ordered sets
    int choice;

    // Display the menu once
    displayMenu();

    do {
        printf("\nEnter your choice: ");
        if (scanf_s("%d", &choice) != 1) { // Check if input is an integer
            /*
             * If the user enters invalid input (e.g., non-integer),
             * the program prompts the user to enter a valid number.
             * This ensures robust error handling and prevents invalid
             * values from affecting program logic.
             */
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue; // Restart the loop
        }

        switch (choice) {
        case 1: { // Create Ordered Set
            int index;
            printf("Enter index (0-9) to create an Ordered Set: ");
            if (scanf_s("%d", &index) != 1 || index < 0 || index >= MAX_SETS) {
                /*
                 * The user is asked to input a valid index between 0 and 9.
                 * If the input is invalid (non-integer or out of range),
                 * the program informs the user and skips this case.
                 */
                printf("Invalid index. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break; // Exit this case and return to the menu
            }

            if (sets[index] != NULL) {
                /*
                 * Check if an ordered set already exists at the specified index.
                 * If so, the user is notified that they must delete the set
                 * before creating a new one at the same index.
                 */
                printf("Set already exists at index %d. Delete it first.\n", index);
            }
            else {
                /*
                 * If the index is valid and no set exists at that index,
                 * create a new ordered set and store it at the specified index.
                 */
                sets[index] = createOrderedSet();
                printf("Created ordered set at index %d.\n", index);
            }
            break;
        }

        case 2: { // Delete Ordered Set
            int index;
            printf("Enter index (0-9) to delete an Ordered Set: ");
            if (scanf_s("%d", &index) != 1 || index < 0 || index >= MAX_SETS) {
                /*
                 * The user is asked to input a valid index for deletion.
                 * If the input is invalid (non-integer or out of range),
                 * the program informs the user and skips this case.
                 */
                printf("Invalid index. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }

            if (sets[index] == NULL) {
                /*
                 * Check if an ordered set exists at the specified index.
                 * If no set exists, notify the user and do nothing.
                 */
                printf("No set exists at index %d.\n", index);
            }
            else {
                /*
                 * If a set exists at the specified index, delete it using
                 * the `deleteOrderedSet` function and set the pointer to NULL.
                 */
                deleteOrderedSet(sets[index]);
                sets[index] = NULL;
                printf("Deleted ordered set at index %d.\n", index);
            }
            break;
        }

        case 3: { // Add Element to Set
            int index, elem;
            printf("Enter index (0-9) to add elements to an Ordered Set: ");
            if (scanf_s("%d", &index) != 1 || index < 0 || index >= MAX_SETS) {
                /*
                 * The user is asked to input a valid index for adding an element.
                 * If the input is invalid (non-integer or out of range),
                 * the program informs the user and skips this case.
                 */
                printf("Invalid index. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }

            if (sets[index] == NULL) {
                /*
                 * Check if an ordered set exists at the specified index.
                 * If no set exists, notify the user and do nothing.
                 */
                printf("No set exists at index %d.\n", index);
                break;
            }

            printf("Enter element to add: ");
            if (scanf_s("%d", &elem) != 1) {
                /*
                 * Prompt the user to enter a valid integer element.
                 * If the input is invalid (non-integer), inform the user
                 * and skip this case.
                 */
                printf("Invalid input. Please enter an integer.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }

            /*
             * Attempt to add the element to the ordered set at the specified index.
             * The `addElement` function provides feedback on whether the element
             * was successfully added, already existed, or if there was an error.
             */
            ReturnValues result = addElement(sets[index], elem);
            if (result == NUMBER_ADDED) {
                printf("Element %d added to the set at index %d.\n", elem, index);
            }
            else if (result == NUMBER_ALREADY_IN_SET) {
                printf("Element %d is already in the set.\n", elem);
            }
            else {
                printf("Error adding element to the set.\n");
            }
            break;
        }

        case 4: { // Remove Element from Set
            int index, elem;
            printf("Enter index (0-9) to remove elements from an Ordered Set: ");
            if (scanf_s("%d", &index) != 1 || index < 0 || index >= MAX_SETS) {
                /*
                 * Validate the index for removing an element.
                 * If invalid, notify the user and skip the case.
                 */
                printf("Invalid index. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }

            if (sets[index] == NULL) {
                /*
                 * Check if an ordered set exists at the specified index.
                 * If no set exists, notify the user and skip this case.
                 */
                printf("No set exists at index %d.\n", index);
                break;
            }

            printf("Enter element to remove: ");
            if (scanf_s("%d", &elem) != 1) {
                /*
                 * Prompt the user to input a valid integer element for removal.
                 * If invalid, notify the user and skip this case.
                 */
                printf("Invalid input. Please enter an integer.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }

            /*
             * Attempt to remove the specified element from the ordered set.
             * Provide feedback on whether the element was removed successfully
             * or doesnt if not found in the set.
             */
            ReturnValues result = removeElement(sets[index], elem);
            if (result == NUMBER_REMOVED) {
                printf("Element %d removed from the set at index %d.\n", elem, index);
            }
            else {
                printf("Element %d not found in the set.\n", elem);
            }
            break;
        }

              // Cases 5, 6, and 7: Operations (Intersection, Union, Difference)
              // Cases include detailed prompts for indices and checks for valid sets.
              // Results are stored in a designated index.

              // Additional cases documented similarly
        }
    } while (choice != 9); // Continue until the user selects the exit option

    return 0;
}
