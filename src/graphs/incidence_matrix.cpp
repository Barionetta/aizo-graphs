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
 *  vertices_num_   [int]   - liczba wierzchołków
 *  edges_num_      [int]   - liczba krawędzi
 *  matrix_         [int**] - tablicę dwuwymiarową o rozmiarach v_num x e_num
 */

#include "incidence_matrix.h"

/**
 * Konstruktor klasy IncidenceMatrix
*/
IncidenceMatrix::IncidenceMatrix()
    : vertices_num_(0),
      edges_num_(0),
      matrix_(nullptr)
{
    this->init_matrix();
    std::cout << "Poprawnie zainicjalizowano macierz incydencji." << std::endl;
}

/**
 * Desktruktor klasy IncidenceMatrix
*/
IncidenceMatrix::~IncidenceMatrix()
{
    for (int e = 0; e < edges_num_; e++)
    {
        delete[] matrix_[e];
    }
    delete[] matrix_;
    std::cout << "Poprawnie usunięto macierz." << std::endl;
}

/**
 * Funkcja ustawiająca liczbę wierzchołków.
 * @param vertices Liczba wierzchołków grafu [int]
 */
void IncidenceMatrix::set_vertices_num(int vertices)
{
    this->vertices_num_ = vertices;
}

/**
 * Funkcja ustawiająca liczbę krawędzi.
 * @param edges Liczba krawędzi grafu [int]
 */
void IncidenceMatrix::set_edges_num(int edges)
{
    this->edges_num_ = edges;
}

/**
 * Funkcja zwracająca liczbę wierzchołków w grafie.
 * @return vertices_num_:  Liczba wierzchołków grafu [int]
 */
int IncidenceMatrix::get_vertices_num() const
{
    return this->vertices_num_;
}

/**
 * Funkcja zwracająca liczbę krawędzi w grafie.
 * @return edges_num:  Liczba krawędzi grafu [int]
 */
int IncidenceMatrix::get_edges_num() const
{
    return this->edges_num_;
}

/**
 * Funkcja dodająca krawędź do grafu.
 * @param edge_num Numer krawędzi [int]
 * @return edge : Obiekt klasy IMEdge [IMEdge*]
 */
IMEdge *IncidenceMatrix::get_edge(int edge_num)
{
    int *row = matrix_[edge_num];
    IMEdge *edge = new IMEdge();
    for (int v = 0; v < vertices_num_; v++)
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
int **IncidenceMatrix::get_all_edges_list()
{
    int **edge_list = new int *[edges_num_];
    for (int e = 0; e < edges_num_; e++)
    {
        IMEdge *edge = get_edge(e);
        int *temp = new int[3];
        temp[0] = edge->source;
        temp[1] = edge->destination;
        temp[2] = edge->weight;
        edge_list[e] = temp;
    }
    return edge_list;
}

/**
 * Funkcja inicjująca macierz
 */
void IncidenceMatrix::init_matrix()
{
    this->matrix_ = new int *[edges_num_];
    for (int e = 0; e < edges_num_; e++)
    {
        this->matrix_[e] = new int[vertices_num_];
    }
}

/**
 * Funkcja dodająca krawędź do grafu.
 * @param edge_num  Numer krawędzi                  [int]
 * @param v1        Numer wierzchołka startowego    [int]
 * @param v2        Numer wierzchołka docelowego    [int]
 * @param weight    Waga krawędzi                   [int]
 */
void IncidenceMatrix::add_edge(int edge_num, int v1, int v2, int weight)
{
    for (int v = 0; v < vertices_num_; v++)
    {
        this->matrix_[edge_num][v] = 0;
    }
    this->matrix_[edge_num][v1] = -1 * weight;
    this->matrix_[edge_num][v2] = weight;
    std::cout << "Poprawnie dodano krawędź (" << v1 << " " << v2 << ")"
         << " " << weight << "." << std::endl;
}

/**
 *  Funkcja wyświetlająca graf w postaci macierzy incydencji.
 */
void IncidenceMatrix::print() const
{
    std::cout << "Krawędź ";
    for (int e = 0; e < edges_num_; e++)
    {
        std::cout << "e" << e << " ";
    }
    std::cout << std::endl;
    for (int v = 0; v < vertices_num_; v++)
    {
        std::cout << "V[" << v << "]     ";
        for (int e = 0; e < edges_num_; e++)
        {
            std::cout << this->matrix_[e][v] << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * Funkcja wczytująca graf z pliku tekstowego.
 * Plik tekstowy musi znajdować się w folderze "test" w tym samym folderze,
 * co główny plik programu!
 *
 * @param filepath Nazwa pliku, z którego wczytywane są krawędzie [string]
 */
void IncidenceMatrix::read_from_file(std::string filepath)
{
    std::string path = filepath;
    std::fstream f;
    int source = 0;
    int destination = 0;
    int weight = 0;
    int i = 0;
    f.open(path);
    if (f.is_open())
    {
        f >> this->edges_num_;
        f >> this->vertices_num_;
        std::cout << "Liczba wierzchołków: " << this->vertices_num_ << std::endl;
        std::cout << "Liczba krawędzi: " << this->edges_num_ << std::endl;
        while (f >> source)
        {
            f >> destination;
            f >> weight;
            this->add_edge(i, source, destination, weight);
            i++;
        }
        f.close();
        std::cout << "Poprawnie wczytano graf ze ścieżki " << path << " \n";
    }
    else
    {
        std::cout << "Nie udało się otworzyć pliku ze ścieżki " << path << " \n";
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
    this->set_vertices_num(vertices);
    this->set_edges_num(edges);
    int ed = 0;
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
                this->add_edge(ed, v, numbers[vertices_num_ - 1], Others::generate_random_number(1, 20));
                ed++;
            }
            else
            {
                this->add_edge(ed, v, numbers[e], Others::generate_random_number(1, 20));
                ed++;
            }
        }
        edges -= edges_per_v;
    }
    for (int e = 0; e < edges; e++)
    {
        std::shuffle(numbers, numbers + vertices_num_, gen);
        if (numbers[e] == vertices_num_ - 1)
        {
            this->add_edge(ed, vertices_num_ - 1, numbers[vertices_num_ - 1], Others::generate_random_number(1, 20));
            ed++;
        }
        else
        {
            this->add_edge(ed, vertices_num_ - 1, numbers[e], Others::generate_random_number(1, 20));
            ed++;
        }
    }
}