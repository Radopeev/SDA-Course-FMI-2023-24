#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> arr(256);
    for (int i = 0; i < s.size(); i++) {
        arr[s[i]]++;
    }
    for (int i = 0; i < s.size(); i++) {
        if (arr[s[i]] == 1) {
            cout << i << " ";
        }
    }
    return 0;
}