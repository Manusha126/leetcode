class Solution {
public:
        bool binarysearch(vector<int>& nums,int start,int end,int target)
        {
            while(start<=end)
            {
            int mid=(start+end)/2;
            if(nums[mid]==target)
            {
                return true;
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
            }
            return false;
            

        }

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;

        int n=nums.size();
        for(int i=1;i<=n;i++)
        {
           if(!binarysearch(nums,0,n-1,i))
           {
                  ans.push_back(i);
           }

        }
        return ans;
         
        
    }
};