class Solution {
public:
    vector<int> minBitwiseArray ( vector<int>& nums ) {

        vector<int> ans;

        for ( int i = 0; i < nums.size(); i++ ) {

            int num = nums[i];

            if ( num == 2 ) {
                ans.push_back ( -1 );
                continue;
            }

            int temp = num;
            int count = 0;

            while ( temp % 2 == 1 ) {
                count++;
                temp = temp / 2;
            }

            int value = num - ( 1 << ( count - 1 ) );
            ans.push_back ( value );
        }

        return ans;
    }
};
