/**
 * Plik źródłowy zawierający implementację klasy DisjointSet.
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 530
 *
 * Klasa DisjointSet jest implementacją zbiorów rozłącznych.
 * Przechowuje ona następujące zmienne:
 *  n_       [int]   - ilość rozpatrywanych wierzchołków
 *  parent_  [int*]  - tablica każdego zbioru
 *  rank_    [int*]  - tablica rang każdego zbioru
 *
 */
#include "disjoint_set.h"

/**
 * Konstruktor klasy DisjointSet
*/
DisjointSet::DisjointSet(int n)
    : n_(n)
{
    rank_ = new int[n];
    parent_ = new int[n];
    make_set();
}

/**
 * Destruktor klasy DisjointSet
*/
DisjointSet::~DisjointSet()
{
    delete[] parent_;
    delete[] rank_;
}

/**
 * Funkcja tworząca n podzbiorów z jednych wierzchołkiem.
 */
void DisjointSet::make_set()
{
    for (int i = 0; i < n_; i++)
    {
        parent_[i] = i;
        rank_[i] = 0;
    }
}

/**
 * Funkcja znajdująca wierzchołek reprezentatywny zbioru,
 * do którego należy zadany wierzchołek.
 * @param x Wierzchołek poszukiwanego zbioru [int]
 * @return parent_[x]:  identyfikator podgrafu zawierającego wierzchołek x [int]
 */
int DisjointSet::find_set(int x)
{
    if (parent_[x] != x)
    {
        parent_[x] = find_set(parent_[x]);
    }
    return parent_[x];
}

/**
 * Funkcja łącząca dwa zbiory rozłączne.
 * @param x Wierzchołek pierwszego zbioru [int]
 * @param y Wierzchołek drugiego zbioru   [int]
 */
void DisjointSet::Union(int x, int y)
{
    int xset = find_set(x);
    int yset = find_set(y);
    if (rank_[xset] > rank_[yset])
    {
        parent_[yset] = xset;
    }
    else
    {
        parent_[xset] = yset;
        if (rank_[xset] == rank_[yset])
        {
            rank_[yset]++;
        }
    }
}