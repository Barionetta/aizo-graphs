/**
 * Plik źródłowy zawierający implementację struktury IMEdge,
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

#include "incidence_matrix.h"

/**
 * Konstruktor klasy IncidenceMatrix
*/
IncidenceMatrix::IncidenceMatrix()
{
    std::cout << "Poprawnie zainicjalizowano macierz incydencji.\n";
}

/**
 * Funkcja zwracająca tablicę wszystkich krawędzi.
 * @return edge_list: Lista wszystkich krawędzi w grafie [Array<Structures::Edge>]
 */
Array<Structures::Edge> IncidenceMatrix::get_all_edges_list()
{
    Array<Structures::Edge> edge_list;
    return edge_list;
}

/**
 * Funkcja dodająca krawędź do grafu
 * @param edge  Krawędź                  [Structures::Edge]
 */
void IncidenceMatrix::add_edge(Structures::Edge edge)
{
    Array<int> new_edge(vertices_num_);
    new_edge.insert(edge.weight, edge.destination_id);
    new_edge.insert(edge.weight * -1, edge.source_id);
    matrix_.push_back(new_edge);
    std::cout << "Poprawnie dodano krawędź ";
    edge.print();
}

/**
 *  Funkcja wyświetlająca graf w postaci macierzy incydencji.
 */
void IncidenceMatrix::print() const
{
    matrix_.print();
}