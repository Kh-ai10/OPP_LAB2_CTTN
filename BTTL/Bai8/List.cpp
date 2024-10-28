#include "List.h"

// Constructor khoi tao list rong
List::List() {
    kichthuoc = 0;
    dulieu = nullptr;
}

// Destructor giai phong bo nho
List::~List() {
    delete[] dulieu;
}

// Them phan tu vao list
void List::Them(double x) {
    double* dulieu_moi = new double[kichthuoc + 1]; // Cap phat bo nho cho mang moi
    for (unsigned int i = 0; i < kichthuoc; i++) {
        dulieu_moi[i] = dulieu[i]; // Sao chep du lieu cu
    }
    dulieu_moi[kichthuoc] = x; // Them phan tu moi
    delete[] dulieu; // Giai phong bo nho cu
    dulieu = dulieu_moi; // Cap nhat con tro
    kichthuoc++;
}

// Xoa phan tu dau tien co gia tri x
void List::XoaDau(double x) {
    for (unsigned int i = 0; i < kichthuoc; i++) {
        if (dulieu[i] == x) {
            for (unsigned int j = i; j < kichthuoc - 1; j++) {
                dulieu[j] = dulieu[j + 1]; // Dich trai cac phan tu
            }
            kichthuoc--; // Giam kich thuoc
            double* dulieu_moi = new double[kichthuoc]; // Cap phat lai mang
            for (unsigned int k = 0; k < kichthuoc; k++) {
                dulieu_moi[k] = dulieu[k]; // Sao chep du lieu
            }
            delete[] dulieu; // Giai phong bo nho cu
            dulieu = dulieu_moi; // Cap nhat con tro
            return;
        }
    }
}

// Xoa tat ca phan tu co gia tri x
void List::XoaTatCa(double x) {
    unsigned int newkichthuoc = 0;
    for (unsigned int i = 0; i < kichthuoc; i++) {
        if (dulieu[i] != x) {
            newkichthuoc++; // Dem so phan tu khong bi xoa
        }
    }

    double* dulieu_moi = new double[newkichthuoc]; // Cap phat mang moi
    unsigned int j = 0;
    for (unsigned int i = 0; i < kichthuoc; i++) {
        if (dulieu[i] != x) {
            dulieu_moi[j++] = dulieu[i]; // Sao chep cac phan tu khong bi xoa
        }
    }

    delete[] dulieu; // Giai phong bo nho cu
    dulieu = dulieu_moi; // Cap nhat con tro
    kichthuoc = newkichthuoc; // Cap nhat kich thuoc
}

// Cap nhat phan tu tai chiso
void List::CapNhat(unsigned int chiso, double y) {
    if (chiso < kichthuoc) {
        dulieu[chiso] = y; // Cap nhat gia tri
    }
}

// In ra list
void List::Xuat() const {
    std::cout << "[";
    for (unsigned int i = 0; i < kichthuoc; i++) {
        std::cout << dulieu[i];
        if (i < kichthuoc - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;
}
