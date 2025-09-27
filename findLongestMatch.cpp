#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

string findLongestMatch(const string& text1, const string& text2, int& longest) {
    int n = text1.length();
    int m = text2.length();
    vector<vector<int>> table(n + 1, vector<int>(m + 1, 0));
    longest = 0;
    int endAt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
                if (table[i][j] > longest) {
                    longest = table[i][j];
                    endAt = i - 1;
                }
            }
        }
    }
    cout << "\nProgress Table:\n    ";
    for (char c : text2) cout << setw(3) << c;
    cout << "\n";
    for (int i = 0; i <= n; i++) {
        if (i > 0) cout << setw(3) << text1[i - 1] << " ";
        else cout << "    ";
        for (int j = 0; j <= m; j++) cout << setw(3) << table[i][j];
        cout << "\n";
    }

    return text1.substr(endAt - longest + 1, longest);
}

int main() {
    string word1, word2;
    cout << "Enter string 1: ";
    cin >> word1;
    cout << "Enter string 2: ";
    cin >> word2;

    if (word1.size() != word2.size()) {
        cout << "Error: Strings must be equal length.\n";
        return 0;
    }

    int longestLen;
    string lcs = findLongestMatch(word1, word2, longestLen);

    cout << "\nSummary:\n";
    cout << "String 1: " << word1 << "\n";
    cout << "String 2: " << word2 << "\n";
    cout << "Longest Common Substring: " << lcs << "\n";
    cout << "Length: " << longestLen << "\n";
}
