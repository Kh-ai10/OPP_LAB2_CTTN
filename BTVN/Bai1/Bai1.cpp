#include <iostream>
using namespace std;

struct PhanSo {
    int tu;  // Tử số
    int mau; // Mẫu số
};

// Hàm để tính giá trị của phân số
float Giatri_ps(const PhanSo& ps) {
    return static_cast<float>(ps.tu) / ps.mau;
}

int main() {
    int n;

    // Nhập số lượng phân số
    cout << "Nhap so luong phan so: ";
    cin >> n;
    while (n <= 0) {
        cout << "Khong hop le, nhap lai: ";
        cin >> n;
    }

    // Khai báo mảng phân số
    PhanSo* luu_tru = new PhanSo[n];

    // Nhập phân số
    for (int i = 0; i < n; i++) {
        cin >> luu_tru[i].tu;

        // Nhập mẫu số và kiểm tra
        do {
            cin >> luu_tru[i].mau;

            // Nếu mẫu số âm, đổi dấu tử số và mẫu số
            if (luu_tru[i].mau < 0) {
                luu_tru[i].tu = -luu_tru[i].tu; // Đổi dấu tử số
                luu_tru[i].mau = -luu_tru[i].mau; // Đổi dấu mẫu số
            }

            if (luu_tru[i].mau == 0) {
                cout << "Mau so phai khac 0. Vui long nhap lai.\n";
            }
        } while (luu_tru[i].mau == 0);
    }

    // Khởi tạo biến để tìm phân số lớn nhất và nhỏ nhất
    PhanSo maxPhanSo = luu_tru[0];
    PhanSo minPhanSo = luu_tru[0];

    // Tìm phân số lớn nhất và nhỏ nhất
    for (int i = 1; i < n; i++) {
        if (Giatri_ps(luu_tru[i]) > Giatri_ps(maxPhanSo)) {
            maxPhanSo = luu_tru[i];
        }
        if (Giatri_ps(luu_tru[i]) < Giatri_ps(minPhanSo)) {
            minPhanSo = luu_tru[i];
        }
    }

    // Xuất kết quả
    cout << "Phan so nho nhat: " << minPhanSo.tu << "/" << minPhanSo.mau << endl;
    cout << "Phan so lon nhat: " << maxPhanSo.tu << "/" << maxPhanSo.mau << endl;

    // Giải phóng bộ nhớ
    delete[] luu_tru;

    return 0;
}
