class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    arr.push_back(nums1[i]);
                }
            }
        }
        int freq[1001]={0};
        vector<int> result;
        for(int x:arr){
            freq[x]++;
        }
        for(int i=0;i<=1000;i++){
            if(freq[i]>0){
                result.push_back(i);
            }
        }
        return result;
    }
};