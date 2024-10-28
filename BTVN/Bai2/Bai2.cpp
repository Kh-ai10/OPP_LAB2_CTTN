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

// Hàm để nhập dữ liệu phân số
void NhapPhanSo(PhanSo* phanSo, int n) {
    for (int i = 0; i < n; i++) {
        cin >> phanSo[i].tu;

        // Nhập mẫu số và kiểm tra
        do {
            cin >> phanSo[i].mau;

            // Nếu mẫu số âm, đổi dấu tử số và mẫu số
            if (phanSo[i].mau < 0) {
                phanSo[i].tu = -phanSo[i].tu; // Đổi dấu tử số
                phanSo[i].mau = -phanSo[i].mau; // Đổi dấu mẫu số
            }

            if (phanSo[i].mau == 0) {
                cout << "Mau so phai khac 0. Vui long nhap lai.\n";
            }
        } while (phanSo[i].mau == 0);
    }
}

// Hàm để tìm phân số lớn thứ k và bé thứ k
void TimPhanSo(PhanSo* phanSo, int n, int k) {
    if (k <= 0 || k > n) {
        cout << "Khong co phan so lon thu " << k << " hoac be thu " << k << ".\n";
        return;
    }

    // Sắp xếp phân số theo giá trị
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (Giatri_ps(phanSo[i]) > Giatri_ps(phanSo[j])) {
                swap(phanSo[i], phanSo[j]);
            }
        }
    }

    // Xuất kết quả
    cout << "Phan so lon thu " << k << ": " << phanSo[n - k].tu << "/" 
         << phanSo[n - k].mau << endl;
    cout << "Phan so be thu " << k << ": " << phanSo[k - 1].tu << "/" 
         << phanSo[k - 1].mau << endl;
}

int main() {
    int n, k;

    // Nhập số lượng phân số
    cout << "Nhap so luong phan so: ";
    cin >> n;

    while (n <= 0) {
        cout << "Khong hop le, nhap lai: ";
        cin >> n;
    }

    cout << "Nhap gia tri k: ";
    cin >> k;

    while (k <= 0) {
        cout << "Gia tri k phai la so nguyen duong. Nhap lai: ";
        cin >> k;
    }

    // Khai báo mảng phân số
    PhanSo* luu_tru = new PhanSo[n];
    NhapPhanSo(luu_tru, n);

    // Tìm và xuất kết quả
    TimPhanSo(luu_tru, n, k);

    // Giải phóng bộ nhớ
    delete[] luu_tru;

    return 0;
}
