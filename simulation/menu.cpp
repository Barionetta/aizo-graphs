/**
 * Plik źródłowy zawierający główną pętle symulacji
 */
#include "menu.h"
#include "incidence_matrix_sub_menu.h"
#include "adjacency_list_sub_menu.h"
#include <iostream>
using namespace std;

void showRepresentations()
{
    cout << "Jakiej reprezentacji chcesz użyć?\n";
    cout << "1 - Macierz incydencji\n";
    cout << "2 - Lista sąsiedztwa\n";
    cout << "0 - Zakończ program\n";
}

void loop()
{
    cout << "Algorytmy i Złożoność Obliczeniowa Projekt 2 - Algorytmy Grafowe\n";
    short int representation;
    showRepresentations();
    cin >> representation;
    while (representation < 0 || representation > 2)
    {
        cout << "Wprowadź poprawną opcję.\n";
        cin >> representation;
    }
    switch (representation)
    {
    case 1:
    {
        matrixSubMenu();
        break;
    }
    case 2:
    {
        listSubMenu();
        break;
    }
    case 0:
    {
        return;
        break;
    }
    default:
    {
        break;
    }
    }
    return;
}
