class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        
        int sum=0;
        int freq[101]={0};
        for(int x:nums){
            freq[x]++;
        }
        for(int i=0;i<nums.size();i++){
            if(freq[nums[i]]==1) sum+=nums[i];
        }
        return sum;
    }
};