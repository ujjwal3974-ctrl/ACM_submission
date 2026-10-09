#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> movies(n);

    for (int i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }

    sort(movies.begin(), movies.end(), [](auto a, auto b) {
        return a.second < b.second;
    });

    int count = 0;
    int lastEnd = 0;

    for (int i = 0; i < n; i++) {
        if (movies[i].first >= lastEnd) {
            count++;
            lastEnd = movies[i].second;
        }
    }

    cout << count << endl;

    return 0;
}