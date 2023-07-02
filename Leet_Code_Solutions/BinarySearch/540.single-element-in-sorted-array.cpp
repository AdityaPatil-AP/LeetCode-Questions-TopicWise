class Solution
{
public:
    int singleNonDuplicate(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
            return arr[0];
        if (arr[0] != arr[1])
            return arr[0];
        if (arr[n - 1] != arr[n - 2])
            return arr[n - 1];

        int l = 1, r = n - 2;
        while (l <= r)
        {
            int mid = (l + (r - l) / 2);
            if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
            {
                return arr[mid];
            }
            if (((mid & 1) && arr[mid] == arr[mid + 1]) || (mid & 1) == 0 && arr[mid] != arr[mid + 1])
            {
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        return 0;
    }
};