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
AIM: To analyse the time complexity of SELECTION SORT algorithm.  
WORKING:  
1. The array size and array elements are taken as user input.
2. The outer loop (i) iterates from the first index to the last index of the array.
3. For each iteration, the variable min is initialized to the current index i.
4. The inner loop (j) runs from i + 1 to the last index of the array, searching for the smallest element.
5. If a smaller element is found (arr[j] < arr[min]), the index min is updated.
6. After the inner loop, the smallest element found is swapped with the element at index i.
7. This process continues until the entire array is sorted.
8. To measure time we have an initailising function which initialises an array of given size with random numbers.
9. Start the timer and call the inerstion sort function 10 times in loop.
10. stop the timer and get the average time by (end-start)/10.
11. Repeat the same process in a loop and in each iteration multiply the size by 10.
12. Get the values of sizes and corresponding times in arrays.Using matplotlib, plot the graph of array size vs time taken.

 OUTPUT :  
size : 10  time :0  
size : 50  time :0  
size : 250  time :0  
size : 1250  time :2702.2  
size : 6250  time :59889.9  
size : 31250  time :1.29409e+006  

Time Complexity : O(n^2)  
Graph :  
![Selectionsort](https://github.com/user-attachments/assets/4b6121bd-d733-4a68-a408-14aea59e505f)


### ------------------------- Program - 03 --------------------------- 
AIM: To analyse the time complexity of BUBBLE SORT algorithm.  
WORKING:    
1. The array size is taken as user input.
2. An integer pointer arr is dynamically allocated to store the elements of the array.  
3. The user is prompted to enter the elements of the array.    
4. The outer loop (i) starts from the last index of the array down to 0.  
5. The inner loop (j) iterates from the first element to the index i-1.  
6. In the inner loop, if the current element (arr[j]) is greater than the next element (arr[j+1]), the two numbers are swapped.  
7. This process continues until the outer loop completes, ensuring that the largest unsorted element moves to its correct position at the end of the array.
8. To measure time we have an initailising function which initialises an array of given size with random numbers.
9. Start the timer and call the inerstion sort function 10 times in loop.
10. stop the timer and get the average time by (end-start)/10.
11. Repeat the same process in a loop and in each iteration multiply the size by 10.
12. Get the values of sizes and corresponding times in arrays. Using matplotlib, plot the graph of array size vs time taken.

OUTPUT:  
size : 10  time :0.1  
size : 50  time :1.3  
size : 250  time :29.6   
size : 1250  time :615.6  
size : 6250  time :9827.8   
size : 31250  time :323853  

Time Complexity : O(n^2)  
Graph:  
![Bubble](https://github.com/user-attachments/assets/b3b7fd81-4eb5-480c-902a-7a35198b2d4d)




### ------------------------- Program - 04 ---------------------------    
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

### ------------------------- Program - 05 ---------------------------      
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

### ------------------------- Program - 06 ---------------------------     
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


### ------------------------- Program - 07 ---------------------------   
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



## Lab - 03      Date: 06-02-2025    
 
### ------------------------- Program - 01 ---------------------------  
AIM : To solve Knapsack fractional problem using 3 approaches : 
i) sorting by profit in non increasing order.    
ii) sorting by weight in non decreasing order.    
iii) sorting by profit per unit weight in non increasing order.   

Knapsack fractional problem : given a set of items, holding weights and profit values, we have to determine the subset of the items to be added in a knapsack such that, the total weight of the items must not exceed the limit of the knapsack and its total profit value is maximum.

WORKING :  
We make a table for 15 items with 2 rows. First row holds profit values and 2nd row holds the weights.  

A) sorting by profit in non increasing order:  
1. using quicksort algorithm we sort the table(swapping elements in all rows together) as per profits in non increasing order.
2. Then we traverse the table from start, and compare each weight with the available capacity.
3. if the weight is less than available capacity we select it, if it is lesser we add the fraction of it which fulfills the capacity. Once the available capacity is zero we dont add anymore items.
    ```
        if(c<=0  || std::abs(c) < 1e-6){
            result[i]=0;
        }
        else if(arr[1][i]<=c){
           result[i]=1;
           c=c-arr[1][i];
        }
        else if(c!=0){
          float f=c/(arr[1][i]);
          result[i]=f;
          float fractionWt=(arr[1][i])*f;
          c=c-fractionWt;
        }
     ```
4. Once the entire table is traversed we get an array which holds values [0,1] as the ouput. 0 means item not selected, 1 means item taken with entire quantity and a fractional value indicating fractional quantity.


B)sorting by weight in non decreasing order.   
1. using quicksort algorithm we sort the table as per weights in non decreasing order.
2. Then we traverse the table from start, and compare each weight with the available capacity.
3. if the weight is less than available capacity we select it, if it is lesser we add the fraction of it which fulfills the capacity. Once the available capacity is zero we dont add anymore items.   
4. Once the entire table is traversed we get an array which holds values [0,1] as the ouput. 0 means item not selected, 1 means item taken with entire quantity and a fractional value indicating fractional quantity.


C)sorting by profit per unit weight in non increasing order. 
1. Make a table with 3 rows : 1st for profits, 2nd for weights and 3rd for ratio of profit/weight.
2. sort the table using quicksort (swapping elements in all rows together) as per the fraction profit/weight.
3. Then we traverse the table from start, and compare each weight with the available capacity.
4. if the weight is less than available capacity we select it, if it is lesser we add the fraction of it which fulfills the capacity. Once the available capacity is zero we dont add anymore items.   
5. Once the entire table is traversed we get an array which holds values [0,1] as the ouput. 0 means item not selected, 1 means item taken with entire quantity and a fractional value indicating fractional quantity.

OUTPUT :  
```
                     **************** Sorted by profit ******************
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
PROFIT |  79   |  68   |  67   |  62   |  59   |  49   |  48   |  40   |  35   |  24   |  24   |  22   |  22   |  10   |   2   |
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
WEIGHT |  43   |  55   |  46   |  18   |   8   |   1   |  62   |  21   |  67   |  15   |  38   |  55   |   1   |  42   |  43   |
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
RESULT |   1   |   1   |0.043  |   0   |   0   |   0   |   0   |   0   |   0   |   0   |   0   |   0   |   0   |   0   |   0   |
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+

                           **************** Sorted by Weight ******************
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
PROFIT |  22   |  49   |  59   |  24   |  62   |  40   |  24   |  10   |   2   |  79   |  67   |  22   |  68   |  48   |  35   |
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
WEIGHT |   1   |   1   |   8   |  15   |  18   |  21   |  38   |  42   |  43   |  43   |  46   |  55   |  55   |  62   |  67   |
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
RESULT |   1   |   1   |   1   |   1   |   1   |   1   |0.95   |   0   |   0   |   0   |   0   |   0   |   0   |   0   |   0   |
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
                                  **************** Sorted by Profit per unit Weight ***************
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
PROFIT |  49   |  22   |  59   |  62   |  68   |  24   |  67   |  79   |  40   |  48   |   2   |  10   |  24   |  22   |  35   |
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
WEIGHT |   1   |   1   |   8   |  18   |  55   |  15   |  46   |  43   |  21   |  62   |  43   |  42   |  38   |  55   |  67   |
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
P/W    |  49   |  22   | 7.4   | 3.4   | 1.2   | 1.6   | 1.5   | 1.8   | 1.9   |0.77   |0.047   |0.24   |0.63   | 0.4   |0.52  |
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
RESULT |   1   |   1   |   1   |   1   |   1   |   1   |0.043  |   0   |   0   |   0   |   0   |   0   |   0   |   0   |   0   |
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 ```
Capacity = 100     Profit generated  
By Profit          149.88  
By Weight          278.80  
By Profit/weight   286.88   (maximum profit)    
  
Ouput for 10 different sets of inputs  
| S.no. | By Profit | By Weight | By Profit/weight |
|-------|-----------|-----------|------------------|
| 1     |111.77     | 177.12    |  203.18          |
| 2     |235.42     | 211.67    |  257             |
| 3     | 112       | 105       |  148.98          |
| 4     | 184.34    | 198.2     |  190.5           |
| 5     | 149.88    | 278.80    |  286.88          |
| 6     | 173.65    | 138.85    |  175.00          |
| 7     | 62.97     | 176.96    |  210.58          |
| 8     | 198.2     | 190.15    |  286.88          |
| 9     | 173.00    | 138.00    |  175             |
| 10    | 171.78    | 244.14    |  279.19          |

### ---------------------  PROGRAM - 2 ---------------------
AIM - To visualise the time complexity of binary search function by plotting a graph  
WORKING -   
1. Write a function for initialisation of an array of given size.  
   The initialisation is done as per the values of i to ensure that the array is sorted.
   ```
   for( i=0 to size )
    {arr[i]=i;}
3. Write a function to perform Linear search on given array.
4. Take the initial value of the size of array.
5. Now for 7 iterations(or any number of iterations) make an array of the current size, start the timer, for 100 times call the
   initialisation  function, call linear search function with this array. After 100 iterations get the end time.
   ```
   size=100;
   for( int i: 0 to 7)
   {
     store this size in an array
    initialse(array,size);
     start the timer
     for(int j : 0 to 100)
      {
        binarysearch(array, element)
      }
      end timer;
      avg = end-start/100;
      store avg time in an array
      size=size*7;
   }
   ```
6. Get the average time duration for one search (end-start)/100.  
7. Store this size and duration in respective arrays.  
8. After each iteration increase the array size by 10 times.  
9. Store this data of array sizes and duration in a csv file.  
10. Read this file in a pyhton program that uses pandas and matpotlib.pyplot and plot a graph .  
11. Use numpy to get a graph of log as well.  
12. The best case complexity corresponds to the search element arr[mid] and the worst case complexity is when search element is
 arr[size];

  
OUTPUT-  
size of array=  50   average time is 36.7  
size of array=  500   average time is 47.8    
size of array=  5000   average time is 62.1    
size of array=  50000   average time is 85.7    
size of array=  500000  average time is 104.2    
size of array=  5000000   average time is 144.1    
size of array=  50000000   average time is 153.2    
  
size, Time  
50 , 36.7    
500 , 47.8    
5000 , 62.1    
50000 , 85.7     
500000 , 104.2     
5000000 , 144.1    
50000000 , 153.2     
![image](https://github.com/user-attachments/assets/7d77abdd-e6e7-4d11-8733-72c96a8904b6)


## Lab - 04      Date: 13-02-2025    
 
### ------------------------- Program - 01 ---------------------------
AIM : to perform matrix multiplication using divide and conquer approach.  
WORKING:  
1. Take the dimension of matrices as input from user.
2. The initialise function initialises the matrices of given size with random values.
3. The matrix function takes the 2 input matrices, the output matrix and 8 arguments corresponding to the starting row index, ending row index, starting column index, ending column index of both matrices.
4. DIVISION : we find out the midrow and mid column indices for both matrices and divide 1 matrix into 4 submatrices of size n/2 by n/2.
5. The base case of recursion is when the matrix is of 2 by 2 size. The multiply function is called then. Which multiplies the 2*2 submatirces of both M1 and M2.
    ```
      for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                mat3[startrow1+i][startcol2+j]+=((mat1[startrow1+i][startcol1+k])*(mat2[startrow2+k][startcol2+j]));
            }
        }
    }

6. If a matrix is divided into 4 parts each of size 2 by 2 then we (multiply topleft matrices of both) + (top right of M1*bottom left of M2) gives us the top left matix of final matrix.
8. The recursive calls are made 8 times ( since we have 4 equations with 2 arguments for addition each).
9. The final matrix is displayed as result.

OUTPUT : 
enter number of rows and columns of matrix1 8 8
enter number of rows and columns of matrix2 8 8
```
elements of matrix1
2   8   15  1   10  5   19  19  
3   5   6   6   2   8   2   12  
16  3   8   17  12  5   3   14  
13  3   2   17  19  16  8   7  
12  19  10  13  8   20  16  15  
4   12  3   14  14  5   2   12  
14  9   8   5   3   18  18  20  
4   2   10  19  17  16  11  3  

elements of matrix2

9   7   1   3   5   9  7   6  
11  10  11  11  7   2  14  9  
10  4   5   15  17  1  7   17  
12  9   5   20  7   4  18  19  
19  3   10  2   14  16 20  19  
5   11  18  7   14  7  2   6  
5   13  11  10  18  14 18  13   
7   11  2   17  16  8  16  15  
Resutant matrix
711   704   607  907   1184  666  1105  1110  
386   401   328  558   562   279  525   571  
827   611   445  868   872   607  1044  1089  
904   696   721  791   985   777  1121  1128  
1010  1048  982  1226  1374  820  1382  1365
751   541   497  756   747   502  987   951
742   926   770  1013  1242  758  1110  1095  
865   662   756  871   1045  688  1086  1180
```
Time Complexity= O(n^3)
Space Complexity =O(n)

GRAPH:   

![matrix](https://github.com/user-attachments/assets/66b7539a-3f2b-4fa8-ab80-a7e60704171a)











