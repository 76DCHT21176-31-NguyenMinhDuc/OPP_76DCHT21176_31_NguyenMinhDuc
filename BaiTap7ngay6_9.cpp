#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int SOMON = 4; // so mon hoc can nhap diem
struct SinhVien {
    string hoTen;
    int namSinh;
    float diem[SOMON];
};
// ===================== CAU 1 =====================
// Nhap thong tin 1 sinh vien: ho ten, nam sinh, diem 4 mon hoc
void nhapSinhVien(SinhVien &sv) {
    cout << "Nhap ho ten: ";
    cin.ignore();
    getline(cin, sv.hoTen);
    cout << "Nhap nam sinh: ";
    cin >> sv.namSinh;
    for (int i = 0; i < SOMON; i++) {
        cout << "Nhap diem mon " << i + 1 << ": ";
        cin >> sv.diem[i];
    }
}
// Xuat thong tin 1 sinh vien ra man hinh
void xuatSinhVien(const SinhVien &sv) {
    cout << left << setw(20) << sv.hoTen
         << setw(10) << sv.namSinh;
    for (int i = 0; i < SOMON; i++)
        cout << setw(6) << fixed << setprecision(1) << sv.diem[i];
    cout << endl;
}

// ===================== CAU 2 =====================
// Tinh diem trung binh (DTB) cua mot sinh vien
float tinhDiemTB(const SinhVien &sv) {
    float tong = 0;
    for (int i = 0; i < SOMON; i++)
        tong += sv.diem[i];
    return tong / SOMON;
}
// ===================== CAU 3 =====================
bool phaiThiTotNghiep(const SinhVien &sv) {
    float dtb = tinhDiemTB(sv);
    if (dtb >= 7) return false; // da du dieu kien, khong phai thi lai

    for (int i = 0; i < SOMON; i++) {
        if (sv.diem[i] < 5) return false; // co mon duoi 5 -> khong thuoc dien nay
    }
    return true;
}
void inTieuDe() {
    cout << left << setw(20) << "Ho ten" << setw(10) << "Nam sinh";
    for (int i = 0; i < SOMON; i++)
        cout << "Mon" << i + 1 << "  ";
    cout << "DTB" << endl;
}
int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    SinhVien *ds = new SinhVien[n];
    // Nhap n sinh vien
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap sinh vien thu " << i + 1 << " ---\n";
        nhapSinhVien(ds[i]);
    }
    // In danh sach toan bo sinh vien kem DTB
    cout << "\n===== DANH SACH SINH VIEN =====\n";
    inTieuDe();
    for (int i = 0; i < n; i++) {
        xuatSinhVien(ds[i]);
        cout << "-> Diem trung binh: " << fixed << setprecision(2)
             << tinhDiemTB(ds[i]) << endl;
    }
    // In danh sach sinh vien phai thi tot nghiep
    cout << "\n===== SINH VIEN PHAI THI TOT NGHIEP =====\n";
    inTieuDe();
    bool coSV = false;
    for (int i = 0; i < n; i++) {
        if (phaiThiTotNghiep(ds[i])) {
            xuatSinhVien(ds[i]);
            coSV = true;
        }
    }
    if (!coSV)
        cout << "Khong co sinh vien nao thuoc dien nay.\n";
    delete[] ds;
    return 0;
}
