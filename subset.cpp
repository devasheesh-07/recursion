#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans) {
        // Base case
        if(index >= nums.size()) {
            ans.push_back(output);
            return;
        }

        // Exclude
        solve(nums, output, index+1, ans);

        // Include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.subsets(nums);

    cout << "Subsets:" << endl;
    for(const auto& subset : result) {
        cout << "[";
        for(int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
