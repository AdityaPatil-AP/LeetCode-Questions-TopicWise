class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // Brute Force.
        // Merge the two sorted arrays using O(n) approach.
        // and then find the median.
        //         int size = nums1.size() + nums2.size();
        //         vector<int> sorted(size);
        //         int i = 0, j = 0, k = 0;
        //         while(i < nums1.size() && j < nums2.size()){
        //             if(nums1[i] < nums2[j]){
        //                 sorted[k++] = nums1[i++];
        //             }
        //             else{
        //                 sorted[k++] = nums2[j++];
        //             }
        //         }
        //         // If any one of the array still contain elements we will empty it.
        //         while(i < nums1.size()){
        //             sorted[k++] = nums1[i++];
        //         }
        //         while(j < nums2.size()){
        //             sorted[k++] = nums2[j++];
        //         }

        //         if(sorted.size() % 2) return 1.0 * sorted[size/2];
        //         return (sorted[size/2] + sorted[(size - 1)/2])/2.0;

        // Using Divide and Conquer and Binary Search.
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        // Now here the basic ideology is to divide the array into two parts.
        // partition X and partition Y.
        int x = nums1.size(), y = nums2.size();
        int low = 0;
        int high = nums1.size();

        while (low <= high)
        {
            int partitionx = (low + high) / 2;
            int partitiony = (x + y + 1) / 2 - partitionx;

            int maxleftx = (partitionx == 0) ? INT_MIN : nums1[partitionx - 1];
            int maxlefty = (partitiony == 0) ? INT_MIN : nums2[partitiony - 1];
            int minrightx = (partitionx == x) ? INT_MAX : nums1[partitionx];
            int minrighty = (partitiony == y) ? INT_MAX : nums2[partitiony];

            if (maxleftx <= minrighty && maxlefty <= minrightx)
            {
                if ((x + y) % 2 == 0)
                    return (max(maxleftx, maxlefty) + min(minrightx, minrighty)) / 2.0;
                else
                    return (max(maxleftx, maxlefty));
            }
            else if (maxleftx > minrighty)
            {
                high = partitionx - 1;
            }
            else
            {
                low = partitionx + 1;
            }
        }

        return 0;
    }
};