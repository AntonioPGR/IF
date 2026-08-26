#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

int main() {

    int m, n;
    cin >> m >> n;

    vector<string> a_str(m);
    for (int i = 0; i < m; i++) cin >> a_str[i];

    unordered_map<string, int> str_to_id;
    vector<string> id_to_str;
    vector<string> b_str(n);
    vector<int> b(n);
    vector<int> pos_b;
    for (int i = 0; i < n; i++) {
        cin >> b_str[i];

        int id;
        unordered_map<string, int>::iterator it_b = str_to_id.find(b_str[i]);
        if (it_b != str_to_id.end()) {
            id = it_b->second;
        } else {
            id = id_to_str.size();
            str_to_id[b_str[i]] = id;
            id_to_str.push_back(b_str[i]);
        }

        b[i] = id;

        if (id >= pos_b.size()) {
            pos_b.resize(id + 1, -1);
        }

        if (pos_b[id] == -1) {
            pos_b[id] = i;
        }
    }

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        unordered_map<string, int>::iterator it_a = str_to_id.find(a_str[i]);
        if (it_a != str_to_id.end()) a[i] = it_a->second;
        else a[i] = -1;
    }

    int num_ids = id_to_str.size();

    vector<pair<int, int>> dp(num_ids, make_pair(-1, -1));

    for (int i = m - 1; i >= 0; i--) {
        int current_id = a[i];

        if (current_id == -1 || pos_b[current_id] == -1) continue;

        dp[current_id] = make_pair(-1, 1);
        int start_j = pos_b[current_id];

        for (int j = start_j; j < n; j++) {
            int next_id = b[j];
            if (next_id == current_id) continue;

            if (dp[next_id].second >= dp[current_id].second) {
                dp[current_id] = make_pair(j, dp[next_id].second + 1);
            }
        }
    }

    pair<int, pair<int, int>> biggest = make_pair(-1, make_pair(-1, -1));
    for (int id = 0; id < num_ids; ++id) {
        if (dp[id].second > biggest.second.second) {
            biggest = make_pair(id, dp[id]);
        }
    }

    if (biggest.second.second == -1) {
        cout << 0 << "\n\n";
        return 0;
    }

    cout << biggest.second.second << "\n";

    int current_id = biggest.first;
    cout << id_to_str[current_id] << " ";

    int next_j = biggest.second.first;
    while (next_j != -1) {
        int next_id = b[next_j];
        cout << id_to_str[next_id] << " ";
        next_j = dp[next_id].first;
    }
    cout << "\n";

    return 0;
}