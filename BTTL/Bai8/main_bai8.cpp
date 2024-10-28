#include "List.h"
#include <iostream>

using namespace std;

int main() {
    List myList; // Khởi tạo list rỗng
    int n;

    while (true) {
        cout << "Nhap chi thi (n): ";
        cin >> n;

        switch (n) {
            case -1:
                // Nhảy đến B3
                goto printList; // Sử dụng goto để nhảy tới phần in ra list
            case 0: {
                double x;
                cout << "Nhap gia tri can them: ";
                cin >> x;
                myList.Them(x); // Thêm x vào list
                break;
            }
            case 1: {
                double x;
                cout << "Nhap gia tri can xoa (dau tien): ";
                cin >> x;
                myList.XoaDau(x); // Xóa phần tử đầu tiên có giá trị x
                break;
            }
            case 2: {
                double x;
                cout << "Nhap gia tri can xoa (tat ca): ";
                cin >> x;
                myList.XoaTatCa(x); // Xóa tất cả phần tử có giá trị x
                break;
            }
            case 3: {
                unsigned int x;
                double y;
                cout << "Nhap chi so x va gia tri moi y: ";
                cin >> x >> y;
                myList.CapNhat(x, y); // Cập nhật phần tử thứ x bằng y
                break;
            }
            default:
                cout << "Chi thi khong hop le. Vui long nhap lai.\n";
                break;
        }
    }
printList:
    myList.Xuat(); // In ra list

    return 0;
}
