class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0 = 0, c1 = 0, c2 = 0;
        int n = nums.size();
        int arr[n];
        int d = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) c0++;
            else if (nums[i] == 1) c1++;
            else c2++;
        }

        for (int i = 0; i < c0; i++)
            arr[d++] = 0;

        for (int i = 0; i < c1; i++)
            arr[d++] = 1;

        for (int i = 0; i < c2; i++)
            arr[d++] = 2;

        for (int i = 0; i < n; i++)
            nums[i] = arr[i];
    }
};
