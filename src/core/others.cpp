/**
 * Plik źródłowy zawierający funkcje pomocnicze
 */

#include "others.h"

// Generator
std::random_device rd;
std::mt19937 gen(rd());

/**
 * Funkcja do zamiany dwóch liczb miejscami
 * 
 * @param num_1 Pierwsza liczba do zamiany [T]
 * @param num_2 Druga liczba do zamiany [T]
*/
template <typename T>
void Others::swap(T& num_1, T& num_2)
{
    T temp = num_1;
    num_1 = num_2;
    num_2 = temp;
}

/**
 * Funkcja do generacji liczby losowej z jakiegoś zakresu
 * 
 * @param down Dolna granica zakresu [int]
 * @param up Górna granica zakresu [int]
*/
int Others::generate_random_number(int down, int up)
{
    std::uniform_int_distribution<> distr(down ,up);
    return (int)distr(gen);
}

/**
 * Funkcja do zapisania wyników pomiarów do pliku .csv
 *
 * @param is_matrix         Czy pomiary były dla macierzy incydencji    [bool]
 * @param algorithm_code    Kod algorytmu                               [unsigned int]
 * @param vertices_num      Liczba wierzchołków grafu                   [int]
 * @param saved_times       Tablica z pomiarami, jakie należy zapisać   [double[]]
 */
void Others::save_experiment_to_file(bool is_matrix, unsigned int algorithm_code, int vertices_num, double saved_times[])
{
    std::string path;
    if(is_matrix) { path = "../output/incidence_matrix.csv"; }
    else { path = "../output/adjacency_list.csv"; }

    std::string algorithm_name;
    switch (algorithm_code)
    {
    case 1: algorithm_name = "mst_prim"; break;
    case 2: algorithm_name = "mst_kruskal"; break;
    case 3: algorithm_name = "sp_dijikstra"; break;
    case 4: algorithm_name = "sp_bellman_ford"; break;
    default: break;
    }

    std::ofstream fout;
    fout.open(path, std::ios_base::out | std::ios::app);
    if (!fout.is_open())
    {
        std::cout << " Nie udało się otworzyć pliku\n";
        return;
    }
    else
    {
        fout << algorithm_name << "," << vertices_num << ",20%," << saved_times[0] << std::endl;
        fout << algorithm_name << "," << vertices_num << ",40%," << saved_times[1] << std::endl;
        fout << algorithm_name << "," << vertices_num << ",60%," << saved_times[2] << std::endl;
        fout << algorithm_name << "," << vertices_num << ",80%," << saved_times[3] << std::endl;
        fout << algorithm_name << "," << vertices_num << ",100%," << saved_times[3] << std::endl;
    }
    std::cout << " Poprawnie zapisano dane do pliku\n";
    fout.close();
}

/*
*   Zdefiniowanie typów dla funkcji
*/
template void Others::swap(int& num_1, int& num_2);
template void Others::swap(Structures::Vertex& num_1, Structures::Vertex& num_2);