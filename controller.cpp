#include <iostream>

using namespace std;

class controller {
private:
  bool work;

public:
  controller() { work = true; }
  bool getWork() { return work; }
  void showMenu() {
    cout << "[1] New item" << endl;
    cout << "[2] Show items" << endl;
    cout << "[3] Load item" << endl;
    cout << "[0] Exit" << endl;
    while (getMenuItem() == -1) {
      cout << "Input wrong" << endl;
    };
  }

  int getMenuItem() {
    int i;
    char c;
    cout << "Input variant: ";
    cin >> c;
    if (c == '1') {
      cout << "вызов операции создания новой сущности" << endl;
      cin >> i;
      return 1;
    } else if (c == '2') {
      cout << "вызов операции вывода сущности" << endl;
      cin >> i;
      return 2;
    } else if (c == '3') {
      cout << "вызов операции вывода сущности" << endl;
      cin >> i;
      return 3;
    } else if (c == '0') {
      work = 0;
      return 0;
    } else {
      return -1;
    }
  }
};

int main() {
  int i;
  controller ctrl;
  while (ctrl.getWork())
    ctrl.showMenu();
  return 0;
}
