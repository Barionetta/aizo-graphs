/**
 * Plik ze strukturami pomocniczymi
 * 
 */

#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iostream>

namespace Structures
{
    struct Vertex
    {
        int vertex_id;  // ID wierzchołka                           [int]
        int key;        // Klucz wierzchołka (dystans/waga/stopień) [int]

        // Konstruktor domyślny
        Vertex() = default;
        // Drugi konstruktor
        Vertex(int vertex_id, int key): vertex_id{vertex_id}, key{key} {}
        // Operator porównania
        bool operator==(const Vertex &vertex)
        {
            if(vertex_id == vertex.vertex_id && key == vertex.key) { return true; }
            return false;
        }
        // Operator >
        bool operator>(const Vertex &vertex) const
        {
            return key > vertex.key;
        }
        // Operator <
        bool operator<(const Vertex &vertex) const
        {
            return key < vertex.key;
        }
        // Desktruktor
        ~Vertex() = default;
        // Funkcja do wyświetlania struktury
        void print() { std::cout << "ID: " << vertex_id << " Key: " << key << "\n"; };
    };

    struct Edge
    {
        int source_id;      // ID wierzchołka startowego    [int]
        int destination_id; // ID wierzchołka końcowego     [int]
        int weight;         // Waga krawędzi                [int]

        // Konstruktor domyślny
        Edge() = default;
        // Drugi konstruktor
        Edge(int source_id, int destination_id, int weight)
            : source_id{source_id},
              destination_id{destination_id},
              weight(weight)
              {}
        // Operator porównania
        bool operator==(const Edge &edge)
        {
            if(source_id == edge.source_id &&
               destination_id == edge.destination_id &&
               weight == edge.weight)
            { return true; }
            return false;
        }
        // Operator >
        bool operator>(const Edge &edge) const
        {
            return weight > edge.weight;
        }
        // Operator <
        bool operator<(const Edge &edge) const
        {
            return weight < edge.weight;
        }
        // Desktruktor
        ~Edge() = default;
        // Funkcja do wyświetlania struktury
        void print() { std::cout << source_id << " -> " << destination_id << " : " << weight << "\n"; };
    };
};

#endif