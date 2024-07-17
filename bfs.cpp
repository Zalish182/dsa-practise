#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void BFS(vector<vector<int>> &graph, int start)
{
    int V = graph.size(); // Number of vertices in the graph
    vector<bool> visited(V, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty())
    {
        // Dequeue a vertex from the queue and print it
        int current = q.front();
        cout << current << " ";
        q.pop();
        for (int i = 0; i < graph[current].size(); ++i)
        {
            int neighbor = graph[current][i];
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
int main()
{
    // Example graph represented using adjacency list
    vector<vector<int>> graph = {
        {1, 3},    // Adjacency list of vertex 0
        {0, 2, 4}, // Adjacency list of vertex 1
        {1, 4},    // Adjacency list of vertex 2
        {0, 1, 3}, // Adjacency list of vertex 3
        {2, 3},
        {4, 6, 3} // Adjacency list of vertex 4
    };
    cout << "Breadth-First Traversal starting from vertex 0: ";
    BFS(graph, 0);
    return 0;
}
int V, E;
cout << "Enter the number of vertices and edges: ";
cin >> V >> E;
vector<vector<int>> graph(V);
cout << "Enter the edges (source and destination) in the graph:\n";
for (int i = 0; i < E; ++i)
{
    int src, dest;
    cin >> src >> dest;
    graph[src].push_back(dest);
    graph[dest].push_back(src);
}
int startVertex;
cout << "Enter the starting vertex for BFS: ";
cin >> startVertex;
BFS(graph, startVertex);
return 0;