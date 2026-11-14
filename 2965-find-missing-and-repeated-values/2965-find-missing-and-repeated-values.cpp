class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    int total = n*n;
    int xr=0;
    for (int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            xr=xr^grid[i][j] ;
        }
    }
     for(int i=1 ; i<=total ; i++){
            xr=xr^i;
        }
        int bitInd=0;
        while(1){
            if((xr & (1 << bitInd)) !=0){
                break;
            }
            else{
            bitInd++;
            }
        }
        int a=0;
        int b=0;
        for(int i=0; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if((grid[i][j] & (1 << bitInd)) !=0){
            a=a^grid[i][j];
            }
            else{
                b=b^grid[i][j];
            }
        }
        }
         for(int i=1 ; i<=total ; i++){
            if((i & (1 << bitInd)) !=0){
                a=a^i;
            }
            else{
                b=b^i;
            }
        }
        int count =0 ;
        for(int i=0 ; i<n ; i++){
        for(int j=0 ; j< n ; j++){
            if(a==grid[i][j]){
                count++;
            }
        }
        }
        if(count==2){
            return{a,b};
        }
        else{
            return{b,a};
        }
    }
};