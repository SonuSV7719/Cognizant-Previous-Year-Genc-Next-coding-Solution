# Cognizant Previous Year Genc-Next Coding Problem Solutions

### Q1 . 

```
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

```


### Q2. 

```
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

```

### Q3.

```
  Problem Statement-  A taxi can take multiple passengers to the railway station at the same time.On the way back to the starting point,the taxi driver may pick up additional passengers for his next trip to the airport.A map of passenger location has been created,represented as a square matrix.
  
  The Matrix is filled with cells,and each cell will have an initial value as follows:
  
  A value greater than or equal to zero represents a path.
  A value equal to 1 represents a passenger.
  A value equal to -1 represents an obstruction.
  The rules of motion of taxi are as follows:
  
  The Taxi driver starts at (0,0) and the railway station is at (n-1,n-1).Movement towards the railway station is right or down,through valid path cells.
  After reaching (n-1,n-1) the taxi driver travels back to (0,0) by travelling left or up through valid path cells.
  When passing through a path cell containing a passenger,the passenger is picked up.once the rider is picked up the cell becomes an empty path cell. 
  If there is no valid path between (0,0) and (n-1,n-1),then no passenger can be picked.
  The goal is to collect as many passengers as possible so that the driver can maximize his earnings.
   
  
  Sample Input 0
  
  4  
  
  4 
  
  0 0 0 1
  
  1 0 0 0
  
  0 0 0 0
  
  0 0 0 0
  
  Sample Output 0
  
  2
  
  Explanation 0
  
  The driver can contain a maximum of 2 passengers by taking the following path (0,0) → (0,1) → (0,2) → (0,3) → (1,3) → (2,3) → (3,3) → (3,2) → (3,1) → (3,0) → (2,0) → (1,0)  → (0,0)
  
   
  
   
  
  Sample Input 1
  
     3   
  
     3    
  
     0 1 -1 
  
     1 0 -1
  
     1 1 1
  
  Sample Output 1
  
  5
  
  Explanation 1
  
  The driver can contain a maximum of 5 passengers by taking the following path (0,0) → (0,1) → (1,1) → (2,1) → (2,2) → (2,1) → (2,0) → (1,0) → (0,0)
```
