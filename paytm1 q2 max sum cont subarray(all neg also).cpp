class Solution{
public:
    int maxSubarraySum(int a[], int N){
        // Your code here
        int max_so_far = a[0];
        int curr_max = a[0];
 
        for (int i = 1; i < N; i++)
        {
            curr_max = max(a[i], curr_max+a[i]);
            max_so_far = max(max_so_far, curr_max);
        }
        return max_so_far;
    }
};