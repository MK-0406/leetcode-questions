#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int size = s.size();
        int count = 0;
        for (int i = 0; i < size; i++) {
            if ((i % 2) != s[i] - '0') {count++;}
            cout << i << " " << i % 2 << " " << s[i] << " " << count << endl;
        }
        return min(count, size - count);
    }
};

int main()
{
    Solution s;
    cout << s.minOperations("0100") << endl;
    cout << s.minOperations("10") << endl;
    
    return 0;
}