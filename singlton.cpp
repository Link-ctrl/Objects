#include "./Tpepp.cpp"
#include <iostream>
class mString;

using namespace std;

class Singlton {
private:
  int val;
  Singlton() { val = 0; }
  Singlton(const Singlton &);
  Singlton &operator=(Singlton &);

public:
  int getVal() { return val; }
  void setVal(int v) { val = v; }
  static Singlton &getInstance() {
    static Singlton instance;
    return instance;
  }
};

class User {
private:
  mString login;
  mString password;
  User() {
    login = "admin";
    password = "password";
  }
  User(const User &);
  User &operator=(User &);

public:
  static User &getInstance() {
    static User instance;
    return instance;
  }
  void changeLogin() {
    mString pw;
    cout << "Введите пароль:";
  }
};

int main() {
  Singlton &s = Singlton::getInstance();
  Singlton &p = Singlton::getInstance();
  cout << s.getVal() << " " << p.getVal() << endl;
  s.setVal(4);
  cout << s.getVal() << " " << p.getVal() << endl;
}
