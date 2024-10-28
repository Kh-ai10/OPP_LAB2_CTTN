#include <iostream>
#include <cmath>
#include "Dagiac.h"
#include "Diem.h"
using namespace std;

int main() {
    Dagiac Dg;

    // Nhập các đỉnh của đa giác
    Dg.Nhap();
    
    // Xuất thông tin ban đầu
    Dg.Xuat();
    cout << "\n";

    // Tinh tien
    float dx, dy;
    cout << "Nhap he so tinh tien (dx, dy): ";
    cin >> dx >> dy;
    Dg.TinhTien(dx, dy);
    
    // Xuất thông tin sau khi dịch chuyển
    cout << "Da giac sau khi tinh tien:\n";
    Dg.Xuat();
    cout << "\n";

    // Phóng to
    float k;
    cout << "Muon phong to may lan: ";
    cin >> k;
    Dg.PhongTo(k);
    
    // Xuất thông tin sau khi phóng to
    cout << "Da giac sau khi phong to:\n";
    Dg.Xuat();
    cout << "\n";

    // Thu nhỏ
    float h;
    cout << "Muon thu nho may lan: ";
    cin >> h;
    Dg.ThuNho(h);
    
    // Xuất thông tin sau khi thu nhỏ
    cout << "Da giac sau khi thu nho:\n";
    Dg.Xuat();
    cout << "\n";

    // Quay
    float gocquay;
    cout << "Nhap goc quay (theo do): ";
    cin >> gocquay;
    Dg.Quay(gocquay);
    
    // Xuất thông tin sau khi quay
   
    cout << "Da giac sau khi quay:\n";
    Dg.Xuat();

    return 0;
}
