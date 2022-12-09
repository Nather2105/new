#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    vector<vector<int>> table(3);
    vector<int> way; 
    int n, el; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> el;
        table[0].push_back(el);
        table[1].push_back(0);
    }

    for (int i = 0; i < n - 1; i++) {
        cin >> el;
        table[2].push_back(el);
    }

    table[2][n-1] = table[1][0] = INT_MAX;

    for (int i = 1; i < n; i++) {
        int m = min(table[0][i-1], table[1][i-1]);
        table[0][i] += m;
        table[1][i] = table[2][i-1];
        table[2][i] += m;
    }

    cout << endl << min(table[0][n-1], table[1][n-1]) << endl;
    
    for (int i = 0; i < n; i++) {
        way.push_back(int(table[0][i] > table[1][i]) + 1);
    }

    for (int i = n - 1, s = 0; s != n; i--, s += way[i]) {
        cout << way[i] << ' ';
    }
    
    return 0;
}