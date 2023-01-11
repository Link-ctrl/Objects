#include <iostream>

using namespace std;

class mString {
private:
  char *st;

public:
  mString() { st = NULL; }

  void test() {
    st = new char(10);
    char c = 'a';
    for (int i = 0; i < 10; i++)
      st[i] = c++;
    st[9] = '\0';
    cout << st;
  }

  ~mString() {
    if (st)
      delete st;
  }

  mString substr(int start, int count);
  int find(const mString &s);
  mString replace(mString &s1, mString &s2);
  mString replace(mString &s, char *c);
  mString replace(char *c, mString &s);
  mString replace(char *c1, char *c2);
  mString replace_k(mString &s1, mString &s2, int count);

  void operator=(const mString &s);
  void operator=(const char *c);
  mString operator+(const mString &s) const;
  mString operator+(const char *s) const;
  friend mString operator+(const char *c, const mString &s);

  friend bool operator==(const mString &a, const mString &b);
  friend bool operator>(const mString &a, const mString &b);
  friend bool operator>=(const mString &a, const mString &b);
  friend bool operator<(const mString &a, const mString &b);
  friend bool operator<=(const mString &a, const mString &b);

  friend istream &operator>>(istream &in, mString &s);
  friend ostream &operator<<(ostream &out, const mString &s);
};

ostream &operator<<(ostream &out, const mString &s) {
  out << s.st;
  return out;
}

istream &operator>>(istream &in, mString &s) {
  char buf[10000], t;
  int i, k = 0;
  t = in.get();
  while ((int)(t) != 10) {
    buf[k++] = t;
    t = in.get();
  }
  if (s.st)
    delete s.st;
  s.st = new char[k + 1];
  for (i = 0; i < k; i++)
    s.st[i] = buf[i];
  s.st[i] = '\0';
  return in;
}

void mString::operator=(const mString &s) {
  if (st)
    delete st;
  int i, k = 0;
  while (s.st[k++])
    ;
  st = new char[k];
  for (i = 0; i < k; i++)
    st[i] = s.st[i];
}

void mString::operator=(const char *c) {
  if (st)
    delete st;
  int i, l = 0;
  while (c[l++])
    ;
  st = new char[l];
  for (i = 0; i < l; i++)
    st[i] = c[i];
  st[i] = '\0';
}

mString mString::operator+(const mString &b) const {
  int i, j, k = 0, l = 0;
  mString ou;

  while (st[k++])
    ;
  k--;
  while (b.st[l++])
    ;
  l--;
  if (ou.st)
    delete ou.st;

  ou.st = new char[k + l];
  for (i = 0; i < k; i++)
    ou.st[i] = st[i];
  for (j = k; j < k + l; j++)
    ou.st[j] = b.st[j - k];
  ou.st[j] = '\0';

  return ou;
}

mString mString::operator+(const char *s) const {
  int i, j, k = 0, l = 0;
  mString ou;

  while (st[k++])
    ;
  k--;
  while (s[l++])
    ;
  l--;
  if (ou.st)
    delete ou.st;

  ou.st = new char[k + l];
  for (i = 0; i < k; i++)
    ou.st[i] = st[i];
  for (j = k; j < k + l; j++)
    ou.st[j] = s[j - k];
  ou.st[j] = '\0';

  return ou;
}

mString operator+(const char *c, const mString &s) {
  int i, j, k = 0, l = 0;
  mString ou;

  while (c[k++])
    ;
  k--;
  while (s.st[l++])
    ;
  l--;
  if (ou.st)
    delete ou.st;

  ou.st = new char[k + l];
  for (i = 0; i < k; i++)
    ou.st[i] = c[i];
  for (j = k; j < k + l; j++)
    ou.st[j] = s.st[j - k];
  ou.st[j] = '\0';

  return ou;
}

bool operator==(const mString &a, const mString &b) {
  int i, j, k = 0, l = 0;

  while (a.st[k++])
    ;
  k--;
  while (b.st[l++])
    ;
  l--;
  if (k != l)
    return 0;

  for (i = 0; i < k; i++)
    if (a.st[i] != b.st[i])
      return 0;

  return 1;
}

bool operator!=(const mString &a, const mString &b) { return !(a == b); }

bool operator>(const mString &a, const mString &b) {
  int i, j, k = 0, l = 0;

  while (a.st[k++])
    ;
  k--;
  while (b.st[l++])
    ;
  l--;
  int r = k;
  if (l < r)
    r = l;

  for (i = 0; i <= r; i++) {
    if (a.st[i] > b.st[i])
      return 1;
    if (a.st[i] < b.st[i])
      return 0;
  }
  return 0;
}

bool operator>=(const mString &a, const mString &b) {
  int i, j, k = 0, l = 0;

  while (a.st[k++])
    ;
  k--;
  while (b.st[l++])
    ;
  l--;
  int r = k;
  if (l < r)
    r = l;

  for (i = 0; i <= r; i++) {
    if (a.st[i] > b.st[i])
      return 1;
    if (a.st[i] < b.st[i])
      return 0;
  }
  return 1;
}

bool operator<(const mString &a, const mString &b) {
  int i, j, k = 0, l = 0;

  while (a.st[k++])
    ;
  k--;
  while (b.st[l++])
    ;
  l--;
  int r = k;
  if (l < r)
    r = l;

  for (i = 0; i <= r; i++) {
    if (a.st[i] < b.st[i])
      return 1;
    if (a.st[i] > b.st[i])
      return 0;
  }
  return 0;
}

bool operator<=(const mString &a, const mString &b) {
  int i, j, k = 0, l = 0;

  while (a.st[k++])
    ;
  k--;
  while (b.st[l++])
    ;
  l--;
  int r = k;
  if (l < r)
    r = l;

  for (i = 0; i <= r; i++) {
    if (a.st[i] < b.st[i])
      return 1;
    if (a.st[i] > b.st[i])
      return 0;
  }
  return 1;
}

mString mString::substr(int start, int count) {
  mString ou;
  int k = start;
  ou.st = new char[count + 1];
  for (int i = 0; i < count; i++, k++)
    ou.st[i] = st[k];
  ou.st[count + 1] = '\0';
  return ou;
}

int mString::find(const mString &s) {
  int i, k = 0, l = 0;

  while (st[k++])
    ;
  while (s.st[l++])
    ;
  l--;

  for (i = 0; i < k; i++) {
    if (st[i] == s.st[0]) {
      if (substr(i, l) == s)
        return i;
    }
  }

  return -1;
}

mString mString::replace(mString &s1, mString &s2) {
  mString ou;
  int i = 0, l = 0, k = 0, p = 0, index;
  index = find(s1);

  while (s1.st[l++])
    ;
  l--;
  while (s2.st[k++])
    ;
  k--;
  while (st[p++])
    ;
  p--;

  ou.st = new char[p - l + k];

  for (i; i < index; i++)
    ou.st[i] = st[i];
  for (i; i < k + index; i++)
    ou.st[i] = s2.st[i - index];
  for (i; i <= (p - l + k); i++)
    ou.st[i] = st[i - l + index];

  return ou;
}

mString mString::replace(mString &s, char *c) {
  mString ch;
  int i, l = 0;

  while (c[l++])
    ;
  ch.st = new char[l];

  for (i = 0; i < l; i++)
    ch.st[i] = c[i];
  ch.st[i] = '\0';

  return replace(s, ch);
}

mString mString::replace(char *c, mString &s) {
  mString ch;
  int i, l = 0;

  while (c[l++])
    ;
  ch.st = new char[l];

  for (i = 0; i < l; i++)
    ch.st[i] = c[i];
  ch.st[i] = '\0';

  return replace(ch, s);
}

mString mString::replace(char *c1, char *c2) {
  mString ch1, ch2;
  int i, j, l = 0, k = 0;

  while (c1[l++])
    ;
  ch1.st = new char[l];
  for (i = 0; i < l; i++)
    ch1.st[i] = c1[i];
  ch1.st[i] = '\0';

  while (c2[k++])
    ;
  ch2.st = new char[k];
  for (j = 0; j < k; j++)
    ch2.st[j] = c2[j];
  ch2.st[j] = '\0';

  return replace(ch1, ch2);
}

mString mString::replace_k(mString &s1, mString &s2, int count) {
  mString ou;
  ou = replace(s1, s2);
  for (int i = 1; i < count; i++) {
    ou = ou.replace(s1, s2);
  };
  return ou;
}

class Tpeep {
protected:
  mString name, surname, otch, dr;
  int state;

public:
  virtual void print() = 0;
  virtual void create(mString &nm, mString &snm, mString &ot, mString &d) {
    name = nm;
    surname = snm;
    otch = ot;
    dr = d;
  }
  virtual void create(const char *nm, const char *snm, const char *ot,
                      const char *d) {
    name = nm;
    surname = snm;
    otch = ot;
    dr = d;
  }
  int getState() { return state; }
};

class Tstudent : public Tpeep {
protected:
  int marks[5];

public:
  Tstudent() {
    state = 0;
    for (int i = 0; i < 5; i++)
      marks[i] = 0;
  }
  Tstudent(mString &n, mString &s, mString &o, mString &d) {
    state = 0;
    name = n;
    surname = s;
    otch = o;
    dr = d;
  }

  void markSet(int i, int vi) { marks[i] = vi; }
  int markGet(int i) { return marks[i]; }

  void print() {
    cout << "Студент" << endl;
    cout << surname << ' ' << ' ' << name << ' ' << otch << ' ' << dr << endl;
    cout << "Оценки: ";
    for (int i = 0; i < 5; i++)
      cout << " " << markGet(i);
    cout << endl;
  }
};

class Tteacher : public Tpeep {
protected:
  mString *subjs = new mString[5];

public:
  Tteacher() { state = 1; }
  Tteacher(mString &n, mString &s, mString &o, mString &d) {
    state = 1;
    name = n;
    surname = s;
    otch = o;
    dr = d;
  }
  void print() {
    cout << "Преподаватель" << endl;
    cout << surname << ' ' << name << ' ' << otch << ' ' << dr << endl;
    cout << "Предметы: ";
    for (int i = 0; i < 5; i++) {
      cout << subjs[i] << " ";
    }
    cout << endl;
  }

  void subjSet(int i, mString &sub) { subjs[i] = sub; }
  mString subjGet(int i) { return subjs[i]; }
};

class fabrika {
public:
  Tpeep *create(const char *nm, const char *snm, const char *ot, const char *d,
                int type) {
    mString nm1, snm1, ot1, d1;
    nm1 = nm;
    snm1 = snm;
    ot1 = ot;
    d1 = d;
    return create(nm1, snm1, ot1, d1, type);
  }

  Tpeep *create(mString &nm, mString &snm, mString &ot, mString &d, int type) {
    Tpeep *res = NULL;
    if (type == 0) {
      res = new Tstudent;
      res->create(nm, snm, ot, d);
    } else if (type == 1) {
      res = new Tteacher;
      res->create(nm, snm, ot, d);
    }
    return res;
  }
};

class builder2 {
public:
  void inputMarks(Tstudent *person) {
    int i, o;
    cout << "Введите оценки" << endl;
    for (i = 0; i < 5; i++) {
      cout << "[" << i << "]";
      cin >> o;
      person->markSet(i, o);
    }
  }
  void inputSubjs(Tteacher *person) {
    int i;
    mString sub;
    cout << "Введите предметы" << endl;
    for (i = 0; i < 5; i++) {
      cout << "[" << i << "]";
      cin >> sub;
      person->subjSet(i, sub);
    }
  }
};

int main1() {
  /* mString n, s, o, d;
  n = "Иван";
  s = "Крэйг";
  o = "Петрович";
  d = "1965-05-13";
  Tpeep *st1 = new Tstudent(n,s,o,d);
  st1->print();
  delete st1;*/
  builder2 uchOtdel;
  mString n, s, o, d;
  fabrika dekanat;
  int k = 1, t, i;
  mString tmp;
  Tpeep **peeps = new Tpeep *[k];
  for (i = 0; i < k; i++) {
    cout << "Введите фамилию: ";
    cin >> s;
    cout << "Введите имя: ";
    cin >> n;
    cout << "Введите отчество: ";
    cin >> o;
    cout << "Введите дату рождения: ";
    cin >> d;
    cout << "Введите статус: ";
    cin >> t;
    cin >> tmp;

    peeps[i] = dekanat.create(n, s, o, d, t);
    if (t == 0) {
      uchOtdel.inputMarks((Tstudent *)peeps[i]);
    } else if (t == 1) {
      uchOtdel.inputSubjs((Tteacher *)peeps[i]);
    }
  }

  for (i = 0; i < k; i++) {
    peeps[i]->print();
  }
  delete peeps;

  // mString s, p, in1, in2;
  // s.test();
  // cout << " <- testing func-test()" << endl;
  // p = s + "hello";
  // s = "hello" + p;
  // s = "loading" + s;
  // cout<< "p = " << p;
  // cout<< "s = " << s;
  // cout<< "p=s: " << std::boolalpha << (p==s) <<endl;
  // cout<< endl << "input test: " << endl;
  // in1= "lo";
  // in2= "777";
  // cout<< in1+in2;

  // cout<< std::boolalpha << (in1!=in2) <<endl;
  // cout<< s.substr(2,4)<<endl;
  // cout<< s.find(in1) <<endl;
  // cout<< s.replace_k(in1, in2, 2) <<endl;

  return 0;
}

// replace(s1,s2), replace(s1,s2, k)
// в s заменить подстроку s1 на s2
// в s заменить подстроку s1 на s2 k раз
// доделать чтобы можно передавать "авотива"
