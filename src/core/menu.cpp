/**
 * Plik źródłowy zawierający struktury i funkcje do obsługi menu
 */

#include "menu.h"

/**
 * Funkcja wyświetlająca mapę struktur Entry
 * 
 * @param menu Menu, które jest wyświetlane [MenuEntries]
*/
void Menu::show(MenuEntries menu)
{
    for (auto const& [key, label] : menu)
    {
        std::cout << key << " - " << label.description;
    }
}

/**
 * Funkcja wykonująca wybraną z MenuEntries funkcję
 * 
 * @param menu Menu, z którego wykonywana jest funkcja [MenuEntries]
*/
void Menu::getEntry(MenuEntries menu)
{
    show(menu);
    unsigned int choice;
    std::cin >> choice;

    try
    {
        Entry entry = menu.at(choice);
        (entry.function)();
    }
    catch(std::out_of_range& e)
    {
        std::cout << "Niepoprawny wybór\n";
    }
}