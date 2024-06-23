/**
 * Plik nagłówkowy pliku zawierającego implementację algorytmów
 * wyznaczających najkrótsze ścieżki w grafie.
 */

#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H
#include "graphs/graph.h"
#include "structures/array.h"
#include "structures/linked_list.h"
#include "structures/priority_queue.h"
#include "structures/structures.h"

namespace ShortestPath
{
    struct Path
    {   
        Array<Structures::Vertex> vertices; // Lista wierzchołków i ich dystansów   [Array<int>]
        Array<int> predcessors;             // Lista poprzedników                   [Array<int>]

        // Funkcja do wyświetlania struktury
        void print()
        {
            std::cout << "Nr    Dystans     Poprzednik\n";
            for (int i = 0; i < vertices.get_size(); i++)
            {
                std::cout << i << "     " << vertices[i].key << "      " << predcessors[i] << "\n";
            }
        }
    };
    // Algorytm Dijkstry
    Path dijkstra(Graph& graph, int source);
    // Algorytm Bellmana - Forda
    Path bellman_ford(Graph& graph, int source);
}

#endif