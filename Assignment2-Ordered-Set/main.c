/**
* @file main.c
* 
* @brief A menu-driven program for managing ordered sets.
* 
* @details
* - This program provides operations to create, delete, add, and remove elements from ordered sets. Additionally, it includes set operations such as intersection,union, and difference.
* 
* @note
* This project work load was split as follows:
* - Sean Kirk (23376201) - Coded the data Structure - Double Linked List section and their header files.
* - Mihail Bizjajevs (23364734) - Documented (doxygen, comments, etc.) Sean Kirk's files.
* - Rory Huynh (23374624) - Coded the Data Type Ordered Set section and their header files.
* - Joseph Ennis (23360798) - Documented (doxygen, comments, etc.) Rory Huynh's files.
* - Ali Farah (23380098) - Coded and Documented the Test Program main file.
* 
* @author Ali Farah - 23380098
* @date 05/12/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include "OrderedList.h"
#define _CRT_SECURE_NO_WARNINGS
#define MAX_SETS 10 // Maximum number of ordered sets.


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

///> Placeholder functions for the actual operations (to be implemented elsewhere) -- ********Commented out******** ******Move the relevant documentation to OrderedListFunction.c********
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
        if (scanf_s("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
        case 1: { // Create Ordered Set
            int index;
            printf("Enter index (0-9) to create an Ordered Set:\n");
            if (scanf_s("%d", &index) != 1 || index < 0 || index >= MAX_SETS) {
                printf("Invalid index. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }

            if (sets[index] != NULL) {
                printf("Set already exists at index %d. Delete it first.\n", index);
            }
            else {
                sets[index] = createOrderedSet();
                printf("Created ordered set at index %d.\n", index);
            }
            break;
        }

        case 2: { // Delete Ordered Set
            int index;
            printf("Enter index (0-9) to delete an Ordered Set:\n");
            if (scanf_s("%d", &index) != 1 || index < 0 || index >= MAX_SETS) {
                printf("Invalid index. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }

            if (sets[index] == NULL) {
                printf("No set exists at index %d.\n", index);
            }
            else {
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
                printf("Invalid index. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }

            if (sets[index] == NULL) {
                printf("No set exists at index %d.\n", index);
                break;
            }
            while (elem >= 0) {
                printf("Enter element to add, or a negative number to stop: ");
                if (scanf_s("%d", &elem) != 1) {
                    printf("Invalid input. Please enter an integer. If a decimal number was added, it was cut down to an integer.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
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
            int elem =0;
            printf("Enter index (0-9) to remove elements from an Ordered Set:\n");
            if (scanf_s("%d", &index) != 1 || index < 0 || index >= MAX_SETS) {
                printf("Invalid index. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }

            if (sets[index] == NULL) {
                printf("No set exists at index %d.\n", index);
                break;
            }
            while (elem >= 0) {
                printf("Enter element to remove, or a negative number to stop: ");
                if (scanf_s("%d", &elem) != 1) {
                    printf("Invalid input. Please enter an integer.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
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
            int i1, i2, i3;
            printf("Enter two indices for Set Intersection (i1, i2):\n");
            if (scanf_s("%d %d", &i1, &i2) != 2 ||
                i1 < 0 || i1 >= MAX_SETS || i2 < 0 || i2 >= MAX_SETS) {
                printf("Invalid indices. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }

            printf("Enter index to store the result (i3):\n");
            if (scanf_s("%d", &i3) != 1 || i3 < 0 || i3 >= MAX_SETS) {
                printf("Invalid index. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }

            if (sets[i1] == NULL || sets[i2] == NULL) {
                printf("One or both sets do not exist.\n");
                break;
            }

            if (sets[i3] != NULL) {
                deleteOrderedSet(sets[i3]); // Clear the existing set
            }

            sets[i3] = setIntersection(sets[i1], sets[i2]);
            printf("Set Intersection stored at index %d.\n", i3);
            printToStdout(sets[i3]);
            break;
        }

        case 6: { // Set Union
            int i1, i2, i3;
            printf("Enter two indices for Set Union (i1, i2):\n");
            if (scanf_s("%d %d", &i1, &i2) != 2 ||
                i1 < 0 || i1 >= MAX_SETS || i2 < 0 || i2 >= MAX_SETS) {
                printf("Invalid indices. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }

            printf("Enter index to store the result (i3):\n");
            if (scanf_s("%d", &i3) != 1 || i3 < 0 || i3 >= MAX_SETS) {
                printf("Invalid index. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }

            if (sets[i1] == NULL || sets[i2] == NULL) {
                printf("One or both sets do not exist.\n");
                break;
            }

            if (sets[i3] != NULL) {
                deleteOrderedSet(sets[i3]); // Clear the existing set
            }

            sets[i3] = setUnion(sets[i1], sets[i2]);
            printf("Set Union stored at index %d.\n", i3);
            printToStdout(sets[i3]);
            break;
        }

        case 7: { // Set Difference
            int i1, i2, i3;
            printf("Enter two indices for Set Difference (i1, i2):\n");
            if (scanf_s("%d %d", &i1, &i2) != 2 ||
                i1 < 0 || i1 >= MAX_SETS || i2 < 0 || i2 >= MAX_SETS) {
                printf("Invalid indices. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }

            printf("Enter index to store the result (i3):\n");
            if (scanf_s("%d", &i3) != 1 || i3 < 0 || i3 >= MAX_SETS) {
                printf("Invalid index. Must be between 0 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
                break;
            }

            if (sets[i1] == NULL || sets[i2] == NULL) {
                printf("One or both sets do not exist.\n");
                break;
            }

            if (sets[i3] != NULL) {
                deleteOrderedSet(sets[i3]); // Clear the existing set
            }

            sets[i3] = setDifference(sets[i1], sets[i2]);
            printf("Set Difference stored at index %d.\n", i3);
            printToStdout(sets[i3]);
            break;
        }

        case 8: // Exit
            printf("Terminating program.\n");
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
    } while (choice != 8);

    return 0;
}
// —————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// END OF MAIN.C