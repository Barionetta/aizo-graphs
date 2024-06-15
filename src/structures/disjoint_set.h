/**
 * Plik nagłówkowy pliku zawierającego implementację klasy DisjointSet
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 530
 * 
 * Klasa DisjointSet jest implementacją zbiorów rozłącznych.
 * Przechowuje ona następujące zmienne:
 *  n       [int]   - ilość rozpatrywanych wierzchołków
 *  parent  [int*]  - tablica każdego zbioru
 *  rank    [int*]  - tablica rang każdego zbioru
 * 
 */

#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <memory>

class DisjointSet
{
public:
    // Konstruktor klasy DisjointSet
    DisjointSet(int n);
    
    // Funkcja tworząca n podzbiorów z jednych wierzchołkiem
    void make_set();
    // Funkcja znajdująca wierzchołek reprezentatywny zbioru, do którego należy zadany wierzchołek
    int find_set(int x);
    // Funkcja łącząca dwa zbiory rozłączne
    void union_(int x, int y);

private:
    std::unique_ptr<int[]> rank_;       // Tablica rang zbiorów [int*]
    std::unique_ptr<int[]> parent_;     // Tablica zbiorów      [int*]
    int n_;                             // Ilość wierzchołków   [int]
};

#endif