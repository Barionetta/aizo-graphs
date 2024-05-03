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
#include <iostream>
#include <cmath>
using namespace std;

// Konstruktor klasy PriorityQueue
PriorityQueue::PriorityQueue()
{
    size = 0;                   // Rozmiar kolejki [int]
    maxSize = 10;               // Maksymalny rozmiar kolejki [int]
    data = new Vertex[maxSize]; // Tablica wierzchołków [Vertex*]
    cout << "Poprawnie zainicjalizowano kopiec minimalny." << endl;
}

/**
 * Funkcja zwracająca indeks rodzica
 *
 * @param idx Indeks elementu, którego rodzic jest poszukiwany [int]
 * @return Indeks rodzica [int]
 */
int PriorityQueue::getParent(int idx) { return floor((idx - 1) / 2); }

/**
 * Funkcja zwracająca indeks lewego dziecka
 *
 * @param idx Indeks elementu, którego dziecko jest poszukiwane [int]
 * @return Indeks lewego dziecka [int]
 */
int PriorityQueue::getLeftChild(int idx) { return (2 * idx) + 1; }

/**
 * Funkcja zwracająca indeks prawego dziecka
 *
 * @param idx Indeks elementu, którego dziecko jest poszukiwane [int]
 * @return Indeks prawego dziecka [int]
 */
int PriorityQueue::getRightChild(int idx) { return (2 * idx) + 2; }

/**
 * Funkcja zwracająca rozmiar kolejki
 *
 * @return size:  Rozmiar kolejki [int]
 */
int PriorityQueue::getSize()
{
    return this->size;
};

/**
 * Funkcja zwracająca listę wierzchołków kolejki
 *
 * @return data: lista wierzchołków kolejki [Vertex*]
 */
Vertex *PriorityQueue::getData()
{
    return this->data;
}

/**
 * Funkcja pomocnicza zamieniająca miejscami dwa wierzchołki
 *
 * @param x Pierwszy zamieniany wierzchołek [Vertex*]
 * @param y Drugi zamieniany wierzchołek [Vertex*]
 */
void PriorityQueue::swap(Vertex *x, Vertex *y)
{
    Vertex temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * Funkcja przeprowadzająca algorytm kopcowania.
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 165
 *
 * @param idx Indeks korzenia poddrzewa [int]
 */
void PriorityQueue::minHeapify(int idx)
{
    int smallest = idx;
    int leftChild = getLeftChild(idx);
    int rightChild = getRightChild(idx);
    if (leftChild <= this->size && data[leftChild].distance < data[idx].distance)
    {
        smallest = leftChild;
    }
    if (rightChild <= this->size && data[rightChild].distance < data[smallest].distance)
    {
        smallest = rightChild;
    }
    if (smallest != idx)
    {
        swap(&data[idx], &data[smallest]);
        minHeapify(smallest);
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
void PriorityQueue::decreaseKey(int v, int key)
{
    data[v].distance = key;
    while (v != 0 && data[getParent(v)].distance > data[v].distance)
    {
        swap(&data[v], &data[getParent(v)]);
        v = getParent(v);
    }
}

/**
 * Funkcja usuwająca najmniejszy wierzchołek w kolejce
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 175
 * @return min - Minimalny dystans wierzchołka kolejki [int]
 */
int PriorityQueue::extractMin()
{
    if (size < 1)
    {
        cout << "Niedomiar kopca!" << endl;
        return -1;
    }
    int min = data[0].distance;
    data[0] = data[size - 1];
    size--;
    minHeapify(0);
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
    for (int i = 0; i < size; i++)
    {
        if (data[i].number == number)
        {
            cout << "Wierzchołek znajduje się na pozycji " << i << ".\n";
            return i;
        }
    }
    cout << "Nie znaleziono podanego wierzchołka." << endl;
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
    if (size == maxSize)
    {
        Vertex *new_data = new Vertex[maxSize + 5];

        for (int i = 0; i < size; i++)
        {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        maxSize += 5;
    }
    data[size].number = v->number;
    decreaseKey(size, v->distance);
    size++;
    cout << "Poprawnie dodano wierzchołek do kopca minimalnego.\n";
}

/**
 * Funkcja która sprawdza, czy kolejka jest pusta
 * @return true/false : Czy kolejka jest pusta
 */
bool PriorityQueue::isEmpty()
{
    if (size == 0)
    {
        return true;
    }
    return false;
}

// Destruktor klasy PriorityQueue
PriorityQueue::~PriorityQueue()
{
    delete[] data;
    cout << "Poprawnie usunięto kopiec minimalny.\n";
}
