#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    int graph[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = 99999;
        }
    }
    int e;
    cout << "Enter Number of Edges: ";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        graph[node1][node2] = weight;
        graph[node2][node1] = weight;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << "\t";
        }
        cout << endl;
    }
    int visited[n] = {0}, visited_n = 0, starting_node;
    cout << "Starting Node: ";
    cin >> starting_node;
    visited[starting_node] = 1;
    visited_n++;
    while (visited_n < n)
    {
        int min_edge = 99999, min_node1 = -1, min_node2 = -1;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (visited[j] == 0 && graph[i][j] < min_edge)
                    {
                        min_edge = graph[i][j];
                        min_node1 = i;
                        min_node2 = j;
                    }
                }
            }
        }
        cout << min_node1 << " " << min_node2 << " " << min_edge << endl;
        visited[min_node2] = 1;
        visited_n++;
    }
}