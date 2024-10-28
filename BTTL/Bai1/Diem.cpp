#include <iostream>
using namespace std;
#include "Diem.h"

Diem:: Diem() : iHoanh(0), iTung(0){}

Diem:: Diem(float Hoanh, float Tung) : iHoanh(Hoanh), iTung(Tung){}

Diem:: Diem(const Diem&x){
    iHoanh = x.iHoanh;
    iTung = x.iTung;
}

void Diem:: Xuat(){
    cout << "(" << iHoanh << ", " << iTung << ")";
}

float Diem:: GetHoanhDo(){
    cout << iHoanh;
    return iHoanh;
}

float Diem::GetTungDo(){
    cout << iTung;
    return iTung;
}

void Diem::SetHoanhDo(){
    float hd;
    cout << "\nGia tri moi cua hoanh do: ";
    cin >> hd;
    iHoanh = hd;
}

void Diem::SetTungDo(){
    float td;
    cout << "Gia tri moi cua tung do: ";
    cin >> td;
    iTung = td;
}

/*
Đầu vào: Hệ số tịnh tiến dx, dy
Đầu ra: Hoành độ và Tung độ sau khi tịnh tiến
Cách hoạt động: 
    x += dx
    y += dy
*/
void Diem::TinhTien() {
    float dx, dy;
    cout << "\nNhap gia tri tinh tien cho hd: ";
    cin >> dx;
    cout << "Nhap gia tri tinh tien cho td: ";
    cin >> dy;
    iHoanh += dx; 
    iTung += dy; 
}

