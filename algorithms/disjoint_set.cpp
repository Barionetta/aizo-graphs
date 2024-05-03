/**
 * Plik źródłowy zawierający implementację klasy DisjointSet.
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
#include "disjoint_set.h"

// Konstruktor klasy DisjointSet
DisjointSet::DisjointSet(int n)
{
    rank = new int[n];
    parent = new int[n];
    this->n = n;
    makeSet();
}

/**
 * Funkcja tworząca n podzbiorów z jednych wierzchołkiem.
 */
void DisjointSet::makeSet()
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

/**
 * Funkcja znajdująca wierzchołek reprezentatywny zbioru,
 * do którego należy zadany wierzchołek.
 * @param x Wierzchołek poszukiwanego zbioru [int]
 * @return parent[x]:  identyfikator podgrafu zawierającego wierzchołek x [int]
 */
int DisjointSet::findSet(int x)
{
    if (parent[x] != x)
    {
        parent[x] = findSet(parent[x]);
    }
    return parent[x];
}

/**
 * Funkcja łącząca dwa zbiory rozłączne.
 * @param x Wierzchołek pierwszego zbioru [int]
 * @param y Wierzchołek drugiego zbioru   [int]
 */
void DisjointSet::Union(int x, int y)
{
    int xset = findSet(x);
    int yset = findSet(y);
    if (rank[xset] > rank[yset])
    {
        parent[yset] = xset;
    }
    else
    {
        parent[xset] = yset;
        if (rank[xset] == rank[yset])
        {
            rank[yset]++;
        }
    }
}

// Destruktor klasy DisjointSet.
DisjointSet::~DisjointSet()
{
    delete[] parent;
    delete[] rank;
}