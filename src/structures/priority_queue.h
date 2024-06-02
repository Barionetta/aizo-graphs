/**
 * Plik nagłówkowy pliku zawierającego implementację struktury
 * Vertex oraz klasy PriorityQueue
 *
 * Klasa PriorityQueue jest kopcem minimalnym struktur Node.
 * Przy ustalaniu pozycji wierzchołków porównuje się ich dystans.
 * Kolejka umożliwia wykonanie podstawowych operacji, takich jak
 * usunięcie korzenia, znalezienie elementu oraz wstawienie go.
 */

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "array.h"
#include "structures.h"
#include "core/others.h"

#include <cmath>

class PriorityQueue
{
public:
    // Konstruktor klasy PriorityQueue
    PriorityQueue();
    // Destruktor klasy PriorityQueue
    ~PriorityQueue() = default;

    // Funkcja usuwająca korzeń kopca
    int extract_min();
    // Funkcja aktualizuje indeks danej wartości
    void decrease_key(int &vertex_id, const int &key);
    // Funkcja znajdująca indeks elementu o zadanym ID wierzchołka
    int find(const int &vertex_id);
    // Funkcja wstawiająca element do kopca
    void push(const int &vertex_id, const int &key);

private:

    Array<Structures::Vertex> data_;  // Kopiec z wierzchołkami [Array<Structures::Vertex>]

    // Funkcja zwracająca indeks rodzica
    int get_parent(int idx) const;
    // Funkcja zwracająca indeks lewego dziecka
    int get_left_child(int idx) const;
    // Funkcja zwracająca indeks prawego dziecka
    int get_right_child(int idx) const;
    // Funkcja przeprowadzająca algorytm kopcowania
    void min_heapify(int idx);
};

#endif