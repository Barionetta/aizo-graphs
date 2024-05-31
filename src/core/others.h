/**
 * Plik nagłówkowy pliku zawierającego funkcje pomocnicze
 */

#ifndef OTHERS_H
#define OTHERS_H

#include <fstream>
#include <iostream>
#include <random>
#include <string>

namespace Others
{
    // Funkcja do zamiany dwóch liczb miejscami
    void swap(int& num_1, int& num_2);
    // Funkcja do generacji liczby losowej z jakiegoś zakresu
    int generate_random_number(int down, int up);
    // Funkcja do zapisania wyników pomiarów do pliku .csv
    void save_experiment_to_file(bool is_matrix, unsigned int algorithm_code, int vertices_num, double saved_times[]);
};

#endif