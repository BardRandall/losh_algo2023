#include <iostream>
#include <vector>

class Graph {
private:
    std::vector<std::vector<int>> data_;

public:

    Graph(int n) : data_(n) {

    }

    void AddEdge(int from, int to) {
        data_[from].push_back(to);
    }

    const std::vector<int>& GetNeighbors(int v) {
        return data_[v];
    }
};

int timer = 0;

void dfs(int v, Graph& graph, std::vector<int>& color,
         std::vector<int>& answer, bool& has_cycle) {
    color[v] = 1;
    for (int u : graph.GetNeighbors(v)) {
        if (color[u] == 1) {
            has_cycle = true;
            return;
        } else if (color[u] == 0) {
            dfs(u, graph, color, answer, has_cycle);
        }
    }
    answer.push_back(v);
    color[v] = 2;
}

// Top Sort
int main() {
    int n;
    Graph graph(n);
    std::vector<int> color(n, 0);
    std::vector<int> answer;
    bool has_cycle = false;
    for (int v = 0; v < n; ++v) {
        if (color[v] == 0) dfs(v, graph, color, answer, has_cycle);
    }
    if (has_cycle) {
        std::cout << "No topologic sort";
    } else {
        for (auto it = answer.rbegin(); it != answer.rend(); ++it) {
            std::cout << *it << " ";
        }
    }
}