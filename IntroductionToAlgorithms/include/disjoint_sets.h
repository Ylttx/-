#ifndef DISJOINT_SETS_H
#define DISJOINT_SETS_H

/**
 * 21.2 Linked-list representation of disjoint sets
 *      and with weighted-union heuristic.
 */

#define T ListSet
typedef struct T* T;

extern void makeset(T set, int x);

extern int find(T set, int x);

extern void unionset(T set, int x, int y);

#endif
