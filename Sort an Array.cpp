class Solution {
public:

    void merge(vector<int>& nums, int l, int mid, int r){
        if(l >= r) return;
        int i = l, j = mid + 1, k = 0, n = r-l+1;
        vector<int> sorted(n, 0);
        while(i <= mid && j <= r){
            sorted[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
        }
        while(i <= mid) sorted[k++] = nums[i++];
        while(j <= r) sorted[k++] = nums[j++];

        for(k = 0; k < n; k++) nums[k+l] = sorted[k];
    }

    void mergeSort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int mid = l + (r-l)/2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid+1, r);
        merge(nums, l, mid, r);
    } 
        
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
