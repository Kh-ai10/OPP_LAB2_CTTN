#include <iostream>
#include "TamGiac.h"

using namespace std;

int main() {
    TamGiac tg;
    tg.Nhap(); // Nhập tọa độ 3 điểm

    float huong, dodai;
    cout << "Nhap huong tinh tien (do): ";
    cin >> huong;
    cout << "Nhap do dai tinh tien: ";
    cin >> dodai;

    // Tịnh tiến tam giác
    tg.TinhTien(huong, dodai);
    
    // Xuất tọa độ sau khi tịnh tiến
    cout << "Toa do tam giac sau khi tinh tien:\n";
    tg.Xuat();

    return 0;
}
