#include <iostream>
#include <cmath>
using namespace std;

class PhanSo {
private:
    int tuSo;
    int mauSo;

    // Tìm u?c chung l?n nh?t - dùng d? rút g?n phân s?
    int UCLN(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return (a == 0) ? 1 : a; // tránh chia cho 0 khi a = b = 0
    }

public:
    // Câu 1: Hàm t?o không d?i
    PhanSo() {
        tuSo = 0;
        mauSo = 1;
    }

    // Câu 1: Hàm t?o có d?i
    PhanSo(int ts, int ms) {
        tuSo = ts;
        mauSo = (ms != 0) ? ms : 1; // d? phòng m?u s? = 0
    }

    // Câu 1: Hàm h?y
    ~PhanSo() {
        // Hàm h?y du?c g?i t? d?ng khi d?i tu?ng k?t thúc vòng d?i
        // Có th? b? dòng cout du?i n?u không c?n minh h?a
        // cout << "Huy doi tuong phan so " << tuSo << "/" << mauSo << endl;
    }

    // Câu 2: Nh?p phân s? t? bàn phím
    void nhap() {
        cout << "Nhap tu so: ";
        cin >> tuSo;
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> mauSo;
            if (mauSo == 0)
                cout << "Mau so khong duoc bang 0, vui long nhap lai!\n";
        } while (mauSo == 0);
    }

    // Câu 2: Xu?t phân s? ra màn hình
    void xuat() const {
        cout << tuSo << "/" << mauSo;
    }

    // Câu 2: Rút g?n phân s?
    void rutGon() {
        int uc = UCLN(tuSo, mauSo);
        tuSo /= uc;
        mauSo /= uc;
        // Ðua d?u âm v? t? s? (m?u s? luôn duong)
        if (mauSo < 0) {
            mauSo = -mauSo;
            tuSo = -tuSo;
        }
    }

    // Câu 2: C?ng hai phân s?
    PhanSo cong(const PhanSo &p2) const {
        PhanSo kq;
        kq.tuSo = tuSo * p2.mauSo + p2.tuSo * mauSo;
        kq.mauSo = mauSo * p2.mauSo;
        kq.rutGon();
        return kq;
    }

    // Câu 2: Tr? hai phân s?
    PhanSo tru(const PhanSo &p2) const {
        PhanSo kq;
        kq.tuSo = tuSo * p2.mauSo - p2.tuSo * mauSo;
        kq.mauSo = mauSo * p2.mauSo;
        kq.rutGon();
        return kq;
    }

    // Câu 2: Nhân hai phân s?
    PhanSo nhan(const PhanSo &p2) const {
        PhanSo kq;
        kq.tuSo = tuSo * p2.tuSo;
        kq.mauSo = mauSo * p2.mauSo;
        kq.rutGon();
        return kq;
    }

    // Câu 2: Chia hai phân s?
    PhanSo chia(const PhanSo &p2) const {
        PhanSo kq;
        if (p2.tuSo == 0) {
            cout << "Loi: khong the chia cho phan so co tu so = 0!\n";
            kq.tuSo = 0;
            kq.mauSo = 1;
            return kq;
        }
        kq.tuSo = tuSo * p2.mauSo;
        kq.mauSo = mauSo * p2.tuSo;
        kq.rutGon();
        return kq;
    }
};

int main() {
    PhanSo p1, p2; // dùng hàm t?o không d?i

    cout << "--- Nhap phan so thu nhat ---\n";
    p1.nhap();
    cout << "--- Nhap phan so thu hai ---\n";
    p2.nhap();

    cout << "\nPhan so thu nhat: ";
    p1.xuat();
    cout << "\nPhan so thu hai: ";
    p2.xuat();
    cout << endl;

    // Câu 3: Th?c hi?n các phép toán, k?t qu? dã du?c rút g?n trong t?ng hàm
    PhanSo tong = p1.cong(p2);
    PhanSo hieu = p1.tru(p2);
    PhanSo tich = p1.nhan(p2);
    PhanSo thuong = p1.chia(p2);

    cout << "\n--- KET QUA ---\n";
    cout << "Tong: "; p1.xuat(); cout << " + "; p2.xuat(); cout << " = "; tong.xuat(); cout << endl;
    cout << "Hieu: "; p1.xuat(); cout << " - "; p2.xuat(); cout << " = "; hieu.xuat(); cout << endl;
    cout << "Tich: "; p1.xuat(); cout << " * "; p2.xuat(); cout << " = "; tich.xuat(); cout << endl;
    cout << "Thuong: "; p1.xuat(); cout << " / "; p2.xuat(); cout << " = "; thuong.xuat(); cout << endl;

    return 0;
}
