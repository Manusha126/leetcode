class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> square(n);
        for(int i=0;i<nums.size();i++)
        {
            square[i]=nums[i]*nums[i];
        }
        sort(square.begin(),square.end());
        return square;
        
    }
};