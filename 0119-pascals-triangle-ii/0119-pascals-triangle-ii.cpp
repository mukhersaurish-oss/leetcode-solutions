class Solution {
public:
    vector<int> getRow(int rowIndex){
        long long  ans =1 ;
        vector<int>ansRow ;
        ansRow.push_back(1);
        for(int col=0 ; col <rowIndex ; col++){
            ans = (ans*(rowIndex-col))/(col+1) ;
            ansRow.push_back(ans);
        }
        return ansRow;
    }
};