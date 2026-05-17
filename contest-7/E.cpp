#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

std::vector<std::vector<std::pair<int, int>>> out;
std::vector<std::pair<int, int>> edges;

std::vector<bool> is_bridge;
std::vector<int> tin;
std::vector<int> low;

int timer = 0;

void DfsBridges(int v, int parent_edge) {
    tin[v] = low[v] = ++timer;
    for (auto [to, id] : out[v]) {
        if (id == parent_edge) {
            continue;
        }
        if (tin[to] == 0) {
            DfsBridges(to, id);
            low[v] = std::min(low[v], low[to]);
            if (low[to] > tin[v]) {
                is_bridge[id] = true;
            }
        } else {
            low[v] = std::min(low[v], tin[to]);
        }
    }
};

int main() {
    int n;
    int m;
    std::cin >> n >> m;

    out = std::vector<std::vector<std::pair<int, int>>>(n);
    edges = std::vector<std::pair<int, int>>(m);
    for (int i = 0; i < m; ++i) {
        int u;
        int v;
        std::cin >> u >> v;
        --u; --v;

        edges[i] = {u, v};
        out[u].emplace_back(v, i);
        out[v].emplace_back(u, i);
    }

    is_bridge = std::vector<bool>(m, false);
    tin = std::vector<int>(n, 0);
    low = std::vector<int>(n, 0);
    for (int i = 0; i < n; ++i) {
        if (tin[i] == 0) {
            DfsBridges(i, -1);
        }
    }
    
    std::cout << std::accumulate(is_bridge.begin(), is_bridge.end(), 0) << '\n';
    for (int i = 0; i < m; ++i) {
        if (is_bridge[i]) {
            std::cout << i + 1 << ' ';
        }
    }
}

