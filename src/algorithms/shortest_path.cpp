/**
 * Plik źródłowy zawierający implementację algorytmów
 * wyznaczających najkrótszą ścieżkę w grafie między dwoma wierzchołkami.
 */

#include "shortest_path.h"

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
        cout << "Nie ma drogi z v" << source << " do v" << destination << std::endl;
        return;
    }
    int i = destination;
    while (i != source && i != -1)
    {
        cout << i << " <- ";
        i = path[i];
    }
    cout << i << std::endl
         << "Długość ścieżki: " << distance << std::endl;
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
void dijkstra_AL(AdjacencyList *G, int source, int destination)
{
    int v_nums = G->get_vertices_num();
    int e_nums = G->get_edges_num();
    int *distances = new int[v_nums];
    int *path = new int[v_nums];
    for (int v = 0; v < v_nums; v++)
    {
        distances[v] = 1000;
        path[v] = -1;
    }
    distances[source] = 0;

    PriorityQueue *Q = new PriorityQueue;
    for (int v = 0; v < v_nums; v++)
    {
        Vertex *vertex = new Vertex;
        vertex->number = v;
        vertex->distance = distances[v];
        Q->push(vertex);
    }

    while (!Q->is_empty())
    {
        int u = Q->get_data()[0].number;
        Edge *temp = G->get_vertices()[u].head;
        int min = Q->extract_min();
        while (temp)
        {
            if (distances[temp->destination] > min + temp->weight)
            {
                distances[temp->destination] = min + temp->weight;
                path[temp->destination] = u;
                Q->decrease_key(Q->find(temp->destination), distances[temp->destination]);
            }
            temp = temp->next;
        }
    }
    cout << v_nums << " " << e_nums << std::endl;
    printPath(source, destination, distances[destination], path);
    delete Q;
    delete[] distances;
    delete[] path;
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
void dijkstra_IM(IncidenceMatrix *G, int source, int destination)
{
    int v_nums = G->get_vertices_num();
    int e_nums = G->get_edges_num();
    int *distances = new int[v_nums];
    int *path = new int[v_nums];
    for (int v = 0; v < v_nums; v++)
    {
        distances[v] = 1000;
        path[v] = -1;
    }
    distances[source] = 0;

    PriorityQueue *Q = new PriorityQueue;
    for (int v = 0; v < v_nums; v++)
    {
        Vertex *vertex = new Vertex;
        vertex->number = v;
        vertex->distance = distances[v];
        Q->push(vertex);
    }

    while (!Q->is_empty())
    {
        int u = Q->get_data()[0].number;
        int min = Q->extract_min();
        for (int e = 0; e < e_nums; e++)
        {
            IMEdge *edge = G->get_edge(e);
            if (edge->source == u)
            {
                if (distances[edge->destination] > min + edge->weight)
                {
                    distances[edge->destination] = min + edge->weight;
                    path[edge->destination] = edge->source;
                    Q->decrease_key(Q->find(edge->destination), distances[edge->destination]);
                }
            }
        }
    }
    printPath(source, destination, distances[destination], path);
    delete Q;
    delete[] distances;
    delete[] path;
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
void bellman_ford_AL(AdjacencyList *G, int source, int destination)
{
    int v_nums = G->get_vertices_num();
    int e_nums = G->get_edges_num();
    int *distances = new int[v_nums];
    int *path = new int[v_nums];
    for (int v = 0; v < v_nums; v++)
    {
        distances[v] = 1000;
        path[v] = -1;
    }
    distances[source] = 0;

    int **edges = G->get_all_edges_list();
    for (int i = 0; i < v_nums - 1; i++)
    {
        for (int e = 0; e < e_nums; e++)
        {
            if (distances[edges[e][1]] > distances[edges[e][0]] + edges[e][2])
            {
                distances[edges[e][1]] = distances[edges[e][0]] + edges[e][2];
                path[edges[e][1]] = edges[e][0];
            }
        }
    }

    for (int e = 0; e < e_nums; e++)
    {
        if (distances[edges[e][1]] > distances[edges[e][0]] + edges[e][2])
        {
            cout << "W grafie znaleziono cykl ujemny!" << std::endl;
            return;
        }
    }
    printPath(source, destination, distances[destination], path);
    for (int e = 0; e < e_nums; e++)
    {
        delete[] edges[e];
    }
    delete[] edges;
    delete[] distances;
    delete[] path;
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
void bellman_ford_IM(IncidenceMatrix *G, int source, int destination)
{
    int v_nums = G->get_vertices_num();
    int e_nums = G->get_edges_num();
    int *distances = new int[v_nums];
    int *path = new int[v_nums];
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
            IMEdge *edge = G->get_edge(e);
            if (distances[edge->destination] > distances[edge->source] + edge->weight)
            {
                distances[edge->destination] = distances[edge->source] + edge->weight;
                path[edge->destination] = edge->source;
            }
        }
    }

    for (int e = 0; e < e_nums; e++)
    {
        IMEdge *edge = G->get_edge(e);
        if (distances[edge->destination] > distances[edge->source] + edge->weight)
        {
            cout << "W grafie znaleziono cykl ujemny!" << std::endl;
            return;
        }
    }
    printPath(source, destination, distances[destination], path);
    delete[] distances;
    delete[] path;
}