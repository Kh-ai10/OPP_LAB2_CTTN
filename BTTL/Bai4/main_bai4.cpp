#include <iostream>
#include "Thisinh.h"
using namespace std;

int main() {
    int n;
    cout << "Nhap so thi sinh: ";
    cin >> n;
    cin.ignore(); // Để xóa bộ đệm sau khi nhập

    // Khai báo mảng động
    ThiSinh* ds_TS = new ThiSinh[n];

    // Nhập thông tin cho từng thí sinh
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin thi sinh " << (i + 1) << ":\n";
        ds_TS[i].Nhap();
    }

    // In ra thí sinh có tổng điểm lớn hơn 15
    cout << "\nThi sinh co tong diem > 15:\n";
    for (int i = 0; i < n; i++) {
        if (ds_TS[i].Tong() > 15){
            ds_TS[i].Xuat();
        }
        else {
        cout << "Khong co thi sinh co tong diem > 15";
        break;
        }
    }

    // Tìm thí sinh có điểm cao nhất
    float diem_caonhat = ds_TS[0].Tong();
    ThiSinh* ts_caonhat = &ds_TS[0];

    for (int i = 0; i < n; i++) {
        if (ds_TS[i].Tong() > diem_caonhat) {
            diem_caonhat = ds_TS[i].Tong();
            ts_caonhat = &ds_TS[i];
        }
    }

    // Kiểm tra thí sinh có điểm cao nhất
    if (ts_caonhat != nullptr) {
        cout << "\nThi sinh co diem cao nhat:\n";
        ts_caonhat->Xuat();
    }

    // Giải phóng bộ nhớ
    delete[] ds_TS;

    return 0;
}
