class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
          int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int k=i+1;k<n;k++)
            {
                int c=0;
                for(int j=0;j<m;j++)
                {
                    if(mat[i][j]==1 && mat[k][j]==1)
                    c++;
                    if(c>=2)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};