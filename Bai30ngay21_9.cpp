#include <bits/stdc++.h>
using namespace std;

// ========================== CÂU 1 ==========================
class SP1 {
protected:
    double thuc;
    double ao;

public:
    SP1(double t = 0, double a = 0) {
        thuc = t;
        ao = a;
    }

    virtual void nhap() {
        cout << "Nhap phan thuc: ";
        cin >> thuc;
        cout << "Nhap phan ao: ";
        cin >> ao;
    }

    virtual void in() const {
        if (ao < 0)
            cout << thuc << " - " << -ao << "i";
        else if (ao > 0)
            cout << thuc << " + " << ao << "i";
        else
            cout << thuc;
    }

    double tinhModule() const {
        return sqrt(thuc * thuc + ao * ao);
    }
};
// ========================== CÂU 2 ==========================
class SP2 : public SP1 {
public:
    SP2(double t = 0, double a = 0) : SP1(t, a) {}

    SP2& operator=(const SP2& other) {
        if (this != &other) {
            thuc = other.thuc;
            ao = other.ao;
        }
        return *this;
    }

    bool operator>(const SP2& other) const {
        return this->tinhModule() > other.tinhModule();
    }
};

// ========================== CÂU 3 ==========================
int main() {
    int n;
    cout << "Nhap so luong so phuc (toi da 10): ";
    cin >> n;
    if (n <= 0 || n > 10) {
        cout << "So lu?ng phan tu khong hop le! Vui long nhap tu 1 den 10.\n";
        return 0;
    }
    SP2 danhSach[10];

    cout << "\n--- NHAP DANH SACH SO PHUC ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Nhap so phuc thu " << i + 1 << ":\n";
        danhSach[i].nhap();
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
    
            if (danhSach[j] > danhSach[i]) {
                SP2 temp = danhSach[i]; 
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }

    cout << "\n--- DANH SACH SAU KHI SAP XEP GIAM DAN THEO MODULE ---\n";
    for (int i = 0; i < n; i++) {
        cout << "So phuc " << i + 1 << ": ";
        danhSach[i].in();
        cout << " (Module = " << danhSach[i].tinhModule() << ")\n";
    }

    return 0;
}
