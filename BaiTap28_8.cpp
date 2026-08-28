#include <iostream>
using namespace std;

class MaTran {
private:
    int soHang;
    int soCot;
    int **phanTu;
public:
    // Cau 2: Ham nhap du lieu cho mot doi tuong ma tran
    void Nhap() {
        cout << "Nhap so hang: ";
        cin >> soHang;
        cout << "Nhap so cot: ";
        cin >> soCot;
        // Cap phat dong mang 2 chieu
        phanTu = new int*[soHang];
        for (int i = 0; i < soHang; i++) {
            phanTu[i] = new int[soCot];
        }
        cout << "Nhap cac phan tu cua ma tran:" << endl;
        for (int i = 0; i < soHang; i++) {
            for (int j = 0; j < soCot; j++) {
                cout << "  Phan tu [" << i << "][" << j << "]: ";
                cin >> phanTu[i][j];
            }
        }
    }
    // Cau 2: Ham xuat du lieu cua mot doi tuong ma tran
    void Xuat() {
        for (int i = 0; i < soHang; i++) {
            for (int j = 0; j < soCot; j++) {
                cout << phanTu[i][j] << "\t";
            }
            cout << endl;
        }
    }
    // Cau 3: Ham ban thuc hien cong hai ma tran dong cap
    friend MaTran Cong(MaTran a, MaTran b);
};
// Dinh nghia ham ban: cong hai ma tran cung kich thuoc
MaTran Cong(MaTran a, MaTran b) {
    MaTran ketQua;
    ketQua.soHang = a.soHang;
    ketQua.soCot = a.soCot;

    ketQua.phanTu = new int*[ketQua.soHang];
    for (int i = 0; i < ketQua.soHang; i++) {
        ketQua.phanTu[i] = new int[ketQua.soCot];
        for (int j = 0; j < ketQua.soCot; j++) {
            ketQua.phanTu[i][j] = a.phanTu[i][j] + b.phanTu[i][j];
        }
    }
    return ketQua;
}
int main() {
    MaTran a, b, c;
    cout << "=== NHAP MA TRAN THU NHAT ===" << endl;
    a.Nhap();
    cout << "\n=== NHAP MA TRAN THU HAI (cung kich thuoc voi ma tran 1) ===" << endl;
    b.Nhap();
    // Cong hai ma tran bang ham ban
    c = Cong(a, b);
    cout << "\n=== MA TRAN THU NHAT ===" << endl;
    a.Xuat();
    
    cout << "\n=== MA TRAN THU HAI ===" << endl;
    b.Xuat();
    
    cout << "\n=== MA TRAN TONG (KET QUA) ===" << endl;
    c.Xuat();

    return 0;
}
