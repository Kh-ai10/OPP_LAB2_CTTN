#include <iostream>
#include <vector>
#include <algorithm>

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
        do {
            cin >> phanSo[i].mau;

            if (phanSo[i].mau == 0) {
                cout << "Mau so phai khac 0. Vui long nhap lai.\n";
            }
        } while (phanSo[i].mau == 0);

        // Nếu mẫu số âm, đổi dấu tử số và mẫu số
        if (phanSo[i].mau < 0) {
            phanSo[i].tu = -phanSo[i].tu; // Đổi dấu tử số
            phanSo[i].mau = -phanSo[i].mau; // Đổi dấu mẫu số
        }
    }
}

// Hàm kiểm tra xem một tập hợp con có tích bằng phân số đích không
bool kiemtra(const vector<PhanSo>& con, PhanSo dich) {
    // Tính tích tử và mẫu
    int tu_product = 1, mau_product = 1;
    for (const auto& ps : con) {
        tu_product *= ps.tu;
        mau_product *= ps.mau;
    }
    // So sánh theo kiểu chéo
    return tu_product * dich.mau == mau_product * dich.tu; 
}

// Hàm tìm tập hợp con có tích bằng phân số đích
void TimTapHopCon(PhanSo* phanSo, int n, PhanSo dich) {
    vector<PhanSo> result;
    int minSize = n + 1; // Khởi tạo kích thước tối thiểu

    // Sử dụng bit masking để tạo ra tất cả các tập hợp con
    for (int mask = 1; mask < (1 << n); ++mask) {
        vector<PhanSo> con;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                con.push_back(phanSo[i]);
            }
        }

        // Kiểm tra nếu tập hợp con có tích bằng phân số đích
        if (kiemtra(con, dich) && con.size() < minSize) {
            result = con; // Cập nhật kết quả
            minSize = con.size();
        }
    }

    // Xuất kết quả
    if (result.empty()) {
        cout << "Khong tim thay tap hop con nao thoa man.\n";
    } else {
        // Sắp xếp các phân số trong tập hợp con
        sort(result.begin(), result.end(), [](const PhanSo& a, const PhanSo& b) {
            return Giatri_ps(a) < Giatri_ps(b);
        });

        cout << "Tap hop con thoa man: ";
        for (const auto& ps : result) {
            cout << ps.tu << "/" << ps.mau << " ";
        }
        cout << endl;
    }
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

    // Nhập phân số đích
    PhanSo dich;
    cout << "Nhap tu so phan so dich: ";
    cin >> dich.tu;
    do {
        cout << "Nhap mau so phan so dich (khong duoc bang 0): ";
        cin >> dich.mau;
    } while (dich.mau == 0);

    // Khai báo mảng phân số
    PhanSo* luu_tru = new PhanSo[n];
    NhapPhanSo(luu_tru, n);

    // Tìm và xuất tập hợp con
    TimTapHopCon(luu_tru, n, dich);

    // Giải phóng bộ nhớ
    delete[] luu_tru;

    return 0;
}
