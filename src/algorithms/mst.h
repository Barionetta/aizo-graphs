/**
 * Plik nagłówkowy pliku zawierającego implementację algorytmów
 * wyznaczających minimalne drzewo spinające grafu.
 */

#ifndef MST_H
#define MST_H
#include "structures/array.h"
#include "structures/structures.h"

#include <iostream>

namespace MST
{
    struct MinimalSpanningTree
    {
        int cost;                       // Koszt ścieżki            [int] 
        Array<Structures::Edge> edges;  // Tablica krawędzi drzewa  [Array<Edge>]

        // Funkcja do wyświetlania struktury
        void print()
        {
            std::cout << "Koszt drzewa: " << cost << "\nKrawędzie:\n";
            edges.print();
        }
    };

    MinimalSpanningTree prim();

    MinimalSpanningTree kruskal();
}

#endif