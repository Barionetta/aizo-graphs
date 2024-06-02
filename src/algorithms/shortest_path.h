/**
 * Plik nagłówkowy pliku zawierającego implementację algorytmów
 * wyznaczających najkrótszą ścieżkę w grafie między dwoma wierzchołkami.
 */

#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include <iostream>

namespace ShortestPath
{
    struct Path
    {
        int cost;           // Koszt ścieżki                    [int]
        int vertices_num;   // Liczba wierzchołków w ścieżce    [int]   
        int vertices[];     // Tablica wierzchołków             [int*]

        // Funkcja do wyświetlania struktury
        void print()
        {
            std::cout << "Koszt ścieżki: " << cost << "Ścieżka: ";
            for (int v = vertices_num - 1; v > 0; v--)
            {
                std::cout << vertices[v] << " -> ";
            }
            std::cout << vertices[0] << "\n";
        }
    };

    Path dijikstra();

    Path bellman_ford();
}

#endif