/**
 * Plik nagłówkowy pliku zawierającego implementację klasy IncidenceMatrix
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
#include "structures/array.h"

class IncidenceMatrix : public Graph
{
public:
    // Konstruktor klasy IncidenceMatrix
    IncidenceMatrix();
    // Konstruktor kopiujący klasy Array
    IncidenceMatrix(const IncidenceMatrix& matrix);
    // Konstruktor przenoszenia klasy Array
    IncidenceMatrix(IncidenceMatrix&& matrix);
    // Operator dostępu
    Array<int>& operator[] (int i);
    // Operator kopiowania
    IncidenceMatrix& operator=(const IncidenceMatrix& matrix);
    // Operator przenoszenia
    IncidenceMatrix& operator=(IncidenceMatrix&& matrix);
    // Destruktor klasy IncidenceMatrix
    ~IncidenceMatrix() = default;

    // Funkcja zwracająca długość tablicy
    int get_size() const;
    // Funkcja ustawiająca wymiary grafu
    void set_size();
    // Funkcja sprawdzająca, czy graf ma krawędź
    bool has_edge(int source, int destination);
    // Funkcja dodająca krawędź do grafu
    void add_edge(Structures::Edge edge);
    // Funkcja zwracająca tablicę wszystkich krawędzi
    Array<Structures::Edge> get_all_edges_list();
    // Funkcja zwracająca sąsiadów danego wierzchołka
    LinkedList get_adjacency(const int &vertex_id);
    // Funkcja wyświetlająca graf
    void print() const;

private:
    int size_;                              // Obecny rozmiar macierzy          [int]
    int max_size_;                          // Maksymalna pojemność macierzy    [int]
    std::unique_ptr<Array<int>[]> matrix_;    // Macierz                          [*Array<int>]
};

#endif