/**
 * Plik źródłowy zawierający implementację algorytmów
 * wyznaczających najkrótszą ścieżkę w grafie między dwoma wierzchołkami.
 */

#include "shortest_path.h"

/**
 * Algorytm Dijkstry
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 620
 * 
 * @param graph Ropatrywany graf w reprezentacji listy sąsiedztwa [Graph]
 * @param source Numer wierzchołka startowego [int]
*/
ShortestPath::Path ShortestPath::dijkstra(Graph& graph, int source)
{
    int v_nums = graph.get_vertices_num();
    ShortestPath::Path shortest_path;
    PriorityQueue queue;

    for (int i = 0; i < v_nums; i++)
    {
        shortest_path.vertices.push_back(Structures::Vertex(i, 1000));
        shortest_path.predcessors.push_back(-1);
        if (i != source ) { queue.push(i, 1000); } 
    }
    shortest_path.vertices[source].key = 0;

    while (!queue.is_empty())
    {
        int u = queue.extract_min();
        LinkedList adjacency = graph.get_adjacency(u);

        for (auto &item : adjacency)
        {
            // if queue.has_item(item)
            int distance = shortest_path.vertices[u].key + item.key;
            if (queue.find(item.vertex_id) != -1 && distance < shortest_path.vertices[u].key)
            {
                shortest_path.vertices[item.vertex_id].key = distance;
                shortest_path.predcessors[item.vertex_id] = u;
            }
            queue.decrease_key(item.vertex_id, item.key);
        }
    }

    return shortest_path;
}

/**
 * Algorytm Bellmana-Forda
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 612
 *
 * @param graph Ropatrywany graf w reprezentacji listy sąsiedztwa [Graph]
 * @param source Numer wierzchołka startowego [int]
 */
ShortestPath::Path ShortestPath::bellman_ford(Graph& graph, int source)
{
    int v_nums = graph.get_vertices_num();
    int e_nums = graph.get_edges_num();
    ShortestPath::Path shortest_path;
    Array<Structures::Edge> edges = graph.get_all_edges_list();

    for (int i = 0; i < v_nums; i++)
    {
        shortest_path.vertices.push_back(Structures::Vertex(i, 1000));
        shortest_path.predcessors.push_back(-1);
    }
    shortest_path.vertices[source].key = 0;

    for (int i = 0; i < v_nums - 1; i++)
    {
        for (int j = 0; j < e_nums; j++)
        {
            int source = edges[j].source_id;
            int destination = edges[j].destination_id;

            int distance = shortest_path.vertices[source].key + edges[j].weight;
            if (distance < shortest_path.vertices[destination].key)
            {
                shortest_path.vertices[destination].key = distance;
                shortest_path.predcessors[destination] = source;
            }
        }
    }

    for (int i = 0; i < e_nums; i++)
    {
        int source = edges[i].source_id;
        int destination = edges[i].destination_id;

        if (shortest_path.vertices[destination].key > shortest_path.vertices[source].key + edges[i].weight)
        {
            std::cout << "W grafie znaleziono cykl ujemny!" << std::endl;
        }
    }

    return shortest_path;
}