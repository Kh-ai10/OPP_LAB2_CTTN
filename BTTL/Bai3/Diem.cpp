#include "Diem.h"
#include <iostream>
using namespace std;

Diem:: Diem(){
            float iHoanh = 0;
            float iTung = 0;
};

Diem:: Diem(float Hoanh, float Tung){
            iHoanh = Hoanh;
            iTung = Tung;
}

float Diem:: GetHoanhDo(){
        return iHoanh;
}

float Diem::GetTungDo(){
        return iTung;
}

void Diem::SetHoanhDo(float hd){
        iHoanh = hd;
}

void Diem::SetTungDo(float td){
        iTung = td;
}

void Diem :: HienThi() const{
        cout << "(" << iHoanh << ", " << iTung << ")  ";
}
