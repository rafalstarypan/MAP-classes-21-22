#include<bits/stdc++.h>
using namespace std;

int dodaj(int a, int b) {
    return a + b;
}

void witaj() {
    cout << "Hello\n";
}

int main() {

    witaj();

    int a = dodaj(5, 6);
    int b = dodaj(7, 8);
    int c = dodaj(20, 30);

    cout << a << " " << b << " " << c;

    return 0;
}