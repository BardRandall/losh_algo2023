#include <vector>

class Graph {
private:
    std::vector<std::vector<int>> data_;

public:

    Graph(int n) : data_(n) {

    }

    void AddEdge(int from, int to) {
        data_[from].push_back(to);
        data_[to].push_back(from);  // для неорграфа
    }

    const std::vector<int>& GetNeighbors(int v) {
        return data_[v];
    }
};

std::vector<int> tin, tout;
int timer = 0;

void dfs(int v, Graph& g, std::vector<int>& used) {
    used[v] = true;
    tin[v] = timer++;
    for (int u : g.GetNeighbors(v)) {
        if (!used[u]) dfs(u, g, used);
    }
    tout[v] = timer++;
}

int main() {
    int n;
    Graph g(n);
    std::vector<int> used(n, 0);
    for (int v = 0; v < n; ++v) {
        if (!used[v]) dfs(v, g, used);
    }
}