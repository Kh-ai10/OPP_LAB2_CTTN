#include "Tamgiac.h"
#include "Diem.h"
#include <cmath>
#define M_PI 3.14159265358979323846

// Hàm kiểm tra thẳng hàng
bool DienTich(const Diem& A, const Diem& B, const Diem& C) {
    float dt = 0.5 * abs(A.GetHoanhDo() * (B.GetTungDo() - C.GetTungDo()) +
                             B.GetHoanhDo() * (C.GetTungDo() - A.GetTungDo()) +
                             C.GetHoanhDo() * (A.GetTungDo() - B.GetTungDo()));
    return dt == 0;
}

// Nhập tọa độ các đỉnh A, B, C
void Tamgiac::Nhap() {
    while (true) {
        float ax, ay, bx, by, cx, cy;
        cout << "Nhap toa do dinh A (x, y): ";
        cin >> ax >> ay;
        cout << "Nhap toa do dinh B (x, y): ";
        cin >> bx >> by;
        cout << "Nhap toa do dinh C (x, y): ";
        cin >> cx >> cy;

        A = Diem(ax, ay);
        B = Diem(bx, by);
        C = Diem(cx, cy);

        // Kiểm tra xem 3 điểm có thẳng hàng không
        if (DienTich(A, B, C)) {
            cout << "Ba diem A, B, C thang hang. Vui long nhap lai.\n";
        } else {
            break; // Nếu không thẳng hàng, thoát vòng lặp
        }
    }
}

// Xuất tọa độ các đỉnh A, B, C
void Tamgiac::Xuat() const {
    cout << "Dinh A: "; A.HienThi();
    cout << ", Dinh B: "; B.HienThi();
    cout << ", Dinh C: "; C.HienThi();
    cout << "\n";
}

/*
Tịnh tiến tam giác theo hệ số dx, dy
Đầu vào: Hệ số tịnh tiến dx, dy
Đầu ra: Tọa độ 3 đỉnh tam giác sau khi tịnh tiến
Cách hoạt động: 
    x += dx
    y += dy
*/
void Tamgiac::TinhTien(float dx, float dy) {
    A = Diem(A.GetHoanhDo() + dx, A.GetTungDo() + dy);
    B = Diem(B.GetHoanhDo() + dx, B.GetTungDo() + dy);
    C = Diem(C.GetHoanhDo() + dx, C.GetTungDo() + dy);
}

/*
Phóng to tam giác theo tỉ lệ k
Đầu vào: Hệ số k
Đầu ra: Tọa độ 3 đỉnh tam giác sau khi phóng to
Cách hoạt động:
    x *= k
    y *= k
*/ 
void Tamgiac::PhongTo(float k) {
    A = Diem(A.GetHoanhDo() * k, A.GetTungDo() * k);
    B = Diem(B.GetHoanhDo() * k, B.GetTungDo() * k);
    C = Diem(C.GetHoanhDo() * k, C.GetTungDo() * k);
}

/*
Thu nhỏ tam giác theo tỉ lệ k
Đầu vào: Hệ số k
Đầu ra: Tọa độ 3 đỉnh tam giác sau khi thu nhỏ
Cách hoạt động: Thu nhỏ k lần = Phóng to (1/k)
*/ 
void Tamgiac::ThuNho(float k) {
    PhongTo(1 / k);
}

/*
Quay tam giác một góc a theo chiều kim đồng hồ
Đầu vào: Góc quay a (độ)
Đầu ra: Tọa độ 3 đỉnh tam giác sau khi quay
Cách hoạt động: 
    Chuyển độ sang radian
    Áp dụng công thức quay theo tâm O(0;0)
    x = x*cos(a) - y*sin(a)
    y = x*sin(a) + y*cos(a)
*/ 
void Tamgiac::Quay(float gocquay) {
    // Kiểm tra xem có điểm nào là gốc tọa độ không
    if ((A.GetHoanhDo() == 0 && A.GetTungDo() == 0) ||
        (B.GetHoanhDo() == 0 && B.GetTungDo() == 0) ||
        (C.GetHoanhDo() == 0 && C.GetTungDo() == 0)) {
        return; // Trả về mà không thực hiện phép quay 
    }
 
    float rad = gocquay * M_PI / 180.0; // Chuyển độ sang radian
    float cosA = cos(rad);
    float sinA = sin(rad);

    for (Diem* point : { &A, &B, &C }) {
        float x_new = point->GetHoanhDo() * cosA - point->GetTungDo() * sinA;
        float y_new = point->GetHoanhDo() * sinA + point->GetTungDo() * cosA;
        *point = Diem(x_new, y_new);
    }
}
