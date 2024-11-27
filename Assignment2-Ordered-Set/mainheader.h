#ifndef mainheader_h 
#define mainheader_h


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
#endif