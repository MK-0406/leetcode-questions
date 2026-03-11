#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        int total = 0;
        int index = 0;
        while (n >= 0) {
            if (!(n & 1)) {
                total += pow(2, index);
            }
            index++;
            n >>= 1;
            if (n == 0) break;
        }
        return total;
    }
};

int main()
{
    Solution s;
    cout << s.bitwiseComplement(5) << endl;
    cout << s.bitwiseComplement(7) << endl;
    cout << s.bitwiseComplement(10) << endl;

    return 0;
}