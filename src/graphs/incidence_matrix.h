/**
 * Plik źródłowy zawierający implementację  klasy IncidenceMatrix
 *
 * Klasa IncidenceMatrix jest implementacją macierzy incydencji.
 * Macierz przechowuje zmienne:
 *  vertices_num_   [int]   - liczba wierzchołków
 *  edges_num_      [int]   - liczba krawędzi
 *  matrix_         [int**] - tablicę dwuwymiarową o rozmiarach v_num x e_num
 */

#ifndef INCIDENCE_MATRIX_H
#define INCIDENCE_MATRIX_H
#include "graph.h"
#include "core/others.h"
#include "structures/linked_list.h"

#include <iostream>

class IncidenceMatrix : public Graph
{
public:
    // Konstruktor klasy IncidenceMatrix
    IncidenceMatrix();
    // Destruktor klasy IncidenceMatrix
    ~IncidenceMatrix() = default;

    // Funkcja dodająca krawędź do grafu
    void add_edge(Structures::Edge edge);
    // Funkcja zwracająca tablicę wszystkich krawędzi
    Array<Structures::Edge> get_all_edges_list();
    // Funkcja zwracająca sąsiadów danego wierzchołka
    LinkedList get_adjacency(const int &vertex_id);
    // Funkcja wyświetlająca graf
    void print() const;

private:
    Array<Array<int>> matrix_;  // Tablica dwuwymiarowa o rozmiarach e_num x v_num    [Array<Array<int>>]
};

#endif