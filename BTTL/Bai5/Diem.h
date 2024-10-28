#ifndef DIEM_H
#define DIEM_H

#include <iostream>

class Diem {
private:
    float iHoanh, iTung;
    
public:
    // Phương thức nhập tọa độ
    void Nhap();
    
    // Phương thức xuất tọa độ
    void Xuat();
    
    // Phương thức nhân đôi tọa độ
    void NhanDoi();
    
    // Phương thức gán về gốc tọa độ
    void GanGoc();
    
    // Phương thức tịnh tiến
    void TinhTien(float k, float d);
};

#endif // DIEM_H
