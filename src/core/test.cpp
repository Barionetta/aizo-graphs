/**
 * Plik źródłowy zawierający struktury i funkcje wykorzystywane do mierzenia czasu wykonywania algorytmów
 */

#include "test.h"

/**
 * Główna funkcja do testowania algorytmów
 */
void Tester::testing()
{
    unsigned int choice;
    do
    {
        std::cout << "Dla jakiej reprezentacji chcesz zrobić pomiary?\n";
        std::cout << "1 - Pomiary dla macierzy incydencji\n";
        std::cout << "2 - Pomiary dla listy sąsiedztwa\n";
        std::cin >> choice;
    } while (choice > 2 || choice < 1);
    
    if (choice == 1)        { std::cout << "Testowańsko dla macierzy\n"; }
    else if (choice == 2)   { std::cout << "Testowańsko dla listy\n"; }
    else { return; }
    
}

/**
 * Funkcja do pomiarów dla wybranego typu
 */
template <typename T>
void Tester::test_for_representation()
{

}

/**
 * Funkcja mierzenia pojedynczego pomiaru
 * 
 * @param graph              Reprezentacja grafu                            [T]
 * @param graph_algorithmn   Algorytm, który ma być prezentowany na grafie  [function<void()>]
 * @return calculated_time - Uśredniony czas wykonania algorytmu            [double]
*/
template <typename T>
double Tester::measure_time(T& graph, std::function<void()> graph_algorithmn)
{
    double calculated_time = 0;
    for (int t = 0; t < Tester::number_of_repeats; t++)
    {
        auto start = std::chrono::steady_clock::now();
        graph_algorithmn(graph);
        auto stop = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        calculated_time += duration.count();
    }
    return calculated_time /= Tester::number_of_repeats;
}