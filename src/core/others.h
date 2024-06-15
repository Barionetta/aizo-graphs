/**
 * Plik nagłówkowy pliku zawierającego funkcje pomocnicze
 */

#ifndef OTHERS_H
#define OTHERS_H
#include "graphs/graph.h"
#include "structures/array.h"
#include "structures/structures.h"

#include <fstream>
#include <iostream>
#include <random>
#include <string>

namespace Others
{
    // Funkcja do zamiany dwóch liczb miejscami
    template <typename T>
    void swap(T& num_1, T& num_2);
    // Funkcja sortująca daną tablicę
    template <typename T>
    void sort(Array<T>& array);
    // Funkcja do generacji liczby losowej z jakiegoś zakresu
    int generate_random_number(int down, int up);
    // Funkcja do wygenerowania tablicy liczb losowych
    void generate_random_graph(Graph& graph, int vertices_num, int density);
    // Funkcja do wygenerowania tablicy z pliku tekstowego
    void read_graph_from_file(Graph& graph, std::string& filepath);
    // Funkcja do zapisania wyników pomiarów do pliku .csv
    void save_experiment_to_file(bool is_matrix, unsigned int algorithm_code, int vertices_num, double saved_times[]);
};

#endif