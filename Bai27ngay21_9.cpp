#include <iostream>
#include <cmath>

using namespace std;
int ucln(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
// CÂU 1:
class PS1 {
protected:
    int tu;  
    int mau; 
public:
    PS1(int t = 0, int m = 1) : tu(t), mau(m == 0 ? 1 : m) {}
    void nhap() {
        cout << "  Nhap tu so: ";
        cin >> tu;
        do {
            cout << "  Nhap mau so (khac 0): ";
            cin >> mau;
            if (mau == 0) {
                cout << "  [Loi] Mau so phai khac 0. Vui long nhap lai!\n";
            }
        } while (mau == 0);
        
        toiGian(); 
    }
    void toiGian() {
        if (mau < 0) { 
            tu = -tu;
            mau = -mau;
        }
        int g = ucln(tu, mau);
        if (g != 0) {
            tu /= g;
            mau /= g;
        }
    }
    void inPS() const {
        if (mau == 1) {
            cout << tu;
        } else {
            cout << tu << "/" << mau;
        }
    }
};
// CÂU 2: 
class PS2 : public PS1 {
public:
    PS2(int t = 0, int m = 1) : PS1(t, m) {}
    PS2& operator=(const PS2& other) {
        if (this != &other) {
            tu = other.tu;
            mau = other.mau;
        }
        return *this;
    }
    bool operator>(const PS2& other) const {
        // So sánh 
        return (this->tu * other.mau) > (other.tu * this->mau);
    }
};
// CÂU 3:
int main() {
    int n;
    PS2 ds[10]; 
    do {
        cout << "Nhap so luong phan so (1 <= n <= 10): ";
        cin >> n;
        if (n < 1 || n > 10) {
            cout << "So luong khong hop le! Vui long nhap lai.\n";
        }
    } while (n < 1 || n > 10);
    cout << "\n=== NHAP DANH SACH PHAN SO ===\n";
    for (int i = 0; i < n; ++i) {
        cout << "Phan so th? " << i + 1 << ":\n";
        ds[i].nhap();
    }

    cout << "\nDanh sach phan so vua nhap (da toi gian): ";
    for (int i = 0; i < n; ++i) {
        ds[i].inPS();
        cout << "   ";
    }
    cout << endl;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (ds[j] > ds[i]) {
                PS2 temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    cout << "\nDanh sach phan so sau khi sap xep GIAM DAN: ";
    for (int i = 0; i < n; ++i) {
        ds[i].inPS();
        cout << "   ";
    }
    cout << endl;
    return 0;
}
