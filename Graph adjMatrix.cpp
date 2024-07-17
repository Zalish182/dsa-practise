#include <iostream>
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
                graph[i][j] = -1;
        }
    }
    int e;
    cout << "Enter Number of Edges: ";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1][node2] = 1;
        graph[node2][node1] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << "\t";
        }
        cout << endl;
    }
}
