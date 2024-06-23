/**
 * Klasa bazowa reprezentacji grafu
*/

#ifndef GRAPH_H
#define GRAPH_H
#include "structures/array.h"
#include "structures/structures.h"
#include "structures/linked_list.h"

class Graph
{
public:
    // Konstruktor klasy Graph
    Graph();
    // Destruktor klasy Graph
    virtual ~Graph() {};

    // Funkcja ustawiająca liczbę wierzchołków
    void set_vertices_num(int vertices);
    // Funkcja ustawiająca liczbę krawędzi
    void set_edges_num(int edges);
    // Funkcja zwracająca liczbę wierzchołków w grafie
    int get_vertices_num() const;
    // Funkcja zwracająca liczbę krawędzi w grafie
    int get_edges_num() const;

    // Funkcja ustawiająca wymiary grafu
    virtual void set_size() = 0;
    // Funkcja sprawdzająca, czy graf ma krawędź
    virtual bool has_edge(int source, int destination) = 0;
    // Funkcja dodająca krawędź do grafu
    virtual void add_edge(Structures::Edge edge) = 0;
    // Funkcja zwracająca tablicę wszystkich krawędzi
    virtual Array<Structures::Edge> get_all_edges_list() = 0;
    // Funkcja zwracająca sąsiadów danego wierzchołka
    virtual LinkedList get_adjacency(const int &vertex_id) = 0;
    // Funkcja wyświetlająca graf
    virtual void print() const {};

protected:
    int vertices_num_;          // Liczba wierzchołków                                [int]
    int edges_num_;             // Liczba krawędzi                                    [int]
};

#endif