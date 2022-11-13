//sort + two pointer
//Runtime: 8 ms, faster than 99.93% of C++ online submissions for Two Sum.
//Memory Usage: 9.5 MB, less than 70.01% of C++ online submissions for Two Sum.
//time: O(NlogN), space: O(N)

// Approach 2 - Sorting - O(nlogn)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<pair<int,int>> temp;
//         for(int i=0;i<nums.size();i++){
//             temp.push_back({nums[i],i});
//         }
        
//         vector<int> ans;
//         sort(temp.begin(), temp.end());
//         int i=0, j=nums.size()-1;
//         while(i<j){
//             if(temp[i].first + temp[j].first == target){
//                 ans.push_back(temp[i].second);
//                 ans.push_back(temp[j].second);
//                 return ans;
//             } else if(temp[i].first + temp[j].first < target){
//                 i++;
//             } else{
//                 j--;
//             }
//         }
//         return ans;
//     }
// };

Hash Map 0(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> target_indices;
        unordered_map<int, int> hash_table;
        for  (int i=0; i< nums.size(); i++){
            int second_integer = target - nums.at(i);

            if (hash_table.find(second_integer)!=hash_table.end()){
                target_indices.push_back(i);
                target_indices.push_back(hash_table.find(second_integer)->second);
                break;
            } else{
                hash_table[nums.at(i)] = i;
            }
        }
        return target_indices;
    }
};



// Brute Force O(n2)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> ans;
//         for(int i=0; i<nums.size();i++){
//             for(int j=i+1; j<nums.size(); j++){
//                 if(nums[i]+nums[j] == target){
//                     ans.push_back(i);
//                     ans.push_back(j);
//                     return ans;
//                 }
//             }
//         }
//         return ans;
        
//     }
// };

// Sorting
