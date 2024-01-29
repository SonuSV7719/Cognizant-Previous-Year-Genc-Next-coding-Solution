/*
	Problem Statement- Ramesh went to a bookshop to buy books. There is a list of books with their value and price. Now Ramesh has limited money but he wants maximum value possible. Now there are 2 kinds of books, one is denoted with 1, that is independent, another one is denoted as 2, which you have to buy in double, that means you can not buy a single or odd number of those books. 

	Print the maximum value Ramesh can extract from the books. 

	 

	Input Format:

	First line contains two integers, n (Number of books) and T, total money he has.
	Then n lines, 4 variables in each line, 
	The serial number of the book
	The value of the book
	The price of the book
	The marking (1 or 2)
	 

	Output Format:

	Maximum value possible to be bought.
	 

	Constraints:

	Number of books: <=100
	Maximum Money with Ramesh <=1000
	Max price of a book<=1000
	 

	Sample Input:

	5 20

	1 3 7 0

	3 9 10 1

	2 4 3 1

	7 3 2 0

	22 7 7 0

	Sample Output:

	20

	 

	Explanation:

	It will be the 1st book,2nd and the third book



*/



#include<bits/stdc++.h>

using namespace std;

bool cp(vector<int>& a, vector<int>& b){
    if (a[1] < b[1]) return false;
    if (a[1] == b[1]){
        if (a[2] < b[2]) return false;
        return true;
    }
    return true;
}

int maximizeValue(vector<vector<int>>& book, int money){
    sort(book.begin(), book.end(), cp);
    // for(auto v: book){
    //     cout << v[0] << " "<< v[1] << " "<< v[2] << " "<< v[3] << endl;
    // }

    int maxValue = 0;

    for(auto i : book){
        if (i[1] <= money && maxValue + i[1] <= money){
            maxValue += i[1];
        }
    }
    return maxValue;
}

int main(){

    int n, money;

    cin >> n >> money;

    vector<vector<int>> book;

    for(int i = 0; i < n; i++){
        int srNo;
        int value;
        int price;
        int marking;

        cin >> srNo >> value >> price >> marking;

        book.push_back({srNo, value, price, marking});
    }

    cout << maximizeValue(book, money);

    return 0;
}
