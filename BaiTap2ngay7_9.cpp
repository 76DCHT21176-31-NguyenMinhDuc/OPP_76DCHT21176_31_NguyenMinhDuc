#include <iostream>
using namespace std;

class PhanSo {
public:
    int tu, mau;

    PhanSo() {
        tu = 0;
        mau = 1;
    }

    PhanSo(int t, int m) {
        tu = t;
        mau = m;
    }

    ~PhanSo() {
    }

    void rutGon() {
        int a = tu, b = mau;
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b != 0) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        if (a != 0) {
            tu = tu / a;
            mau = mau / a;
        }
    }

    friend istream& operator>>(istream &in, PhanSo &p) {
        cout << "Nhap tu so: ";
        in >> p.tu;
        cout << "Nhap mau so: ";
        in >> p.mau;
        return in;
    }

    friend ostream& operator<<(ostream &out, PhanSo &p) {
        out << p.tu << "/" << p.mau;
        return out;
    }

    PhanSo operator+(PhanSo p2) {
        PhanSo kq(tu * p2.mau + p2.tu * mau, mau * p2.mau);
        kq.rutGon();
        return kq;
    }

    PhanSo operator-(PhanSo p2) {
        PhanSo kq(tu * p2.mau - p2.tu * mau, mau * p2.mau);
        kq.rutGon();
        return kq;
    }

    PhanSo operator*(PhanSo p2) {
        PhanSo kq(tu * p2.tu, mau * p2.mau);
        kq.rutGon();
        return kq;
    }

    PhanSo operator/(PhanSo p2) {
        PhanSo kq(tu * p2.mau, mau * p2.tu);
        kq.rutGon();
        return kq;
    }
};
int main() {
    PhanSo p1, p2;
    cout << "Nhap phan so thu nhat:\n";
    cin >> p1;
    cout << "Nhap phan so thu hai:\n";
    cin >> p2;
    PhanSo tong = p1 + p2;
    PhanSo hieu = p1 - p2;
    PhanSo tich = p1 * p2;
    PhanSo thuong = p1 / p2;
    cout << "\nTong: " << tong;
    cout << "\nHieu: " << hieu;
    cout << "\nTich: " << tich;
    cout << "\nThuong: " << thuong;
    cout << endl;
    return 0;
}
