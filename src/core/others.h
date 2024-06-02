/**
 * Plik nagłówkowy pliku zawierającego funkcje pomocnicze
 */

#ifndef OTHERS_H
#define OTHERS_H
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
    // Funkcja do generacji liczby losowej z jakiegoś zakresu
    int generate_random_number(int down, int up);
    // Funkcja do zapisania wyników pomiarów do pliku .csv
    void save_experiment_to_file(bool is_matrix, unsigned int algorithm_code, int vertices_num, double saved_times[]);
};

#endif