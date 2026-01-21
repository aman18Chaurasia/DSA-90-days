class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        
        int sum=0;
        int freq[101]={0};
        for(int x:nums){
            freq[x]++;
        }
        for(int i=1;i<=100;i++){
            if(freq[i]==1) sum+=i;
        }
        return sum;
    }
};