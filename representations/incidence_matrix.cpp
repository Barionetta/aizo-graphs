/**
 * Plik źródłowy zawierający implementację struktury IMEdge,
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
 *  matrix [int**] - tablicę dwuwymiarową o rozmiarach v_num x e_num
 */
#include "incidence_matrix.h"
#include "simulation/generator.h"
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
using namespace std;

// Konstruktor klasy IncidenceMatrix
IncidenceMatrix::IncidenceMatrix()
{
    this->vertices_num = 0; // Liczba wierzchołków [int]
    this->edges_num = 0;    // Liczba krawędzi [int]
    this->matrix = nullptr; // Tablica dwuwymiarowa o rozmiarach v_num x e_num [int**]

    cout << "Poprawnie zainicjalizowano macierz incydencji." << endl;
}

/**
 * Funkcja ustawiająca liczbę wierzchołków.
 * @param vertices Liczba wierzchołków grafu [int]
 */
void IncidenceMatrix::setVerticesNum(int vertices)
{
    this->vertices_num = vertices;
}

/**
 * Funkcja ustawiająca liczbę krawędzi.
 * @param edges Liczba krawędzi grafu [int]
 */
void IncidenceMatrix::setEdgesNum(int edges)
{
    this->edges_num = edges;
}

/**
 * Funkcja zwracająca ilość wierzchołków w grafie.
 * @return vertices_num:  Liczba wierzchołków grafu [int]
 */
int IncidenceMatrix::getVerticesNum()
{
    return this->vertices_num;
}

/**
 * Funkcja zwracająca ilość krawędzi w grafie.
 * @return edges_num:  Liczba krawędzi grafu [int]
 */
int IncidenceMatrix::getEdgesNum()
{
    return this->edges_num;
}

/**
 * Funkcja inicjująca macierz
 */
void IncidenceMatrix::initMatrix()
{
    this->matrix = new int *[edges_num];
    for (int e = 0; e < edges_num; e++)
    {
        this->matrix[e] = new int[vertices_num];
    }
}

/**
 * Funkcja dodająca krawędź do grafu.
 * @param edge_num Numer krawędzi [int]
 * @param v1 Numer wierzchołka startowego [int]
 * @param v2 Numer wierzchołka docelowego [int]
 * @param weight Waga krawędzi [int]
 */
void IncidenceMatrix::addEdge(int edge_num, int v1, int v2, int weight)
{
    for (int v = 0; v < vertices_num; v++)
    {
        this->matrix[edge_num][v] = 0;
    }
    this->matrix[edge_num][v1] = -1 * weight;
    this->matrix[edge_num][v2] = weight;
    cout << "Poprawnie dodano krawędź (" << v1 << " " << v2 << ")"
         << " " << weight << "." << endl;
}

/**
 * Funkcja dodająca krawędź do grafu.
 * @param edge_num Numer krawędzi [int]
 * @return edge : Obiekt klasy IMEdge [IMEdge*]
 */
IMEdge *IncidenceMatrix::getEdge(int edge_num)
{
    int *row = matrix[edge_num];
    IMEdge *edge = new IMEdge();
    for (int v = 0; v < vertices_num; v++)
    {
        if (row[v] > 0)
        {
            edge->destination = v;
            edge->weight = row[v];
        }
        else if (row[v] < 0)
        {
            edge->source = v;
        }
    }
    return edge;
}

/**
 * Funkcja zwracająca tablicę wszystkich krawędzi.
 * @return edge_list: Lista wszystkich krawędzi w grafie [int**]
 */
int **IncidenceMatrix::getAllEdgesList()
{
    int **edge_list = new int *[edges_num];
    for (int e = 0; e < edges_num; e++)
    {
        IMEdge *edge = getEdge(e);
        int *temp = new int[3];
        temp[0] = edge->source;
        temp[1] = edge->destination;
        temp[2] = edge->weight;
        edge_list[e] = temp;
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
void IncidenceMatrix::readFromFile(string filepath)
{
    string path = filepath;
    fstream f;
    int source = 0;
    int destination = 0;
    int weight = 0;
    int i = 0;
    f.open(path);
    if (f.is_open())
    {
        f >> this->edges_num;
        f >> this->vertices_num;
        cout << "Liczba wierzchołków: " << this->vertices_num << endl;
        cout << "Liczba krawędzi: " << this->edges_num << endl;
        this->initMatrix();
        while (f >> source)
        {
            f >> destination;
            f >> weight;
            this->addEdge(i, source, destination, weight);
            i++;
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
 *  Funkcja zapełniająca macierz incydencji liczbami wygenerowanymi losowo
 *
 * @param vertices Liczba wierzchołków [int]
 * @param edges Liczba krawędzi [int]
 */
void IncidenceMatrix::generate(int vertices, int edges)
{
    this->setVerticesNum(vertices);
    this->setEdgesNum(edges);
    this->initMatrix();
    int ed = 0;
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
                this->addEdge(ed, v, numbers[vertices_num - 1], generate_random_number(20));
                ed++;
            }
            else
            {
                this->addEdge(ed, v, numbers[e], generate_random_number(20));
                ed++;
            }
        }
        edges -= edges_per_v;
    }
    for (int e = 0; e < edges; e++)
    {
        std::shuffle(numbers, numbers + vertices_num, gen);
        if (numbers[e] == vertices_num - 1)
        {
            this->addEdge(ed, vertices_num - 1, numbers[vertices_num - 1], generate_random_number(20));
            ed++;
        }
        else
        {
            this->addEdge(ed, vertices_num - 1, numbers[e], generate_random_number(20));
            ed++;
        }
    }
}

/**
 *  Funkcja wyświetlająca graf w postaci macierzy incydencji.
 */
void IncidenceMatrix::show()
{
    cout << "Krawędź ";
    for (int e = 0; e < edges_num; e++)
    {
        cout << "e" << e << " ";
    }
    cout << endl;
    for (int v = 0; v < vertices_num; v++)
    {
        cout << "V[" << v << "]     ";
        for (int e = 0; e < edges_num; e++)
        {
            cout << this->matrix[e][v] << " ";
        }
        cout << endl;
    }
}

// Desktruktor klasy IncidenceMatrix
IncidenceMatrix::~IncidenceMatrix()
{
    for (int e = 0; e < edges_num; e++)
    {
        delete[] matrix[e];
    }
    delete[] matrix;
    cout << "Poprawnie usunięto macierz." << endl;
}