#include <iostream>
#include "Diem.h"

using namespace std;

int main() {
    Diem d;
    d.Nhap(); // Nhập tọa độ

    int n;
    cout << "Nhap so luong chi thi: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cout << "Nhap chi thi (1, 2, 3): ";
        cin >> x;

        switch (x) {
            case 1:
                d.NhanDoi();
                break;
            case 2:
                d.GanGoc();
                break;
            case 3: {
                float k, hesotinhtien;
                cout << "Nhap huong tinh tien (0: x, khac 0: y): ";
                cin >> k;
                cout << "Nhap he so tinh tien: ";
                cin >> hesotinhtien;
                d.TinhTien(k, hesotinhtien);
                break;
            }
            default:
                // Không làm gì cả
                break;
        }
        // Xuất tọa độ sau mỗi chỉ thị
    }
    d.Xuat();

    return 0;
}
