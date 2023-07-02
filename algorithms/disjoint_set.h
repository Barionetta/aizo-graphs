/**
 * Plik nagłówkowy pliku zawierającego implementację klasy DisjointSet
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 530
 * 
 * Klasa DisjointSet jest implementacją zbiorów rozłącznych.
 * Przechowuje ona następujące zmienne:
 *  n [int] - ilość rozpatrywanych wierzchołków
 *  parent [int*] - tablica każdego zbioru
 *  rank [int*] - tablica rang każdego zbioru
 * 
 */
#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

class DisjointSet
{
private:
    int *rank;      // Tablica rang zbiorów [int*]
    int *parent;    // Tablica zbiorów [int*]
    int n;          // Ilość wierzchołków [int]

public:
    // Konstruktor klasy DisjointSet
    DisjointSet(int n);
    // Funkcja tworząca n podzbiorów z jednych wierzchołkiem
    void makeSet();
    // Funkcja znajdująca wierzchołek reprezentatywny zbioru, do którego należy zadany wierzchołek
    int findSet(int x);
    // Funkcja łącząca dwa zbiory rozłączne
    void Union(int x, int y);
    // Destruktor klasy DisjointSet
    ~DisjointSet();
};

#endif