#include <bits/stdc++.h> 
using namespace std;

// Câu 1:
class SP1 {
protected:
    double thuc, ao;

public:
    SP1(double t = 0, double a = 0) {
        thuc = t;
        ao = a;
    }

    void nhap() {
        cout << "  Nhap phan thuc: ";
        cin >> thuc;
        cout << "  Nhap phan ao: ";
        cin >> ao;
    }

    void in() {
        if (ao >= 0)
            cout << thuc << " + " << ao << "i";
        else
            cout << thuc << " - " << -ao << "i";
    }

    double module() {
        return sqrt(thuc * thuc + ao * ao);
    }
};

//  Câu 2:
class SP2 : public SP1 {
public:
    SP2(double t = 0, double a = 0) : SP1(t, a) {}

    SP2& operator=(const SP2& b) {
        thuc = b.thuc;
        ao = b.ao;
        return *this;
    }

    bool operator>(SP2 b) {
        return module() > b.module();
    }
};

// ===== Câu 3: 
int main() {
    SP2 a[10];
    int n;

    do {
        cout << "Nhap so phan tu (1-10): ";
        cin >> n;
    } while (n < 1 || n > 10);

    for (int i = 0; i < n; i++) {
        cout << "So phuc thu " << i + 1 << ":\n";
        a[i].nhap();
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {
                SP2 tam = a[i];
                a[i] = a[j];
                a[j] = tam;
            }
        }
    }

    cout << "\nDanh sach sau khi sap xep giam dan theo module:\n";
    for (int i = 0; i < n; i++) {
        a[i].in();
        cout << "  (module = " << a[i].module() << ")\n";
    }

    return 0;
}
