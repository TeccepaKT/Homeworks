// clang-format off
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
#define uset std::unordered_set
#define umap std::unordered_map
#define pii std::pair<int, int>
using std::vector;
using std::pair;

const int cMax = 2009000999;

void Test() {
  int n;
  int m;
  cin >> n;
  cin >> m;

  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; ++i) {
    int u;
    int v;
    int c;
    cin >> u;
    cin >> v;
    cin >> c;

    g[u].push_back({v, c});
    g[v].push_back({u, c});
  }

  int s;
  cin >> s;

  vector<int> res(n, cMax);
  uset<int> been;
  std::priority_queue<pii, vector<pii>, std::greater<pii>> heap;  // <Вес, Вершина>
  heap.push({0, s});

  while (!heap.empty()) {
    auto [pt, v] = heap.top();
    heap.pop();

    if (been.contains(v)) {
      continue;
    }
    res[v] = pt;
    been.emplace(v);

    for (auto [u, w] : g[v]) {
      if (been.contains(u)) {
        continue;
      }
      heap.push({pt + w, u});
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << res[i] << ' ';
  }
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    Test();
  }
}

