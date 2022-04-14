#include <bits/stdc++.h>
using namespace std;

bool my_sum_comparator(pair<int, int> a, pair<int, int> b) {
    return a.first + a.second < b.first + b.second;
}

bool my_second_first_comparator(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    /* Ponizsze dwie linijki przyspiesza znacznie wasz program
    na sprawdzaczkach internetowych takich jak themis. Konretniej -- przyspiesza
    wczytywanie danych. Na niektorych problemach nie da sie dostac AC bez nich. */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int tab[10];
    cout << "tab = ";
    for (int i = 0; i < 10; ++i) {
        tab[i] = rand() % 10; // losowa liczba z przedzialu [0, 9]
        cout << tab[i] << " ";
    }
    cout << "\n";

    // Posortuj tablice. Podajemy poczatek i (koniec + 1) przedzialu, ktory chcemy posortowac.
    sort(tab, tab + 10);
    cout << "sort(tab, tab + 10);\ntab = ";
    for (int i = 0; i < 10; ++i) {
        cout << tab[i] << " ";
    }
    cout << "\n\n";
    // Na przyklad zeby posortowac przedzial [2, 3] wywolamy
    sort(tab + 2, tab + 4);

    pair<int, int> p; // para liczb
    p.first = 5;
    p.second = 10;

    pair<int, int> tab2[10]; // tablica par liczb
    cout << "tab2 = ";
    for (int i = 0; i < 10; ++i) {
        tab2[i].first = rand() % 10;
        tab2[i].second = rand() % 10;
        cout << "(" << tab2[i].first << ", " << tab2[i].second << ") ";
    }
    cout << "\n";
    sort(tab2, tab2 + 10); // posortuje nam pary defaultowym komparatorem, czyli najpierw porowna pierwsza wspolrzedna,
                            // a w przypadku remisow druga

    cout << "sort(tab2, tab2 + 10);\ntab2 = ";
    for (int i = 0; i < 10; ++i) {
        cout << "(" << tab2[i].first << ", " << tab2[i].second << ") ";
    }
    cout << "\n";

    // zeby posortowac cos w innej kolejnosci niz defaultowa, mozemy podac komparator,
    // czyli funkcje przyjmujaca dwa argumenty i zwracajaca true, jezeli pierwszy jest mniejszy od drugiego

    sort(tab2, tab2 + 10, my_sum_comparator); // posortuje wedlug sumy wspolrzednych
    cout << "sort(tab2, tab2 + 10, my_sum_comparator);\ntab2 = ";
    for (int i = 0; i < 10; ++i) {
        cout << "(" << tab2[i].first << ", " << tab2[i].second << ") ";
    }
    cout << "\n";

    sort(tab2, tab2 + 10, my_second_first_comparator); // posortuje patrzac najpierw na druga wspolrzedna
    cout << "sort(tab2, tab2 + 10, my_second_first_comparator);\ntab2 = ";
    for (int i = 0; i < 10; ++i) {
        cout << "(" << tab2[i].first << ", " << tab2[i].second << ") ";
    }
    cout << "\n";

    return 0;
}