/**
 * Plik nagłówkowy pliku zawierający podmenu dla klasy IncidenceMatrix
 */
#ifndef INCIDENCE_MATRIX_SUB_MENU_H
#define INCIDENCE_MATRIX_SUB_MENU_H
#include "generator.h"
#include "representations/incidence_matrix.h"
#include "algorithms/minimal_spanning_tree.h"
#include "algorithms/shortest_path.h"

// Główne menu klasy
void matrixSubMenu();
// Funkcja wyświetlająca opcje dla zadań
void matrixDisplayTaskOptions();
// Funkcja wyświetlająca opcje dla macierzy
void matrixDisplayAlgorithmsOptions();
// Funkcja wyświetlająca opcje wczytania z pliku
void matrixDisplayFileOptions();
// Menu testowe macierzy
void matrixTestSubMenu();
// Menu do badań macierzy
void matrixRecordSubMenu();

#endif