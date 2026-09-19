#include <iostream>
#include <string>
using namespace std;

// ===== Câu 1: =====
class Nguoi {
protected:              
    string hoTen;
    int namSinh;

public:
    // Câu 2
    void nhap() {
        cin.ignore();   
        cout << "  Ho ten: ";
        getline(cin, hoTen);
        cout << "  Nam sinh: ";
        cin >> namSinh;
    }
    void xuat() {
        cout << "Ho ten: " << hoTen
             << " - Nam sinh: " << namSinh;
    }
    // dùng cho Câu 3
    string getHoTen() {
        return hoTen;
    }
};
// ===== Câu 1: =====
class SinhVien : public Nguoi {
private:
    string maSV;
    float diemTB;

public:
    // Câu 2: 
    void nhap() {
        Nguoi::nhap();          
        cout << "  Ma sinh vien: ";
        cin >> maSV;
        cout << "  Diem trung binh: ";
        cin >> diemTB;
    }

    void xuat() {
        Nguoi::xuat();          
        cout << " - Ma SV: " << maSV
             << " - Diem TB: " << diemTB << endl;
    }

    string getMaSV() {
        return maSV;
    }
};

// ===== Câu 3: =====
int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    SinhVien* dsSV = new SinhVien[n];   

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":\n";
        dsSV[i].nhap();
    }

    string tuKhoa;
    cin.ignore();
    cout << "\nNhap ma sinh vien hoac ho ten can tim: ";
    getline(cin, tuKhoa);
    bool timThay = false;
    cout << "\nKET QUA TIM KIEM:\n";
    for (int i = 0; i < n; i++) {
        if (dsSV[i].getMaSV() == tuKhoa || dsSV[i].getHoTen() == tuKhoa) {
            dsSV[i].xuat();
            timThay = true;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay sinh vien nao phu hop.\n";
    }

    delete[] dsSV;  
    return 0;
}
