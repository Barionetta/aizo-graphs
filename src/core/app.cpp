/**
 * Plik źródłowy zawierający główną pętle programu
 */

#include "app.h"

/**
 * Konstruktor klasy App
*/
App::App()
    : is_running_(false),
      state_(1)
{
    modes_menu_ = {make_pair(1, Menu::Entry("Przeprowadź testy\n", [this](){ this->set_state(2); })),
                   make_pair(2, Menu::Entry("Przeprowadź badania\n", [](){ Tester::testing(); })),
                   make_pair(3, Menu::Entry("Zakończ\n", [this](){ this->is_running_ = false; }))};

    graphs_menu_ = {make_pair(1, Menu::Entry("Wygeneruj graf z pliku\n", [this](){ cout << "Podaj nazwę pliku: \n"; std::string filename; cin >> filename; Others::read_graph_from_file(demo_incidence_matrix_, filename); demo_incidence_matrix_.print();
                                                                                    Others::read_graph_from_file(demo_adjacency_list_, filename); demo_adjacency_list_.print();})),
                   make_pair(2, Menu::Entry("Wygeneruj graf z losowymi danymi\n", [this](){ int v_num; float density; cout << "Ile wierzchołków ma mieć graf?\n"; cin >> v_num; cout << "Jak gęsty ma być graf?\n"; cin >> density; Others::generate_random_graph(demo_incidence_matrix_, v_num, density); demo_incidence_matrix_.print();
                                                                                            Others::generate_random_graph(demo_adjacency_list_, v_num, density); demo_adjacency_list_.print();})),
                   make_pair(3, Menu::Entry("Zakończ\n", [this](){ this->is_running_ = false; }))};

    algorithms_menu_ = {make_pair(1, Menu::Entry("Minimalne drzewo spinające - Algorytm Prima\n", [this](){perform_alogrithm(1);})),
                        make_pair(2, Menu::Entry("Minimalne drzewo spinające - Algorytm Kruskala\n", [this](){perform_alogrithm(4);})),
                        make_pair(3, Menu::Entry("Najkrótsza ścieżka - Algorytm Dijikstry\n", [this](){perform_alogrithm(2);})),
                        make_pair(4, Menu::Entry("Najkrótsza ścieżka - Algorytm Bellmana-Forda\n", [this](){perform_alogrithm(3);})),
                        make_pair(5, Menu::Entry("Wygeneruj nowy graf\n", [this](){ this->set_state(2); })),
                        make_pair(6, Menu::Entry("Zakończ\n", [this](){ this->is_running_ = false; }))};
}

/**
 * Funkcja uruchamiająca aplikację
*/
void App::run()
{
    this->is_running_ = true;
    cout << "Algorytmy i Złożoność Obliczeniowa Projekt 2 - Algorytmy Grafowe\n";
    do
    {
        switch(this->state_) {
            case 1:
                perform_mode_selection();
                break;
            case 2:
                perform_graph_creation();
                break;
            case 3:
                perform_algorithm_selection();
                break;
            default:
                cout << "Nieobsługiwany stan!\n";
        }
    } while (this->is_running_);
}

/**
 * Funkcja ustawiająca stan aplikacji
 * 
 * @param state Numer stanu aplikacji [unsigned int]
*/
void App::set_state(unsigned int state)
{
    this->state_ = state;
}

/**
 * Funkcja wykonująca stan wyboru trybu
*/
void App::perform_mode_selection()
{
    cout << "Co chcesz zrobić?\n";
    Menu::get_entry(this->modes_menu_);
}

/**
 * Funkcja wykonująca stan tworzenia grafu
*/
void App::perform_graph_creation()
{
    cout << "Jak chcesz wygenerować graf?\n";
    Menu::get_entry(this->graphs_menu_);
    this->set_state(3);
}

/**
 * Funkcja wykonująca stan wyboru algorytmu
*/
void App::perform_algorithm_selection()
{
    cout << "Jaki algorytm chcesz zaprezentować?\n";
    Menu::get_entry(this->algorithms_menu_);
}

/**
 * Funkcja wykonująca wybrany algorytm
 * 
 * @param algorithm_number  Numer algorytmu [int]
*/
void App::perform_alogrithm(unsigned int algorithm_number)
{
    switch(algorithm_number) {
        case 1: {
            cout << "Przeprowadzam algorytm Prima...\n";
            MST::MinimalSpanningTree tree_m = MST::prim(demo_incidence_matrix_);
            cout << "Wyniki dla reprezentacji macierzowej: \n";
            tree_m.print();
            cout << "Wyniki dla reprezentacji listowej: \n";
            MST::MinimalSpanningTree tree_a = MST::prim(demo_adjacency_list_);
            tree_a.print();
            break; }
        case 2: {
            int source;
            cout << "Z którego wierzchołka poprowadzić ścieżki?\n";
            cin >> source;
            cout << "Przeprowadzam algorytm Dijkstry...\n";
            ShortestPath::Path path_m = ShortestPath::dijkstra(demo_incidence_matrix_, source);
            cout << "Wyniki dla reprezentacji macierzowej: \n";
            path_m.print();
            cout << "Wyniki dla reprezentacji listowej: \n";
            ShortestPath::Path path_a = ShortestPath::dijkstra(demo_adjacency_list_, source);
            path_a.print();
            break; }
        case 3: {
            int source;
            cout << "Z którego wierzchołka poprowadzić ścieżki?\n";
            cin >> source;
            cout << "Przeprowadzam algorytm Bellmana-Forda...\n";
            ShortestPath::Path path_m = ShortestPath::bellman_ford(demo_incidence_matrix_, source);
            cout << "Wyniki dla reprezentacji macierzowej: \n";
            path_m.print();
            cout << "Wyniki dla reprezentacji listowej: \n";
            ShortestPath::Path path_a = ShortestPath::bellman_ford(demo_adjacency_list_, source);
            path_a.print();
            break; }
        case 4: {
            cout << "Przeprowadzam algorytm Kruskala...\n";
            MST::MinimalSpanningTree tree_m = MST::kruskal(demo_incidence_matrix_);
            cout << "Wyniki dla reprezentacji macierzowej: \n";
            tree_m.print();
            cout << "Wyniki dla reprezentacji listowej: \n";
            MST::MinimalSpanningTree tree_a = MST::kruskal(demo_adjacency_list_);
            tree_a.print();
            break; }
        default: {
            cout << "Nieprawidłowa nazwa algorytmu\n";
            break; }
    }
}