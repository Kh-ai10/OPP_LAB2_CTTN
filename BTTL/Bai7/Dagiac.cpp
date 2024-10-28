#include "Dagiac.h"
#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

/*
Hàm xác định vị trí của một điểm:
Đầu vào: Tọa độ 3 điểm O, A và B
Đầu ra: Một giá trị định thức x nào đó.
        x > 0 -> B nằm bên trái OA
        x < 0 -> B nằm bên phải OA
        x = 0 -> B nằm trên OA.
Cách hoạt động: Tính định thức của ma trận 2*2 được tạo bởi 2 vector là OA và OB.
*/
float cross(const Diem& O, const Diem& A, const Diem& B) {
    return (A.GetHoanhDo() - O.GetHoanhDo()) * (B.GetTungDo() - O.GetTungDo()) - 
    (A.GetTungDo() - O.GetTungDo()) * (B.GetHoanhDo() - O.GetHoanhDo());
}

void Dagiac::Nhap() {
    cout << "Nhap so dinh (n > 2): ";
    cin >> sodinh;

    while (sodinh <= 2) {
        cout << "So dinh phai lon hon 2. Nhap lai: ";
        cin >> sodinh;
    }

    dinh = new Diem[sodinh]; // Cấp phát bộ nhớ cho mảng động

    for (int i = 0; i < sodinh; i++) {
        while (true) {
            cout << "Nhap toa do dinh " << (i + 1) << " (x, y): ";
            dinh[i].Nhap();

            // Kiểm tra xem đỉnh vừa nhập có trùng với đỉnh nào trước đó không
            bool trung = false;
            for (int j = 0; j < i; j++) {
                if (dinh[i].GetHoanhDo() == dinh[j].GetHoanhDo() &&
                    dinh[i].GetTungDo() == dinh[j].GetTungDo()) {
                    trung = true;
                    break;
                }
            }

            if (trung) {
                cout << "Dinh bi trung voi dinh " << (i + 1) << ", nhap lai.\n";
            } else {
                break; // Nếu không trùng thì thoát khỏi vòng lặp
            }
        }
    }

    bool ktra = true;
    for (int i = 2; i < sodinh; i++) {
        if (cross(dinh[0], dinh[1], dinh[i]) != 0) {
             ktra = false;
            break;
    }
}

    if (ktra) {
        cout << "Cac dinh nam tren mot duong thang. Nhap lai.\n";
    delete[] dinh; // Giải phóng bộ nhớ đã cấp phát
    dinh = nullptr; // Đặt về null để tránh truy cập không hợp lệ
    Nhap(); // Gọi lại hàm nhập
}   
}

/*
Hàm tính diện tích đa giác
Đầu vào: Tọa độ các đỉnh của đa giác
Đầu ra: Diện tích của đa giác.
Cách hoạt động: Tính theo công thức Shoelace
Tuy nhiên công thức này yêu cầu các điểm phải theo thứ tự kim đồng hồ
Vậy ta cần viết 1 giải thuật để sắp xếp lại các điểm trong trường hợp không thỏa
Áp dụng thuật toán Graham Scan
Tiến hành: 
Tìm điểm A có tung độ nhỏ nhất.
Sắp xếp các điểm còn lại theo góc so với điểm A.
Lấy điểm hoặc bỏ: dựa vào giá trị định thức đã trình bày.
Chỉ lấy điểm nằm bên trái đoạn thẳng đang xét.
Những điểm thỏa mãn thì ta bỏ vào 1 mảng động để tính diện tích
*/
float Dagiac::DienTich() {
    // Tìm điểm thấp nhất
    Diem thapnhat = dinh[0];
    for (int i = 1; i < sodinh; i++) {
        if (dinh[i].GetTungDo() < thapnhat.GetTungDo() || 
            (dinh[i].GetTungDo() == thapnhat.GetTungDo() 
            && dinh[i].GetHoanhDo() < thapnhat.GetHoanhDo())) {
            thapnhat = dinh[i];
        }
    }

    // Sắp xếp các điểm theo góc với điểm thấp nhất
    auto sapxep = [&](const Diem& a, const Diem& b) {
        float goc_A = atan2(a.GetTungDo() - thapnhat.GetTungDo(), 
        a.GetHoanhDo() - thapnhat.GetHoanhDo());
        float goc_B = atan2(b.GetTungDo() - thapnhat.GetTungDo(), 
        b.GetHoanhDo() - thapnhat.GetHoanhDo());
        return goc_A < goc_B;
    };

    // Sắp xếp bằng mảng động
    Diem* d_da_sxep = new Diem[sodinh];
    copy(dinh, dinh + sodinh, d_da_sxep);
    sort(d_da_sxep, d_da_sxep + sodinh, sapxep);

    // Bước 3: Xây dựng đường bao
    Diem* duong_bao = new Diem[sodinh]; // Mảng chứa điểm của đường bao
    int kichthuoc = 0; // Số điểm trong đường bao

    duong_bao[kichthuoc++] = thapnhat;

    for (int i = 0; i < sodinh; i++) {
        while (kichthuoc >= 2 && cross(duong_bao[kichthuoc - 2], 
        duong_bao[kichthuoc - 1], d_da_sxep[i]) <= 0) {
            kichthuoc--;
        }
        duong_bao[kichthuoc++] = d_da_sxep[i];
    }

    float dienTich = 0.0;
    for (int i = 0; i < kichthuoc; i++) {
        int j = (i + 1) % kichthuoc; // Lấy chỉ số của đỉnh tiếp theo
        dienTich += (duong_bao[i].GetHoanhDo() * duong_bao[j].GetTungDo()) - 
        (duong_bao[j].GetHoanhDo() * duong_bao[i].GetTungDo());
    }

    delete[] d_da_sxep; // Giải phóng bộ nhớ
    delete[] duong_bao; // Giải phóng bộ nhớ
    return abs(dienTich) / 2.0; // Trả về diện tích
}

void Dagiac::Xuat() {
    cout << "Toa do cac dinh cua da giac:\n";
    for (int i = 0; i < sodinh; i++) {
        dinh[i].Xuat();
    }
}

Dagiac::~Dagiac() {
    delete[] dinh; // Giải phóng bộ nhớ
}
