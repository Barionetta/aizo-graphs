/**
 * Plik źródłowy zawierający implementację algorytmów
 * wyznaczających najkrótszą ścieżkę w grafie między dwoma wierzchołkami.
 */
#include "shortest_path.h"
#include "priority_queue.h"
#include "representations/adjacency_list.h"
#include "representations/incidence_matrix.h"
#include <iostream>
using namespace std;

/**
 * Funkcja do wyświetlania najkrótszej ścieżki w grafie
 *
 * @param source Numer wierzchołka startowego [int]
 * @param destination Numer wierzchołka docelowego [int]
 * @param distance Dystans ścieżki [int]
 * @param path Tablica odwiedzonych wierzchołków [int*]
 */
void printPath(int source, int destination, int distance, int *path)
{
    if (distance == 1000)
    {
        cout << "Nie ma drogi z v" << source << " do v" << destination << endl;
        return;
    }
    int i = destination;
    while (i != source)
    {
        cout << " <- " << i;
        i = path[i];
    }
    cout << i << endl
         << "Długość ścieżki: " << distance << endl;
}

/**
 * Algorytm Dijkstry dla listy sąsiedztwa
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 620
 *
 * @param G Ropatrywany graf w reprezentacji listy sąsiedztwa [AdjacencyList]
 * @param source Numer wierzchołka startowego [int]
 * @param destination Numer wierzchołka docelowego [int]
 */
void dijkstra_AL(AdjacencyList G, int source, int destination)
{
    int v_nums = G.getVerticesNum();
    int e_nums = G.getEdgesNum();
    int distances[v_nums];
    int path[v_nums];
    for (int v = 0; v < v_nums; v++)
    {
        distances[v] = 1000;
        path[v] = -1;
    }
    distances[source] = 0;

    PriorityQueue Q;
    for (int v = 0; v < v_nums; v++)
    {
        Vertex *vertex;
        vertex->number = v;
        vertex->distance = distances[v];
        Q.push(vertex);
    }

    while (Q.isEmpty() == false)
    {
        int min = Q.getData()[0].number;
        int u = Q.extractMin();
        Edge *temp = G.getVertices()[min].head;
        while (temp)
        {
            if (distances[temp->destination] > Q.find(min) + temp->weight)
            {
                distances[temp->destination] > Q.find(min) + temp->weight;
                path[temp->destination] = min;
            }
            temp = temp->next;
        }
    }
    printPath(source, destination, distances[destination], path);
}

/**
 * Algorytm Dijkstry dla macierzy incydencji
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 620
 *
 * @param G Ropatrywany graf w reprezentacji macierzy incydencji [IncidenceMatrix]
 * @param source Numer wierzchołka startowego [int]
 * @param destination Numer wierzchołka docelowego [int]
 */
void dijkstra_IM(IncidenceMatrix G, int source, int destination)
{
    int v_nums = G.getVerticesNum();
    int e_nums = G.getEdgesNum();
    int distances[v_nums];
    int path[v_nums];
    for (int v = 0; v < v_nums; v++)
    {
        distances[v] = 1000;
        path[v] = -1;
    }
    distances[source] = 0;

    PriorityQueue Q;
    for (int v = 0; v < v_nums; v++)
    {
        Vertex *vertex;
        vertex->number = v;
        vertex->distance = distances[v];
        Q.push(vertex);
    }

    while (Q.isEmpty() == false)
    {
        int u = Q.extractMin();
        for (int e = 0; e < e_nums; e++)
        {
            IMEdge *edge = G.getEdge(e);
            if (edge->source == u)
            {
                if (distances[edge->destination] > Q.find(edge->source) + edge->weight)
                {
                    distances[edge->destination] = Q.find(edge->source) + edge->weight;
                    path[edge->destination] = edge->source;
                }
            }
        }
    }
    printPath(source, destination, distances[destination], path);
}

/**
 * Algorytm Bellmana-Forda dla listy sąsiedztwa
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 612
 *
 * @param G Ropatrywany graf w reprezentacji listy sąsiedztwa [AdjacencyList]
 * @param source Numer wierzchołka startowego [int]
 * @param destination Numer wierzchołka docelowego [int]
 */
void bellman_ford_AL(AdjacencyList G, int source, int destination)
{
    int v_nums = G.getVerticesNum();
    int e_nums = G.getEdgesNum();
    int distances[v_nums];
    int path[v_nums];
    for (int v = 0; v < v_nums; v++)
    {
        distances[v] = 1000;
        path[v] = -1;
    }
    distances[source] = 0;

    int **edges = G.getAllEdgesList();
    for (int i = 0; i < v_nums - 1; i++)
    {
        for (int e = 0; e < e_nums; e++)
        {
            if (distances[edges[e][1]] > distances[edges[e][0]] + distances[edges[e][2]])
            {
                distances[edges[e][1]] = distances[edges[e][0]] + distances[edges[e][2]];
                path[edges[e][1]] = edges[e][0];
            }
        }
    }

    for (int e = 0; e < e_nums; e++)
    {
        if (distances[edges[e][1]] > distances[edges[e][0]] + distances[edges[e][2]])
        {
            cout << "W grafie znaleziono cykl ujemny!" << endl;
            return;
        }
    }
    printPath(source, destination, distances[destination], path);
}

/**
 * Algorytm Bellmana-Forda dla macierzy incydencji
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 612
 *
 * @param G Ropatrywany graf w reprezentacji macierzy incydencji [IncidenceMatrix]
 * @param source Numer wierzchołka startowego [int]
 * @param destination Numer wierzchołka docelowego [int]
 */
void bellman_ford_IM(IncidenceMatrix G, int source, int destination)
{
    int v_nums = G.getVerticesNum();
    int e_nums = G.getEdgesNum();
    int distances[v_nums];
    int path[v_nums];
    for (int v = 0; v < v_nums; v++)
    {
        distances[v] = 1000;
        path[v] = -1;
    }
    distances[source] = 0;

    for (int i = 0; i < v_nums - 1; i++)
    {
        for (int e = 0; e < e_nums; e++)
        {
            IMEdge *edge = G.getEdge(e);
            if (distances[edge->destination] > distances[edge->source] + edge->weight)
            {
                distances[edge->destination] = distances[edge->source] + edge->weight;
                path[edge->destination] = edge->source;
            }
        }
    }

    for (int e = 0; e < e_nums; e++)
    {
        IMEdge *edge = G.getEdge(e);
        if (distances[edge->destination] > distances[edge->source] + edge->weight)
        {
            cout << "W grafie znaleziono cykl ujemny!" << endl;
            return;
        }
    }
    printPath(source, destination, distances[destination], path);
}