#include "Diem.h"

// Hàm khởi tạo mặc định
Diem::Diem() : iHoanh(0), iTung(0) {}

// Hàm khởi tạo với tham số
Diem::Diem(float Hoanh, float Tung) : iHoanh(Hoanh), iTung(Tung) {}

float Diem::GetHoanhDo() const {
    return iHoanh;
}

float Diem::GetTungDo() const {
    return iTung;
}

// Hiển thị tọa độ điểm
void Diem::HienThi() const {
    cout << "(" << iHoanh << ", " << iTung << ")";
}
