/**
 * Plik nagłówkowy pliku zawierającego implementację algorytmów
 * wyznaczających minimalne drzewo spinające grafu.
 */
#ifndef MINIMAL_SPANNING_TREE_INCLUDED
#define MINIMAL_SPANNING_TREE_INCLUDED
#include "priority_queue.h"
#include "disjoint_set.h"
#include "representations/adjacency_list.h"
#include "representations/incidence_matrix.h"

// Algorytm Prima dla listy sąsiedztwa
void prim_AL(AdjacencyList G, int root);
// Algorytm Prima dla macierzy incydencji
void prim_IM(IncidenceMatrix G, int root);

// Algorytm Kruskala dla listy sąsiedztwa
void kruskal_AL(AdjacencyList G);
// Algorytm Kruskala dla macierzy incydencji
void kruskal_IM(IncidenceMatrix G);

#endif