#ifndef TAMGIAC_H
#define TAMGIAC_H

#include "Diem.h"

class Tamgiac {
private:
    Diem A, B, C;

public:
    void Nhap(); // Nhập tọa độ các đỉnh
    void Xuat() const; // Xuất tọa độ các đỉnh
    void TinhTien(float dx, float dy); // Dịch chuyển tam giác
    void PhongTo(float k); // Phóng to tam giác
    void ThuNho(float k); // Thu nhỏ tam giác
    void Quay(float gocquay); // Quay tam giác
};

#endif // CLS_TAMGIAC_H
