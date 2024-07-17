#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<int> graph[n];
    int e;
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter Edges: " << endl;
    for (int i = 0; i < e; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    cout << "Adjacency List: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}