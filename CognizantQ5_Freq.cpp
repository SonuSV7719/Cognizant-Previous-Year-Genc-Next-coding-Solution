/*

    Problem Statement – Codu is given a string and he thinks the letters that are repeated do have more power. He gathers only the repeating characters and keeps them as the most powerful to least powerful manner. Now it is your turn to write a code that will help Codu to do that.

    Note that: only lowercase alphabets are accepted in input.



    Input Format:

    A string in a single line


    Output Format:

    A string made of only the repeated characters as sorted their frequency reducin, if the same the lower ascii value comes before.


    Constraints:

    Length of string<=10^5


    Sample Input:

    abcdefghaabca



    Sample Output:

    abc

*/

#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<char, int> &a, pair<char, int> &b)
{
    return (a.second > b.second) || (a.second == b.second && a.first < b.first);
}

string maxFreqStr(string &str)
{
    unordered_map<char, int> m;

    for (int i = 0; i < str.size(); i++)
    {
        m[str[i]]++;
    }

    vector<pair<char, int>> freqVector(m.begin(), m.end());

    sort(freqVector.begin(), freqVector.end(), cmp);


    string result;
    for (const auto &p : freqVector)
    {
        if (p.second > 1)
        {
            result += p.first;
        }
    }

    return result;
}

int main()
{
    string str;
    cin >> str;

    cout << maxFreqStr(str);

    return 0;
}
