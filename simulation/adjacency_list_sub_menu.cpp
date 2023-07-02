/**
 * Plik nagłówkowy pliku zawierający podmenu dla klasy AdjacencyList
 */
#include "adjacency_list_sub_menu.h"
#include "generator.h"
#include "representations/adjacency_list.h"
#include "algorithms/minimal_spanning_tree.h"
#include "algorithms/shortest_path.h"
#include <iostream>
#include <chrono>
#include <fstream>
#include <cmath>
using namespace std;

void listSubMenu()
{
    cout << "Wybrano listę sąsiadów\n";
    short int task;
    listDisplayTaskOptions();
    cin >> task;
    while (task < 0 || task > 2)
    {
        cout << "Wprowadź poprawną opcję.\n";
        cin >> task;
    }
    switch (task)
    {
    case 1:
    {
        listTestSubMenu();
        break;
    }
    case 2:
    {
        listRecordSubMenu();
        break;
    }
    case 0:
    {
        return;
        break;
    }
    default:
    {
        break;
    }
    }
    return;
}

void listDisplayTaskOptions()
{
    cout << "Co zamierzasz zrobić?\n";
    cout << "1 - Test\n";
    cout << "2 - Badania\n";
    cout << "0 - Zakończ program\n";
}

void listDisplayAlgorithmsOptions()
{
    cout << "Który algorytm chcesz sprawdzić?\n";
    cout << "1 - Minimalne drzewo spinające - algorytm Prima\n";
    cout << "2 - Minimalne drzewo spinające - algorytm Kruskala\n";
    cout << "3 - Najkrótsza ścieżka - algorytm Dijkstry\n";
    cout << "4 - Najkrótsza ścieżka - algorytm Bellmana-Forda\n";
    cout << "0 - Zakończ program\n";
}

void listDisplayFileOptions()
{
    cout << "Jak chcesz stworzyć graf?\n";
    cout << "1 - Wczytaj z pliku\n";
    cout << "2 - Wygeneruj losowo\n";
}

void listTestSubMenu()
{
    cout << "Wybrano testy.\n";
    AdjacencyList *adjacencyList = new AdjacencyList();
    listDisplayFileOptions();
    short int choice;
    cin >> choice;
    while (choice < 1 || choice > 2)
    {
        cout << "Wprowadź poprawną opcję.\n";
        cin >> choice;
    }
    if (choice == 1)
    {
        cout << "Wybrano wczytanie z pliku.\n";
        string filepath;
        cout << "Podaj nazwę pliku:\n";
        cin >> filepath;
        adjacencyList->readFromFile(filepath);
        adjacencyList->show();
    }
    else
    {
        int v_num = 0;
        int e_num = 0;
        cout << "\nIle wierzchołków ma mieć twój graf?\n";
        cin >> v_num;
        cout << "\nIle krawędzi ma mieć twój graf?\n";
        cin >> e_num;
        cout << "\nGeneruję graf... proszę czekać\n";
        adjacencyList->generate(v_num, e_num);
        adjacencyList->show();
    }
    short int algorithm = 7;
    while (algorithm != 0)
    {
        listDisplayAlgorithmsOptions();
        cin >> algorithm;
        while (algorithm < 0 || algorithm > 4)
        {
            cout << "Wprowadź poprawną opcję.\n";
            cin >> algorithm;
        }
        switch (algorithm)
        {
        case 1:
        {
            cout << "Wybrano algorytm Prima\n";
            int v = 0;
            cout << "\nKtóry wierzchołek ma być korzeniem MST?\n";
            cin >> v;
            prim_AL(*adjacencyList, v);
            break;
        }
        case 2:
        {
            cout << "Wybrano algorytm Kruskala\n";
            kruskal_AL(*adjacencyList);
            break;
        }
        case 3:
        {
            cout << "Wybrano algorytm Dijkstry\n";
            int v1 = 0;
            int v2 = 0;
            cout << "\nZ którego wierzchołka chcesz wystartować?\n";
            cin >> v1;
            cout << "\nNa którym wierzchołku chcesz skończyć?\n";
            cin >> v2;
            dijkstra_AL(*adjacencyList, v1, v2);
            break;
        }
        case 4:
        {
            cout << "Wybrano algorytm Bellmana-Forda\n";
            int v1 = 0;
            int v2 = 0;
            cout << "\nZ którego wierzchołka chcesz wystartować?\n";
            cin >> v1;
            cout << "\nNa którym wierzchołku chcesz skończyć?\n";
            cin >> v2;
            bellman_ford_AL(*adjacencyList, v1, v2);
            break;
        }
        case 0:
        {
            delete adjacencyList;
            return;
            break;
        }
        default:
        {
            break;
        }
        }
    }
    delete adjacencyList;
    return;
}

void listRecordSubMenu()
{
    cout << "Wybrano badania.\n";
    string path = "../output/adjacencelist.csv";
    ofstream outf(path);
    int tests = 100;
    int vertices[5] = {5, 7, 10, 12, 14};
    for (int i = 0; i < 5; i++)
    {
        int max_e = static_cast<int>((vertices[i] * (vertices[i] - 1)) / 2);
        int diff = static_cast<int>(max_e * 0.25);
        for (int j = 0; j < 4; j++)
        {
            AdjacencyList *adjacencyList = new AdjacencyList();
            adjacencyList->generate(vertices[i], max_e);
            // Mierzenie czasu algorytmu Prima
            double primTime = 0;
            for (int t = 0; t < tests; t++)
            {
                int n = generate_random_number(vertices[i]);
                auto start = std::chrono::steady_clock::now();
                prim_AL(*adjacencyList, n);
                auto stop = std::chrono::steady_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
                primTime += duration.count();
            }
            primTime /= 100;
            // Mierzenie czasu algorytmu Kruskala
            double kruskalTime = 0;
            for (int t = 0; t < tests; t++)
            {
                int n = generate_random_number(vertices[i]);
                auto start = std::chrono::steady_clock::now();
                kruskal_AL(*adjacencyList);
                auto stop = std::chrono::steady_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
                kruskalTime += duration.count();
            }
            kruskalTime /= 100;
            // Mierzenie czasu algorytmu Dijkstry
            double dijkstraTime = 0;
            for (int t = 0; t < tests; t++)
            {
                int v1 = generate_random_number(vertices[i]);
                int v2 = generate_random_number(vertices[i]);
                auto start = std::chrono::steady_clock::now();
                dijkstra_AL(*adjacencyList, v1, v2);
                auto stop = std::chrono::steady_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
                dijkstraTime += duration.count();
            }
            dijkstraTime /= 100;
            // Mierzenie czasu algorytmu Bellmana-Forda
            double bellmanTime = 0;
            for (int t = 0; t < tests; t++)
            {
                int v1 = generate_random_number(vertices[i]);
                int v2 = generate_random_number(vertices[i]);
                auto start = std::chrono::steady_clock::now();
                bellman_ford_AL(*adjacencyList, v1, v2);
                auto stop = std::chrono::steady_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
                bellmanTime += duration.count();
            }
            if (!outf.bad())
            {
                outf << "prim," << to_string(vertices[i]) << "," << to_string(max_e) << "," << to_string(primTime) << endl;
                outf << "kruskal," << to_string(vertices[i]) << "," << to_string(max_e) << "," << to_string(kruskalTime) << endl;
                outf << "dijkstra," << to_string(vertices[i]) << "," << to_string(max_e) << "," << to_string(dijkstraTime) << endl;
                outf << "bellman_ford," << to_string(vertices[i]) << "," << to_string(max_e) << "," << to_string(bellmanTime) << endl;
            }
            else
            {
                cout << "Nie udało się otworzyć pliku ze ścieżki " << path << " \n";
                outf.close();
                return;
            }
            max_e -= diff;
            delete adjacencyList;
        }
    }
    outf.close();
    cout << "Badania zakończono pomyślnie.\n";
    return;
}
