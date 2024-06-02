/**
 * Plik nagłówkowy pliku zawierającego implementację struktury Edge,
 * struktury EdgeList oraz klasy AdjacencyList
 *
 * Struktura Egde jest pojedynczą krawędzią należącą do EgdeList,
 * czyli komórki listy sąsiedztwa przechowującą listę krawędzi
 * powiązanych z danym wierzchołkiem. Egde przechowuje
 * zmienną destination [int], czyli numer wierzchołka docelowego,
 * zmienną weight [int], czyli wagę wierzchołka, oraz
 * wskaźnik na następną krawędź next [Edge*].
 *
 * Struktura EgdeList jest listą krawędzi, z którą dany
 * wierzchołek jest połączony. Przechowuje ona
 * zmienną v_num [int], czyli numer wierzchołka startowego,
 * oraz wskaźnik na początek (głowę) listy head [Edge*]
 *
 * Klasa AdjacencyList jest implementacją listy sąsiedztwa.
 * Lista przechowuje zmienne:
 *  vertices_num    [int]       - ilość wierzchołków
 *  edges_num       [int]       - ilość krawędzi
 *  vertices        [EdgeList*] - listy dla każdego wierzchołka
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
    // Funkcja wyświetlająca graf
    void print() const;

private:
    Array<LinkedList> adjacency_list; // Tablica list krawędzi dla każdego wierzchołka    [Array<LinkedList>]
};

#endif