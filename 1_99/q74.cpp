

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowIndex = bsearch(matrix, [](const vector<int>& v){ return v[0]; }, target);
        if (rowIndex < matrix.size() && matrix[rowIndex][0] == target)
        {
            // handles the case where [row][0] was the target
            return true;
        }
        else if (rowIndex == 0)
        {
            // handles the case where target should be inserted before the smallest row
            return false;
        }
        else
        {
            int colIndex = bsearch(matrix.at(rowIndex - 1), [](const int& i){ return i; }, target);
            return colIndex < matrix[rowIndex - 1].size() && matrix[rowIndex - 1][colIndex] == target;
        }
    }
private:
    // return the index where f(matrix[i]) == target. if none, return the insertion point
    template<typename T, typename Func>
    int bsearch(vector<T>& matrix, Func f, int target)
    {
        int l = 0, r = matrix.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int cur = f(matrix[mid]);
            if (cur < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return l;
    }
};

int main() {
//    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    vector<vector<int>> matrix = {{1}};
    cout << std::boolalpha << Solution().searchMatrix(matrix, 2) << endl;
    return 0;
}
