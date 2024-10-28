#ifndef DIEM_H
#define DIEM_H

#include <iostream>

class Diem {
private:
    float iHoanh, iTung;

public:

    // Nhập tọa độ
    void Nhap();
    
    // Xuất tọa độ
    void Xuat();
    
    float GetHoanhDo() const;
    float GetTungDo() const;
    
    // Tịnh tiến điểm
    void TinhTien(float huong, float dodai);
};

#endif // DIEM_H
