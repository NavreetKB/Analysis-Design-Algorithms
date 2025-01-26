# Analysis and Design of Algorithms

## Lab - 01      Date: 23-01-2025    
 
### -------------------------Program - 01 ---------------------------    
AIM : To find Peak element in a given 1D and 2D array.    
WORKING:    
1D array:    
1.Start    
2.The given array is passed as argument to the findPeak function along with the number of elements.    
3.The function is based on binary search.Initially the start index is at 0 and end index is at n-1.    
4.The mid is calculated and while start<=end check if the mid element is a peak.    
5.Peak is defined as if arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1] then arr[mid] is a peak.    
6.If mid is the peak then return mid.    
7.Else if arr[mid]<arr[mid-1] then check the left part of array , otherwise check the right part of array.      
  
2D array: 
1. In the given 2D array, first find the central column 'j' and find the maximum element within this column.
2. Once the maximum is found check if it is a peak by comparing with elements to the left and right of it.
3. If it is a peak then simply print it.
4. If it is not a peak then either the left or the right element would be greater than it.
5. Check if the left is greater than it then recursively call the same program by column index from start to 'j-1'.
6. Similarly if right is greater than it then recursively call the same program by column index from 'j+1' to end.
7. In this way the matrix keeps dividing into width of n/2 while number of rows remain the same.
8. Now in the new matrix of half the width, again the central column would be found and its maximum element will be checked.
9. Base Case: when indices get out of the array bounds i.e. (start<0 || start>3 || end<0 || end>3)
10. Edge Cases: The cases when the j is 0 (no left element) and j is n-1 (no right element)  

Input:  
{1,2,6,3,8,9,4}
Output :  
Peak at 3    
Input: 
{  
    {1,  2,  3,  100},  
    {4,  5,  6,  7},  
    {8,  9,  10, 11},  
    {12, 13, 14, 15}     
}  
Output:  
maximum element 13  
maximum element 14  
maximum element 100  
Peak element is 100   

Time Complexity: 1D: O(logn)   
                 2D: O(nlogn)  
Space Complexity: 1D: O(n)   
                  2D: O(n^2)  
                  
<br/><br/>
### -------------------------Program - 02 ---------------------------    

AIM: To create a program that creates a magic square as per the size of square given by user (odd sizes only).  
WORKING:  
1. A magic square is a square in which the sum of elements of all rows, columns and diagonals is the same.  
2. Take the size of sqaure as user input.
3. create a 2D array of given size and initialise all cells with -1.
4. Start from the central column and 1st row i.e. arr[0][n/2] = 1.
5. Now the next elements are to placed diagonally upward to the left i.e. at arr[i-1][j-1].
6. If there is no row above then the number should wrap to the bottom row. Similary if the numbers should wrap around left, right and bottom of array.    
     ```
      if(x<0) then x=n-1;
      if(y<0) then y=n-1;
      if(x>=n)then x=0;
      if(y>=n)then y=0;
7. Incase there already exists a number at that position where the next number is to be placed then place is directly below the current number.
8. For a square of n size the numbers should range from 1 to n^2.

OUTPUT:
enter the dimension of square : 5  
  ```
   15  8   1   24  17  
   16  14  7   5   23  
   22  20  13  6   4  
   3   21  19  12  10  
   9   2   25  18  11    
  ```
Time Complexity: O(n^2)    
Space Complexity: O(n^2)  

<br/><br/>
### -------------------------Program - 03 ---------------------------      

AIM : To find the extent of similarity between 2 text documents by using 'Cosine Similarity'.  
WORKING:  
1. Cosine similarity is based on the dot product of 2 vectors. The cosine of an angle is defined as : cos(Ø) = A.B /(|A|*|B|).
2. The greater the overlap (similarity) between vectors the closer is the value of cosine to 1.
3. The 2 test files are read and their contents are stored in contentA and contentB .
4. Using the library nltk the stopwords are removed from the contents of both the files.
5. The punctuations are also removed and a dictionary is made for each file which contains the unique words of each file (in lowercase).
6. When the word is first entered into the dictionary its frequency is set to 1.
7. Then for each repetition of the word the frequency of that word is incremented by 1.
8. This gives us a frequency table of words for each file.
9. A grand dictionary is constructed in which the product of frequencies of same words from both files is stored.
10. To get A.B all the values of grand dictionary are added.
11. To  get |A| we get the sum of squares of all values of A and similarly get |B|.
12. cosine is obtained by the above mentioned fromula.

OUTPUT:  
dictA:  
 {'education': 3, 'cornerstone': 1, 'individual': 1, 'societal': 1, 'progress': 1, 'empowers': 1, 'individuals': 2, 'knowledge': 1, 'skills': 1, 'critical': 1, 'thinking': 1, 'abilities': 1, 'enabling': 1, 'navigate': 1, 'complexities': 1, 'modern': 1, 'world': 1, 'unlock': 1, 'potential': 1, 'pursue': 1, 'dreams': 1, 'contribute': 1, 'meaningfully': 1, 'society': 2, 'access': 1, 'quality': 1, 'crucial': 1, 'breaking': 1, 'cycle': 1, 'poverty': 1, 'promoting': 1, 'social': 1, 'mobility': 1, 'fostering': 1, 'equitable': 1}    
   
dictB:  
 {"here's": 1, 'alternative': 1, 'text': 1, 'slightly': 1, 'different': 1, 'emphasis:': 1, 'education': 3, 'fundamental': 1, 'individual': 1, 'societal': 1, 'advancement': 1, 'empowers': 1, 'individuals': 2, 'knowledge': 1, 'skills': 1, 'critical': 1, 'thinking': 1, 'necessary': 1, 'thrive': 1, 'ever-changing': 1, 'world': 1, 'unlock': 1, 'full': 1, 'potential': 1, 'pursue': 1, 'aspirations': 1, 'become': 1, 'active': 1, 'engaged': 1, 'members': 1, 'society': 2, 'ensuring': 1, 'equitable': 3, 'access': 1, 'quality': 1, 'paramount': 1, 'breaking': 1, 'barriers': 1, 'opportunity': 1, 'fostering': 2, 'social': 1, 'mobility': 1, 'building': 1, 'worldd': 1}  
 
Grand dictionary:  
 {'education': 9, 'individual': 1, 'societal': 1, 'empowers': 1, 'individuals': 4, 'knowledge': 1, 'skills': 1, 'critical': 1, 'thinking': 1, 'world': 1, 'unlock': 1, 'potential': 1, 'pursue': 1, 'society': 4, 'access': 1, 'quality': 1, 'breaking': 1, 'social': 1, 'mobility': 1, 'fostering': 2, 'equitable': 3}  

modA = 7.0  
modB = 8.306623862918075  
A.B=  38  
consine =  0.6535232024656042  













