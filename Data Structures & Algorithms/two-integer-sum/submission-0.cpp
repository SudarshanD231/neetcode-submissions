#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;        // value -> index
        seen.reserve(nums.size());

        for (int i = 0; i < (int)nums.size(); i++) {
            int comp = target - nums[i];

            auto it = seen.find(comp);       // lookup first
            if (it != seen.end())
                return {it->second, i};

            seen[nums[i]] = i;               // then insert
        }
        return {};                           // no solution
    }
};