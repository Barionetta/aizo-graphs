/**
 * Plik nagłówkowy pliku zawierającego kod klasy App odpowiedzialnej za sterowanie programem
 */

#ifndef APP_H
#define APP_H
#include "menu.h"
#include "test.h"
#include "algorithms/mst.h"
#include "algorithms/shortest_path.h"
#include "graphs/adjacency_list.h"
#include "graphs/incidence_matrix.h"

#include <iostream>
#include <string>

using std::cout, std::cin, std::make_pair;

class App
{
public:
    // Konstruktor klasy App
    App();
    // Destruktor klasy App
    ~App() = default;
    // Funkcja uruchamiająca aplikację
    void run();

private:
    bool is_running_;                                               // Czy aplikacja jest uruchomiona                       [bool]
    unsigned int state_;                                            // Stan aplikacji                                       [unsigned int]
    Menu::MenuEntries modes_menu_, graphs_menu_, algorithms_menu_;  // Menu aplikacji                                       [MenuEntries]
    IncidenceMatrix demo_incidence_matrix_;                         // Demonstracyjna macierz incydencji                    [Array<int>]
    AdjacencyList demo_adjacency_list_;                              // Demonstracyjna lista sąsiedztwa                      [Array<float>]

    // Funkcja ustawiająca stan aplikacji
    void set_state(unsigned int state);
    // Funkcja wykonująca stan wyboru trybu
    void perform_mode_selection();
    // Funkcja wykonująca stan tworzenia grafu
    void perform_graph_creation();
    // Funkcja wykonująca stan wyboru algorytmu
    void perform_algorithm_selection();
    // Funkcja wykonująca wybrany algorytm
    void perform_alogrithm(unsigned int algorithm_number);
};

#endif