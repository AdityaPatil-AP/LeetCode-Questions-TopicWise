class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        // Brute Force will give TLE.
        //         int max_product = INT_MIN;
        //         int n = nums.size();
        //         for(int i = 0;i < n;i++){
        //             int curr_product = 1;

        //             for(int j = i;j < n;j++){
        //                 curr_product *= nums[j];
        //                 max_product = max(curr_product, max_product);
        //             }
        //         }

        //         return max_product;

        // 2) Using DP and storing the max_product, and min_product.
        // To find : The Maximum product subarray,
        // How does the sign changes,
        // When a negative number multiplies with a negative number then it may give the largest
        // product as well.

        // So we need to maintain one variable to store the min_product.
        // and other to store the max_product.

        // As well keep updating the global_max_product in some variable.

        // Here there is a juggle between min_product and max_product, if the number is positive then
        // the max_product increases, and the min_product increases as well,
        // if the number is negative, then max_product takes help of min_product. and min_product checks for
        // for max_product * curr_number.

        // min_product = min(nums[i], min_product * nums[i], max_product * nums[i]);
        // max_product = max(nums[i], max_product * nums[i], min_product * nums[i]);
        int n = nums.size();
        int min_product = nums[0];
        int max_product = nums[0];

        int result = nums[0];

        for (int i = 1; i < n; i++)
        {
            int temp = max(nums[i], max(nums[i] * max_product, nums[i] * min_product));
            min_product = min(nums[i], min(nums[i] * max_product, nums[i] * min_product));
            max_product = temp;

            result = max(result, max_product);
        }

        return result;
    }
};