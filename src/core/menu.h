/**
 * Plik nagłówkowy pliku zawierającego struktury i funkcje do obsługi menu
 */

#ifndef MENU_H
#define MENU_H

#include <functional>
#include <iostream>
#include <map>
#include <string>

namespace Menu
{
    typedef std::function<void()> entryFunction;

    struct Entry
    {
        Entry(std::string d, entryFunction f) : description(d), function(f) {};
        std::string description;
        entryFunction function;
    };

    typedef std::map<unsigned int, Entry> MenuEntries;

    // Funkcja wyświetlająca mapę struktur Entry
    void show(MenuEntries menu);
    // Funkcja wykonująca wybraną z MenuEntries funkcję
    void getEntry(MenuEntries menu);

};

#endif