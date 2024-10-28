#include <iostream>
using namespace std;

/*
 Hàm thực hiện biến đổi Arnold's Cat Map trên một ma trận.
 Đầu vào: 
 * matrix: con trỏ đến ma trận (int**) cần biến đổi.
 * m: kích thước của ma trận (số hàng và số cột, int).
 Đầu ra:
 * Ma trận đã biến đổi.
 Hoạt động: 
 - Tạo một ma trận tạm thời cùng kích thước với ma trận gốc.
 - Thực hiện biến đổi Arnold's Cat Map cho từng phần tử của ma trận gốc,
 - Tính toán vị trí mới cho từng phần tử và lưu vào ma trận tạm thời.
 - Cập nhật ma trận gốc bằng cách sao chép từ ma trận tạm thời.
 - Giải phóng bộ nhớ đã cấp phát cho ma trận tạm thời.
 */

void arnoldsCatMap(int** matrix, int m) {
    // Tạo một ma trận tạm thời
    int** tam_thoi = new int*[m];
    for (int i = 0; i < m; i++) {
        tam_thoi[i] = new int[m];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            int new_i = (2 * i + j) % m;
            int new_j = (i + j) % m;
            tam_thoi[new_i][new_j] = matrix[i][j]; // Gán giá trị mới 
        }
    }

    // Cập nhật ma trận gốc
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = tam_thoi[i][j];
        }
    }

    // Giải phóng bộ nhớ của ma trận tạm thời
    for (int i = 0; i < m; i++) {
        delete[] tam_thoi[i];
    }
    delete[] tam_thoi;
}

// Hàm kiểm tra hai ma trận có giống nhau không
bool isEqual(int** a, int** b, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int m;
    cin >> m;

    // Nhập ma trận ban đầu
    int** matrix = new int*[m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << '\n';

    // Lưu lại ma trận ban đầu để so sánh
    int** original_matrix = new int*[m];
    for (int i = 0; i < m; i++) {
        original_matrix[i] = new int[m];
        for (int j = 0; j < m; j++) {
            original_matrix[i][j] = matrix[i][j];
        }
    }

    int k = 0; // Biến đếm số lần biến đổi
    do {
        arnoldsCatMap(matrix, m); // Thực hiện biến đổi Arnold's Cat Map
        k++; // Tăng biến đếm số lần biến đổi lên 1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cout << matrix[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    } while (!isEqual(matrix, original_matrix, m));
    
    // Dừng khi ma trận ban đầu được phục hồi

    // Xuất số lần biến đổi
    cout << k << '\n';

    // Giải phóng bộ nhớ
    for (int i = 0; i < m; i++) {
        delete[] matrix[i];
        delete[] original_matrix[i];
    }
    delete[] matrix;
    delete[] original_matrix;

    return 0;
}
