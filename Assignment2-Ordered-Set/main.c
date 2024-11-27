#include <stdio.h>
#include <stdlib.h>
#include "mainheader.h"
#define _CRT_SECURE_NO_WARNINGS
#define MAX_SETS 10 // Maximum number of ordered sets

// Placeholder functions for the actual operations (to be implemented elsewhere)
void createOrderedSet(int index);
void deleteOrderedSet(int index);
void addElementsToSet(int index);
void removeElementsFromSet(int index);
void setIntersection(int i1, int i2, int i3);
void setUnion(int i1, int i2, int i3);
void setDifference(int i1, int i2, int i3);

// Function to display the menu
void displayMenu() {
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

// Main function to handle menu and user input
int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: {
            int index;
            printf("Enter index (0-9) to create an Ordered Set: ");
            scanf_s("%d", &index);
            if (index < 0 || index >= MAX_SETS) {
                printf("Invalid index. Must be between 0 and 9.\n");
            }
            else {
                createOrderedSet(index);
            }
            break;
        }
        case 2: {
            int index;
            printf("Enter index (0-9) to delete an Ordered Set: ");
            scanf_s("%d", &index);
            if (index < 0 || index >= MAX_SETS) {
                printf("Invalid index. Must be between 0 and 9.\n");
            }
            else {
                deleteOrderedSet(index);
            }
            break;
        }
        case 3: {
            int index;
            printf("Enter index (0-9) to add elements to an Ordered Set: ");
            scanf_s("%d", &index);
            if (index < 0 || index >= MAX_SETS) {
                printf("Invalid index. Must be between 0 and 9.\n");
            }
            else {
                addElementsToSet(index);
            }
            break;
        }
        case 4: {
            int index;
            printf("Enter index (0-9) to remove elements from an Ordered Set: ");
            scanf_s("%d", &index);
            if (index < 0 || index >= MAX_SETS) {
                printf("Invalid index. Must be between 0 and 9.\n");
            }
            else {
                removeElementsFromSet(index);
            }
            break;
        }
        case 5: {
            int i1, i2, i3;
            printf("Enter three indices (i1, i2, i3) for Set Intersection: ");
            scanf_s("%d %d %d", &i1, &i2, &i3);
            if (i1 < 0 || i1 >= MAX_SETS || i2 < 0 || i2 >= MAX_SETS || i3 < 0 || i3 >= MAX_SETS) {
                printf("Invalid indices. Must be between 0 and 9.\n");
            }
            else {
                setIntersection(i1, i2, i3);
            }
            break;
        }
        case 6: {
            int i1, i2, i3;
            printf("Enter three indices (i1, i2, i3) for Set Union: ");
            scanf_s("%d %d %d", &i1, &i2, &i3);
            if (i1 < 0 || i1 >= MAX_SETS || i2 < 0 || i2 >= MAX_SETS || i3 < 0 || i3 >= MAX_SETS) {
                printf("Invalid indices. Must be between 0 and 9.\n");
            }
            else {
                setUnion(i1, i2, i3);
            }
            break;
        }
        case 7: {
            int i1, i2, i3;
            printf("Enter three indices (i1, i2, i3) for Set Difference: ");
            scanf_s("%d %d %d", &i1, &i2, &i3);
            if (i1 < 0 || i1 >= MAX_SETS || i2 < 0 || i2 >= MAX_SETS || i3 < 0 || i3 >= MAX_SETS) {
                printf("Invalid indices. Must be between 0 and 9.\n");
            }
            else {
                setDifference(i1, i2, i3);
            }
            break;
        }
        case 8:
            printf("Terminating program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}

