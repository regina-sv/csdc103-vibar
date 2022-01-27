// Filename : lab2.cpp
//
// Description : This source code defines and tests the following recursive functions: 
//  1) count_vowels(string s) - counts the vowel letters from a given string s formed by the letters
//      of the English alphabet, returns the total number of vowels in s (regardless of the letter
//      being an uppercase or lowercase).
//
//  2) binary_to_decimal(int b) - converts binary from given integer b composed of zeros and ones,
//      returns the number whose binary representation is precisely the sequence of zeros and ones in b.
//
//  3) search(A, n, x) - searches for the first occurrence of element x in array A containing n elements
//      and returns its position or index if x is in A otr -1 otherwise.
//      
//  4) search_sorted(A, n, x) - searches for the first occurrence of element x in a sorted array A containing
//       n elements, returns the index or position number of any occurrence of x if x is in A or -1 otherwise.    
//
//
// Author : Regina Juliane Vibar
// rvibar@gbox.adnu.edu.ph
//
// Honor Code : I have not received nor given any unauthorized help
// in completing this exercise.

/*
    Recurrence & Decomposition: 

        (1) count_vowels(string s)
                = 0 if s is empty 
                = count_vowels(s-1) + 1 if first letter is a vowel letter
                = count_vowels(s-1) if first letter is now a vowel letter

            For count_vowels(string s) we have a base case when string s is empty.
            If there's nothing in a string, we do not need to search for anything.
            The decomposition approach is to decrease s by a single unit.

                    +---+      +------------------------------+   
            C =     |   |   +  |                              |
                    +---+      +------------------------------+                 

            By removing the first letter from the string, we split it into two 
                    1) The first letter from the string
                    2) The second letter from the string to the last letter

            Hence, we can derive a recursive case as follows:

                To count the vowel letters for any string s, we have to check if the string has a value.
                So, we return 0 if the string is empty (since there is nothing to check) or 
                there are no vowel letters in the string.
                If the string has a value, we check if the first letter is a vowel.
                If so, we add one, and we proceed to the next letter to check if it is a vowel.
                Adding one to each recursive call will be the counter of the vowels.
                If the first letter of the string is not a vowel, we remove it to get a smaller input size
                where the new first letter is the next letter from the given string. 

        (2) binary_to_decimal(int b)
                = 0 if b is empty
                = (binary_to_decimal(b/10) * 2) + b % 10 if b != 0

            For binary_to_string(int b) we have a base case when b is empty.
            If b is empty we do not need to convert anything.

            The decomposition approach is to decrease b by a single unit.

                    +----------------------------------+        +---+
            B =     |                                  |   +    |   |
                    +----------------------------------+        +---+
            B =                 B(b/10)                    +     b%10

            That is, we split b into two: 
                    1) The integer containing the first b-1 digits. (b//10)
                    2) The last element of b. (b%10)  

            Hence, we can derive a recursive case as follows:

                To convert the given binary to decimal, we have to check first if the 
                input has a value. If b has a value, we use the doubling method to convert the 
                binary to decimal. As we divide b by 10, we will go down to the most significant 
                bit of the given sequence of zeroes and ones. 
                Once we get to the most significant bit, we multiply that value by two 
                and add the next bit which was retrieved by b%10.
                The recursive call would be B(b/10) * 2) + b % 10, which returns the number whose binary 
                representation is precisely the sequence of zeros and ones in b if b has a value or 0 otherwise.

        (3) search(A[], n, x)
                = -1 if n < 0
                = 0 if A[0] = x
                = -1 if search(A+1, n-1,x) = -1
                = search(A+1, n-1, x) + 1 if search(A+1, n-1, x) != 0

            For search(A, n, x) we have a base case when the position of x is at index 0.
            The decomposition approach is to decrease n by one and leave out the first 
            element on array A.

                    +---+       +--------------------------------+ 
            A =     |   |   +   |                                |
                    +---+       +--------------------------------+ 
            A =     A[0]    +                  A[1:n]      

            That is, we split A into two: 
                    1) The first element in array A. (A[0])
                    2) The second up to the last element. (A[1:n])

            Hence, we can derive a recursive case as follows:

                For any array A containing n > 0 elements.
                Since we are after the first occcurrence of x, we check first if
                the first element A[0] is x. 
                If if so, then x is at positon A[0].
                If not, then we search for the first occurrence of x in array A.
                Through the recursive call search(A + 1, n - 1, x) + 1, we can get the
                index of the first occcurrence of x in A if it is in A or -1 otherwise.

        (4) search_sorted(A, n, x)
                = -1 if n = 0
                = n-1 if A[n - 1] = x
                = search_sorted(A, n - 1, x) if x > A[mid_index]
                                            mid_index is the index of the half or the middle of array A
                = search_sorted(A, mid_index, x) if x < A[mid_index]
                = mid_index if x is not in the upper or lower half of the array

            For search_sorted(A, n, x) we have a base case when A is empty.
            The decomposition approach is to roughly split A in half.

                    +-----------------+        +-----------------+
            A =     |                 :    +   :                 |
                    +-----------------+        +-----------------+
            A =          A[0:n/2]          +         A[n/2:n]
            
*/

#include <iostream>

using namespace std; 


bool is_vowel(char c) { // Funtion to check if a letter is a vowel for count_vowels
	return (c == 'a' || c == 'e' || c == 'i'|| c == 'o'|| c == 'u' ||
			c == 'A' || c == 'E' || c == 'I'|| c == 'O'|| c == 'U'); 
} 


// Recursive Functions: 

int count_vowels(string s) {
    if (s == "") { // Base Case (If the string is empty, there is nothing to check )
        return 0; // If there are no vowel letters found in the string
    } else {
        if (is_vowel(s.front())) { // Check if the first letter from the string is a vowel
            return count_vowels(s.erase(0,1)) + 1; // If vowel is found, we add one, and remove the first letter 
        } else {                                    // We now have a smaller input where first letter from the word is removed 
            return count_vowels(s.erase(0,1));  // The new first letter is the next letter from the given string
        }                                       // If the first letter is not a vowel we won't add one
    }
}


int binary_to_decimal(int b) {
    if (b == 0) { // Base Case
        return 0; // If integer b is empty and there are no more bits to check 
    } else {
        // The recursive call will keep on dividing b by 10 until it gets to 0
        // Then it will multiply by two and add the next bit from the given integer
        // that value will be the next to be multiplied by two where we add the next bit
        return (binary_to_decimal(b/10) * 2) + b % 10; // returns the decimal equivalent of b
    }
}

int search(int A[], int n, int x) {

    if (n < 0) {        // Base Case (n < 0, we don't need to find anything in the array because the position starts from 0)
        return -1;      // or the element is not in the array
    }

    if (A[0] == x) {    // Base Case (First element in array is left out) 
        return 0;       // If the value of element at A[0] is equal to the value of x, then x is at position 0
    } else {
        // Recursive call to search for x among the first n-1 elements in A
        int sub = search(A + 1, n - 1, x); // If x is not in index 0, we get the value of the recursive call that gives the index of the first occcurrence of x
        if (sub == -1) {      
            return - 1; // The recursive call did not find x in the array so we return -1
        } else { // Otherwise, if the recursive call found the element, we return the position or index of x.
            return sub + 1; // We add one to the search recursive call to match the indexing of the original problem 
        }
    }

}

int search_sorted(int A[], int n, int x)  {

    if (n == 0) {  // Base Case
        return -1; // The element x is not in the array
    }             

	if (A[n - 1] == x) { // Base Case
		return n - 1; // If the last element of A is x, then the position of x is at n-1
	}
	
	int mid_index = ((n - 1)/ 2); // The "index" of the half or the middle of the array

    // Since the array is sorted, we check if the value of element x is bigger or smaller than the 
    // value of the element at the position of the middle index (mid_index).
    // Then search for the position of x using recursive calls.

    if (x > A[mid_index]) {  // If the value of x is greater than the value of the element at position middle_index
        return search_sorted(A, n - 1, x); // Then, we search for x from the first n-1 elements of A to get its position
    } else if (x < A[mid_index]) { // If the value of x is less than the value of the element at position middle_index
        return search_sorted(A, mid_index, x); // Then, we search for x from the middle or half of the array to get its position
    } else {
        return mid_index; // If x is not in the upper or lower half of the array, then it is in the middle.
    }
}

int main () {
    // Some list:

    int A[] = {90, 38, 1001, 87, 90};
    int B[] = {111, 90, 1301, 137, 90};
    int C[] = {35, 98, 99, 101, 777, 137};
    int D[] = {22, 34, 189, 199};
    int E[] = {};
    
    // Function calls: 

    cout << "count_vowels(s) sample cases: " << endl;
    cout << count_vowels("BanAnaApplE") << endl; // Prints "5" 
    cout << count_vowels("AntholOgy") << endl; // Prints "3" 
    cout << count_vowels("AAAaaaEEEeeeIIIiiiOOOoooUUUAeIoU") << endl; // Prints "32" 
    cout << count_vowels("gypsySky") << endl; // Prints "0" 
    cout << count_vowels(" ") << endl; // Prints "0" 

    cout << endl << "binary_to_decimal(b) sample cases: " << endl;
    cout << binary_to_decimal(10110) << endl; // Prints "22"
    cout << binary_to_decimal(0) << endl; // Prints "0"
    cout << binary_to_decimal(101100) << endl; // Prints "44"
    cout << binary_to_decimal(1) << endl; // Prints "1"
    cout << binary_to_decimal(111000111) << endl; // Prints "455"

    cout << endl << "search(int A, n, x) sample cases: " << endl;
    cout << search(A, 5, 90) << endl; // Prints "0"
    cout << search(B, 5, 90) << endl; // Prints "1"
    cout << search(C, 6, 137) << endl; // Prints "5"
    cout << search(E, 0, 10) << endl; // Prints "2"
    cout << search(A, 3, 1002) << endl; // Prints "-1

    cout << endl << "search_sorted(A, n, x) sample cases: " << endl;
    cout << search_sorted(C, 6, 777) << endl; // Prints "4"
    cout << search_sorted(C, 6, 101) << endl; // Prints "3"
    cout << search_sorted(C, 3, 35) << endl; // Prints "0"
    cout << search_sorted(D, 4, 101) << endl; // Prints "-1" 
    cout << search_sorted(E, 0, 1) << endl; // Prints "2"   

    return 0;
}