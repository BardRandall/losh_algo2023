#include <iostream>
#include <vector>

struct Edge {
    int from;
    int to;
};

using Graph = std::vector<std::vector<int>>;

void euler(int v, Graph& g, std::vector<Edge>& edges, std::vector<int>& p, std::vector<bool>& used) {
    while (p[v] != g[v].size()) {
        int e = g[v][p[v]];
        if (used[e]) {
            p[v]++;
        }
        used[e] = true;
        used[e ^ 1] = true;
        ++p[v];
        euler(edges[e].to, g, edges, p, used);
    }
    std::cout << v << " ";
}

int main() {
    int n, m;
    Graph g;
    // храним индекс ребра в списке рёбер
    std::vector<Edge> edges;  // список рёбер
    // раздвоенные рёбра лежат рядом
    std::vector<int> p(n, 0);
    std::vector<bool> used(m, false);
    euler(0, g, edges, p, used);
}