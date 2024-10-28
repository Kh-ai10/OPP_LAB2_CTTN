#ifndef DAGIAC_H
#define DAGIAC_H
#include "Diem.h"
#include <iostream>
using namespace std;

class Dagiac{
    private:
    int n;
    Diem* dinh;

    public:
    void Nhap();
    void Xuat();
    void TinhTien(float dx, float dy);
    void PhongTo(float k);
    void ThuNho(float k);
    void Quay(float goc);

    ~Dagiac();

};
#endif