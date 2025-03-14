class Solution {
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);
        int low=0;
        int high=nums.length-1;
        int mid=low+(high-low)/2;
        while(low<=high)
        {
            if(low==high)
            {
                if(nums[low]==low)//for{0,1}
                   mid=low+1;
                else
                {
                    mid=low;//for{0,2}
                }
                break;
            }
           if(nums[mid]!=mid)
           {
             high=mid-1;
             mid=low+(high-low)/2;
           }
           else
           {
            low=mid+1;
             mid=low+(high-low)/2;
           }
        }
        return mid;
        
    }
}