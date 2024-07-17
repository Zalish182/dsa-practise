#include <iostream>
#include <vector>
#include <stack>
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
    stack<int> st;
    int visited[n] = {0};
    st.push(0);
    while (!st.empty())
    {
        int node = st.top();
        if (visited[node] == 1)
        {
            st.pop();
            continue;
        }
        cout << st.top() << " ";
        st.pop();
        visited[node] = 1;
        for (int i = 0; i < graph[node].size(); i++)
        {
            int adj_node = graph[node][i];
            if (visited[adj_node] == 0)
            {
                st.push(adj_node);
            }
        }
    }
}
