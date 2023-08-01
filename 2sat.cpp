#include <algorithm>
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
        data_[to].push_back(from);  // для неорграфа
    }

    const std::vector<int>& GetNeighbors(int v) {
        return data_[v];
    }
};

void dfs(int v, Graph& graph, std::vector<int>& color,
         std::vector<int>& answer) {
    color[v] = 1;
    for (int u : graph.GetNeighbors(v)) {
        if (color[v] == 0) {
            dfs(u, graph, color, answer);
        }
    }
    answer.push_back(v);
    color[v] = 2;
}

void dfsR(int v, Graph& graph, std::vector<int>& color,
         std::vector<int>& conn_comp, int current_num) {
    color[v] = 1;
    conn_comp[v] = current_num;
    for (int u : graph.GetNeighbors(v)) {
        if (color[v] == 0) {
            dfsR(u, graph, color, conn_comp, current_num);
        }
    }
    color[v] = 2;
}

// Kosaraju
int main() {
    int n;
    Graph graph(n);
    Graph graphR(n);
    // input ...
    int u, v;
    graph.AddEdge(u, v);
    graphR.AddEdge(v, u);
    std::vector<int> color(n, 0);
    std::vector<int> permutation;
    for (int v = 0; v < n; ++v) {
        if (color[v] == 0) dfs(v, graph, color, permutation);
    }
    std::reverse(permutation.begin(), permutation.end());
    color.assign(n, 0);
    std::vector<int> conn_comp(n);  // храним номер КСС
    int counter = 0;
    for (int v : permutation) {
        if (color[v] == 0) dfsR(v, graphR, color, conn_comp, ++counter);
    }
    bool not_solvable = false;
    std::vector<int> answer(n);
    for (int v = 0; v < 2 * n; v += 2) {
        if (conn_comp[v] == conn_comp[v ^ 1]) {
            not_solvable = true;
            break;
        } else {
            answer[v / 2] = conn_comp[v] > conn_comp[v ^ 1];
        }
    }
    if (not_solvable) {
        std::cout << "No solution" << "\n";
    } else {
        for (int b : answer) {
            std::cout << b << " ";
        }
    }
}