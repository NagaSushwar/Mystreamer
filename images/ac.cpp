#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

struct Edge {
    int from, to, weight;
};

void bellmanFord(vector<Edge>& edges, int n, int s, vector<int>& dist, vector<int>& parent) {
    // Initialize distances and parent pointers
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[s] = 0;

    // Relax all edges n-1 times
    for (int i = 1; i < n; i++) {
        for (auto edge : edges) {
            int u = edge.from;
            int v = edge.to;
            int w = edge.weight;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    // Check for negative cycles
    for (auto edge : edges) {
        int u = edge.from;
        int v = edge.to;
        int w = edge.weight;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            cout << "Graph contains negative cycle" << endl;
            return;
        }
    }
}

int main() {
    int n = 5;
    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };
    int s = 0;

    vector<int> dist(n);
    vector<int> parent(n);
    bellmanFord(edges, n, s, dist, parent);

    // Print the distances and parent pointers
    for (int i = 0; i < n; i++) {
        cout << "Distance from " << s << " to " << i << " is " << dist[i] << endl;
        cout << "Parent of " << i << " is " << parent[i] << endl;
    }

    return 0;
}
