// clang-format off
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

const int cINF = 1e9;

int main() {
	int n;
	int m;
	std::cin >> n;
	std::cin >> m;

	std::vector<int> w(n);
	std::vector<int> c(n);

	for (int i = 0; i < n; ++i) {
		int wi;
		std::cin >> wi;
		w[i] = wi;
	}
	for (int i = 0; i < n; ++i) {
		int wi;
		std::cin >> wi;
		c[i] = wi;
	}

	std::vector<std::vector<int>> dp(n, std::vector<int>(m + 1, -cINF));
	std::vector<std::vector<int>> dp_ind(n, std::vector<int>(m + 1, -1));
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		if (i != 0) {
			for (int j = 0; j < m + 1; ++j) {
				dp[i][j] = dp[i - 1][j];
				dp_ind[i][j] = dp_ind[i - 1][j];
			}
		}

		for (int j = m; j >= w[i]; --j) {
			int new_val = dp[i][j - w[i]] + c[i];
			if (new_val > dp[i][j]) {
				dp[i][j] = new_val;
				dp_ind[i][j] = i;
			}
		}
	}

	// Print(dp);
	// Print(dp_ind);

	int i = n - 1;
	int j = std::max_element(dp[n - 1].begin(), dp[n - 1].end()) - dp[n - 1].begin();
	std::stack<int> res;

	while (i >= 0) {
		int d = dp_ind[i][j];
		if (d == -1) {
			break;
		}
		res.push(d);

		int new_i = d - 1;
		j -= w[d];
		i = new_i;
	}

	while (!res.empty()) {
		std::cout << res.top() + 1 << '\n';
		res.pop();
	}
}