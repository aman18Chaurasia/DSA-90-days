class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> r(m, vector<int>(n+1)), c(m+1, vector<int>(n));
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                r[i][j+1]=r[i][j]+g[i][j];
                c[i+1][j]=c[i][j]+g[i][j];
            }
        
        for(int k=min(m,n);k>=1;k--)
            for(int i=0;i+k<=m;i++)
                for(int j=0;j+k<=n;j++){
                    int s=r[i][j+k]-r[i][j], d1=0,d2=0;
                    bool ok=true;
                    
                    for(int x=0;x<k;x++){
                        if(r[i+x][j+k]-r[i+x][j]!=s ||
                           c[i+k][j+x]-c[i][j+x]!=s){
                            ok=false; break;
                        }
                        d1+=g[i+x][j+x];
                        d2+=g[i+x][j+k-1-x];
                    }
                    if(ok && d1==s && d2==s) return k;
                }
        return 1;
    }
};
