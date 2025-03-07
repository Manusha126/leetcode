class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int value;
        for(int i=0;i<nums.size();i++)
        {
            value=target-nums[i];
            if(mp.find(value)!=mp.end())
            {
                return {mp[value],i};
            }
            else
            {
                mp[nums[i]]=i;
            }
        }
        return {};
    }
};