class Solution {
public:
void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> leftPart;
        vector<int> rightPart;
 
        // Copy left range to preserve values during merging.
        for (int index = left; index <= mid; index++) {
            leftPart.push_back(nums[index]);
        }
 
        // Copy right range for safe comparison during merging.
        for (int index = mid + 1; index <= right; index++) {
            rightPart.push_back(nums[index]);
        }
 
        int leftIndex = 0;
        int rightIndex = 0;
        int writeIndex = left;
 
        // Compare both ranges until one becomes empty.
        while (leftIndex < leftPart.size() && rightIndex < rightPart.size()) {
            // Take from left on equality to keep sorting stable.
            if (leftPart[leftIndex] <= rightPart[rightIndex]) {
                nums[writeIndex] = leftPart[leftIndex];
                leftIndex++;
            } else {
                nums[writeIndex] = rightPart[rightIndex];
                rightIndex++;
            }
            writeIndex++;
        }
 
        // Copy remaining left values as they are already sorted.
        while (leftIndex < leftPart.size()) {
            nums[writeIndex] = leftPart[leftIndex];
            leftIndex++;
            writeIndex++;
        }
 
        // Copy remaining right values as they are already sorted.
        while (rightIndex < rightPart.size()) {
        nums[writeIndex] = rightPart[rightIndex];
            rightIndex++;
            writeIndex++;
        }
}
int countPair(vector<int>&nums, int low , int mid , int high){
    int left=low;
    int right = mid+1;
    int count =0 ;
    for(int i=left ; i<=mid ; i++){
        while(right <= high && nums[i]> 2LL *nums[right]){
            right++;
        }
        count += right-(mid+1);
    }
return count ;
}
  int mergeSortHelper(vector<int>& nums, int left, int right) {
        // A range of zero or one value is already sorted.
        if (left >= right) {
            return 0;
        }
        long long count =0 ;
 
        int mid = left + (right - left) / 2;
 
        // Sort left half before merging.
       count += mergeSortHelper(nums, left, mid);
 
        // Sort right half before merging.
       count += mergeSortHelper(nums, mid + 1, right);

       count+= countPair(nums , left , mid , right);
        // Merge both sorted halves.
       merge(nums, left, mid, right);
       return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
    int count = mergeSortHelper(nums , 0 , n-1);
    return count ;
    }
};