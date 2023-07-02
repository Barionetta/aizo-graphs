/**
 * Plik nagłówkowy pliku zawierającego implementację algorytmów
 * wyznaczających najkrótszą ścieżkę w grafie między dwoma wierzchołkami.
 */
#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H
#include "priority_queue.h"
#include "representations/adjacency_list.h"
#include "representations/incidence_matrix.h"

// Funkcja do wyświetlania najkrótszej ścieżki w grafie
void printPath(int source, int destination, int distance, int *path);

// Algorytm Dijkstry dla listy sąsiedztwa
void dijkstra_AL(AdjacencyList G, int source, int destination);
// Algorytm Dijkstry dla macierzy incydencji
void dijkstra_IM(IncidenceMatrix G, int source, int destination);

// Algorytm Bellmana-Forda dla listy sąsiedztwa
void bellman_ford_AL(AdjacencyList G, int source, int destination);
// Algorytm Bellmana-Forda dla macierzy incydencji
void bellman_ford_IM(IncidenceMatrix G, int source, int destination);

#endif