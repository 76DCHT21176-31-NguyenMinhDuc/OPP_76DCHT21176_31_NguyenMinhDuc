#include <iostream>
using namespace std;

class SoPhuc {
private:
    double thucPhan;
    double aoPhan;
public:
    // Cau 1: Ham tao khong doi
    SoPhuc() {
        thucPhan = 0;
        aoPhan = 0;
    }
    // Cau 1: Ham tao co doi
    SoPhuc(double thuc, double ao) {
        thucPhan = thuc;
        aoPhan = ao;
    }
    // Cau 1: Ham huy
    ~SoPhuc() {
        // Khong co vung nho cap phat dong nen khong can giai phong gi them
    }
    // Cau 2: Toan tu nhap >> (dang a+b*i)
    friend istream& operator>>(istream& in, SoPhuc& sp) {
        cout << "  Nhap phan thuc: ";
        in >> sp.thucPhan;
        cout << "  Nhap phan ao: ";
        in >> sp.aoPhan;
        return in;
    }
    // Cau 2: Toan tu xuat << (dang a+b*i)
    friend ostream& operator<<(ostream& out, const SoPhuc& sp) {
        out << sp.thucPhan;
        if (sp.aoPhan >= 0)
            out << "+" << sp.aoPhan << "i";
        else
            out << sp.aoPhan << "i";
        return out;
    }
    // Cau 3: Toan tu cong
    SoPhuc operator+(const SoPhuc& sp) const {
        return SoPhuc(thucPhan + sp.thucPhan, aoPhan + sp.aoPhan);
    }
    // Cau 3: Toan tu tru
    SoPhuc operator-(const SoPhuc& sp) const {
        return SoPhuc(thucPhan - sp.thucPhan, aoPhan - sp.aoPhan);
    }
    // Cau 3: Toan tu nhan
    SoPhuc operator*(const SoPhuc& sp) const {
        double thuc = thucPhan * sp.thucPhan - aoPhan * sp.aoPhan;
        double ao = thucPhan * sp.aoPhan + aoPhan * sp.thucPhan;
        return SoPhuc(thuc, ao);
    }
    // Cau 3: Toan tu chia
    SoPhuc operator/(const SoPhuc& sp) const {
        double mauSo = sp.thucPhan * sp.thucPhan + sp.aoPhan * sp.aoPhan;
        if (mauSo == 0) {
            cout << "Loi: chia cho so phuc 0!" << endl;
            return SoPhuc(0, 0);
        }
        double thuc = (thucPhan * sp.thucPhan + aoPhan * sp.aoPhan) / mauSo;
        double ao = (aoPhan * sp.thucPhan - thucPhan * sp.aoPhan) / mauSo;
        return SoPhuc(thuc, ao);
    }
};
int main() {
    SoPhuc a, b; // dung ham tao khong doi
    cout << "--- Nhap so phuc thu nhat ---" << endl;
    cin >> a;
    cout << "--- Nhap so phuc thu hai ---" << endl;
    cin >> b;
    cout << "\nSo phuc thu nhat: " << a << endl;
    cout << "So phuc thu hai: " << b << endl;
    cout << "\nTong: " << (a + b) << endl;
    cout << "Hieu: " << (a - b) << endl;
    cout << "Tich: " << (a * b) << endl;
    cout << "Thuong: " << (a / b) << endl;
    return 0;
}
