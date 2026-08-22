#include <iostream>
#include <string>
#include <vector>
using namespace std;

// LOP NHAN VIEN
class NhanVien
{
private:
    string maNV;
    string hoTen;
    int tuoi;
    double luong;

public:
    void nhap()
    {
        cout << "Ma nhan vien: ";
        cin >> maNV;
        cin.ignore();
        cout << "Ho ten: ";
        getline(cin, hoTen);
        cout << "Tuoi: ";
        cin >> tuoi;
        cout << "Luong: ";
        cin >> luong;
    }

    void xuat()
    {
        cout << "Ma NV: " << maNV
             << " | Ho ten: " << hoTen
             << " | Tuoi: " << tuoi
             << " | Luong: " << luong << endl;
    }

    string layTen() { return hoTen; }
};
const int SL = 10; 
// CACH 1: MANG TINH (MANG CO DIEN)
void cach1_MangTinh()
{
    cout << "\n\n########## CACH 1: MANG TINH ##########\n";
    NhanVien dsnv[SL];
    for (int i = 0; i < SL; i++)
    {
        cout << "\n=== NHAP THONG TIN CHO NHAN VIEN THU " << i + 1 << " ===" << endl;
        dsnv[i].nhap();
    }
    cout << "\n=== XUAT DANH SACH NHAN VIEN (MANG TINH) ===\n";
    for (int i = 0; i < SL; i++)
    {
        dsnv[i].xuat();
    }
}
// CACH 2: MANG DONG (CON TRO + new)
void cach2_MangDong()
{
    cout << "\n\n########## CACH 2: MANG DONG (new) ##########\n";
    NhanVien *dsnv = new NhanVien[SL]; 

    for (int i = 0; i < SL; i++)
    {
        cout << "\n=== NHAP THONG TIN CHO NHAN VIEN THU " << i + 1 << " ===" << endl;
        dsnv[i].nhap();
    }

    cout << "\n=== XUAT DANH SACH NHAN VIEN (MANG DONG) ===\n";
    for (int i = 0; i < SL; i++)
    {
        dsnv[i].xuat();
    }

    delete[] dsnv; 
}
// CACH 3: VECTOR
void cach3_Vector()
{
    cout << "\n\n########## CACH 3: VECTOR ##########\n";
    vector<NhanVien> ds; // vector rong ban dau

    for (int i = 0; i < SL; i++)
    {
        NhanVien nv;
        cout << "\n=== NHAP THONG TIN CHO NHAN VIEN THU " << i + 1 << " ===" << endl;
        nv.nhap();
        ds.push_back(nv); 
    }

    cout << "\n=== XUAT DANH SACH NHAN VIEN (VECTOR) ===\n";
    for (int i = 0; i < (int)ds.size(); i++)
    {
        ds[i].xuat();
    }
}
int main()
{
    cach1_MangTinh();
    return 0;
}
