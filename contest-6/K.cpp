// clang-format off
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

const long long cINF = 1LL << 33;

signed main() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (auto& ai : a) {
		std::cin >> ai;
	}

	std::vector<long long> dp(n, -cINF);
	std::vector<std::vector<int>> dp_ind(n);

	for (int i = 0; i < n; ++i) {
		int l = -1;
		int r = n;

		while (r > l + 1) {
			int m = (l + r) / 2;
			if (dp[m] >= a[i]) {
				l = m;
			} else {
				r = m;
			}
		}

		dp[r] = a[i];
		dp_ind[r].push_back(i);
	}

	// Print(dp);
	// Print(dp_ind);

	int r = dp.rend() - std::upper_bound(dp.rbegin(), dp.rend(), -cINF);
	int last_ind = n;
	std::cout << r << '\n';

	std::stack<int> st;
	for (int i = r - 1; i >= 0; --i) {
		for (int j = dp_ind[i].size() - 1; j >= 0; --j) {
			if (dp_ind[i][j] < last_ind) {
				st.push(dp_ind[i][j]);
				last_ind = dp_ind[i][j];
				break;
			}
		}
	}

	while (!st.empty()) {
		std::cout << st.top() + 1 << ' ';
		st.pop();
	}
}
