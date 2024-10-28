#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
  Kiểm tra xem hình chữ nhật có rìa bằng 0 hay không.
Đầu vào:
   matrix: Ma trận chứa dữ liệu đầu vào.
   x: Tọa độ x (cột) của hình chữ nhật.
   y: Tọa độ y (hàng) của hình chữ nhật.
   w: Chiều rộng của hình chữ nhật.
   h: Chiều cao của hình chữ nhật.
   m: Số hàng của ma trận.
  n: Số cột của ma trận.
Hoạt động:
- Duyệt qua các cạnh trên và dưới của hình chữ nhật để kiểm tra nếu có bất kỳ 
  phần tử nào không phải là 0.
- Tương tự, kiểm tra các cạnh trái và phải.
Đầu ra: true nếu rìa của hình chữ nhật bằng 0, ngược lại false.
 */
bool Kiemtra(const vector<vector<int>>& matrix, int x, int y, int w, 
int h, int m, int n) {
    // Kiểm tra cạnh trên và cạnh dưới của hình chữ nhật
    for (int j = x; j < x + w; ++j) {
        if ((y > 0 && matrix[y - 1][j] != 0) || (y + h < m && 
        matrix[y + h][j] != 0)) {
            return false;
        }
    }
    // Kiểm tra cạnh trái và cạnh phải của hình chữ nhật
    for (int i = y; i < y + h; ++i) {
        if ((x > 0 && matrix[i][x - 1] != 0) || (x + w < n && 
        matrix[i][x + w] != 0)) {
            return false;
        }
    }
    return true;
}

/*
  Kiểm tra xem tất cả các phần tử trong hình chữ nhật có giá trị bằng 1 hay không.
  
   matrix: Ma trận chứa dữ liệu đầu vào.
   x: Tọa độ x (cột) của hình chữ nhật.
   y: Tọa độ y (hàng) của hình chữ nhật.
   w: Chiều rộng của hình chữ nhật.
   h: Chiều cao của hình chữ nhật.
   Hoạt động: Duyệt qua tất cả các phần tử trong hình chữ nhật và kiểm tra từng phần tử.
   return: true nếu tất cả các phần tử đều bằng 1, ngược lại false.
 */
bool Ktra_ptu_la_1(const vector<vector<int>>& matrix, int x, int y, int w, int h) {
    for (int i = y; i < y + h; ++i) {
        for (int j = x; j < x + w; ++j) {
            if (matrix[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

/*
  Tìm tất cả các hình chữ nhật trong ma trận có kích thước tối thiểu 2x2.

Đầu vào:
   matrix: Ma trận chứa dữ liệu đầu vào.
   m: Số hàng của ma trận.
   n: Số cột của ma trận.
Hoạt động:
   Duyệt qua từng phần tử trong ma trận. 
   Nếu phần tử có giá trị 1 và chưa được đánh dấu là đã tìm tới:
   Xác định chiều rộng w và chiều cao h của hình chữ nhật bằng cách kiểm tra 
   liên tiếp các phần tử bên phải và bên dưới.
   Kiểm tra các điều kiện: chiều rộng và chiều cao phải lớn hơn hoặc bằng 2, 
   và rìa phải bằng 0, cũng như toàn bộ phần tử bên trong phải bằng 1.
   Nếu tất cả điều kiện đều thỏa mãn, thêm hình chữ nhật vào danh sách và 
   đánh dấu các phần tử của nó là đã tìm tới.
Đầu ra:
Danh sách các hình chữ nhật dưới dạng vector, mỗi hình chữ nhật được đại diện
        bởi một vector gồm 4 phần tử: {x, y, width, height}.
 */
vector<vector<int>> Tim(const vector<vector<int>>& matrix, int m, int n) {
    vector<vector<int>> rectangles;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                int x = j, y = i;
                int w = 0, h = 0;

                // Tìm chiều rộng của hình chữ nhật
                while (x + w < n && matrix[i][x + w] == 1) ++w;

                // Tìm chiều cao của hình chữ nhật
                while (y + h < m && matrix[y + h][j] == 1) ++h;

                // Nếu thỏa mãn các điều kiện
                if (w >= 2 && h >= 2 && Kiemtra(matrix, j, i, w, h, m, n) 
                    && Ktra_ptu_la_1(matrix, j, i, w, h)) {
                    
                    // Thêm hình chữ nhật vào danh sách
                    rectangles.push_back({ j, i, w, h });

                    // Đánh dấu các phần tử của hình chữ nhật là đã tìm tới
                    for (int p = i; p < i + h; ++p) 
                        for (int q = j; q < j + w; ++q) 
                            visited[p][q] = true;
                }
            }
        }
    }

    // Sắp xếp danh sách các hình chữ nhật từ trái sang phải và từ trên xuống dưới
    sort(rectangles.begin(), rectangles.end(), [](const vector<int>& a, 
        const vector<int>& b) {
             if (a[1] == b[1]) return a[0] < b[0];
             return a[1] < b[1];
    });

    return rectangles;
}


int main() {
    int m, n;
    cin >> m >> n;

    // Nhập ma trận
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Tìm các hình chữ nhật
    vector<vector<int>> rectangles = Tim(matrix, m, n);

    // Xuất các hình chữ nhật
    if (rectangles.empty()) {
        cout << "Khong co hinh chu nhat nao thoa\n"; 
        // Kiểm tra nếu không có hình chữ nhật nào
    } else {
        for (const auto& rect : rectangles) {
            cout << "[" << rect[0] << ", " << rect[1] << ", " << rect[2] << ", " 
            << rect[3] << "]\n";
        }
    }
    return 0;
}
