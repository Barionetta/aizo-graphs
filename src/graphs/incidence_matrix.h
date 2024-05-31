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
#include "core/others.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

struct IMEdge
{
    int source = 0;      // Numer wierzchołka startowego [int]
    int destination = 0; // Numer wierzchołka docelowego [int]
    int weight = 0;      // Waga krawędzi [int]
};

class IncidenceMatrix
{
public:
    // Konstruktor klasy IncidenceMatrix
    IncidenceMatrix();
    // Destruktor klasy IncidenceMatrix
    ~IncidenceMatrix();

    // Funkcja ustawiająca liczbę wierzchołków
    void set_vertices_num(int vertices);
    // Funkcja ustawiająca liczbę krawędzi
    void set_edges_num(int edges);
    // Funkcja zwracająca liczbę wierzchołków w grafie
    int get_vertices_num() const;
    // Funkcja zwracająca liczbę krawędzi w grafie
    int get_edges_num() const;
    // Funkcja zwracająca krawędź o zadanym numerze
    IMEdge *get_edge(int edge_num);
    // Funkcja zwracająca tablicę wszystkich krawędzi
    int **get_all_edges_list();

    // Funkcja inicjująca macierz
    void init_matrix();
    // Funkcja dodająca krawędź do grafu
    void add_edge(int edge_num, int v1, int v2, int weight);
    // Funkcja wyświetlająca graf w postaci macierzy incydencji
    void print() const;
    // Funkcja wczytująca graf z pliku tekstowego
    void read_from_file(std::string filepath);
    // Funkcja zapełniająca macierz incydencji liczbami wygenerowanymi losowo
    void generate(int vertices, int edges);

private:
    int vertices_num_; // Liczba wierzchołków                                [int]
    int edges_num_;    // Liczba krawędzi                                    [int]
    int **matrix_;     // Tablica dwuwymiarowa o rozmiarach v_num x e_num    [int**]
};

#endif