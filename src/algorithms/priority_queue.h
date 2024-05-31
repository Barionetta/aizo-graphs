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

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <cmath>
#include <iostream>

using std::cout;

struct Vertex
{
    int number;   // Number wierzchołka [int]
    int distance; // Dystans od wierzchołka startowego (w MST klucz wierzchołka) [int]
};

class PriorityQueue
{
public:
    // Konstruktor klasy PriorityQueue
    PriorityQueue();
    // Destruktor klasy PriorityQueue
    ~PriorityQueue();

    // Funkcja zwracająca rozmiar kolejki
    int get_size();
    // Funkcja zwracająca listę wierzchołków kolejki
    Vertex *get_data();

    // Funkcja przeprowadzająca algorytm kopcowania
    void min_heapify(int idx);
    // Funkcja aktualizuje indeks danej wartości
    void decrease_key(int v, int key);
    // Funkcja usuwająca najmniejszy wierzchołek z kolejki
    int extract_min();
    // Funkcja znajdująca indeks wierzchołka o zadanym numerze
    int find(int number);
    // Funkcja dodająca nowy wierzchołek do kolejki
    void push(Vertex *v);
    // Funkcja która sprawdza, czy kolejka jest pusta
    bool is_empty();

private:
    int size_;      // Rozmiar kolejki              [int]
    int max_size_;  // Maksymalny rozmiar kolejki   [int]
    Vertex *data_;  // Tablica wierzchołków         [Vertex*]
    
    // Funkcja zwracająca indeks rodzica
    int get_parent(int idx);
    // Funkcja zwracająca indeks lewego dziecka
    int get_left_child(int idx);
    // Funkcja zwracająca indeks prawego dziecka
    int get_right_child(int idx);
    // Funkcja pomocnicza zamieniająca miejscami dwie liczby
    void swap(Vertex &x, Vertex &y);
};

#endif