/**
 * Plik nagłówkowy pliku zawierającego struktury i funkcje wykorzystywane do mierzenia czasu wykonywania algorytmów
 */

#ifndef TEST_H
#define TEST_H
#include "algorithms/mst.h"
#include "algorithms/shortest_path.h"
#include "graphs/incidence_matrix.h"
#include "graphs/adjacency_list.h"
#include "structures/structures.h"

#include <chrono>
#include <functional>
#include <map>
#include <iostream>

using std::cout, std::cin;

namespace Tester
{
    // Główna funkcja do testowania algorytmów
    void testing();
    // Funkcja do pomiarów dla wybranej reprezentacji
    void test_for_representation(bool is_matrix);
    // Funkcja mierzenia pojedynczego pomiaru
    template <typename T>
    double measure_time(T& graph, std::function<void()> graph_algorithmn);

    // Stałe
    constexpr int number_of_sizes = 7;
    constexpr int number_of_repeats = 100;
    constexpr int vertices_numbers[7] = {10, 20, 30, 40, 50, 60, 70};
}

#endif