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
        if (scanf_s("%d", &choice) != 1) {// Check if input is an integer
            /*
             * If the user enters invalid input (e.g., non-integer),
             * the program prompts the user to enter a valid number.
             * This ensures robust error handling and prevents invalid
             * values from affecting program logic.
             */
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;// Restart the loop
        }

        switch (choice) {
        case 1: { // Create Ordered Set
            int index;
            printf("Enter index (0-9) to create an Ordered Set:\n");
            if (scanf_s("%d", &index) != 1 || index < 0 || index >= MAX_SETS) {
                /*
                    * The user is asked to input a valid index between 0 and 9.
                    * If the input is invalid (non-integer or out of range),
                    * the program informs the user and skips this case.
                    */
                printf("Invalid index. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;// Exit this case and return to the menu
            }

            if (sets[index] != NULL) { /*
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
            printf("Enter index (0-9) to delete an Ordered Set:\n");
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
            int index;
            int elem = 0;
            printf("Enter index (0-9) to add elements to an Ordered Set, a negative number will stop the process.:\n");
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
            while (elem >= 0) {
                printf("Enter element to add, or a negative number to stop: ");
                if (scanf_s("%d", &elem) != 1) {
                    /*
                   * Prompt the user to enter a valid integer element.
                   * If the input is invalid (non-integer), inform the user
                   * and skip this case.
                   */
                    printf("Invalid input. Please enter an integer. If a decimal number was added, it was cut down to an integer.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                /*
                 * Attempt to add the element to the ordered set at the specified index.
                 * The `addElement` function provides feedback on whether the element
                 * was successfully added, already existed, or if there was an error.
                 */
                if (elem >= 0) {
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
                }
            }
            printToStdout(sets[index]);
            break;
        }

        case 4: { // Remove Element from Set
            int index;
            int elem = 0;
            printf("Enter index (0-9) to remove elements from an Ordered Set:\n");
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
            while (elem >= 0) {
                printf("Enter element to remove, or a negative number to stop: ");
                if (scanf_s("%d", &elem) != 1) {
                    /*
                    * Prompt the user to input a valid integer element for removal.
                    * If invalid, notify the user and skip this case.
                    */
                    printf("Invalid input. Please enter an integer.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                /*
                * Attempt to remove the specified element from the ordered set.
                * Provide feedback on whether the element was removed successfully
                * or not found in the set.
                */
                if (elem >= 0) {
                    ReturnValues result = removeElement(sets[index], elem);
                    if (result == NUMBER_REMOVED) {
                        printf("Element %d removed from the set at index %d.\n", elem, index);
                    }
                    else {
                        printf("Element %d not found in the set.\n", elem);
                    }
                }
            }
            printToStdout(sets[index]);
            break;
        }

        case 5: { // Set Intersection
            int i1, i2, i3;// Declare indices for input sets and result set
            printf("Enter two indices for Set Intersection (i1, i2):\n");
            if (scanf_s("%d %d", &i1, &i2) != 2 ||
                i1 < 0 || i1 >= MAX_SETS || i2 < 0 || i2 >= MAX_SETS) {
                /*
                    * Validate input indices for the two sets.
                    * Indices must be between 0 and MAX_SETS - 1.
                    * If invalid, clear the input buffer and inform the user.
                    */
                printf("Invalid indices. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }

            printf("Enter index to store the result (i3):\n");
            if (scanf_s("%d", &i3) != 1 || i3 < 0 || i3 >= MAX_SETS) {
                /*
                    * Validate the index for the result set.
                    * If invalid, clear the input buffer and inform the user.
                    */
                printf("Invalid index. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }/*
                     * Check if both input sets exist.
                     * If not, inform the user and exit this case.
                     */
            if (sets[i1] = NULL && sets[i2] == NULL) {

                printf("No ordered set available at index %d or index %d Intersection cannot be found.\n", i1, i2);
                break;
            }
            else if (sets[i1] == NULL) {
                printf("No set available at index %d. Intersection cannot be found\n", i1);
                break;
            }
            else if (sets[i2] == NULL) {
                printf("No set available at index %d. Intersection cannot be found\n", i2);
                break;
            }
            if (sets[i3] != NULL) {
                /*
                    * If a set already exists at the result index, delete it first
                    * to free memory and prepare for the new result.
                    */
                deleteOrderedSet(sets[i3]); // Clear the existing set
            }

            /*
             * Perform the intersection operation using `setIntersection`.
             * Store the resulting set in the specified result index.
             */
            sets[i3] = setIntersection(sets[i1], sets[i2]);
            printf("Set Intersection stored at index %d.\n", i3);
            printToStdout(sets[i3]);
            break;
        }

        case 6: { // Set Union
            int i1, i2, i3;// Declare indices for input sets and result set
            printf("Enter two indices for Set Union (i1, i2):\n");
            if (scanf_s("%d %d", &i1, &i2) != 2 ||
                i1 < 0 || i1 >= MAX_SETS || i2 < 0 || i2 >= MAX_SETS) {
                /*
                     * Validate input indices for the two sets.
                     * Indices must be between 0 and MAX_SETS - 1.
                     * If invalid, clear the input buffer and inform the user.
                     */
                printf("Invalid indices. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }

            printf("Enter index to store the result (i3):\n");
            if (scanf_s("%d", &i3) != 1 || i3 < 0 || i3 >= MAX_SETS) {
                /*
                    * Validate the index for the result set.
                    * If invalid, clear the input buffer and inform the user.
                    */
                printf("Invalid index. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }
            /*
                     * Check if both input sets exist.
                     * If not, inform the user and exit this case.
                     */
            if (sets[i1] = NULL && sets[i2] == NULL) {
                printf("No ordered set available at index %d or index %d. Union cannot be found.\n", i1, i2);
                break;
            }
            else if (sets[i1] == NULL) {
                printf("No set available at index %d. Union cannot be found\n", i1);
                break;
            }
            else if (sets[i2] == NULL) {
                printf("No set available at index %d. Union cannot be found\n", i2);
                break;

                if (sets[i3] != NULL) {
                    /*
                    * If a set already exists at the result index, delete it first
                    * to free memory and prepare for the new result.
                    */
                    deleteOrderedSet(sets[i3]); // Clear the existing set
                }
                /*
                                * Perform the union operation using `setUnion`.
                                * Store the resulting set in the specified result index.
                                */
                sets[i3] = setUnion(sets[i1], sets[i2]);
                printf("Set Union stored at index %d.\n", i3);
                printToStdout(sets[i3]);
                break;
            }

        case 7: { // Set Difference
            int i1, i2, i3;// Declare indices for input sets and result set
            printf("Enter two indices for Set Difference (i1, i2):\n");
            if (scanf_s("%d %d", &i1, &i2) != 2 ||
                i1 < 0 || i1 >= MAX_SETS || i2 < 0 || i2 >= MAX_SETS) {
                /*
                    * Validate input indices for the two sets.
                    * Indices must be between 0 and MAX_SETS - 1.
                    * If invalid, clear the input buffer and inform the user.
                    */
                printf("Invalid indices. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }

            printf("Enter index to store the result (i3):\n");
            if (scanf_s("%d", &i3) != 1 || i3 < 0 || i3 >= MAX_SETS) {
                /*
                     * Validate the index for the result set.
                     * If invalid, clear the input buffer and inform the user.
                     */
                printf("Invalid index. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }

            if (sets[i1] = NULL && sets[i2] == NULL) {/*
                     * Check if both input sets exist.
                     * If not, inform the user and exit this case.
                     */
                printf("No ordered set available at index %d or index %d Difference cannot be found.\n", i1, i2);
                break;
            }
            else if (sets[i1] == NULL) {
                printf("No set available at index %d. Difference cannot be found\n", i1);
                break;
            }
            else if (sets[i2] == NULL) {
                printf("No set available at index %d. Difference cannot be found\n", i2);
                break;
            }

            if (sets[i3] != NULL) { /*
                     * If a set already exists at the result index, delete it first
                     * to free memory and prepare for the new result.
                     */
                deleteOrderedSet(sets[i3]); // Clear the existing set
            }
            /*
                             * Perform the difference operation using `setDifference`.
                             * Store the resulting set in the specified result index.
                             */
            sets[i3] = setDifference(sets[i1], sets[i2]);
            printf("Set Difference stored at index %d.\n", i3);
            printToStdout(sets[i3]);
            break;
        }

        case 8: // Terminate program
            printf("Terminating program.\n");
            /*
                * Loop through all possible sets in the `sets` array.
                * If a set exists at an index, delete it to free memory.
                */
            for (int i = 0; i < MAX_SETS; i++) {
                if (sets[i] != NULL) {
                    deleteOrderedSet(sets[i]);
                }
            }
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            while (getchar() != '\n'); // Clear input buffer
        }
        }
        } while (choice != 8);

        return 0;
    }
    // —————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// END OF MAIN.C