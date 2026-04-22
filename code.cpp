#include <bits/stdc++.h>
using namespace std;

class mystring {
private:
    char *ch = nullptr;
    int len = 0;

public:
    mystring() : ch(nullptr), len(0) {}

    mystring(int _len, int c) : ch(nullptr), len(0) {
        if (_len > 0) {
            len = _len;
            ch = new char[len];
            for (int i = 0; i < len; ++i) ch[i] = static_cast<char>(c);
        }
    }

    mystring(string &c) : ch(nullptr), len(0) {
        len = static_cast<int>(c.length());
        if (len > 0) {
            ch = new char[len];
            memcpy(ch, c.data(), len);
        }
    }

    // deep copy constructor
    mystring(const mystring &o) : ch(nullptr), len(o.len) {
        if (len > 0 && o.ch) {
            ch = new char[len];
            memcpy(ch, o.ch, len);
        }
    }

    // copy assignment (deep copy)
    mystring &operator=(const mystring &o) {
        if (this == &o) return *this;
        char *nch = nullptr;
        if (o.len > 0 && o.ch) {
            nch = new char[o.len];
            memcpy(nch, o.ch, o.len);
        }
        delete[] ch;
        ch = nch;
        len = o.len;
        return *this;
    }

    ~mystring() { delete[] ch; }

    int get_len() { return len; }

    void out() {
        if (len == 0 || ch == nullptr) return;
        cout.write(ch, len);
    }

    // index operator: if out of range, return '\0'
    char operator[](int x) {
        if (x < 0 || x >= len || ch == nullptr) return '\0';
        return ch[x];
    }

    bool operator<(const mystring &rhs) const {
        int n = min(len, rhs.len);
        for (int i = 0; i < n; ++i) {
            char a = (ch ? ch[i] : '\0');
            char b = (rhs.ch ? rhs.ch[i] : '\0');
            if (a < b) return true;
            if (a > b) return false;
        }
        return len < rhs.len;
    }

    void ADD(const mystring &other) {
        if (other.len == 0) return;
        char *nch = new char[len + other.len];
        if (len > 0 && ch) memcpy(nch, ch, len);
        if (other.len > 0 && other.ch) memcpy(nch + len, other.ch, other.len);
        delete[] ch;
        ch = nch;
        len = len + other.len;
    }
};

string str_in1, str_in2;
int n, id;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> id)) return 0;
    if (id == 1) {
        mystring str1(100, 'a');
        str1.out();
        cout << '\n';
        // cout << str1 << endl;
    } else if (id == 2) {
        cin >> str_in1;
        mystring str2 = str_in1;
        cin >> n;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            cout << str2[x] << '\n';
        }
    } else if (id == 3) {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cout << (int)(str2 < str3) << '\n';
    } else if (id == 4) {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        str2.ADD(str3);
        str2.out();
        cout << '\n';
        // cout << str2 << endl;
    } else {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cin >> n;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            cout << str3[x] << '\n';
        }
        cout << str2.get_len() << ' ' << str3.get_len() << '\n';
        cout << (int)(str2 < str3) << '\n';
        str2.ADD(str3);
        str2.out();
        cout << '\n';
        // cout << str2 << endl;
        cout << str2.get_len() << '\n';
    }
    return 0;
}
