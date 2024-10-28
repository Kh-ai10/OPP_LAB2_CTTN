#include "Diem.h"
using namespace std;

void Diem::Nhap() {
    cin >> iHoanh >> iTung;
}

void Diem::Xuat() const {
    cout << "(" << iHoanh << ", " << iTung << ")\n";
}

float Diem::GetHoanhDo() const {
    return iHoanh; // Trả về hoành độ
}

float Diem::GetTungDo() const {
    return iTung; // Trả về tung độ
}
