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
    : size_(0),
      max_size_(10),
      matrix_(std::make_unique<Array<int>[]>(max_size_))
{
    std::cout << "Poprawnie zainicjalizowano macierz incydencji.\n";
}

/**
 * Konstruktor kopiujący klasy IncidenceMatrix
 *
 * @param array Macierz, która jest kopiowana [IncidenceMatrix&]
 */
IncidenceMatrix::IncidenceMatrix(const IncidenceMatrix& matrix)
    : size_(matrix.size_),
      max_size_(matrix.max_size_),
      matrix_(std::make_unique<Array<int>[]>(matrix.max_size_))
{
    std::copy_n(matrix.matrix_.get(), matrix.size_, matrix_.get());
}

/**
 * Konstruktor przenoszenia klasy IncidenceMatrix
 *
 * @param matrix Macierz, która jest przenoszona [IncidenceMatrix&&]
 */
IncidenceMatrix::IncidenceMatrix(IncidenceMatrix&& matrix)
    : size_(matrix.size_),
      max_size_(matrix.max_size_),
      matrix_(nullptr)
{
    *this = matrix;
}

/**
 * Operator dostępu
*/
Array<int>& IncidenceMatrix::operator[] (int i)
{
    return matrix_.get()[i];
}

/**
 * Operator kopiowania
*/
IncidenceMatrix& IncidenceMatrix::operator=(const IncidenceMatrix& matrix)
{
    if (this == &matrix) { return *this; }

    matrix_ = std::make_unique<Array<int>[]>(matrix.max_size_);
    size_ = matrix.size_;
    std::copy_n(matrix.matrix_.get(), matrix.size_, matrix_.get());

    return *this;
}

/**
 * Operator przenoszenia
*/
IncidenceMatrix& IncidenceMatrix::operator=(IncidenceMatrix&& matrix)
{
    std::swap(matrix_, matrix.matrix_);
    std::swap(max_size_, matrix.max_size_);
    std::swap(size_, matrix.size_);
    return *this;
}

/**
 * Funkcja zwracająca liczbą wierszy macierzy
 * 
 * @return this->size_ : Rozmiar macierzy [int]
*/
int IncidenceMatrix::get_size() const
{
    return size_;
}

/**
 * Funkcja ustawiająca wymiary grafu
*/
void IncidenceMatrix::set_size()
{
    //matrix_.set_size(edges_num_);
}

/**
 * Funkcja sprawdzająca, czy graf ma krawędź
 * 
 * @param source Źródło sprawdzanej krawędzi    [int]
 * @param destination Cel sprawdzanej krawędzi  [int]
 * @return Czy ma krawędź?                      [bool]
*/
bool IncidenceMatrix::has_edge(int source, int destination)
{
    for (int i = 0; i < size_; i++)
    {
        if (matrix_[i][source] > 0 && matrix_[i][destination] < 0)
        {
            return true;
        }
    }
    return false;
}

/**
 * Funkcja dodająca krawędź do grafu
 * 
 * @param edge  Krawędź [Structures::Edge]
 */
void IncidenceMatrix::add_edge(Structures::Edge edge)
{
    if (size_ == max_size_)
    {
        std::unique_ptr<Array<int>[]> new_data = std::make_unique<Array<int>[]>(max_size_ + 5);
        new_data = std::move(matrix_);
        std::swap(matrix_, new_data);
        max_size_ += 5;
    }

    Array<int> new_edge;
    for (int i = 0; i < vertices_num_; i++)
    {
        new_edge.push_back(0);
    }
    new_edge.insert(edge.weight, edge.destination_id);
    new_edge.insert(edge.weight * -1, edge.source_id);
    matrix_[size_] = new_edge;
    size_++;

    std::cout << "Poprawnie dodano krawędź ";
    edge.print();
}

/**
 * Funkcja zwracająca tablicę wszystkich krawędzi
 * 
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
        if (matrix_.get()[i][vertex_id])
        {
            for (int j = 0; j < vertices_num_; j++)
            {
                if(matrix_.get()[i][j] > 0 && j != vertex_id)
                {
                    adjacency.push_front(j, matrix_.get()[i][j]);
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
    std::cout << "Graf w postaci macierzowej: \n";

    for (int i = 0; i < size_; i++)
    {
        matrix_[i].print();
    }
    std::cout << std::endl;
}