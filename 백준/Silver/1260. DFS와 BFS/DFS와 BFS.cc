#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;

void DFS(int start) {
    visited[start] = 1;
    cout << start << " ";

    for (int i = 1; i < graph[start].size(); i++) {
        if (graph[start][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 1; i < graph[node].size(); i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int v, e, start;
    cin >> v >> e >> start;

    graph.resize(v + 1, vector<int>(v + 1, 0));
    visited.resize(v + 1, 0);

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;

        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    DFS(start);
    cout << endl;
    fill(visited.begin(), visited.end(), 0);
    BFS(start);
}