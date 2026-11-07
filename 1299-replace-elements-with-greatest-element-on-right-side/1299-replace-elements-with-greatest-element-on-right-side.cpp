class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
    int maxi=-1;
    vector<int>ans;
   int n= arr.size() ;
    for(int i=n-1 ; i>=0 ;i-- ){
      ans.push_back(maxi);
      maxi = max(maxi,arr[i]);  
    }
    reverse(ans.begin(),ans.end());
      return ans;
    }
};