#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /*
    Sortowanie tablicy
    int n; cin >> n;
    int a[10];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }*/

    /*vector<int> vec(n, 0);
    vec.push_back(5);
    cout << vec.back() << '\n';
    vec.pop_back();
    cout << vec.size() << '\n';
    cout << vec.empty() << '\n';*/

    int n; cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    vec.push_back(100);
    vec.push_back(200);
    cout << vec.back() << '\n';
    vec.pop_back();
    cout << vec.back() << '\n';

    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ' ';
    }

    return 0;
}