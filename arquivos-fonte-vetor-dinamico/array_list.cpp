#include <iostream>
#include "array_list.hpp"
using namespace std;

int main() {
    vetorDinamico lista;
    int x;
    for (int i = 0; i < 8; i++) {
        cin >> x;
        lista.push_back(x);
    }

    cout << lista.front() << "\n";
    cout << lista.back() << "\n";
    lista.push_front(9);

    for (int i = 0; i < 9; i++) {
        cout << lista.get_at(i) << " ";
    }

    return 0;
 }
