/**
 * Plik źródłowy zawierającegy implementację struktury Edge,
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
#include "adjacency_list.h"
#include "simulation/generator.h"
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
using namespace std;

// Konstruktor klasy AdjacencyList
AdjacencyList::AdjacencyList()
{
    this->vertices_num = 0;   // Liczba wierzchołków [int]
    this->edges_num = 0;      // Liczba krawędzi [int]
    this->vertices = nullptr; // Tablica list krawędzi dla każdego wierzchołka [EdgeList*]

    //cout << "Poprawnie zainicjalizowano listę sąsiedztwa." << endl;
}

/**
 * Funkcja ustawiająca liczbę wierzchołków.
 * @param vertices Liczba wierzchołków grafu [int]
 */
void AdjacencyList::setVerticesNum(int vertices)
{
    this->vertices_num = vertices;
}

/**
 * Funkcja ustawiająca liczbę krawędzi.
 * @param edges Liczba krawędzi grafu [int]
 */
void AdjacencyList::setEdgesNum(int edges)
{
    this->edges_num = edges;
}

/**
 * Funkcja zwracająca ilość wierzchołków w grafie.
 * @return vertices_num:  Liczba wierzchołków grafu [int]
 */
int AdjacencyList::getVerticesNum()
{
    return this->vertices_num;
}

/**
 * Funkcja zwracająca ilość krawędzi w grafie.
 * @return edges_num:  Liczba krawędzi grafu [int]
 */
int AdjacencyList::getEdgesNum()
{
    return this->edges_num;
}

/**
 * Funkcja inicjująca tablicę.
 */
void AdjacencyList::initArray()
{
    this->vertices = new EdgeList[vertices_num];
    for (int i = 0; i < this->vertices_num; i++)
    {
        this->vertices[i].head = nullptr;
        this->vertices[i].v_num = i;
    }
}

/**
 * Funkcja zwracająca tablicę list krawędzi.
 * @return vertices: tablica list krawędzi [EdgeList*]
 */
EdgeList *AdjacencyList::getVertices()
{
    return this->vertices;
}

/**
 * Funkcja dodająca krawędź do grafu.
 * @param source Numer wierzchołka startowego [int]
 * @param destination Numer wierzchołka docelowego [int]
 * @param weight Waga krawędzi [int]
 */
void AdjacencyList::addEdge(int source, int destination, int weight)
{
    EdgeList *sourceVertex = findVertex(source);

    Edge *newEdge = new Edge();
    newEdge->destination = destination;
    newEdge->weight = weight;
    newEdge->next = sourceVertex->head;
    sourceVertex->head = newEdge;
    //cout << "Poprawnie dodano krawędź." << endl;
}

/**
 * Funkcja zwracająca listę krawędzi dla jednego wierzchołka.
 * @param vertex_num Numer wierzchołka [int]
 * @return vertices[vertex_num]: Lista krawędzi wierzchołka [EdgeList*]
 */
EdgeList *AdjacencyList::findVertex(int vertex_num)
{
    return &vertices[vertex_num];
}

/**
 * Funkcja zwracająca tablicę wszystkich krawędzi.
 * @return edge_list: Lista wszystkich krawędzi w grafie [int**]
 */
int **AdjacencyList::getAllEdgesList()
{
    int **edge_list = new int *[edges_num];
    int e = 0;
    for (int v = 0; v < vertices_num; v++)
    {
        Edge *temp = this->vertices[v].head;
        while (temp)
        {
            int *edge = new int[3];
            edge[0] = v;
            edge[1] = temp->destination;
            edge[2] = temp->weight;
            edge_list[e] = edge;
            temp = temp->next;
            e++;
        }
    }
    return edge_list;
}

/**
 * Funkcja wczytująca graf z pliku tekstowego.
 * Plik tekstowy musi znajdować się w folderze "test" w tym samym folderze,
 * co główny plik programu!
 *
 * @param filepath Nazwa pliku, z którego wczytywane są krawędzie [string]
 */
void AdjacencyList::readFromFile(string filepath)
{
    string path = filepath;
    fstream f;
    int source = 0;
    int destination = 0;
    int weight = 0;
    f.open(path);
    if (f.is_open())
    {
        f >> this->edges_num;
        f >> this->vertices_num;
        cout << "Liczba wierzchołków: " << this->vertices_num << endl;
        cout << "Liczba krawędzi: " << this->edges_num << endl;
        this->initArray();
        while (f >> source)
        {
            f >> destination;
            f >> weight;
            this->addEdge(source, destination, weight);
        }
        f.close();
        cout << "Poprawnie wczytano graf ze ścieżki " << path << " \n";
    }
    else
    {
        cout << "Nie udało się otworzyć pliku ze ścieżki " << path << " \n";
    }
}

/**
 *  Funkcja zapełniająca listę sąsiedztwa liczbami wygenerowanymi losowo
 *
 * @param vertices Liczba wierzchołków [int]
 * @param edges Liczba krawędzi [int]
 */
void AdjacencyList::generate(int vertices, int edges)
{
    this->setVerticesNum(vertices);
    this->setEdgesNum(edges);
    this->initArray();
    int *numbers = new int[vertices];
    for (int i = 0; i < vertices; i++)
    {
        numbers[i] = i;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    int edges_per_v = static_cast<int>(edges / vertices);

    for (int v = 0; v < vertices_num - 1; v++)
    {
        std::shuffle(numbers, numbers + vertices_num, gen);
        for (int e = 0; e < edges_per_v; e++)
        {
            if (numbers[e] == v)
            {
                this->addEdge(v, numbers[vertices_num - 1], generate_random_number(20));
            }
            else
            {
                this->addEdge(v, numbers[e], generate_random_number(20));
            }
        }
        edges -= edges_per_v;
    }
    for (int e = 0; e < edges; e++)
    {
        std::shuffle(numbers, numbers + vertices_num, gen);
        if (numbers[e] == vertices_num - 1)
        {
            this->addEdge(vertices_num - 1, numbers[vertices_num - 1], generate_random_number(20));
        }
        else
        {
            this->addEdge(vertices_num - 1, numbers[e], generate_random_number(20));
        }
    }
}

/**
 *  Funkcja wyświetlająca graf w postaci listy sąsiedztwa.
 */
void AdjacencyList::show()
{
    for (int v = 0; v < vertices_num; v++)
    {
        cout << "Wierzchołek [" << v << "] -> |  ";
        Edge *temp = this->vertices[v].head;
        while (temp)
        {
            cout << temp->destination << "/" << temp->weight << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
    cout << endl;
}

// Destruktor klasy AdjacencyList
AdjacencyList::~AdjacencyList()
{
    for (int v = 0; v < vertices_num; v++)
    {
        Edge *temp = this->vertices[v].head;
        while (temp)
        {
            temp = this->vertices[v].head->next;
            delete this->vertices[v].head;
            this->vertices[v].head = temp;
        }
        delete this->vertices[v].head;
    }
    delete[] vertices;
    //cout << "Poprawnie usunięto listę." << endl;
}
