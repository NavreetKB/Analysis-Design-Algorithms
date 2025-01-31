# Analysis and Design of Algorithms

## Lab - 01      Date: 23-01-2025    
 
### ------------------------- Program - 01 ---------------------------    
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
### ------------------------- Program - 02 ---------------------------    

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
### ------------------------- Program - 03 ---------------------------      

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
 {'education': 3, 'fundamental': 1, 'individual': 1, 'societal': 1, 'advancement': 1, 'empowers': 1, 'individuals': 2, 'knowledge': 1, 'skills': 1, 'critical': 1, 'thinking': 1, 'necessary': 1, 'thrive': 1, 'ever-changing': 1, 'world': 1, 'unlock': 1, 'full': 1, 'potential': 1, 'pursue': 1, 'aspirations': 1, 'become': 1, 'active': 1, 'engaged': 1, 'members': 1, 'society': 2, 'ensuring': 1, 'equitable': 3, 'access': 1, 'quality': 1, 'paramount': 1, 'breaking': 1, 'barriers': 1, 'opportunity': 1, 'fostering': 2, 'social': 1, 'mobility': 1, 'building': 1, 'worldd': 1}  
 
Grand dictionary:  
 {'education': 9, 'individual': 1, 'societal': 1, 'empowers': 1, 'individuals': 4, 'knowledge': 1, 'skills': 1, 'critical': 1, 'thinking': 1, 'world': 1, 'unlock': 1, 'potential': 1, 'pursue': 1, 'society': 4, 'access': 1, 'quality': 1, 'breaking': 1, 'social': 1, 'mobility': 1, 'fostering': 2, 'equitable': 3}  
 
modA = 7.0  
modB = 7.937253933193772  
A.B=  38  
consine =  0.6839357130643159  
## Lab - 02      Date: 30-01-2025    
 
### ------------------------- Program - 01 ---------------------------    
AIM:To analyse and plot a graph for Time Complexity of magic square algorithm.  
WORKING:  
1. Import C libraries like ctime, chrono,cmath,etc.
2. In the algoritm of magic square there is a 'for' loop that runs n^2 times, hence it is evident that the time complexity of the program is O(n^2).
3. To obtain data points we start with a value of sqaure size and start the timer.
4. We call the magic square function 100 times and then stop the timer.
5. We get the average duration by (end-start)/100
    ```
          auto duration = duration_cast<nanoseconds>(end - start);
          double avg = static_cast<long double>(duration.count())/100;
      
7. Store each size and corresponding time in arrays.
8. Repeat steps 3 to 6 in a loop, increasing the size in each iteration.
9. Get the arrays of size and array of corresponding times.
10. Using these sizes and times arrays plot the graph using matplotlib.

OUTPUT :  
size of square : 3  time taken 0  
size of square : 9  time taken 0      
size of square : 27  time taken 11630  
size of square : 81  time taken 142490  
size of square : 243  time taken 757750  
size of square : 729  time taken 1.03548e+007  

Time Complexity : O(n^2)    
Space Complexity: O(n^2)  

GRAPH:  
![magicsqare](https://github.com/user-attachments/assets/f6ed0571-abf0-4da7-a6c3-f733731a891a)


### ------------------------- Program - 02 ---------------------------    
AIM : To analyse the time complexity of Insertion sort (best, average and worst case)    
WORKING:    
1. Insertion sort algorithm works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list.
2. We start with second element of the array as first element in the array is assumed to be sorted.  
3. Compare second element with the first element and check if the second element is smaller then swap them.  
4. Move to the third element and compare it with the first two elements and put at its correct position.  
5. Repeat until the entire array is sorted.
6. To measure time we have an initailising function which initialises an array of given size with random numbers.
7. Start the timer and call the inerstion sort function 10 times in loop.
8. stop the timer and get the average time by (end-start)/10.
9. Repeat the same process in a loop and in each iteration multiply the size by 10.
10. Get the values of sizes and corresponding times in arrays.
11. Using matplotlib, plot the graph of array size vs time taken.
12. Best case: O(n), If the list is already sorted, where n is the number of elements in the list.    
13. Average case: O(n2), If the list is randomly ordered    
14. Worst case: O(n2), If the list is in reverse order    

OUTPUT:  
(average case):
size : 7  time :0  
size : 35  time :0  
size : 175  time :0  
size : 875  time :52400  
size : 4375  time :2.5276e+006  
size : 21875  time :6.973e+007  
size : 109375  time :1.73914e+009  
GRAPH (Average Case):  
![InsertionSort](https://github.com/user-attachments/assets/cbbae104-7291-4fa8-b819-edb3cf644513)

(best case):    
![bestIS](https://github.com/user-attachments/assets/b3fd51d1-22a5-4ae7-a1f2-5e61d0a9c148)

### ------------------------- Program - 03 ---------------------------      
AIM : To analyse the time complexity of Quick sort (best and average/worst case).  
WORKING:  
1. QuickSort is a sorting algorithm based on the Divide and Conquer that picks an element as a pivot and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array.  
2. The first element is chosen as pivot here and all elements smaller than pivot are moved to its left and greater ones to the right.  
3. Recursively apply the same process to the two partitioned sub-arrays (left and right of the pivot).  
4. The recursion stops when there is only one element left in the sub-array, as a single element is already sorted.
5. To measure time we have an initailising function which initialises an array of given size with random numbers.
6. Start the timer and call the inerstion sort function 10 times in loop.  
7. stop the timer and get the average time by (end-start)/10.  
8. Repeat the same process in a loop and in each iteration multiply the size by 10.  
9. Get the values of sizes and corresponding times in arrays.  
10. Using matplotlib, plot the graph of array size vs time taken.  
Best Case: O(n log n), Occurs when the pivot element divides the array into two equal halves.  
Average Case (O(n log n)), On average, the pivot divides the array into two parts, but not necessarily equal.  
Worst Case: (O(n²)), Occurs when the smallest or largest element is always chosen as the pivot (e.g., sorted arrays).   

OUTPUT:  
(average case)  
size : 5  time :164  
size : 25  time :726  
size : 125  time :8385  
size : 625  time :155490   
size : 3125  time :3.36806e+06  
size : 15625  time :8.82135e+07        
![QuikAVG](https://github.com/user-attachments/assets/875950bc-30a0-4b5d-98d8-82b187f263ab)


(worst case)    
size : 5  time :143  
size : 25  time :937  
size : 125  time :12473   
size : 625  time :244608  
size : 3125  time :5.82058e+06  
size : 15625  time :1.61703e+08     
![QuickWC](https://github.com/user-attachments/assets/cc44b29c-5c20-401c-83a1-f909b2a243da)  

### ------------------------- Program - 04 ---------------------------     
AIM : To analyse and plot graph of time complexity of MergeSort algorithm.  
WORKING:  
1.  It works by recursively dividing the input array into smaller subarrays and sorting those subarrays then merging them back together to obtain the sorted array.
2.  Divide the list or array recursively into two halves until it can no more be divided.
3.  Each subarray is sorted individually using the merge sort algorithm.
4.  The sorted subarrays are merged back together in sorted order. The process continues until all elements from both subarrays have been merged.
5.  To measure time we have an initailising function which initialises an array of given size with random numbers.
6. Start the timer and call the inerstion sort function 10 times in loop.
7. stop the timer and get the average time by (end-start)/10.
8. Repeat the same process in a loop and in each iteration multiply the size by 10.
9. Get the values of sizes and corresponding times in arrays.
10. Using matplotlib, plot the graph of array size vs time taken.
Time Complexity : O(n log n)

OUTPUT:  
size : 5  time :0.3  
size : 25  time :3.1  
size : 125  time :14.7  
size : 625  time :82.7  
size : 3125  time :454.1   
size : 15625  time :2557.8  
size : 78125  time :14650.8  
Graph:  
![MergeSort](https://github.com/user-attachments/assets/d67dcb41-6f54-4ca0-a66c-c95b6b36f202)


### ------------------------- Program - 05 ---------------------------   
AIM : To analyse and plot graph of time complexity of HeapSort algorithm.  
WORKING:    
1. Heap sort is a comparison-based sorting technique based on Binary Heap Data Structure.
2. we first find the max (or min) element and swap it with the last (or first). We repeat the same process for the remaining elements.
3. Rearrange array elements so that they form a Max Heap.
4. Repeat the following steps until the heap contains only one element:
5. Swap the root element of the heap (which is the largest element in current heap) with the last element of the heap.
6. Remove the last element of the heap (which is now in the correct position). We mainly reduce heap size and do not remove element from the actual array.
7. Heapify the remaining elements of the heap.Finally we get sorted array.
8. The time is measured for increasing sizes of array in loop.
9. Graph is plotted using matplotlib. 

Time Complexity : O(n log n)  

OUTPUT:   
size : 10  time :1  
size : 70  time :6  
size : 490  time :90  
size : 3430  time :713  
size : 24010  time :5754  
size : 168070  time :150720    
size : 1176490  time :1.0916e+06  
  

Graph:    
![Heapsort](https://github.com/user-attachments/assets/96c1bcd8-fa0a-4152-8b0d-d453835a720f)









