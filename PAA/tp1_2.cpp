#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<string> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    vector<string> b(n);
    unordered_map<string, int> pos_b;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (!pos_b.contains(b[i])) {
            pos_b[b[i]] = i;
        }
    }

    // stock -> next stock, total_sum
    unordered_map<string, pair<int, int>> dp;
    for (int i = m - 1; i >= 0; i--) {
        const string& current_stock = a[i];
        if (!pos_b.contains(current_stock)) continue;

        dp[current_stock] = make_pair(-1, 1);
        for (int j = pos_b[current_stock]; j < n; j++) {
            const string& next_stock = b[j];
            if (next_stock == current_stock) continue;
            if (dp.contains(next_stock) && (dp[next_stock].second >= dp[current_stock].second)) {
                int new_total = dp[b[j]].second + 1;
                dp[a[i]] = make_pair(j, new_total);
            }
        }
    }

    pair<string, pair<int, int>> biggest = make_pair("", make_pair(-1, -1));
    for(pair<string, pair<int, int>> key : dp) {
        if (biggest.first.empty() || key.second.second > biggest.second.second) {
            biggest = key;
        }
    }

    cout << (biggest.second.second != -1 ? biggest.second.second : 0) << "\n";
    if (biggest.second.second != -1) {
        pair<string, pair<int, int>> next_display = biggest;
        cout << next_display.first << " ";
        while (next_display.second.first != -1) {
            const string& next_str = b[next_display.second.first];
            next_display = make_pair(next_str, dp[next_str]);
            cout << next_display.first << " ";
        }
    }
    cout << "\n";

    return 0;
}