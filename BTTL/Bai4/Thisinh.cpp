#include "Thisinh.h"
using namespace std;

void ThiSinh::Nhap() {
    cout << "Nhap ten: ";
    getline(cin, Ten);
    cout << "Nhap MSSV: ";
    getline(cin, MSSV);
    cout << "Nhap ngay sinh (ngay thang nam): ";
    cin >> iNgay >> iThang >> iNam;
    cout << "Nhap diem Toan: ";
    cin >> fToan;
    cout << "Nhap diem Van: ";
    cin >> fVan;
    cout << "Nhap diem Anh: ";
    cin >> fAnh;
    cin.ignore(); // Để xóa bộ đệm sau khi nhập
}

void ThiSinh::Xuat() {
    cout << "Ten: " << Ten << "\n";
    cout << "MSSV: " << MSSV << "\n";
    cout << "Ngay sinh: " << iNgay << "/" << iThang << "/" << iNam << "\n";
    cout << "Diem Toan: " << fToan << "\n";
    cout << "Diem Van: " << fVan << "\n";
    cout << "Diem Anh: " << fAnh << "\n";
    cout << "Tong diem: " << fToan + fVan + fAnh << "\n";
}

float ThiSinh::Tong() {
    return fToan + fVan + fAnh;
}
