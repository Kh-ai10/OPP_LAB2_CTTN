#include <iostream>
#include "Diem.h"
#include "Tamgiac.h"
using namespace std;

int main() {
    Tamgiac TG; 
    TG.Nhap();
    TG.Xuat();

    float dx, dy;
    cout << "Nhap gia tri dich chuyen (dx dy): ";
    cin >> dx >> dy;
    TG.TinhTien(dx, dy);
    cout << "Sau khi dich chuyen: ";
    TG.Xuat();

    float k;
    cout << "Muon phong to len may lan: ";
    cin >> k;
    TG.PhongTo(k);
    cout << "Sau khi phong to len " << k << " lan: ";
    TG.Xuat();

    float h;
    cout << "Muon thu nho may lan: ";
    cin >> h;
    TG.ThuNho(h);
    cout << "Sau khi thu nho " << h << " lan: ";
    TG.Xuat();

    float gocquay;
    cout << "Muon quay bao nhieu do: ";
    cin >> gocquay;
    TG.Quay(gocquay);
    cout << "Sau khi quay " << gocquay << " do: ";
    TG.Xuat();

   

}
