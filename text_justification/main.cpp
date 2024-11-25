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

        while (last < n && totalChars + words[last].size() + (last - index) <= maxWidth) {
            totalChars += words[last].size();
            last++;
        }

        string line;
        int spaces = last - index - 1;

        if (last == n || spaces == 0) {
            // Left-justified line
            for (int i = index; i < last; i++) {
                line += words[i];
                if (i < last - 1) line += " ";
            }
            while (line.size() < maxWidth) line += " ";
        } else {
            // Fully-justified line
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
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    cin >> maxWidth;

    vector<string> result = fullJustify(words, maxWidth);
    for (const string& line : result) {
        cout << "\"" << line << "\"" << endl;
    }

    return 0;
}
