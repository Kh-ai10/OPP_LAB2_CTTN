#include <iostream>
#include "Dagiac.h"
#include "Diem.h"
#include <cmath>
#define PI 3.14159265358979323846
using namespace std;

void Dagiac::Nhap() {
    bool kiemtra = false; // Biến kiểm tra tính hợp lệ

    while (!kiemtra) {
        cout << "Nhap so dinh: ";
        cin >> n;
        while (n <= 0) {
            cout << "Khong hop le, nhap lai: ";
            cin >> n;
        }
        delete[] dinh; // Giải phóng bộ nhớ trước khi cấp phát mới
        dinh = new Diem[n];

        // Nhập tọa độ cho các đỉnh
        for (int i = 0; i < n; i++) {
            float x, y;
            cout << "Nhap toa do cho dinh " << (i + 1) << " (x, y): ";
            cin >> x >> y;

            // Kiểm tra trùng lặp
            bool trung = false;
            for (int j = 0; j < i; j++) {
                if (dinh[j].GetHoanhDo() == x && dinh[j].GetTungDo() == y) {
                    trung = true;
                    break;
                }
            }

            if (trung) {
                cout << "Toa do da ton tai, vui long nhap lai dinh " << (i + 1) << ":\n";
                i--; // Giảm i để nhập lại tọa độ
            } else {
                dinh[i] = Diem(x, y);
            }
        }

        // Kiểm tra xem các điểm có nằm trên cùng một đường thẳng không
        if (n < 3) {
            cout << "Khong phai la da giac (can it nhat 3 dinh).\n";
            continue; // Yêu cầu nhập lại
        }

        float x1 = dinh[0].GetHoanhDo();
        float y1 = dinh[0].GetTungDo();
        float x2 = dinh[1].GetHoanhDo();
        float y2 = dinh[1].GetTungDo();

        float dx = x2 - x1;
        float dy = y2 - y1;

        bool ktra = true;
        int i = 2; // Bắt đầu từ điểm thứ ba
        while (i < n) {
            float x3 = dinh[i].GetHoanhDo();
            float y3 = dinh[i].GetTungDo();

            // Sử dụng phép nhân chéo
            if (fabs(dy * (x3 - x1) - dx * (y3 - y1)) != 0) {
                ktra = false;
                break;
            }
            i++;
        }

        if (ktra) {
            cout << "Cac dinh da nhap nam tren cung mot duong thang. Vui long nhap lai.\n";
        } else {
            kiemtra = true; // Nếu không nằm trên một đường thẳng, đánh dấu là hợp lệ
        }
    }
}



void Dagiac::Xuat() {
    cout << "Cac dinh cua da giac la: ";
    for (int i = 0; i < n; i++) {
        dinh[i].HienThi();
    }
}

/*
Tịnh tiến đa giác theo hệ số dx, dy
Đầu vào: Hệ số tịnh tiến dx, dy
Đầu ra: Tọa độ n đỉnh đa giác sau khi tịnh tiến
Cách hoạt động: 
    x += dx
    y += dy
*/
void Dagiac::TinhTien(float dx, float dy) {
    for (int i = 0; i < n; i++) {
        dinh[i].SetHoanhDo(dinh[i].GetHoanhDo() + dx);
        dinh[i].SetTungDo(dinh[i].GetTungDo() + dy);
    }
}
/*
Phóng to đa giác theo tỉ lệ k
Đầu vào: Hệ số k
Đầu ra: Tọa độ n đỉnh đa giác sau khi phóng to
Cách hoạt động:
    x *= k
    y *= k
*/ 
void Dagiac::PhongTo(float k) {
    for (int i = 0; i < n; i++) {
        dinh[i].SetHoanhDo(dinh[i].GetHoanhDo() * k);
        dinh[i].SetTungDo(dinh[i].GetTungDo() * k);
    }
}

/*
Thu nhỏ đa giác theo tỉ lệ k
Đầu vào: Hệ số k
Đầu ra: Tọa độ n đỉnh đa giác sau khi thu nhỏ
Cách hoạt động: Thu nhỏ k lần = Phóng to (1/k)
*/ 
void Dagiac::ThuNho(float k) {
    PhongTo(1 / k);
}
/*
Quay đa giác một góc a theo chiều kim đồng hồ
Đầu vào: Góc quay a (độ)
Đầu ra: Tọa độ n đỉnh đa giác sau khi quay
Cách hoạt động: 
    Chuyển độ sang radian
    Áp dụng công thức quay theo tâm O(0;0)
    x = x*cos(a) - y*sin(a)
    y = x*sin(a) + y*cos(a)
*/
void Dagiac::Quay(float goc) {
    // Nếu có đỉnh là gốc tọa độ thì không cần quay
    for (int i = 0; i < n; i++){
        if(dinh[i].GetHoanhDo()==0 && dinh[i].GetTungDo()==0) return;
    }

    float rad = (goc * PI) / 180;
    for (int i = 0; i < n; i++) {
        float x_moi = dinh[i].GetHoanhDo() * cos(rad) - dinh[i].GetTungDo() * sin(rad);
        float y_moi = dinh[i].GetHoanhDo() * sin(rad) + dinh[i].GetTungDo() * cos(rad);
        dinh[i].SetHoanhDo(x_moi); // Cập nhật hoành độ
        dinh[i].SetTungDo(y_moi); // Cập nhật tung độ
    }
}

Dagiac::~Dagiac() {
    delete[] dinh;
}
