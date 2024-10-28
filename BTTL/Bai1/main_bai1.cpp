#include <iostream>
#include "Diem.h"
#include "Diem.cpp"

using namespace std;

int main() {
    // Khởi tạo điểm mặc định
    Diem d; 
    cout << "Diem mac dinh: ";
    d.Xuat();

    float x, y;
    cout << "\nNhap toa do cho diem A(x, y): ";
    cin >> x >> y;
    Diem d1(x, y);
    cout << "Toa do diem A: ";
    d1.Xuat();

    cout << "\nSao chep toa do diem A sang diem B:\n";
    Diem d2(d1);
    cout << "Toa do diem B: ";
    d2.Xuat();

    cout << "\nHoanh do cua diem B: ";
    d2.GetHoanhDo();

    cout << "\nTung do cua diem B: ";
    d2.GetTungDo();

    d2.SetHoanhDo();
    d2.SetTungDo();
    cout << "Toa do moi cua diem B: ";
    d2.Xuat();

    d2.TinhTien();
    cout << "Toa do cua diem B sau khi tinh tien: ";
    d2.Xuat();


}