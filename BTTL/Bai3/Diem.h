#ifndef DIEM_H
#define DIEM_H
#include <iostream>
using namespace std;

class Diem{
private:
    float iHoanh, iTung;

public:
    Diem();
    Diem(float Hoanh, float Tung);
    float GetTungDo(); 
    float GetHoanhDo(); 
    void SetTungDo(float td);
    void SetHoanhDo(float hd);
    void HienThi() const;
       
};
#endif