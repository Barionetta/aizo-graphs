/**
 * Plik źródłowy zawierający implementację algorytmów
 * wyznaczających minimalne drzewo spinające grafu.
 */

#include "minimal_spanning_tree.h"

/**
 * Algorytm Prima dla listy sąsiedztwa
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 596
 *
 * @param G Ropatrywany graf w reprezentacji listy sąsiedztwa [AdjacencyList]
 * @param root Numer wierzchołka startowego (korzenia) [int]
 */
void prim_AL(AdjacencyList *G, int root)
{
    int v_nums = G->get_vertices_num();
    int e_nums = G->get_edges_num();
    int *keys = new int[v_nums];
    int *predecessors = new int[v_nums];
    for (int v = 0; v < v_nums; v++)
    {
        keys[v] = 1000;
        predecessors[v] = -1;
    }
    keys[root] = 0;

    PriorityQueue *Q = new PriorityQueue;
    for (int v = 0; v < v_nums; v++)
    {
        Vertex *vertex = new Vertex;
        vertex->number = v;
        vertex->distance = keys[v];
        Q->push(vertex);
    }

    while (!Q->is_empty())
    {
        int u = Q->get_data()[0].number;
        Edge *temp = G->get_vertices()[u].head;
        int min = Q->extract_min();
        while (temp)
        {
            if (Q->find(temp->destination) != -1 && temp->weight < keys[temp->destination])
            {
                keys[temp->destination] = temp->weight;
                predecessors[temp->destination] = u;
                Q->decrease_key(Q->find(temp->destination), temp->weight);
            }
            temp = temp->next;
        }
    }
    cout << "Krawędź:       Waga:\n";
    for (int v = 0; v < v_nums; v++)
    {
        if (predecessors[v] != -1)
        {
            cout << predecessors[v] << " -> " << v << "     " << keys[v] << std::endl;
        }
    }
    cout << e_nums << " " << v_nums << std::endl;
    delete Q;
    delete[] keys;
    delete[] predecessors;
}

/**
 * Algorytm Prima dla macierzy incydencji
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 596
 *
 * @param G Ropatrywany graf w reprezentacji macierzy incydencji [IncidenceMatrix]
 * @param root Numer wierzchołka startowego (korzenia) [int]
 */
void prim_IM(IncidenceMatrix *G, int root)
{
    int v_nums = G->get_vertices_num();
    int e_nums = G->get_edges_num();
    int *keys = new int[v_nums];
    int *predecessors = new int[v_nums];
    for (int v = 0; v < v_nums; v++)
    {
        keys[v] = 1000;
        predecessors[v] = -1;
    }
    keys[root] = 0;

    PriorityQueue *Q = new PriorityQueue;
    for (int v = 0; v < v_nums; v++)
    {
        Vertex *vertex = new Vertex;
        vertex->number = v;
        vertex->distance = keys[v];
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
                if (Q->find(edge->destination) != -1 && edge->weight < keys[edge->destination])
                {
                    keys[edge->destination] = edge->weight;
                    predecessors[edge->destination] = edge->source;
                    Q->decrease_key(Q->find(edge->destination), edge->weight);
                }
            }
        }
    }
    cout << "Krawędź:       Waga:\n";
    for (int v = 1; v < v_nums; v++)
    {
        if (predecessors[v] != -1)
        {
            cout << predecessors[v] << " -> " << v << "     " << keys[v] << std::endl;
        }
    }
    cout << e_nums << " " << v_nums << std::endl;
    delete Q;
    delete[] keys;
    delete[] predecessors;
}

/**
 * Algorytm Kruskala dla listy sąsiedztwa
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 594
 *
 * @param G Ropatrywany graf w reprezentacji listy sąsiedztwa [AdjacencyList]
 */
void kruskal_AL(AdjacencyList *G)
{
    int v_nums = G->get_vertices_num();
    int e_nums = G->get_edges_num();
    int **A = new int *[v_nums];
    for (int i = 0; i < v_nums; i++)
    {
        A[i] = new int[3];
    }
    DisjointSet *V = new DisjointSet(v_nums);
    int **edges = G->get_all_edges_list();
    for (int i = 0; i < e_nums - 1; i++)
    {
        for (int j = 0; j < e_nums - i - 1; j++)
        {
            if (edges[j][2] > edges[j + 1][2])
            {
                int *temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
    int v = 0;
    for (int e = 0; e < e_nums; e++)
    {
        if (V->find_set(edges[e][0]) != V->find_set(edges[e][1]))
        {
            A[v][0] = edges[e][0];
            A[v][1] = edges[e][1];
            A[v][2] = edges[e][2];
            V->Union(edges[e][0], edges[e][1]);
            v++;
        }
    }
    cout << "Krawędź:       Waga:\n";
    for (int v = 0; v < v_nums - 1; v++)
    {
        cout << A[v][0] << " -> " << A[v][1] << "     " << A[v][2] << std::endl;
        delete A[v];
    }
    delete A[v_nums - 1];
    delete[] A;

    for (int e = 0; e < e_nums; e++)
    {
        delete[] edges[e];
    }
    delete V;
    delete[] edges;
}

/**
 * Algorytm Kruskala dla macierzy incydencji
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 594
 *
 * @param G Ropatrywany graf w reprezentacji macierzy incydencji [IncidenceMatrix]
 */
void kruskal_IM(IncidenceMatrix *G)
{
    int v_nums = G->get_vertices_num();
    int e_nums = G->get_edges_num();
    int **A = new int *[v_nums];
    for (int i = 0; i < v_nums; i++)
    {
        A[i] = new int[3];
    }
    DisjointSet *V = new DisjointSet(v_nums);
    int **edges = G->get_all_edges_list();
    for (int i = 0; i < e_nums - 1; i++)
    {
        for (int j = 0; j < e_nums - i - 1; j++)
        {
            if (edges[j][2] > edges[j + 1][2])
            {
                int *temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
    int v = 0;
    for (int e = 0; e < e_nums; e++)
    {
        if (V->find_set(edges[e][0]) != V->find_set(edges[e][1]))
        {
            A[v][0] = edges[e][0];
            A[v][1] = edges[e][1];
            A[v][2] = edges[e][2];
            V->Union(edges[e][0], edges[e][1]);
            v++;
        }
    }
    cout << "Krawędź:       Waga:\n";
    for (int v = 0; v < v_nums - 1; v++)
    {
        cout << A[v][0] << " -> " << A[v][1] << "     " << A[v][2] << std::endl;
        delete A[v];
    }
    delete A[v_nums - 1];
    delete[] A;

    for (int e = 0; e < e_nums; e++)
    {
        delete[] edges[e];
    }
    delete V;
    delete[] edges;
}