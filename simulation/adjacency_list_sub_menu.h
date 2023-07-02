/**
 * Plik nagłówkowy pliku zawierający podmenu dla klasy AdjacencyList
 */
#ifndef ADJACENCY_LIST_SUB_MENU_H
#define ADJACENCY_LIST_SUB_MENU_H
#include "generator.h"
#include "representations/adjacency_list.h"
#include "algorithms/minimal_spanning_tree.h"
#include "algorithms/shortest_path.h"

// Główne menu klasy
void listSubMenu();
// Funkcja wyświetlająca opcje dla zadań
void listDisplayTaskOptions();
// Funkcja wyświetlająca opcje dla reprezentacji
void listDisplayAlgorithmsOptions();
// Funkcja wyświetlająca opcje wczytania z pliku
void listDisplayFileOptions();
// Menu testowe klasy
void listTestSubMenu();
// Menu do badań klasy
void listRecordSubMenu();

#endif