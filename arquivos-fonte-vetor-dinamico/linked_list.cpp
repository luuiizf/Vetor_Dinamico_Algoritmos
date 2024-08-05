#include "linked_list.hpp"
#include <iostream>
using namespace std;

int main() {
  listaLigada lista;
  int x;
  for (int i = 0; i < 5; i++) {
    cin >> x;
    lista.push_back(x);
  }
  cout << lista.front() << "\n";
  cout << lista.back() << "\n";
  lista.push_front(6);

  cout << "Tamanho da lista: " << lista.size() << endl;

  for (int i = 0; i < 6; i++) {
    cout << lista.get_at(i) << " ";
  }
  return 0;
}
