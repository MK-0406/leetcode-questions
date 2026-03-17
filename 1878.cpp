#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void getBiggestThree(vector<vector<int>>& grid) {
        vector<int> sizes;
        for (int i = 0; i < grid.size(); i++){
            cout << grid.size() << endl;
            for (int j = 0; j < grid[i].size(); j++){
                cout << grid[i].size() << endl;
                for (int s = 0; s <= min((int)floor((grid.size() - i - 1) / 2), min(j, (int)grid[i].size() - j - 1)); s++) {
                    cout << i << " " << j << " " << s << endl;
                    sizes.push_back(getRhombusSize(grid, i, j, s));
                    cout << sizes.back() << endl;
                }
            }
        }
        sort(sizes.begin(), sizes.end(), greater<int>());
        auto last = unique(sizes.begin(), sizes.end());
        sizes.erase(last, sizes.end());

        if (sizes.size() > 3) {
            sizes.erase(sizes.begin() + 3, sizes.end());
        }
        cout << sizes.size() << endl << endl;
        return;
    }
    int getRhombusSize(vector<vector<int>>& grid, int y, int x, int size){
        if (size == 0) return grid[y][x];
        int total = 0;
        for (int i = 0; i < size; i++) {
            total += grid[y + i][x + i];
            cout << grid[y + i][x + i] << endl;
        }
        for (int i = 0; i < size; i++) {
            total += grid[y + size + i][x + size - i];
            cout << grid[y + size + i][x + size - i] << endl;
        }
        for (int i = 0; i < size; i++) {
            total += grid[y + size * 2 - i][x - i];
            cout << grid[y + size * 2 - i][x - i] << endl;
        }
        for (int i = 0; i < size; i++) {
            total += grid[y + size - i][x - size + i];
            cout << grid[y + size - i][x - size + i] << endl;
        }
        return total;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{1,2,3}, {4,5,6}, {7,8,9}};
    s.getBiggestThree(grid);
    grid = {{3,4,5,1,3}, {3,3,4,2,3}, {20,30,200,40,10}, {1,5,5,4,1}, {4,3,2,2,5}};
    s.getBiggestThree(grid);
    grid = {{7,7,7}};
    s.getBiggestThree(grid);

    return 0;
}