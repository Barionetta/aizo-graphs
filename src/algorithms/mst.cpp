/**
 * Plik źródłowy zawierający implementację algorytmów
 * wyznaczających minimalne drzewo spinające grafu.
 */

#include "mst.h"
#include "structures/disjoint_set.h"

/**
 * Algorytm Prima
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 596
 * 
 * @param graph Graf, w którym wyznacza się minimalne drzewo spinające [Graph]
*/
MST::MinimalSpanningTree MST::prim(Graph& graph)
{
    int v_nums = graph.get_vertices_num();
    int e_nums = graph.get_edges_num();
    int keys[v_nums];
    int parents[v_nums];
    PriorityQueue queue;
    MST::MinimalSpanningTree ms_tree;
    keys[0] = 0;
    parents[0] = -1;

    for (int i = 1; i < v_nums; i++)
    {
        keys[i] = 1000;
        parents[i] = -1;
        queue.push(i, keys[i]);
    }

    while (!queue.is_empty())
    {
        int u = queue.extract_min();
        LinkedList adjacency = graph.get_adjacency(u);

        for (auto &item : adjacency)
        {
            if ( queue.find(item.vertex_id) != -1 && item.key < keys[u] )
            {
                parents[item.vertex_id] = u;
                keys[item.vertex_id] = item.key;
                queue.decrease_key(item.vertex_id, item.key);
            }
        }
    }

    for (int i = 1; i < v_nums; i++)
    {
        ms_tree.edges.push_back(Structures::Edge(i, parents[i], keys[i]));
    }

    return ms_tree;
}

/**
 * Algorytm Kruskala
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 594
 * 
 * @param graph Graf, w którym wyznacza się minimalne drzewo spinające [Graph]
*/
MST::MinimalSpanningTree MST::kruskal(Graph& graph)
{
    MST::MinimalSpanningTree ms_tree;
    int v_nums = graph.get_vertices_num();
    int e_nums = graph.get_edges_num();

    DisjointSet disjoint_set(v_nums);
    Array<Structures::Edge> edges = graph.get_all_edges_list();
    Others::sort(edges);

    for (int i = 0; i < e_nums; i++)
    {
        if (disjoint_set.find_set(edges[i].source_id) != disjoint_set.find_set(edges[i].destination_id))
        {
            ms_tree.edges.push_back(edges[i]);
            disjoint_set.union_(edges[i].source_id, edges[i].destination_id);
        }
    }
    return ms_tree;
}