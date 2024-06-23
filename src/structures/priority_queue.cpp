/**
 * Plik źródłowy zawierający implementację struktury
 * Vertex oraz klasy PriorityQueue
 *
 * Struktura Vertex jest implementacją wierzchołka grafu.
 * Przechowuje zmienne number [int], czyli numer wierzchołka oraz
 * key [int], który jest dystansem wierzchołka od wierzchołka
 * startowego bądź kluczem wierzchołka w przypadku algorytmu Prim'a.
 */

#include "priority_queue.h"

/**
 * Konstruktor klasy PriorityQueue
*/
PriorityQueue::PriorityQueue()
{ }

/**
 * Funkcja sprawdzająca, czy kolejka jest pusta
 * 
 * @return is_empty - czy kolejka jest pusta [bool]
*/
bool PriorityQueue::is_empty()
{
    return data_.get_size() == 0;
}

/**
 * Funkcja wyświetlająca zawartość kolejki
*/
void PriorityQueue::print() const
{

}

/**
 * Funkcja usuwająca korzeń kopca
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 175
 * @return min - Korzeń kopca [int]
 */
int PriorityQueue::extract_min()
{
    int size = data_.get_size();
    if (size < 1) { return -1; }
    int min = data_[0].key;
    std::swap(data_[0], data_[size - 1]);
    data_.pop_back();
    min_heapify(0);
    return min;
}

/**
 * Funkcja aktualizuje indeks danej wartości.
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 176
 *
 * @param vertex_id Indeks, na którym znajduje się sprawdzana wartość   [int]
 * @param key       Nowy klucz                                          [int]
 */
void PriorityQueue::decrease_key(int vertex_id, int key)
{
    int i;
    int size = data_.get_size();
    for (i = 0; i < size; i++)
    {
        if (data_[i].vertex_id == vertex_id)
        {
            data_[i].key = key;
            break;
        }
    }
    min_heapify_up(size - 1);
}

/**
 * Funkcja znajdująca indeks elementu o zadanej wartości
 *
 * @param vertex_id ID wierzchołka, który jest szukany [int]
 * @return Indeks, na którym znajduje się wierzchołek
 * (jeżeli nie znaleziono, to -1) [int]
 */
int PriorityQueue::has_vertex(int vertex_id)
{
    int size = data_.get_size();
    for (int i = 0; i < size; i++)
    {
        if (data_[i].vertex_id == vertex_id) { return true; }
    }
    return false;
}

/**
 * Funkcja dodająca nowy wierzchołek do kolejki
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 176
 *
 * @param vertex_id ID wierzchołka      [int]
 * @param key       Klucz wierzchołka   [int]
 */
void PriorityQueue::push(const int &vertex_id, const int &key)
{
    data_.push_back(Structures::Vertex(vertex_id, key));
    min_heapify_up(data_.get_size() - 1);
}

/**
 * Funkcja zwracająca indeks rodzica
 *
 * @param idx Indeks elementu, którego rodzic jest poszukiwany [int]
 * @return Indeks rodzica [int]
 */
int PriorityQueue::get_parent(int idx) const { return (idx - 1) / 2; }

/**
 * Funkcja zwracająca indeks lewego dziecka
 *
 * @param idx Indeks elementu, którego dziecko jest poszukiwane [int]
 * @return Indeks lewego dziecka [int]
 */
int PriorityQueue::get_left_child(int idx) const { return (2 * idx) + 1; }

/**
 * Funkcja zwracająca indeks prawego dziecka
 *
 * @param idx Indeks elementu, którego dziecko jest poszukiwane [int]
 * @return Indeks prawego dziecka [int]
 */
int PriorityQueue::get_right_child(int idx) const { return (2 * idx) + 2; }

/**
 * Funkcja przeprowadzająca algorytm kopcowania.
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 165
 *
 * @param root Indeks korzenia poddrzewa, które się kopcuje [int]
*/
void PriorityQueue::min_heapify(int root)
{
    int size = data_.get_size();
    int smallest = root;
    int left_child = get_left_child(root);
    int right_child = get_right_child(root);

    if (left_child < size && data_[left_child] < data_[smallest]) { smallest = left_child; }
    if (right_child < size && data_[right_child] < data_[smallest]) { smallest = right_child; }
    
    if (smallest != root)
    {
        std::swap(data_[root], data_[smallest]);
        min_heapify(smallest);
    }
}

/**
 * Funkcja przeprowadzająca algorytm kopcowania w górę
*/
void PriorityQueue::min_heapify_up(int root)
{
    int parent = get_parent(root);
    while (root > 0 && data_[root] < data_[parent])
    {
        std::swap(data_[root], data_[parent]);
        root = parent;
        parent = (root - 1)/2;
    }
}