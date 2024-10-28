#ifndef LIST_H
#define LIST_H

#include <iostream>

class List {
private:
    double* dulieu;            // Con tro quan ly mang
    unsigned int kichthuoc;       // Kich thuoc cua list

public:
    List();                  // Constructor
    ~List();                 // Destructor
    void Them(double x);     // Them phan tu
    void XoaDau(double x);   // Xoa phan tu dau tien co gia tri x
    void XoaTatCa(double x);  // Xoa tat ca phan tu co gia tri x
    void CapNhat(unsigned int chiso, double y); // Cap nhat phan tu tai chiso
    void Xuat() const;       // In ra list
};

#endif // LIST_H
