/**
 * Plik źródłowy zawierającegy implementację klasy AdjacencyList
 *
 * Klasa AdjacencyList jest implementacją listy sąsiedztwa.
 * Lista przechowuje zmienne:
 *  vertices_num_    [int]                  - ilość wierzchołków
 *  edges_num_       [int]                  - ilość krawędzi
 *  adjacency_list_  [Array<LinkedList>]    - listy dla każdego wierzchołka
 */

#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H
#include "graph.h"
#include "core/others.h"
#include "structures/linked_list.h"

#include <iostream>

class AdjacencyList : public Graph
{
public:
    // Konstruktor klasy AdjacencyList
    AdjacencyList();
    // Destruktor klasy AdjacencyList
    ~AdjacencyList() = default;

    // Funkcja dodająca krawędź do grafu
    void add_edge(Structures::Edge edge);
    // Funkcja zwracająca tablicę wszystkich krawędzi
    Array<Structures::Edge> get_all_edges_list();
    // Funkcja zwracająca sąsiadów danego wierzchołka
    LinkedList get_adjacency(const int &vertex_id);
    // Funkcja wyświetlająca graf
    void print() const;

private:
    Array<LinkedList> adjacency_list_; // Tablica list krawędzi dla każdego wierzchołka    [Array<LinkedList>]
};

#endif