#include <stdio.h>
#include <stdlib.h>
#include "mainheader.h"
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

 // Placeholder functions for the actual operations (to be implemented elsewhere)

 /**
  * @brief Creates an ordered set at the specified index.
  * @param index Index of the ordered set to be created.
  */
void createOrderedSet(int index);

/**
 * @brief Deletes the ordered set at the specified index.
 * @param index Index of the ordered set to be deleted.
 */
void deleteOrderedSet(int index);

/**
 * @brief Adds elements to the ordered set at the specified index.
 * @param index Index of the ordered set to add elements to.
 */
void addElementsToSet(int index);

/**
 * @brief Removes elements from the ordered set at the specified index.
 * @param index Index of the ordered set to remove elements from.
 */
void removeElementsFromSet(int index);

/**
 * @brief Computes the intersection of two sets and stores the result in a third set.
 * @param i1 Index of the first input set.
 * @param i2 Index of the second input set.
 * @param i3 Index of the set to store the intersection result.
 */
void setIntersection(int i1, int i2, int i3);

/**
 * @brief Computes the union of two sets and stores the result in a third set.
 * @param i1 Index of the first input set.
 * @param i2 Index of the second input set.
 * @param i3 Index of the set to store the union result.
 */
void setUnion(int i1, int i2, int i3);

/**
 * @brief Computes the difference of two sets and stores the result in a third set.
 * @param i1 Index of the first input set.
 * @param i2 Index of the second input set.
 * @param i3 Index of the set to store the difference result.
 */
void setDifference(int i1, int i2, int i3);

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
    int choice; // Variable to store user choice

    do {
        displayMenu(); // Display menu options
        printf("Enter your choice: ");
        scanf_s("%d", &choice); // Get user choice

        switch (choice) {
        case 1: { // Case for creating an ordered set
            int index;
            printf("Enter index (0-9) to create an Ordered Set: ");
            scanf_s("%d", &index); // Get the index from user
            if (index < 0 || index >= MAX_SETS) { // Validate index
                printf("Invalid index. Must be between 0 and 9.\n");
            }
            else {
                createOrderedSet(index); // Call function to create set
            }
            break;
        }
        case 2: { // Case for deleting an ordered set
            int index;
            printf("Enter index (0-9) to delete an Ordered Set: ");
            scanf_s("%d", &index); // Get the index from user
            if (index < 0 || index >= MAX_SETS) { // Validate index
                printf("Invalid index. Must be between 0 and 9.\n");
            }
            else {
                deleteOrderedSet(index); // Call function to delete set
            }
            break;
        }
        case 3: { // Case for adding elements to a set
            int index;
            printf("Enter index (0-9) to add elements to an Ordered Set: ");
            scanf_s("%d", &index); // Get the index from user
            if (index < 0 || index >= MAX_SETS) { // Validate index
                printf("Invalid index. Must be between 0 and 9.\n");
            }
            else {
                addElementsToSet(index); // Call function to add elements
            }
            break;
        }
        case 4: { // Case for removing elements from a set
            int index;
            printf("Enter index (0-9) to remove elements from an Ordered Set: ");
            scanf_s("%d", &index); // Get the index from user
            if (index < 0 || index >= MAX_SETS) { // Validate index
                printf("Invalid index. Must be between 0 and 9.\n");
            }
            else {
                removeElementsFromSet(index); // Call function to remove elements
            }
            break;
        }
        case 5: { // Case for set intersection
            int i1, i2, i3;
            printf("Enter three indices (i1, i2, i3) for Set Intersection: ");
            scanf_s("%d %d %d", &i1, &i2, &i3); // Get indices from user
            if (i1 < 0 || i1 >= MAX_SETS || i2 < 0 || i2 >= MAX_SETS || i3 < 0 || i3 >= MAX_SETS) {
                printf("Invalid indices. Must be between 0 and 9.\n");
            }
            else {
                setIntersection(i1, i2, i3); // Call function for intersection
            }
            break;
        }
        case 6: { // Case for set union
            int i1, i2, i3;
            printf("Enter three indices (i1, i2, i3) for Set Union: ");
            scanf_s("%d %d %d", &i1, &i2, &i3); // Get indices from user
            if (i1 < 0 || i1 >= MAX_SETS || i2 < 0 || i2 >= MAX_SETS || i3 < 0 || i3 >= MAX_SETS) {
                printf("Invalid indices. Must be between 0 and 9.\n");
            }
            else {
                setUnion(i1, i2, i3); // Call function for union
            }
            break;
        }
        case 7: { // Case for set difference
            int i1, i2, i3;
            printf("Enter three indices (i1, i2, i3) for Set Difference: ");
            scanf_s("%d %d %d", &i1, &i2, &i3); // Get indices from user
            if (i1 < 0 || i1 >= MAX_SETS || i2 < 0 || i2 >= MAX_SETS || i3 < 0 || i3 >= MAX_SETS) {
                printf("Invalid indices. Must be between 0 and 9.\n");
            }
            else {
                setDifference(i1, i2, i3); // Call function for difference
            }
            break;
        }
        case 8: // Case to terminate the program
            printf("Terminating program.\n");
            break;
        default: // Default case for invalid input
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8); // Repeat until user chooses to terminate

    return 0;
}
