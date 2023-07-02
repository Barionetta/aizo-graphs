/**
 * Plik nagłówkowy pliku zawierającego implementację struktury IMEdge,
 * oraz klasy IncidenceMatrix
 *
 * Struktura IMEdge jest strukturą zawierającą informację
 * o krawędzi. Przechowuje zmienną source [int], czyli numer
 * wierzchołka startowego, zmienną destination [int], czyli
 * numer wierzchołka końcowego, oraz zmienną weight [int],
 * czyli wagę krawędzi.
 *
 * Klasa IncidenceMatrix jest implementacją macierzy incydencji.
 * Macierz przechowuje zmienne:
 *  vertices_num [int] - ilość wierzchołków
 *  edges_num [int] - ilość krawędzi
 *  matrix[int**] - tablicę dwuwymiarową o rozmiarach v_num x e_num
 */
#ifndef INCIDENCE_MATRIX_H
#define INCIDENCE_MATRIX_H
#include "simulation/generator.h"
#include <string>

struct IMEdge
{
    int source = 0;      // Numer wierzchołka startowego [int]
    int destination = 0; // Numer wierzchołka docelowego [int]
    int weight = 0;      // Waga krawędzi [int]
};

class IncidenceMatrix
{

private:
    int vertices_num; // Liczba wierzchołków [int]
    int edges_num;    // Liczba krawędzi [int]
    int **matrix;     // Tablica dwuwymiarowa o rozmiarach v_num x e_num [int**]

public:
    // Konstruktor klasy IncidenceMatrix
    IncidenceMatrix();
    // Funkcja ustawiająca liczbę wierzchołków
    void setVerticesNum(int vertices);
    // Funkcja ustawiająca liczbę krawędzi
    void setEdgesNum(int edges);
    // Funkcja zwracająca ilość wierzchołków w grafie
    int getVerticesNum();
    // Funkcja zwracająca ilość krawędzi w grafie
    int getEdgesNum();
    // Funkcja inicjująca macierz
    void initMatrix();
    // Funkcja dodająca krawędź do grafu
    void addEdge(int edge_num, int v1, int v2, int weight);
    // Funkcja zwracająca krawędź o zadanym numerze
    IMEdge *getEdge(int edge_num);
    // Funkcja zwracająca tablicę wszystkich krawędzi
    int **getAllEdgesList();
    // Funkcja wczytująca graf z pliku tekstowego
    void readFromFile(std::string filepath);
    // Funkcja zapełniająca macierz incydencji liczbami wygenerowanymi losowo
    void generate(int vertices, int edges);
    // Funkcja wyświetlająca graf w postaci macierzy incydencji
    void show();
    // Destruktor klasy IncidenceMatrix
    ~IncidenceMatrix();
};
#endif