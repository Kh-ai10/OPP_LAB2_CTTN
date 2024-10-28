#include "Diem.h"
#include <cmath>
using namespace std;


void Diem::Nhap() {
    cin >> iHoanh >> iTung;
}

void Diem::Xuat() {
    cout << "(" << iHoanh << ", " << iTung << ")\n";
}
float Diem::GetHoanhDo() const{
    return iHoanh;
}

float Diem::GetTungDo() const{
    return iTung;
}


void Diem::TinhTien(float huong, float dodai) {
    // Đổi độ sang radian
    float radian = huong * (3.14 / 180.0);
    iHoanh += dodai * cos(radian);
    iTung += dodai * sin(radian);
}