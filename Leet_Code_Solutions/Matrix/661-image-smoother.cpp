class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int n = img.size();
        int m = img[0].size();

        vector<vector<int>> image_smoother(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                int sum = 0, count = 0;

                for (int x = i - 1; x <= i + 1; x++)
                {
                    for (int y = j - 1; y <= j + 1; y++)
                    {
                        if (x >= 0 && y >= 0 && x < n && y < m)
                        {
                            sum += img[x][y];
                            count += 1;
                        }
                    }
                }

                image_smoother[i][j] = sum / count;
            }
        }
        return image_smoother;
    }
};