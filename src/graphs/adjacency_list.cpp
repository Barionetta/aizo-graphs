/**
 * Plik źródłowy zawierającegy implementację struktury Edge,
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
 *  vertices_num_    [int]       - ilość wierzchołków
 *  edges_num_       [int]       - ilość krawędzi
 *  vertices        [EdgeList*] - listy dla każdego wierzchołka
 */

#include "adjacency_list.h"

using namespace std;

/**
 * Konstruktor klasy AdjacencyList
*/
AdjacencyList::AdjacencyList()
    : vertices_num_(0),
      edges_num_(0),
      vertices_(nullptr)
{
    this->init_array();
    cout << "Poprawnie zainicjalizowano listę sąsiedztwa." << endl;
}

/**
 * Destruktor klasy AdjacencyList
*/
AdjacencyList::~AdjacencyList()
{
    for (int v = 0; v < vertices_num_; v++)
    {
        Edge *temp = this->vertices_[v].head;
        while (temp)
        {
            temp = this->vertices_[v].head->next;
            delete this->vertices_[v].head;
            this->vertices_[v].head = temp;
        }
        delete this->vertices_[v].head;
    }
    delete[] vertices_;
    cout << "Poprawnie usunięto listę." << endl;
}

/**
 * Funkcja ustawiająca liczbę wierzchołków.
 * @param vertices Liczba wierzchołków grafu [int]
 */
void AdjacencyList::set_vertices_num(int vertices)
{
    this->vertices_num_ = vertices;
}

/**
 * Funkcja ustawiająca liczbę krawędzi.
 * @param edges Liczba krawędzi grafu [int]
 */
void AdjacencyList::set_edges_num(int edges)
{
    this->edges_num_ = edges;
}

/**
 * Funkcja zwracająca liczbę wierzchołków w grafie.
 * @return vertices_num_:  Liczba wierzchołków grafu [int]
 */
int AdjacencyList::get_vertices_num() const
{
    return this->vertices_num_;
}

/**
 * Funkcja zwracająca liczbę krawędzi w grafie.
 * @return edges_num_:  Liczba krawędzi grafu [int]
 */
int AdjacencyList::get_edges_num() const
{
    return this->vertices_num_;
}

/**
 * Funkcja zwracająca tablicę list krawędzi.
 * @return vertices: tablica list krawędzi [EdgeList*]
 */
EdgeList *AdjacencyList::get_vertices()
{
    return this->vertices_;
}

/**
 * Funkcja zwracająca tablicę wszystkich krawędzi.
 * @return edge_list: Lista wszystkich krawędzi w grafie [int**]
 */
int **AdjacencyList::get_all_edges_list()
{
    int **edge_list = new int *[edges_num_];
    int e = 0;
    for (int v = 0; v < vertices_num_; v++)
    {
        Edge *temp = this->vertices_[v].head;
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
 * Funkcja inicjująca tablicę.
 */
void AdjacencyList::init_array()
{
    this->vertices_ = new EdgeList[vertices_num_];
    for (int i = 0; i < this->vertices_num_; i++)
    {
        this->vertices_[i].head = nullptr;
        this->vertices_[i].v_num = i;
    }
}

/**
 * Funkcja dodająca krawędź do grafu.
 * @param source        Numer wierzchołka startowego    [int]
 * @param destination   Numer wierzchołka docelowego    [int]
 * @param weight        Waga krawędzi                   [int]
 */
void AdjacencyList::add_edge(int source, int destination, int weight)
{
    EdgeList *sourceVertex = find_vertex(source);

    Edge *newEdge = new Edge();
    newEdge->destination = destination;
    newEdge->weight = weight;
    newEdge->next = sourceVertex->head;
    sourceVertex->head = newEdge;
    cout << "Poprawnie dodano krawędź." << endl;
}

/**
 * Funkcja zwracająca listę krawędzi dla jednego wierzchołka.
 * @param vertex_num Numer wierzchołka [int]
 * @return vertices[vertex_num]: Lista krawędzi wierzchołka [EdgeList*]
 */
EdgeList *AdjacencyList::find_vertex(int vertex_num)
{
    return &vertices_[vertex_num];
}

/**
 *  Funkcja wyświetlająca graf w postaci listy sąsiedztwa.
 */
void AdjacencyList::print() const
{
    for (int v = 0; v < vertices_num_; v++)
    {
        cout << "Wierzchołek [" << v << "] -> |  ";
        Edge *temp = this->vertices_[v].head;
        while (temp)
        {
            cout << temp->destination << "/" << temp->weight << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * Funkcja wczytująca graf z pliku tekstowego.
 * Plik tekstowy musi znajdować się w folderze "test" w tym samym folderze,
 * co główny plik programu!
 *
 * @param filepath Nazwa pliku, z którego wczytywane są krawędzie [string]
 */
void AdjacencyList::read_from_file(string filepath)
{
    string path = filepath;
    fstream f;
    int source = 0;
    int destination = 0;
    int weight = 0;
    f.open(path);
    if (f.is_open())
    {
        f >> this->edges_num_;
        f >> this->vertices_num_;
        cout << "Liczba wierzchołków: " << this->vertices_num_ << endl;
        cout << "Liczba krawędzi: " << this->edges_num_ << endl;
        while (f >> source)
        {
            f >> destination;
            f >> weight;
            this->add_edge(source, destination, weight);
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
    this->set_vertices_num(vertices);
    this->set_edges_num(edges);
    int *numbers = new int[vertices];
    for (int i = 0; i < vertices; i++)
    {
        numbers[i] = i;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    int edges_per_v = static_cast<int>(edges / vertices);

    for (int v = 0; v < vertices_num_ - 1; v++)
    {
        std::shuffle(numbers, numbers + vertices_num_, gen);
        for (int e = 0; e < edges_per_v; e++)
        {
            if (numbers[e] == v)
            {
                this->add_edge(v, numbers[vertices_num_ - 1], Others::generate_random_number(1, 20));
            }
            else
            {
                this->add_edge(v, numbers[e], Others::generate_random_number(1, 20));
            }
        }
        edges -= edges_per_v;
    }
    for (int e = 0; e < edges; e++)
    {
        std::shuffle(numbers, numbers + vertices_num_, gen);
        if (numbers[e] == vertices_num_ - 1)
        {
            this->add_edge(vertices_num_ - 1, numbers[vertices_num_ - 1], Others::generate_random_number(1, 20));
        }
        else
        {
            this->add_edge(vertices_num_ - 1, numbers[e], Others::generate_random_number(1, 20));
        }
    }
}