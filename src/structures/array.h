/**
 * Plik nagłówkowy pliku zawierającego implementację klasy Array
 *
 * Klasa Array jest generyczną tablicą dynamiczną.
 * Znajdują się w niej podstawowe funkcje umożliwiające dodawanie,
 * usuwanie, wyświetlanie i wyszukiwanie jej elementów.
 */

#ifndef ARRAY_H
#define ARRAY_H
#include "linked_list.h"
#include "structures.h"

#include <algorithm>
#include <iostream>
#include <memory>

template <typename T>
class Array
{
public:
    // Domyślny konstruktor klasy Array
    Array();
    // Konstruktor kopiujący klasy Array
    Array(const Array<T>& array);
    // Konstruktor przenoszenia klasy Array
    Array(Array<T>&& array);
    // Operator dostępu
    T& operator[] (int i);
    // Operator kopiowania
    Array& operator=(const Array& array);
    // Operator przenoszenia
    Array& operator=(Array&& array);
    // Destruktor klasy Array
    ~Array() = default;

    // Funkcja zwracająca długość tablicy
    int get_size() const;
    // Funkcja ustawiająca długość tablicy
    void set_size(const int& size);
    // Funkcja wyświetlająca zawartość tablicy
    void print() const;
    // Funkcja dodająca nowy element na koniec istniejącej tablicy
    void push_back(const T& value);
    // Funkcja usuwająca element z końca tablicy
    void pop_back();
    // Funkcja modyfikująca wartość na wybranej pozycji
    void insert(const T& value, const int& position);

private:
    int size_;                      // Obecny rozmiar tablicy [int]
    int max_size_;                  // Maksymalna pojemność tablicy [int]
    std::unique_ptr<T[]> data_;     // Zawartość tablicy [T*]
};

#endif