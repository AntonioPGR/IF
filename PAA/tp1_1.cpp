#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    int m, n;
    cin >> m >> n;

    vector<string> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    vector<string> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<string> max_seq, cur_seq;
    for (int i = 0; i < m; i++) {
        cur_seq.clear();
        int last_find_idx = 0;
        for (int j = i; j < m; j++) {
            const string& search = a[j];
            int find_idx = -1;
            for (int k = last_find_idx; k < b.size(); k++) {
                if (b[k] == search) {
                    find_idx = k;
                }
            }
            if (find_idx == -1) continue;
            last_find_idx = find_idx;
            cur_seq.push_back(search);
            if (last_find_idx == m - 1) break;
        }
        if (cur_seq.size() > max_seq.size()) {
            max_seq.clear();
            for (const string& s : cur_seq) max_seq.push_back(s);
        }
    }

    cout << max_seq.size() << endl;
    for (const string& s : max_seq) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}