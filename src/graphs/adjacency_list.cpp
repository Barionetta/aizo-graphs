/**
 * Plik źródłowy zawierającegy implementację struktury Edge,
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
 *  vertices_num_    [int]       - ilość wierzchołków
 *  edges_num_       [int]       - ilość krawędzi
 *  vertices        [EdgeList*] - listy dla każdego wierzchołka
 */

#include "adjacency_list.h"

using namespace std;

/**
 * Konstruktor klasy AdjacencyList
*/
AdjacencyList::AdjacencyList()
{
    std::cout << "Poprawnie zainicjalizowano listę sąsiedztwa.\n";
}

/**
 * Funkcja zwracająca tablicę wszystkich krawędzi.
 * @return edge_list: Lista wszystkich krawędzi w grafie [Array<Structures::Edge>]
 */
Array<Structures::Edge> AdjacencyList::get_all_edges_list()
{
    Array<Structures::Edge> edge_list;
    return edge_list;
}

/**
 * Funkcja dodająca krawędź do grafu
 * @param edge  Krawędź                  [Structures::Edge]
 */
void AdjacencyList::add_edge(Structures::Edge edge)
{

}

/**
 *  Funkcja wyświetlająca graf w postaci macierzy incydencji.
 */
void AdjacencyList::print() const
{

}