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
    
    if (choice == 1)        { test_for_representation(true); }
    else if (choice == 2)   { test_for_representation(false); }
    else { return; }
}

/**
 * Funkcja do pomiarów dla wybranego typu
 */
void Tester::test_for_representation(bool is_matrix)
{
    std::map<unsigned int, std::function<void(Graph&)>> algorithms_map;
    algorithms_map[1] = MST::prim;
    algorithms_map[2] = MST::kruskal;
    algorithms_map[3] = ShortestPath::dijkstra;
    algorithms_map[4] = ShortestPath::bellman_ford;

    for (auto const& [key, algorithm] : algorithms_map)
    {
        for (int i = 0; i < Tester::number_of_sizes; i++)
        {
            std::cout << "Pomiary dla rozmiaru " << Tester::vertices_numbers[i] << "\n";
            double times[4];

            Graph graph;
            if (is_matrix) { graph = IncidenceMatrix(); }
            else { graph = AdjacencyList(); }

            /*      25%      */
            Others::generate_random_graph(graph, vertices_numbers[i], 0.25);
            times[0] = measure_time(graph, algorithm);

            /*      50%     */
            Others::generate_random_graph(graph, vertices_numbers[i], 0.50);
            times[1] = measure_time(graph, algorithm);

            /*      75%     */
            Others::generate_random_graph(graph, vertices_numbers[i], 0.75);
            times[2] = measure_time(graph, algorithm);

            /*      99%     */
            Others::generate_random_graph(graph, vertices_numbers[i], 0.99);
            times[3] = measure_time(graph, algorithm);
            
            Others::save_experiment_to_file(true, key, Tester::vertices_numbers[i], times);
        }
    }
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