/**
 * Lista jednokierunkowa
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "structures.h"

#include <algorithm>
#include <iostream>
#include <memory>

class LinkedList
{
public:
    // Konstruktor klasy LinkedList
    LinkedList();
    // Konstruktor kopiujący klasy LinkedList
    LinkedList(const LinkedList& list);
    // Konstruktor przenoszenia klasy LinkedList
    LinkedList(LinkedList&& list);
    // Operator kopiowania
    LinkedList& operator=(const LinkedList& list);
    // Operator przenoszenia
    LinkedList& operator=(LinkedList&& list);
    // Destruktor klasy LinkedList
    ~LinkedList();
    
    // Funkcja wyświetlająca listę
    void print() const;
    // Funkcja znajdująca klucz zadanego elementu
    int find_key(const int &vertex_id);
    // Funkcja dodająca element na początku listy
    void push_front(const int &vertex_id, const int &weight);
    // Funkcja usuwająca element z początka listy
    void pop_front();

private:
    struct Node
    {
        Structures::Vertex vertex;  // Wierzchołek                  [Structures::Vertex]
        std::unique_ptr<Node> next; // Następna krawędź             [int*]
        
        Node(Structures::Vertex vertex,
            std::unique_ptr<Node>&& next = nullptr)
            : vertex{vertex},
              next{std::move(next)}
            {}

        ~Node() = default;
    };
    std::unique_ptr<Node> head_;   // Wskaźnik na pierwszy element [Node*]
};

#endif