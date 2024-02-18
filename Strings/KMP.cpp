#include <bits/stdc++.h>
using namespace std;

void computeLPS(string pattern, vector<int> &LPS, int n)
{
    int i = 0;
    int len = 0;

    while (i < n)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            LPS[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = LPS[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
vector<int> result KMP(string &text, string &pattern)
{
    int m = text.length();
    int n = pattern.length();
    vector<int> result;
    vector<int> LPS(n, 0);

    computeLPS(pattern, LPS, n);

    int i = 0;
    int j = 0;

    while (i < m)
    {
        if (pattern[i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == n)
        {
            result.push_back(i - j + 1);
            j = LPS[j - 1];
        }
        else if (pattern[i] != pattern[j])
        {
            if (j != 0)
            {
                j = LPS[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return result;
}
int main()
{
    string text, pattern;

    cin >> text >> pattern;

    return 0;
}
