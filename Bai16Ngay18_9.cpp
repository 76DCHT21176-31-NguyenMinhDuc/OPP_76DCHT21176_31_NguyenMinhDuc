#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// ================= CÂU 1: KHAI BÁO L?P =================
class MonHoc {
protected:
    string tenMon;
    double CC, KT, DT;
public:
    void nhap();
    void xuat();
    double tinhDiemHP();   
    bool biCamThi();      
};

class SinhVien : public MonHoc {
private:
    string hoTen, lop, maSV;
public:
    void nhap();
    void xuat();
};

// ================= CÂU 2 =================
void MonHoc::nhap() {
    cout << "Ten mon hoc: ";
    getline(cin, tenMon);
    cout << "Diem chuyen can: ";
    cin >> CC;
    cout << "Diem kiem tra: ";
    cin >> KT;
    cout << "Diem thi: ";
    cin >> DT;
    cin.ignore();  
}

void MonHoc::xuat() {
    cout << "Mon: " << tenMon
         << " | CC: " << CC << " | KT: " << KT << " | DT: " << DT << endl;
}

// Công thuc : 10% CC + 30% KT + 60% thi
double MonHoc::tinhDiemHP() {
    return CC * 0.1 + KT * 0.3 + DT * 0.6;
}
bool MonHoc::biCamThi() {
    return CC < 5 || KT == 0;
}

void SinhVien::nhap() {
    cout << "Ho ten: ";
    getline(cin, hoTen);
    cout << "Lop: ";
    getline(cin, lop);
    cout << "Ma sinh vien: ";
    getline(cin, maSV);
    MonHoc::nhap();  
}

void SinhVien::xuat() {
    cout << "Ho ten: " << hoTen << " | Lop: " << lop << " | MSV: " << maSV << endl;
    MonHoc::xuat();  // xu?t ph?n thông tin môn h?c
    cout << "Diem hoc phan: " << tinhDiemHP() << endl;
}
// ================= CÂU 3: HÀM MAIN =================
int main() {
    cout << fixed << setprecision(2);  
    int n;
    cout << "Nhap so sinh vien n: ";
    cin >> n;
    cin.ignore();
    vector<SinhVien> ds(n);
    // Nhap n sinh viên
    for (int i = 0; i < n; i++) {
        cout << "\n--- Sinh vien thu " << i + 1 << " ---\n";
        ds[i].nhap();
    }

    cout << "\n===== DANH SACH SINH VIEN BI CAM THI =====\n";
    bool coAi = false;
    for (int i = 0; i < n; i++) {
        if (ds[i].biCamThi()) {
            ds[i].xuat();
            cout << "-----------------------------\n";
            coAi = true;
        }
    }
    if (!coAi) cout << "Khong co sinh vien nao bi cam thi.\n";

    return 0;
}
