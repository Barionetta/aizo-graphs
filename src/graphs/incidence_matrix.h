/**
 * Plik nagłówkowy pliku zawierającego implementację struktury IMEdge,
 * oraz klasy IncidenceMatrix
 *
 * Struktura IMEdge jest strukturą zawierającą informację
 * o krawędzi. Przechowuje zmienną source [int], czyli numer
 * wierzchołka startowego, zmienną destination [int], czyli
 * numer wierzchołka końcowego, oraz zmienną weight [int],
 * czyli wagę krawędzi.
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
    // Funkcja wyświetlająca graf
    void print() const;

private:
    Array<Array<int>> matrix_;  // Tablica dwuwymiarowa o rozmiarach e_num x v_num    [Array<Array<int>>]
};

#endif