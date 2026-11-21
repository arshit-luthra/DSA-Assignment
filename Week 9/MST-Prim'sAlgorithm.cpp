
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void primMST(vector<vector<int>>& graph, int V) {
    vector<int> key(V, INT_MAX);
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }

        if (u == -1 || key[u] == INT_MAX)
            break;

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int totalWeight = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i
                 << " : " << graph[i][parent[i]] << endl;
            totalWeight += graph[i][parent[i]];
        }
    }

    cout << "Total Minimum Cost: " << totalWeight;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    primMST(graph, V);

    return 0;
}
