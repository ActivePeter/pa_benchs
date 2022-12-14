#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//返回两部分的差值
int diff(vector<int> &vec)
{
    int len = vec.size();
    int sum = 0;
    for (int i = 0; i < len; ++i)
    {
        sum += vec[i];
    }
    vector<vector<int>> dp;
    for (int i = 0; i <= len; i++)
    {
        vector<int> tmp;
        for (int j = 0; j <= sum / 2; ++j)
        {
            tmp.push_back(0);
        }
        dp.push_back(tmp);
    }
    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= sum / 2; j++)
        {
            if (j >= vec[i - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vec[i - 1]] + vec[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    /*for (int i = 0; i <= len; i++) {
      for (int j = 0; j <= sum / 2; j++) {
       cout<<dp[i][j]<<" ";

      }
      cout<<endl;
    }*/
    int f[1005];
    int i = len;
    cout << i << "len";

    int j = sum / 2;
    cout << j << "sum";
    vector<int> ans;
    for (i; i > 0; i--)
    {
        if (dp[i][j] == dp[i - 1][j])
        {
            continue;
        }
        else
        {
            ans.push_back(i-1);
            j = j - vec[i-1];
            cout << i << " ";
        }
    }

    /*for(int i=0;i<ans.size();i++)
    {
      cout<<vec[ans[i]]<<" ";
    }
    cout<<endl;*/

    return sum - 2 * dp[len][sum / 2];
}
int main()
{
    int a[] = {3, 3, 7, 9, 10};
    vector<int> vec(a, a + 5);

    cout << diff(vec) << endl;
    system("pause");
    return 0;
}