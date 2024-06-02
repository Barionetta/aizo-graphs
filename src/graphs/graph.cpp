/**
 * Klasa bazowa reprezentacji grafu
*/

#include "graph.h"

/**
 * Konstruktor klasy Graph
*/
Graph::Graph()
    :vertices_num_(0),
     edges_num_(0)
{ std::cout << "Utworzono graf...\n";}

/**
 * Funkcja ustawiająca liczbę wierzchołków.
 * @param vertices Liczba wierzchołków grafu [int]
 */
void Graph::set_vertices_num(int vertices)
{
    vertices_num_ = vertices;
}

/**
 * Funkcja ustawiająca liczbę krawędzi.
 * @param edges Liczba krawędzi grafu [int]
 */
void Graph::set_edges_num(int edges)
{
    edges_num_ = edges;
}

/**
 * Funkcja zwracająca liczbę wierzchołków w grafie.
 * @return vertices_num_:  Liczba wierzchołków grafu [int]
 */
int Graph::get_vertices_num() const
{
    return vertices_num_;
}

/**
 * Funkcja zwracająca liczbę krawędzi w grafie.
 * @return edges_num:  Liczba krawędzi grafu [int]
 */
int Graph::get_edges_num() const
{
    return edges_num_;
}