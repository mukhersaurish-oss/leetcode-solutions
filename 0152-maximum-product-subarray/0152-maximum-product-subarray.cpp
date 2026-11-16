class Solution {
public:
    int maxProduct(vector<int>& nums) {
     int maxi= INT_MIN;
     int suf=1;
     int pref=1 ;
     for(int i=0 ;  i<nums.size() ; i++){
        if(suf==0) suf=1;
        if(pref==0) pref=1;
        suf*=nums[i];
        pref*=nums[nums.size()-i-1];
        maxi = max(maxi , max(suf,pref));
     }
     return maxi ;   
    }
};