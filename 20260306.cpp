#include <iostream>
#include <string>

using namespace std;

class Solution1
{
public:
    bool checkOnesSegment(string s)
    {
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                for (int j = i; j < s.size(); j++)
                {
                    if (s[j] == '1')
                        return false;
                }
            }
        }
        return true;
    }
};

class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        bool afterZero = false;

        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '0') afterZero = true;

            if (afterZero && s[i] == '1') return false; 
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.checkOnesSegment("1001") << endl;
    cout << s.checkOnesSegment("110") << endl;
    cout << s.checkOnesSegment("1") << endl;
    cout << s.checkOnesSegment("1100111") << endl;

    return 0;
}