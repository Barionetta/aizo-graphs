/**
 * Plik źródłowy zawierający implementację  klasy IncidenceMatrix
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
 * Funkcja zwracająca tablicę wszystkich krawędzi.
 * @return edge_list: Lista wszystkich krawędzi w grafie [Array<Structures::Edge>]
 */
Array<Structures::Edge> IncidenceMatrix::get_all_edges_list()
{
    Array<Structures::Edge> edge_list;
    
    for (int i = 0; i < edges_num_; i++)
    {
        Structures::Edge edge;
        for (int j = 0; j < vertices_num_; j++)
        {
            if ( matrix_[i][j] > 0)
            {
                edge.destination_id = j;
                edge.weight = matrix_[i][j];
            }
            if ( matrix_[i][j] < 0 ) { edge.source_id = j; }
        }
        edge_list.push_back(edge);
    }
    return edge_list;
}

/**
 * Funkcja zwracająca sąsiadów danego wierzchołka
 * 
 * @param verted_id ID wierzchołka,którego szukane jest sąsiedztwo [int]
 * @return adjacency - lista sąsiadów [LinkedList]
*/
LinkedList IncidenceMatrix::get_adjacency(const int &vertex_id)
{
    LinkedList adjacency;
    for (int i = 0; i < edges_num_; i++)
    {
        if (matrix_[i][vertex_id])
        {
            for (int j = 0; j < vertices_num_; j++)
            {
                if(matrix_[i][j] && j != vertex_id)
                {
                    adjacency.push_front(j, matrix_[i][j]);
                }
            }
        }
    }
    return adjacency;
}

/**
 *  Funkcja wyświetlająca graf w postaci macierzy incydencji.
 */
void IncidenceMatrix::print() const
{
    matrix_.print();
}