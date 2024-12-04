#ifndef MENU_H
#define MENU_H

#define _CRT_SECURE_NO_WARNINGS
#define MAX_SETS 10 // Maximum number of ordered sets

// Placeholder functions for the actual operations (to be implemented elsewhere)
/**
 * @brief Displays the menu options to the user.
 */
void displayMenu();

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
void addElement(int index);

/**
 * @brief Removes elements from the ordered set at the specified index.
 * @param index Index of the ordered set to remove elements from.
 */
void removeElement(int index);

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
#endif