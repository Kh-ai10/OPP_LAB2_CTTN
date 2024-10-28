#include "TamGiac.h"
#include "Diem.h"
#include <cmath>
using namespace std;

// Hàm kiểm tra thẳng hàng
bool DienTich(const Diem& A, const Diem& B, const Diem& C) {
    float dt = 0.5 * abs(A.GetHoanhDo() * (B.GetTungDo() - C.GetTungDo()) +
                             B.GetHoanhDo() * (C.GetTungDo() - A.GetTungDo()) +
                             C.GetHoanhDo() * (A.GetTungDo() - B.GetTungDo()));
    return dt == 0;
}

// Nhập tọa độ các đỉnh A, B, C
void TamGiac::Nhap() {
    while (true) {
        cout << "Nhap toa do 3 diem A, B, C (x1, y1, x2, y2, x3, y3): ";
        A.Nhap();
        B.Nhap();
        C.Nhap();

        // Kiểm tra xem 3 điểm có thẳng hàng không
        if (DienTich(A, B, C)) {
            cout << "Ba diem A, B, C thang hang. Vui long nhap lai.\n";
        } else {
            break; // Nếu không thẳng hàng, thoát vòng lặp
        }
    }
}

void TamGiac::Xuat() {
    cout << "A: ";
    A.Xuat();
    cout << "B: ";
    B.Xuat();
    cout << "C: ";
    C.Xuat();
}

/*
Đầu vào Hướng và độ dài tịnh tiến
Đầu ra: Tọa độ 3 đỉnh tam giác sau khi tịnh tiến.
*/
void TamGiac::TinhTien(float huong, float dodai) {
    A.TinhTien(huong, dodai);
    B.TinhTien(huong, dodai);
    C.TinhTien(huong, dodai);
}

