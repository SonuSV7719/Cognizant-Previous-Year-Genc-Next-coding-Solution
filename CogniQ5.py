"""
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

"""


givenInput = input()

charFreq = {}

for i in givenInput:
    if i not in charFreq:
        charFreq[i] = 1
    else:
        charFreq[i] += 1 
    
sorted(charFreq.items(), key=lambda x: (x[1], x[0]), reverse=True)

ans = ""

for i in charFreq:
    if charFreq[i] > 1:
        ans += i
        
print(ans)
