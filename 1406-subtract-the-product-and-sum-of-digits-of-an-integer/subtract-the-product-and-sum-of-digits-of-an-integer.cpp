class Solution {
public:
    int subtractProductAndSum(int n) {
        int s=0;
        int m=1;
        int d;
        while(n>0){
            int d=n%10;
            s+=d;
            m*=d;
            n/=10;
        }
        return m-s;
    }
};