/**
 * Plik nagłówkowy pliku zawierającego implementację struktury Edge,
 * struktury EdgeList oraz klasy AdjacencyList
 *
 * Struktura Egde jest pojedyńczą krawędzią należącą do EgdeList,
 * czyli komórki listy sąsiedztwa przechowującą listę krawędzi
 * powiązanych z danym wierzchołkiem. Egde przechowuje
 * zmienną destination [int], czyli numer wierzchołka docelowego,
 * zmienną weight [int], czyli wagę wierzchołka, oraz
 * wskaźnik na następną krawędź next [Edge*].
 *
 * Struktura EgdeList jest listą krawędzi, z którą dany
 * wierzchołek jest połączony. Przechowuje ona
 * zmienną v_num [int], czyli numer wierzchołka startowego,
 * oraz wskaźnik na początek (głowę) listy head [Edge*]
 *
 * Klasa AdjacencyList jest implementacją listy sąsiedztwa.
 * Lista przechowuje zmienne:
 *  vertices_num [int] - ilość wierzchołków
 *  edges_num [int] - ilość krawędzi
 *  vertices [EdgeList*] - listy dla każdego wierzchołka
 */
#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H
#include "simulation/generator.h"
#include <string>

struct Edge
{
    int destination; // Numer wierzchołka docelowego [int]
    int weight;      // Waga krawędzi [int]
    Edge *next;      // Wskaźnik na następną krawędź [Edge*]
};

struct EdgeList
{
    int v_num;  // Numer wierzchołka startowego [int]
    Edge *head; // Wskaźnik na głowę listy [Edge*]
};

class AdjacencyList
{

private:
    int vertices_num;   // Liczba wierzchołków [int]
    int edges_num;      // Liczba krawędzi [int]
    EdgeList *vertices; // Tablica list krawędzi dla każdego wierzchołka [EdgeList*]

public:
    // Konstruktor klasy AdjacencyList
    AdjacencyList();
    // Funkcja ustawiająca liczbę wierzchołków
    void setVerticesNum(int vertices);
    // Funkcja ustawiająca liczbę krawędzi
    void setEdgesNum(int edges);
    // Funkcja zwracająca ilość wierzchołków w grafie
    int getVerticesNum();
    // Funkcja zwracająca ilość krawędzi w grafie
    int getEdgesNum();
    // Funkcja inicjująca tablicę
    void initArray();
    // Funkcja zwracająca tablicę list krawędzi
    EdgeList *getVertices();
    // Funkcja dodająca krawędź do grafu
    void addEdge(int source, int destination, int weight);
    // Funkcja zwracająca listę krawędzi dla jednego wierzchołka
    EdgeList *findVertex(int vertex_num);
    // Funkcja zwracająca tablicę wszystkich krawędzi
    int **getAllEdgesList();
    // Funkcja wczytująca graf z pliku tekstowego
    void readFromFile(std::string filepath);
    // Funkcja zapełniająca listę sąsiedztwa liczbami wygenerowanymi losowo
    void generate(int vertices, int edges);
    // Funkcja wyświetlająca graf w postaci listy sąsiedztwa
    void show();
    // Destruktor klasy AdjacencyList
    ~AdjacencyList();
};

#endif