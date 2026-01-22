class Solution{
public:
int removeElement(vector<int>&nums,int val){
    int left=0,right=nums.size();
    while(left<right){
        if(nums[left]==val){
             nums[left]=nums[--right];
        }else{
              left++;
        }
    }
    return right;
    }
};
