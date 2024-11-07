#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];

                if (total > 0) {
                    k--;
                } else if (total < 0) {
                    j++;
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;

                    while (nums[j] == nums[j-1] && j < k) {
                        j++;
                    }
                }
            }
        }
        return res;        
    }
};

int main(){
    Solution solution;
    vector<int> nums;

    int n;
    cout << "Enter the number of the elements: ";
    cin >> num;
    
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }

    vector<vector<int>> result = solution.threeSum(nums);

    cout << "Triplets that sum to zero:\n";
    for (const auto& triplet : result) {
        cout << "[";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}