#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    string target = "hello";
    int j = 0; // Chỉ số cho target

    // Duyệt qua từng ký tự của chuỗi s
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == target[j]) {
            j++;
        }
        // Nếu đã tìm được toàn bộ "hello"
        if (j == target.size()) {
            cout << "YES" << endl;
            return 0;
        }
    }

    // Nếu không tìm thấy đầy đủ "hello"
    cout << "NO" << endl;
    return 0;
}
