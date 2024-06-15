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
    if (data_.get_size())
    {
        return false;
    }
    return true;
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
    Others::swap(data_[0], data_[size - 1]);
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
void PriorityQueue::decrease_key(int &vertex_id, const int &key)
{
    data_[vertex_id].key = key;
    while (vertex_id != 0 && data_[get_parent(vertex_id)].key > data_[vertex_id].key)
    {
        Others::swap(data_[vertex_id], data_[get_parent(vertex_id)]);
        vertex_id = get_parent(vertex_id);
    }
}

/**
 * Funkcja znajdująca indeks elementu o zadanej wartości
 *
 * @param vertex_id ID wierzchołka, który jest szukany [int]
 * @return Indeks, na którym znajduje się wierzchołek
 * (jeżeli nie znaleziono, to -1) [int]
 */
int PriorityQueue::find(const int &vertex_id)
{
    for (int i = 0; i < data_.get_size(); i++)
    {
        if (data_[i].vertex_id == vertex_id)
        {
            return i;
        }
    }
    return -1;
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
    int size = data_.get_size();
    data_.push_back(Structures::Vertex(vertex_id, key));
    if (size > 1)
    {
        for ( int i = size / 2 - 1; i >= 0; i--)
        {
            min_heapify(i);
        }
    }
}

/**
 * Funkcja zwracająca indeks rodzica
 *
 * @param idx Indeks elementu, którego rodzic jest poszukiwany [int]
 * @return Indeks rodzica [int]
 */
int PriorityQueue::get_parent(int idx) const { return floor((idx - 1) / 2); }

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
 * @param idx Indeks korzenia poddrzewa, które się kopcuje [int]
*/
void PriorityQueue::min_heapify(int idx)
{
    int smallest = idx;
    int left_child = get_left_child(idx);
    int right_child = get_right_child(idx);
    if (left_child <= data_.get_size() && data_[left_child].key < data_[idx].key)
    {
        smallest = left_child;
    }
    if (right_child <= data_.get_size() && data_[right_child].key < data_[smallest].key)
    {
        smallest = right_child;
    }
    if (smallest != idx)
    {
        Others::swap(data_[idx], data_[smallest]);
        min_heapify(smallest);
    }
}