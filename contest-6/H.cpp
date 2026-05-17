#include <iostream>
#include <vector>

using Ll = long long;

int main() {
	int n;
	std::cin >> n;

	/* dp[mn][mx] - количество множеств с суммой чисел n таких, что
		минимальный элемент не меньше mn, максимальный элемент не больше mx.
		Тогда шаг простой */
	std::vector<std::vector<Ll>> dp(n + 1, std::vector<Ll>(n + 1, 0));
	dp[1][1] = 1;

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			if (j < i) {
				continue;
			}
			dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
		}
	}
}