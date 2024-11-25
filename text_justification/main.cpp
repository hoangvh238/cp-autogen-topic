#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int n = words.size();
    int index = 0;

    while (index < n) {
        int totalChars = words[index].size();
        int last = index + 1;

        // Tìm số lượng từ có thể đặt trên một dòng
        while (last < n && totalChars + words[last].size() + (last - index) <= maxWidth) {
            totalChars += words[last].size();
            last++;
        }

        string line;
        int spaces = last - index - 1;

        if (last == n || spaces == 0) {
            // Dòng cuối cùng hoặc dòng chỉ có một từ
            for (int i = index; i < last; i++) {
                line += words[i];
                if (i < last - 1) line += " ";
            }
            line += string(maxWidth - line.size(), ' '); // Thêm khoảng trắng còn lại
        } else {
            // Dòng căn giữa
            int extraSpaces = (maxWidth - totalChars) / spaces;
            int remainderSpaces = (maxWidth - totalChars) % spaces;

            for (int i = index; i < last; i++) {
                line += words[i];
                if (i < last - 1) {
                    line += string(extraSpaces + (remainderSpaces > 0 ? 1 : 0), ' ');
                    if (remainderSpaces > 0) remainderSpaces--;
                }
            }
        }

        result.push_back(line);
        index = last;
    }

    return result;
}

int main() {
    int n, maxWidth;
    cin >> n;
    cin.ignore(); // Bỏ qua ký tự xuống dòng sau n

    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    cin >> maxWidth;

    // Kiểm tra ràng buộc đầu vào
    if (n < 1 || n > 300) {
        cerr << "Error: Number of words (n) must be between 1 and 300." << endl;
        return 1;
    }
    if (maxWidth < 1 || maxWidth > 100) {
        cerr << "Error: maxWidth must be between 1 and 100." << endl;
        return 1;
    }
    for (const string& word : words) {
        if (word.size() > maxWidth) {
            cerr << "Error: Each word length must not exceed maxWidth." << endl;
            return 1;
        }
    }

    vector<string> result = fullJustify(words, maxWidth);
    for (const string& line : result) {
        cout << "\"" << line << "\"" << endl;
    }

    return 0;
}
