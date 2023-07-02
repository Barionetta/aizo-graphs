/**
 * Plik nagłówkowy pliku zawierającego implementację struktury
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
#ifndef PRIORITY_QUEUE_INCLUDED
#define PRIORITY_QUEUE_INCLUDED

struct Vertex
{
    int number;   // Number wierzchołka [int]
    int distance; // Dystans od wierzchołka startowego (w MST klucz wierzchołka) [int]
};

class PriorityQueue
{
private:
    int size;     // Rozmiar kolejki [int]
    int maxSize;  // Maksymalny rozmiar kolejki [int]
    Vertex *data; // Tablica wierzchołków [Vertex*]
    // Funkcja zwracająca indeks rodzica
    int getParent(int idx);
    // Funkcja zwracająca indeks lewego dziecka
    int getLeftChild(int idx);
    // Funkcja zwracająca indeks prawego dziecka
    int getRightChild(int idx);
    // Funkcja pomocnicza zamieniająca miejscami dwie liczby
    void swap(Vertex *x, Vertex *y);

public:
    // Konstruktor klasy PriorityQueue
    PriorityQueue();
    // Funkcja zwracająca rozmiar kolejki
    int getSize();
    // Funkcja zwracająca listę wierzchołków kolejki
    Vertex *getData();
    // Funkcja przeprowadzająca algorytm kopcowania
    void minHeapify(int idx);
    // Funkcja aktualizuje indeks danej wartości
    void decreaseKey(int idx, Vertex v);
    // Funkcja usuwająca najmniejszy wierzchołek z kolejki
    int extractMin();
    // Funkcja znajdująca indeks wierzchołka o zadanym numerze
    int find(int number);
    // Funkcja dodająca nowy wierzchołek do kolejki
    void push(Vertex *v);
    // Funkcja która sprawdza, czy kolejka jest pusta
    bool isEmpty();
    // Destruktor klasy PriorityQueue
    ~PriorityQueue();
};

#endif