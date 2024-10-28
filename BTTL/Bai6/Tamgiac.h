#ifndef TAMGIAC_H
#define TAMGIAC_H

#include "Diem.h"

class TamGiac {
private:
    Diem A, B, C;

public:
    // Nhập tọa độ 3 điểm
    void Nhap();
    
    // Xuất tọa độ 3 điểm
    void Xuat();

    
    // Tịnh tiến tam giác
    void TinhTien(float huong, float dodai);
};

#endif 
