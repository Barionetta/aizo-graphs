/**
 * Plik źródłowy zawierający główną pętle programu
 */

#include "app.h"

/**
 * Konstruktor klasy App
*/
App::App()
    : is_running_(false),
      is_matrix(true),
      state_(1)
{
    modes_menu_ = {make_pair(1, Menu::Entry("Przeprowadź testy\n", [this](){ this->set_state(2); })),
                   make_pair(2, Menu::Entry("Przeprowadź badania\n", [](){ Tester::testing(); })),
                   make_pair(3, Menu::Entry("Zakończ\n", [this](){ this->is_running_ = false; }))};

    graphs_menu_ = {make_pair(1, Menu::Entry("Macierz incydencji z pliku\n", [this](){ })),
                   make_pair(2, Menu::Entry("Macierz incydencji z losowymi danymi\n", [this](){ })),
                   make_pair(3, Menu::Entry("Lista sąsiedztwa z pliku\n", [this](){ })),
                   make_pair(4, Menu::Entry("Lista sąsiedztwa z losowymi danymi\n", [this](){ })),
                   make_pair(5, Menu::Entry("Zakończ\n", [this](){ this->is_running_ = false; }))};

    algorithms_menu_ = {make_pair(1, Menu::Entry("Minimalne drzewo spinające - Algorytm Prima\n", [this](){ })),
                        make_pair(2, Menu::Entry("Minimalne drzewo spinające - Algorytm Kruskala\n", [this](){ })),
                        make_pair(3, Menu::Entry("Najkrótsza ścieżka - Algorytm Dijikstry\n", [this](){ })),
                        make_pair(4, Menu::Entry("Najkrótsza ścieżka - Algorytm Bellmana-Forda\n", [this](){ })),
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
    cout << "Jakiej reprezentacji chcesz użyć?\n";
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
 * @param graph             Reprezentacja grafu                             [T]
 * @param graph_algorithmn  Algorytm, który ma być prezentowany na grafie   [function<void()>]
*/
template <typename T>
void App::perform_alogrithm(T graph, std::function<void()> graph_algorithmn)
{
    //graph_algorithmn(graph);
}

/*
*   Zdefiniowanie typów dla funkcji
*/
template void App::perform_alogrithm(IncidenceMatrix graph, std::function<void()> graph_algorithm);
template void App::perform_alogrithm(AdjacencyList graph, std::function<void()> graph_algorithm);