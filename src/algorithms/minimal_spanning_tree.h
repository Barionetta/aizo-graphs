/**
 * Plik nagłówkowy pliku zawierającego implementację algorytmów
 * wyznaczających minimalne drzewo spinające grafu.
 */

#ifndef MINIMAL_SPANNING_TREE_H
#define MINIMAL_SPANNING_TREE_H
#include "priority_queue.h"
#include "disjoint_set.h"
#include "graphs/adjacency_list.h"
#include "graphs/incidence_matrix.h"

#include <iostream>

using std::cout;

// Algorytm Prima dla listy sąsiedztwa
void prim_AL(AdjacencyList *G, int root);
// Algorytm Prima dla macierzy incydencji
void prim_IM(IncidenceMatrix *G, int root);

// Algorytm Kruskala dla listy sąsiedztwa
void kruskal_AL(AdjacencyList *G);
// Algorytm Kruskala dla macierzy incydencji
void kruskal_IM(IncidenceMatrix *G);

#endif