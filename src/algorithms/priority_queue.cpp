/**
 * Plik źródłowy zawierający implementację struktury
 * Vertex oraz klasy PriorityQueue
 *
 * Struktura Vertex jest implementacją wierzchołka grafu.
 * Przechowuje zmienne number [int], czyli numer wierzchołka oraz
 * distance [int], który jest dystansem wierzchołka od wierzchołka
 * startowego bądź kluczem wierzchołka w przypadku algorytmu Prim'a.
 *
 * Klasa PriorityQueue jest kopcem minimalnym struktur Vertex.
 * Przy ustalaniu pozycji wierzchołków porównuje się ich dystans.
 * Kolejka umożliwia wykonanie podstawowych operacji, takich jak
 * usunięcie korzenia, znalezienie elementu oraz wstawienie go.
 */

#include "priority_queue.h"

/**
 * Konstruktor klasy PriorityQueue
*/
PriorityQueue::PriorityQueue()
    : size_(0),
      max_size_(10)
{
    data_ = new Vertex[max_size_]; // Tablica wierzchołków [Vertex*]
    cout << "Poprawnie zainicjalizowano kopiec minimalny.\n";
}

// Destruktor klasy PriorityQueue
PriorityQueue::~PriorityQueue()
{
    delete[] data_;
    cout << "Poprawnie usunięto kopiec minimalny.\n";
}

/**
 * Funkcja zwracająca rozmiar kolejki
 *
 * @return size:  Rozmiar kolejki [int]
 */
int PriorityQueue::get_size()
{
    return this->size_;
};

/**
 * Funkcja zwracająca listę wierzchołków kolejki
 *
 * @return data: lista wierzchołków kolejki [Vertex*]
 */
Vertex *PriorityQueue::get_data()
{
    return this->data_;
}

/**
 * Funkcja przeprowadzająca algorytm kopcowania.
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 165
 *
 * @param idx Indeks korzenia poddrzewa [int]
 */
void PriorityQueue::min_heapify(int idx)
{
    int smallest = idx;
    int leftChild = get_left_child(idx);
    int rightChild = get_right_child(idx);
    if (leftChild <= this->size_ && data_[leftChild].distance < data_[idx].distance)
    {
        smallest = leftChild;
    }
    if (rightChild <= this->size_ && data_[rightChild].distance < data_[smallest].distance)
    {
        smallest = rightChild;
    }
    if (smallest != idx)
    {
        swap(data_[idx], data_[smallest]);
        min_heapify(smallest);
    }
}

/**
 * Funkcja aktualizuje indeks danej wartości.
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 176
 *
 * @param v Indeks, na którym znajduje się sprawdzana wartość [int]
 * @param key Wierzchołek, który jest porównywany [Vertex*] nieaktualne już
 */
void PriorityQueue::decrease_key(int v, int key)
{
    data_[v].distance = key;
    while (v != 0 && data_[get_parent(v)].distance > data_[v].distance)
    {
        swap(data_[v], data_[get_parent(v)]);
        v = get_parent(v);
    }
}

/**
 * Funkcja usuwająca najmniejszy wierzchołek w kolejce
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 175
 * @return min - Minimalny dystans wierzchołka kolejki [int]
 */
int PriorityQueue::extract_min()
{
    if (size_ < 1)
    {
        cout << "Niedomiar kopca!\n";
        return -1;
    }
    int min = data_[0].distance;
    data_[0] = data_[size_ - 1];
    size_--;
    min_heapify(0);
    return min;
}

/**
 * Funkcja znajdująca indeks elementu o zadanej wartości.
 *
 * @param number Numer wierzchołka, który jest szukany [int]
 * @return Indeks, na którym znajduje się wierzchołek
 * (jeżeli nie znaleziono, to -1) [int]
 */
int PriorityQueue::find(int number)
{
    for (int i = 0; i < size_; i++)
    {
        if (data_[i].number == number)
        {
            cout << "Wierzchołek znajduje się na pozycji " << i << ".\n";
            return i;
        }
    }
    cout << "Nie znaleziono podanego wierzchołka.\n";
    return -1;
}

/**
 * Funkcja dodająca nowy wierzchołek do kolejki
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 176
 *
 * @param v Wierzchołek, który jest wstawiany [Vertex*]
 */
void PriorityQueue::push(Vertex *v)
{
    if (size_ == max_size_)
    {
        Vertex *new_data = new Vertex[max_size_ + 5];

        for (int i = 0; i < size_; i++)
        {
            new_data[i] = data_[i];
        }

        delete[] data_;
        data_ = new_data;
        max_size_ += 5;
    }
    data_[size_].number = v->number;
    decrease_key(size_, v->distance);
    size_++;
    cout << "Poprawnie dodano wierzchołek do kopca minimalnego.\n";
}

/**
 * Funkcja która sprawdza, czy kolejka jest pusta
 * @return true/false : Czy kolejka jest pusta
 */
bool PriorityQueue::is_empty()
{
    if (size_ == 0)
    {
        return true;
    }
    return false;
}


/**
 * Funkcja zwracająca indeks rodzica
 *
 * @param idx Indeks elementu, którego rodzic jest poszukiwany [int]
 * @return Indeks rodzica [int]
 */
int PriorityQueue::get_parent(int idx) { return floor((idx - 1) / 2); }

/**
 * Funkcja zwracająca indeks lewego dziecka
 *
 * @param idx Indeks elementu, którego dziecko jest poszukiwane [int]
 * @return Indeks lewego dziecka [int]
 */
int PriorityQueue::get_left_child(int idx) { return (2 * idx) + 1; }

/**
 * Funkcja zwracająca indeks prawego dziecka
 *
 * @param idx Indeks elementu, którego dziecko jest poszukiwane [int]
 * @return Indeks prawego dziecka [int]
 */
int PriorityQueue::get_right_child(int idx) { return (2 * idx) + 2; }

/**
 * Funkcja pomocnicza zamieniająca miejscami dwa wierzchołki
 *
 * @param x Pierwszy zamieniany wierzchołek [Vertex*]
 * @param y Drugi zamieniany wierzchołek [Vertex*]
 */
void PriorityQueue::swap(Vertex &x, Vertex &y)
{
    Vertex temp = x;
    x = y;
    y = temp;
}