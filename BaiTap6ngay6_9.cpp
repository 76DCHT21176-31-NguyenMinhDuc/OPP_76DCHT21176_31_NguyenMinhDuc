#include <iostream>
#include <string>
using namespace std;

const int SO_MON = 5;
string tenMon[SO_MON] = {"Toan", "Vat ly", "Hoa hoc", "Anh van", "Tin hoc"};
// ==================== CAU 1: KHAI BAO LOP SINH VIEN ====================
class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[SO_MON];
public:
    // ================ CAU 2: CAC PHUONG THUC ================
    // Phuong thuc NHAP thong tin 1 sinh vien
    void nhap() {
        cin.ignore(); // xoa ky tu newline con sot lai trong bo dem sau khi cin >> truoc do
        cout << "Nhap ho ten: ";
        getline(cin, hoTen); // dung getline vi ho ten co the co khoang trang

        cout << "Nhap nam sinh: ";
        cin >> namSinh;

        for (int i = 0; i < SO_MON; i++) {
            cout << "Nhap diem mon " << tenMon[i] << ": ";
            cin >> diem[i];
        }
    }
    // Phuong thuc TINH DIEM TRUNG BINH
    float tinhDTB() {
        float tong = 0;
        for (int i = 0; i < SO_MON; i++) {
            tong += diem[i];
        }
        return tong / SO_MON;
    }
    // Phuong thuc XUAT thong tin 1 sinh vien
    void xuat() {
        cout << "Ho ten: " << hoTen << " - Nam sinh: " << namSinh << endl;
        cout << "Diem: ";
        for (int i = 0; i < SO_MON; i++) {
            cout << tenMon[i] << "=" << diem[i] << "  ";
        }
        cout << endl;
        cout << "Diem trung binh: " << tinhDTB() << endl;
    }
    // ================ CAU 3: KIEM TRA MON THI LAI ================
    // Neu sinh vien co mon < 5, in ten + nam sinh + tung mon thi lai kem diem
    // Tra ve true neu sinh vien nay co it nhat 1 mon phai thi lai
    bool inMonThiLai() {
        bool coMonThiLai = false;

        for (int i = 0; i < SO_MON; i++) {
            if (diem[i] < 5) {
                if (!coMonThiLai) {
                    // chi in dong thong tin sinh vien 1 lan duy nhat, truoc mon thi lai dau tien
                    cout << "Sinh vien: " << hoTen << " - Nam sinh: " << namSinh << endl;
                    coMonThiLai = true;
                }
                cout << "   + Mon thi lai: " << tenMon[i] << " - Diem: " << diem[i] << endl;
            }
        }

        return coMonThiLai;
    }
};
int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    SinhVien *dsSV = new SinhVien[n]; // cap phat mang dong n sinh vien
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap sinh vien thu " << i + 1 << " ---" << endl;
        dsSV[i].nhap();
    }
    cout << "\n=== DANH SACH TOAN BO SINH VIEN ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\n-- Sinh vien " << i + 1 << " --" << endl;
        dsSV[i].xuat();
    }
    cout << "\n=== DANH SACH SINH VIEN PHAI THI LAI ===" << endl;
    bool coAiThiLai = false;
    for (int i = 0; i < n; i++) {
        if (dsSV[i].inMonThiLai()) {
            coAiThiLai = true;
        }
    }
    if (!coAiThiLai) {
        cout << "Khong co sinh vien nao phai thi lai." << endl;
    }
    delete[] dsSV; // giai phong bo nho da cap phat dong
    return 0;
}
