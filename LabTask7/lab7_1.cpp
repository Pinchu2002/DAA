// Longest common subsequence
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int ans;
        if (text1.size() >= text2.size())
        {
            vector<vector<int>> dp(text2.size() + 1, vector<int>(text1.size() + 1, 0));
            for (int i = 0; i < text2.size(); i++)
            {
                for (int j = 0; j < text1.size(); j++)
                {
                    if (text2[i] == text1[j])
                    {
                        dp[i + 1][j + 1] = 1 + dp[i][j];
                    }
                    else
                    {
                        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                    }
                }
            }
            ans = dp[text2.size()][text1.size()];
        }
        else
        {
            vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
            for (int i = 0; i < text1.size(); i++)
            {
                for (int j = 0; j < text2.size(); j++)
                {
                    if (text1[i] == text2[j])
                    {
                        dp[i + 1][j + 1] = 1 + dp[i][j];
                    }
                    else
                    {
                        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                    }
                }
            }
            ans = dp[text1.size()][text2.size()];
        }
        return ans;
    }
};

int main(){
    
    string s1, s2;
    cout << "Enter string1 - ";
    cin >> s1;
    cout << "Enter string2 - ";
    cin >> s2;
    Solution obj;
    cout << obj.longestCommonSubsequence(s1, s2) << endl;
    return 0;
}