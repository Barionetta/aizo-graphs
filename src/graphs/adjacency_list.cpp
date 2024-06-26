/**
 * Plik źródłowy zawierającegy implementację klasy AdjacencyList
 *
 * Klasa AdjacencyList jest implementacją listy sąsiedztwa.
 * Lista przechowuje zmienne:
 *  vertices_num_    [int]                  - ilość wierzchołków
 *  edges_num_       [int]                  - ilość krawędzi
 *  adjacency_list_  [Array<LinkedList>]    - listy dla każdego wierzchołka
 */

#include "adjacency_list.h"

/**
 * Konstruktor klasy AdjacencyList
*/
AdjacencyList::AdjacencyList()
{
    std::cout << "Poprawnie zainicjalizowano listę sąsiedztwa.\n";
}

/**
 * Funkcja ustawiająca wymiary grafu
*/
void AdjacencyList::set_size()
{
    adjacency_list_.set_size(vertices_num_);
}

/**
 * Funkcja sprawdzająca, czy graf ma krawędź
 * 
 * @param source Źródło sprawdzanej krawędzi    [int]
 * @param destination Cel sprawdzanej krawędzi  [int]
 * @return Czy ma krawędź?                      [bool]
*/
bool AdjacencyList::has_edge(int source, int destination)
{
    for (const auto &item : adjacency_list_[source])
    {
        if (item.vertex_id == destination) { return true;}
    }
    return false;
}

/**
 * Funkcja dodająca krawędź do grafu
 * @param edge  Krawędź                  [Structures::Edge]
 */
void AdjacencyList::add_edge(Structures::Edge edge)
{
    adjacency_list_[edge.source_id].push_front(edge.destination_id, edge.weight);
    std::cout << "Poprawnie dodano krawędź ";
    edge.print();
}

/**
 * Funkcja zwracająca tablicę wszystkich krawędzi.
 * @return edge_list: Lista wszystkich krawędzi w grafie [Array<Structures::Edge>]
 */
Array<Structures::Edge> AdjacencyList::get_all_edges_list()
{
    Array<Structures::Edge> edge_list;
    for (int i = 0; i < vertices_num_; i++)
    {
        for (const auto &item : adjacency_list_[i])
        {
            Structures::Edge edge(i, item.vertex_id, item.key);
            edge_list.push_back(edge);
        }
    }
    return edge_list;
}

/**
 * Funkcja zwracająca sąsiadów danego wierzchołka
 * 
 * @param verted_id ID wierzchołka,którego szukane jest sąsiedztwo [int]
 * @return adjacency - lista sąsiadów [LinkedList]
*/
LinkedList AdjacencyList::get_adjacency(const int &vertex_id)
{
    return adjacency_list_[vertex_id];
}

/**
 *  Funkcja wyświetlająca graf w postaci macierzy incydencji.
 */
void AdjacencyList::print() const
{
    std::cout << "Graf w postaci listowej: \n";
    adjacency_list_.print();
}