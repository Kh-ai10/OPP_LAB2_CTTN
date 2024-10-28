#include <iostream>
#include "Dagiac.h"

using namespace std;

int main() {
    Dagiac dg;
    dg.Nhap(); // Nhập thông tin đa giác
    
    // Tính diện tích
    float dienTich = dg.DienTich();
    
    // Xuất diện tích
    cout << "Dien tich cua da giac: " << dienTich << "\n";
    
    // Xuất tọa độ các đỉnh


    return 0;
}
