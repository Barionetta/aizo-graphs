/**
 * Plik nagłówkowy pliku zawierającego implementację struktury Edge,
 * struktury EdgeList oraz klasy AdjacencyList
 *
 * Struktura Egde jest pojedynczą krawędzią należącą do EgdeList,
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
 *  vertices_num    [int]       - ilość wierzchołków
 *  edges_num       [int]       - ilość krawędzi
 *  vertices        [EdgeList*] - listy dla każdego wierzchołka
 */

#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H
#include "core/others.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

struct Edge
{
    int destination; // Numer wierzchołka docelowego    [int]
    int weight;      // Waga krawędzi                   [int]
    Edge *next;      // Wskaźnik na następną krawędź    [Edge*]
};

struct EdgeList
{
    int v_num;  // Numer wierzchołka startowego [int]
    Edge *head; // Wskaźnik na głowę listy      [Edge*]
};

class AdjacencyList
{
public:
    // Konstruktor klasy AdjacencyList
    AdjacencyList();
    // Destruktor klasy AdjacencyList
    ~AdjacencyList();

    // Funkcja ustawiająca liczbę wierzchołków
    void set_vertices_num(int vertices);
    // Funkcja ustawiająca liczbę krawędzi
    void set_edges_num(int edges);
    // Funkcja zwracająca liczbę wierzchołków w grafie
    int get_vertices_num() const;
    // Funkcja zwracająca liczbę krawędzi w grafie
    int get_edges_num() const;
    // Funkcja zwracająca tablicę list krawędzi
    EdgeList *get_vertices();
    // Funkcja zwracająca tablicę wszystkich krawędzi
    int **get_all_edges_list();

    // Funkcja inicjująca tablicę
    void init_array();
    // Funkcja dodająca krawędź do grafu
    void add_edge(int source, int destination, int weight);
    // Funkcja zwracająca listę krawędzi dla jednego wierzchołka
    EdgeList *find_vertex(int vertex_num);
    // Funkcja wyświetlająca graf w postaci listy sąsiedztwa
    void print() const;
    // Funkcja wczytująca graf z pliku tekstowego
    void read_from_file(std::string filepath);
    // Funkcja zapełniająca listę sąsiedztwa liczbami wygenerowanymi losowo
    void generate(int vertices, int edges);

private:
    int vertices_num_;   // Liczba wierzchołków                              [int]
    int edges_num_;      // Liczba krawędzi                                  [int]
    EdgeList *vertices_; // Tablica list krawędzi dla każdego wierzchołka    [EdgeList*]
};

#endif