#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

class NhanVien {
private:
    string maNV;
    string hoTen;
    int tuoi;
    double luong;

public:
    // Constructor khong doi
    NhanVien() {
        maNV = "";
        hoTen = "";
        tuoi = 0;
        luong = 0;
    }

    // Constructor co doi
    NhanVien(string maNV, string hoTen, int tuoi, double luong) {
        this->maNV = maNV;
        this->hoTen = hoTen;
        this->tuoi = tuoi;
        this->luong = luong;
    }

    // Cac ham lay du lieu (getter) de xuat theo cot
    string getMaNV() const { return maNV; }
    string getHoTen() const { return hoTen; }
    int getTuoi() const { return tuoi; }
    double getLuong() const { return luong; }
};

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    cin.ignore(); // bo ky tu newline con lai trong buffer sau khi cin >> n

    vector<NhanVien> dsnv; // cach 3: dung vector thay cho mang tinh/mang dong

    for (int i = 0; i < n; i++) {
        string maNV, hoTen;
        int tuoi;
        double luong;

        cout << "\n=== NHAP THONG TIN NHAN VIEN THU " << i + 1 << " ===" << endl;
        cout << "Ma nhan vien: ";
        getline(cin, maNV);
        cout << "Ho ten: ";
        getline(cin, hoTen);
        cout << "Tuoi: ";
        cin >> tuoi;
        cout << "Luong: ";
        cin >> luong;
        cin.ignore();

        // Dung constructor co doi de tao doi tuong, roi dua thang vao vector
        dsnv.push_back(NhanVien(maNV, hoTen, tuoi, luong));
    }

    // Xuat du lieu theo cot
    cout << "\n=== DANH SACH NHAN VIEN ===" << endl;
    cout << left
         << setw(10) << "Ma NV"
         << setw(20) << "Ho ten"
         << setw(8)  << "Tuoi"
         << setw(12) << "Luong" << endl;
    cout << string(50, '-') << endl;

    for (int i = 0; i < (int)dsnv.size(); i++) {
        cout << left
             << setw(10) << dsnv[i].getMaNV()
             << setw(20) << dsnv[i].getHoTen()
             << setw(8)  << dsnv[i].getTuoi()
             << setw(12) << fixed << setprecision(2) << dsnv[i].getLuong()
             << endl;
    }

    return 0;
}
