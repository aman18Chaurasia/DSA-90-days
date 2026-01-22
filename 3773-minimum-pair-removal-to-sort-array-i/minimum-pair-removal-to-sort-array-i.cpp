class Solution {
public:
    bool is(const vector<int>& nums){
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1])
                return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums){
        int ops=0;
        while(!is(nums)){
            int minSum=INT_MAX;
            int idx=0;
            for(int i=0;i+1<nums.size();i++){
                int s=nums[i]+nums[i+1];
                if(s<minSum){
                    minSum=s;
                    idx=i;
                }
            }
            nums[idx]= nums[idx]+nums[idx+1];
            nums.erase(nums.begin()+idx+1);
            ops++;
        }
        return ops;
    }
};
