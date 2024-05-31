/**
 * Plik nagłówkowy pliku zawierającego struktury i funkcje wykorzystywane do mierzenia czasu wykonywania algorytmów
 */

#ifndef TEST_H
#define TEST_H

#include <functional>
#include <iostream>

using std::cout, std::cin;

namespace Tester
{
    // Główna funkcja do testowania algorytmów
    void testing();
    // Funkcja do pomiarów dla wybranej reprezentacji
    template <typename T>
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