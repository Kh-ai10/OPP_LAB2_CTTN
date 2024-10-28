#ifndef DIEM_H
#define DIEM_H

#include <iostream>

class Diem {
private:
    float iHoanh, iTung; // Tung độ

public:
    // Nhập tọa độ
    void Nhap();
    
    // Xuất tọa độ
    void Xuat() const;
    
    // Khai báo phương thức để lấy hoành độ
    float GetHoanhDo() const;
    
    // Khai báo phương thức để lấy tung độ
    float GetTungDo() const;
};

#endif // DIEM_H
