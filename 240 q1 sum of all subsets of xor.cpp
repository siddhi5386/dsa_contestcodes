Brute force approach where we iterate over all possible subsets and compute their XORs and add that to result.

Here the trick is to use binary representation of numbers to generate power set.
For instance, if we have 3 elements, we can generate binary counting upto 2^3 to get all possible subsets.

000 => {empty set}
001 => {set with only first element}
010 => {set with only second element}
011 => {set with first and second element}
100 ... and so on
101
110
111 => {subset with all three elements}
Here is the C++ code for this brute force approach.

class Solution
{
public:
    int subsetXORSum(vector<int>& nums)
    {
        int N = nums.size();
        int numOfSubsets = pow(2, N);
        int result = 0;
        
        // binary representation of subsets help us identify whether to take an element of num or not
        for (int subset = 1; subset < numOfSubsets; ++subset)
        {
            int runningXor = 0;
            for (int i = 0, bits = subset; i < nums.size(); ++i, bits >>= 1)
                if (bits & 1)   // whether to include current element in subset
                    runningXor ^= nums[i];
            
            result += runningXor;
        }
        
        return result;
    }
};