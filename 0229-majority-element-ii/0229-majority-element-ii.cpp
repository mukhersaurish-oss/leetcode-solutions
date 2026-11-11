class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1= 0 ;
        int count1 =0 ;
        int el2=0 ;
        int count2=0;
        vector<int>ans;
        for(int i=0 ; i<  nums.size() ; i++){
            if (el1==nums[i]){
                count1++ ;            
        }
         else if (el2==nums[i]){
                count2++ ;            
        }
        else if(count1==0){
                el1=nums[i];
                count1++;
            }
           else if(count2==0){
                el2=nums[i];
                count2++;
            }
        else {
        count1--;
        count2--;
        }
    }
    count1 = 0;
 count2=0;
    for(int i=0 ; i<nums.size(); i++){
        if(el1==nums[i]){
            count1++;
        }
       else if(el2==nums[i]){
            count2++;
        }
    }
    if(count1 > nums.size()/3){
         ans.push_back(el1);
    }
    if(count2 > nums.size()/3){
        ans.push_back(el2);
    }
    return ans;
    }
};