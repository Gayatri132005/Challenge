#include <iostream>
#include <string>
using namespace std;

int countSubstrings(string s, int start, int end) {
    if (start == s.length())
        return 0;
    
    if (end == s.length())
        return countSubstrings(s, start + 1, start + 1); // move to next start index
    
    int count = 0;
    if (s[start] == s[end])
        count = 1;
    
    return count + countSubstrings(s, start, end + 1);
}

int main() {
    string S = "abcab";
    int result = countSubstrings(S, 0, 0);
    cout << "Count of substrings that start and end with same character: " << result << endl;
    return 0;
}
