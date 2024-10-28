#include "Diem.h"
using namespace std;

void Diem::Nhap() {
    cout << "Nhap hoanh do: ";
    cin >> iHoanh;
    cout << "Nhap tung do: ";
    cin >> iTung;
}

void Diem::Xuat() {
    cout << "Toa do diem: (" << iHoanh << ", " << iTung << ")\n";
}

/*
Đầu vào: Hoành độ và Tung độ.
Đầu ra: Hoành độ và Tung độ sau khi nhân đôi.
*/
void Diem::NhanDoi() {
    iHoanh *= 2;
    iTung *= 2;
}

/*
Đầu vào: Hoành độ và Tung Độ.
Đầu ra: Hoành độ = Tung độ = 0.
*/
void Diem::GanGoc() {
    iHoanh = 0;
    iTung = 0;
}

/*
Đầu vào: Hướng tịnh tiến k, độ dài tịnh tiến.
Đầu ra: Hoành độ/ Tung độ sau khi tịnh tiến.
Cách hoạt động: Hoành/Tung += độ dài.
*/
void Diem::TinhTien(float k, float d) {
    if (k == 0) { // Tịnh tiến theo trục iHoanh
        iHoanh += d;
    } else { // Tịnh tiến theo trục iTung
        iTung += d;
    }
}
