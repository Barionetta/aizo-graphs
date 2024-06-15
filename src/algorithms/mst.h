/**
 * Plik nagłówkowy pliku zawierającego implementację algorytmów
 * wyznaczających minimalne drzewo spinające grafu.
 */

#ifndef MST_H
#define MST_H
#include "graphs/graph.h"
#include "structures/array.h"
#include "structures/disjoint_set.h"
#include "structures/priority_queue.h"
#include "structures/structures.h"

#include <iostream>

namespace MST
{
    struct MinimalSpanningTree
    {
        Array<Structures::Edge> edges;  // Tablica krawędzi drzewa  [Array<Edge>]

        // Funkcja do wyświetlania struktury
        void print()
        {
            std::cout << "Krawędzie:\n";
            edges.print();
        }
    };
    // Algorytm Prima
    MinimalSpanningTree prim(Graph& graph);
    // Algorytm Kruskala
    MinimalSpanningTree kruskal(Graph& graph);
}

#endif