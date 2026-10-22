class Solution {
public:
    bool isPalindrome(int x){
        if (x<0 ||( x%10==0 && x!= 0)){
            return false ;
        }
        int reverse_half = 0;
        while(x>reverse_half){
            int digit = x%10;
            reverse_half = reverse_half*10 + digit;
            x=x/10;
        }
        if(reverse_half==x || reverse_half/10 ==x){
    
        return true ;
        }
     return false;
 }   


};