#ifndef DIEM_H
#define DIEM_H

#include <iostream>
using namespace std;

class Diem {
private:
    float iHoanh, iTung;

public:
    Diem();
    Diem(float Hoanh, float Tung);

    float GetTungDo() const; 
    float GetHoanhDo() const; 
    void HienThi() const;
};

#endif 
