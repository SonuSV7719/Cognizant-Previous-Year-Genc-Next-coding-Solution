/*
    Problem statement-: Elliot made a KeyLogger for his friend Romero,
    so that he can see the passwords of his friend. Keylogger is a software
    that can tell you the buttons pressed in the keyboard without the
    consent of the user, and hence unethical. Elliot made it to hack Romero’s
    passwords. The one problem is, Romero writes the passwords in lowercase
    characters only, and the keylogger only takes the values of the keys.
    Like, for a it takes 1, for b 2, and for z 26. For a given number Elliot
    produces all combinations of passwords in a dictionary and starts a
    dictionary-based password attack. For a given number, print all the
    possible passwords in lexicographic order.

    Input Format:

    One line, denoting the value given by the keylogger

    Output Format:

    All possible combinations of keyloggers in new lines are lexicographically ordered.

    Constraints:

    2 <= Number of digits in input <= 1000

    Sample Input:

    1234

    Sample Output:

    abcd

    awd

    lcd

    Explanation:

    For 12, you can take 1,2 that is ab, or you can take l.
*/





#include <bits/stdc++.h>

using namespace std;

void find_combinations(string a, int i, string res, vector<string>& list){
    if (i == a.size()){
        list.push_back(res);
        return;
    }

    if (a[i] == '0') return;
    if (i > a.length()) return;

    char ch = static_cast<char>('a' + (a[i] - '1'));

    find_combinations(a, i + 1, res + ch, list);


    if (i != a.size() - 1 && a[i] < '3' && a[i + 1] < '7'){
        string pair = string(1, a[i]) + a[i + 1];
        char pairCh = static_cast<char>('a' + stoi(pair) - 1);

        find_combinations(a, i + 2, res + pairCh, list);

    }


    
}

int main(){
    string a;
    cin >> a;

    vector<string> ans;
    find_combinations(a, 0, "", ans);
    sort(ans.begin(), ans.end());

    for(auto i : ans){
        cout << i << endl;
    }
    return 0;
}
