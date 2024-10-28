#ifndef DAGIAC_H
#define DAGIAC_H

#include "Diem.h"

class Dagiac {
private:
    int sodinh; // Số đỉnh của đa giác
    Diem* dinh; // Mảng động chứa các điểm

public:
    // Nhập thông tin đa giác
    void Nhap();
    
    // Tính diện tích của đa giác
    float DienTich();
    
    // Xuất thông tin đa giác
    void Xuat();
    
    // Giải phóng bộ nhớ
    ~Dagiac();
};

#endif // DAGIAC_H
