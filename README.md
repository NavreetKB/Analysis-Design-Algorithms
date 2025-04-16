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

 ![Screenshot 2025-04-02 225931](https://github.com/user-attachments/assets/1a3cb391-f710-498b-ac05-85fa8005b449)

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

<br><br><br>
### ------------------------- Program - 02 ---------------------------
AIM : To find if a point is in interior of a triangle or not.  
WORKING:  
1. Take three points' coordinates as input from the user.
2. The determinant function calculates the determinant of a 3 by 3 matrix. The first column correspinds to 1st point and second column has coordinates of 2nd point (clockwise manner).
3. if the point lies to the left of a line then the determinant returns a positive value else a negative value.
4. We check the point with each line of triangle and if it lies to the right of each line in taken clockwise manner then the point lies in interior of the triangle.

OUTPUT:  
*************** Triangle ABC *****************  
enter the coordinates of A -3 -5  
enter the coordinates of B 5 9  
enter the coordinates of C 15 5   
enter the coordinates of D 2 2  
Point D is an interior point of triangle ABC  

*************** Triangle ABC *****************  
enter the coordinates of A 1 1  
enter the coordinates of B 4 5  
enter the coordinates of C 8 1  
enter the coordinates of D -3 2  
Point D is an exterior point of triangle ABC  

![Screenshot 2025-02-21 220256](https://github.com/user-attachments/assets/5a0d0ee0-eaad-44c2-82f8-96e6220dc544)


Time complexity : O(n^3) since n is fixed= 3, therefore O(1)  
space complexity : O(1)

<br><br><br>

### ------------------------- Program - 03 ---------------------------
AIM : to implement iterative quicksort.  
WORKING:  
1. QuickSort is a sorting algorithm that follows the divide-and-conquer approach. Unlike the recursive version, the iterative version uses a stack to manage subarrays.
2. Choose a pivot element, usually the first element of the subarray.
3. Partition the array according to the pivot element.  
4. The smaller array is processed first and the starting and ending points of larger subaray are pushed onto stack.
5. After processing smaller subarrays the larger ones are popped out of stack and sorted.
6. The loop stops when the stack is empty.
7. This algorithm improves stack space usage in recusrsion as in worst case of recursive quicksort ( 1 and n-1 division ) the stack space need is O(n) whereas here it will never require more than O(logn) and in worst case it may remain almost constant as indices are popped out just after being pushed.

OUTPUT:  
enter the size of array 7  
enter the array 2 6 3 -7 2 0 2  
sorted array  
-7  0  2  2  2  3  6  

Time complexity : O(nlogn)  
Space complexity : O(logn)
GRAPH OF SPACE COMPLEXITY :  
![Screenshot 2025-03-09 160813](https://github.com/user-attachments/assets/6eea49b2-0ade-40d7-9514-ca2367520b56)


<br><br><br>

### ------------------------- Program - 04 ---------------------------  
AIM : To find the maximum and minimum element from an array using divide and conquer.   
WORKING:  
1. If the array has only one element, return it as both the maximum and minimum.  
2. Find the middle index of the array.  
3. Recursively call the function for the left half of the array.  
4. Recursively call the function for the right half of the array.  
5. Compare the maximum values from both halves and store the larger one.  
6. Compare the minimum values from both halves and store the smaller one.  
7. Return the final maximum and minimum values.

OUTPUT :  
enter no. of elements in array 8  
1 2 5 11 9 -5 3 2  
maxmum element 11  
minimum element -5  

Time complexity : O(n)  
space complexity : O(n)     
![Screenshot 2025-04-01 201508](https://github.com/user-attachments/assets/ca843fdb-b9d1-48d3-a13b-a46639cf5c26)



<br><br><br>
### ------------------------- Program - 05 --------------------------- 
AIM : to implement quickhull algorithm and finding the convex hull points with divide and conquer approach.  
WORKING : 
1. The function determinant(int **mat, int n) computes the determinant of an n × n matrix.
2. The function LeftRightcheck determines whether p3 is to the left or right of the line formed by p1 and p2 by using determinant value.
3. We first find the horizontally farthest points by finding leftmost and rightmost points. This gives us a division line. Add these points to hull.
4. divide the points around this line into left and right sets by using determinant logic.
5. Once the first division is done, we call the QuickHullRec function once for each side i.e. left and right.
6. In the passed set of points (left or right points) we find the point farthest from the division line. Push this farthest point into Hull as well.
7. Again create two sets of left and right points, once wrt to the p1 point of division line and the farthest point, and once wrt to p2 point of division line and fathest point.
8. Now we have two sets of left points (we do not take right side points here as they will be interior to the triangle of p1,p2 and farthest).
9. Recursively call the same function twice once with each division line (at each division we keep getting two partition lines).
10. Base case occurs when the vector containg the points of a side becomes empty.

OUTPUT :  
Enter number of points: 15  
The points are:  
 -9,  -3  
  4, -10   
 -1,  -6  
  8,   8  
 -8,  -6   
 -5,  -5  
 -9,  -3   
 -9,   1  
  5,  -8  
 -3,   6  
  1,  -6  
 -8,   3  
  2,  -8   
 -9,   6  
  8,   5  
  
Convex Hull Points:  
-9, -3  
8, 8  
4, -10  
-8, -6  
5, -8   
8, 5   
-9, 6  
Graphs:  
![Screenshot 2025-02-21 214605](https://github.com/user-attachments/assets/21872ebd-9cd7-403e-bbb1-d17861c40c6f)

![{2C225BB0-D1F6-4364-94BF-812F5BDA577C}](https://github.com/user-attachments/assets/787ef549-d667-422b-9054-275a1848b17f)

Time Complexity : O(n^3)  
Space complexity : O(n^2)

<br><br><br>

### ------------------------- Program - 06 ---------------------------   
AIM : To find all possible triangles with given n points from user.  
WORKING:  
1. Take the number of points as input from user.
2. Take n point coordinates either as input or generate randomly in specified range using rand() function.
3. The distance function calculates the distance between two points and returns the distance.
4. We keep the points in form a vector of pairs.
5. We keep selecting 3 points from the set and find the distances among the 3 points.If there are duplicate points they are detected and not considered for triangle.
6. Using the triangle inequality we check if points are collinear or not as collinear points will not form a triangle.
   ```
   if(d1==0 || d2==0 || d3==0)
                    continue;
   if((d1+d2>d3) && (d1+d3>d2) && (d2+d3>d1))
          cout<<"points ("<<points[i].first<<","<<points[i].second<<") , ("<<points[j].first<<","<<points[j].second<<") , ("<<points[k].first<<","<<points[k].second<<") form a triangle "<<endl;
   ```
7. The coordinates of each triangle are printed.

OUTPUT:  
enter the number of points 4  
points are   
-4,2  
-1,-5  
4,-1  
3,3  
points (-4,2) , (-1,-5) , (4,-1) form a triangle   
points (-4,2) , (-1,-5) , (3,3) form a triangle   
points (-4,2) , (4,-1) , (-1,-5) form a triangle   
points (-4,2) , (4,-1) , (3,3) form a triangle   
points (-4,2) , (3,3) , (-1,-5) form a triangle   
points (-4,2) , (3,3) , (4,-1) form a triangle   
points (-1,-5) , (-4,2) , (4,-1) form a triangle   
points (-1,-5) , (-4,2) , (3,3) form a triangle   
points (-1,-5) , (4,-1) , (-4,2) form a triangle   
points (-1,-5) , (4,-1) , (3,3) form a triangle   
points (-1,-5) , (3,3) , (-4,2) form a triangle   
points (-1,-5) , (3,3) , (4,-1) form a triangle   
points (4,-1) , (-4,2) , (-1,-5) form a triangle   
points (4,-1) , (-4,2) , (3,3) form a triangle   
points (4,-1) , (-1,-5) , (-4,2) form a triangle  
points (4,-1) , (-1,-5) , (3,3) form a triangle   
points (4,-1) , (3,3) , (-4,2) form a triangle     
points (4,-1) , (3,3) , (-1,-5) form a triangle   
points (3,3) , (-4,2) , (-1,-5) form a triangle   
points (3,3) , (-4,2) , (4,-1) form a triangle  
points (3,3) , (-1,-5) , (-4,2) form a triangle   
points (3,3) , (-1,-5) , (4,-1) form a triangle  
points (3,3) , (4,-1) , (-4,2) form a triangle   
points (3,3) , (4,-1) , (-1,-5) form a triangle   

Time complexity : O(n^3) 
Space complexity : O(n)  




## Lab - 05      Date: 27-02-2025    
 
### ------------------------- Program - 01 ---------------------------
AIM : To implement activity selection using Greedy approach   
i) Selection by sorting start times in non decreasing order  
ii) selection by sorting finish times in non decreasing order
iii) selection by sorting duration in non decreasing order  

WORKING :  
1. We have a table with job ids, their start times and finish times.
2. Feasibilty : to finish the jobs within the time limit (here 24 hrs)
   Objective function : To complete maximum no. of jobs
3. APPROACH 1 : sort the given table by start times in non decreasing order using quicksort.
4. then select a job in order from the sorted table and check for feasibility
     ```
      if(c >=(arr[2][i]-arr[1][i]) && arr[1][i] >= prev_finish){
            result[i]=arr[0][i];
            prev_finish=arr[2][i];
            c-=(arr[2][i]-arr[1][i]); }
     ```
5. If it satisfies the feasibility criteria then add it to result otherwise check next jobs.
6. APPROACH 2 : sort the given table by finish times in non decreasing order using quicksort.
7. then select a job in order from the sorted table and check for feasibility, if it satisfies the feasibility criteria then add it to result otherwise check next jobs.
8. APPROACH 3: sort the given table by duration in non decreasing order using quicksort.
9. then select a job in order from the sorted table and check for feasibility, if it satisfies the feasibility criteria then add it to result otherwise check next jobs.
10. Comparison shows that the 2nd approach (sorting finish times in non decreasing orders) gives maximum profit.

OUTPUT :  
```
  ORIGINAL TABLE  
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
  JOBS |   0   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |  10   |  11   |  12   |  13   |  14   |
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 START |  18   |   9   |  10   |   1   |   6   |   1   |   5   |   2   |   5   |  20   |   7   |  15   |  16   |  10   |   7   |
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 FINISH|  19   |  10   |  15   |  20   |  11   |   7   |  13   |  14   |   8   |  21   |  12   |  16   |  19   |  11   |  23   |
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+

                            ********************** Sorting by start time ************************* 
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
  JOBS |   5   |   3   |   7   |   6   |   8   |   4   |  14   |  10   |   1   |   2   |  13   |  11   |  12   |   0   |   9   |
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 START |   1   |   1   |   2   |   5   |   5   |   6   |   7   |   7   |   9   |  10   |  10   |  15   |  16   |  18   |  20   |
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 FINISH|   7   |  20   |  14   |  13   |   8   |  11   |  23   |  12   |  10   |  15   |  11   |  16   |  19   |  19   |  21   |
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
Result : 
J5   J14   
No. of jobs executed : 2

                           ********************** Sorting by Finish time *************************
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
  JOBS |   5   |   8   |   1   |   4   |  13   |  10   |   6   |   7   |   2   |  11   |   0   |  12   |   3   |   9   |  14   |  
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+  
 START |   1   |   5   |   9   |   6   |  10   |   7   |   5   |   2   |  10   |  15   |  18   |  16   |   1   |  20   |   7   |  
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+  
 FINISH|   7   |   8   |  10   |  11   |  11   |  12   |  13   |  14   |  15   |  16   |  19   |  19   |  20   |  21   |  23   |  
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
Result :
J5   J1   J13   J11   J0   J9
No. of jobs executed : 6
                                     **************** Sorted by Duration ***************
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+  
   JOB |   1   |  13   |  11   |   9   |   0   |  12   |   8   |   2   |   4   |  10   |   5   |   6   |   7   |  14   |   3   |
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+  
 START |   9   |  10   |  15   |  20   |  18   |  16   |   5   |  10   |   6   |   7   |   1   |   5   |   2   |   7   |   1   |
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+  
 FINISH|  10   |  11   |  16   |  21   |  19   |  19   |   8   |  15   |  11   |  12   |   7   |  13   |  14   |  23   |  20   |
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+  
 DURATION| 1   |   1   |   1   |   1   |   1   |   3   |   3   |   5   |   5   |   5   |   6   |   8   |  12   |  16   |  19   |
-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+  
Result :
J1   J13   J11   J9
No. of jobs executed : 4

```

Ouput for different sets of inputs  
| S.no. | By start time| By Finish time | By duration |
|-------|-----------|-----------|------------------|
| 1     |2     | 6    |  4         |
| 2     |4    | 6   |  2            |
| 3     | 7      | 9       |  3         |
| 4     | 2    | 7     |  4           |
| 5     | 4   | 6    |  2          |
| 6     | 3    | 6   |  4          |
| 7    | 3    | 6   |  1          |
| 8     | 3    | 5   | 1          |
| 9     | 5    | 6   |  2          |
| 10     | 4    | 6   |  3          |

Timecomplexity = O(nlogn) for sorting O(n) for greedy approach ,hence O(nlogn)
Space complexity =O(n)

![Screenshot 2025-04-13 002448](https://github.com/user-attachments/assets/aa8e6172-092b-4c9c-bdde-c21707b7c9c0)





### ------------------------- Program - 02 ---------------------------  
AIM : to implement Dijkstra's algorithm for single source shortest path and trace the shortest path from source to destination.  
WORKING :  
1. Take the graph as input from user. It is stored in an adjacency matrix.
2. Dist is a 1D array that has indices corresponding to vertices and stores minimum distance of each vertex from source. Visited is a 1d boolean array.
3. Path is a 1D array that stores the preceeding vertex from which current vertex is reached.
4. Initialise distances of vertices as weight of edge between that vertex and source (if no edge between v and src then dist is infinity).Visited of source vertex is set to true and its dist is set to 0. 
5. for remaining  vertices , find a non visited vertex whose dist is minimum. let it be u
6. visited[u] is set to true and all other vertices are checked as follows :
    ```
      if(dist[i]> dist[min_ind]+adj[min_ind][i]){
                dist[i]=dist[min_ind]+adj[min_ind][i];
                path[i]=min_ind;
        }
    ```
7. This loop continues until all vertices are visited.
8. Path is backtracked from current vertex to all subsequent preceeding vertices until source vertex is reached.

OUTPUT :  
![Picture1](https://github.com/user-attachments/assets/041dfda3-9e91-42b9-9647-14155d4a7342)


enter no. of vertices 6  
enter no. of edges 8    
enter source :0    enter destination :1   enter edge weight :7    
enter source :0    enter destination :2   enter edge weight :12  
enter source :1    enter destination :3   enter edge weight :9  
enter source :1    enter destination :2   enter edge weight :2  
enter source :2    enter destination :4   enter edge weight :10  
enter source :4    enter destination :3   enter edge weight :4  
enter source :4    enter destination :5   enter edge weight :5  
enter source :3    enter destination :5   enter edge weight :1  
edge 0 to 0 : 0  edge 0 to 1 : 7  edge 0 to 2 : 12  edge 0 to 3 : 32767  edge 0 to 4 : 32767  edge 0 to 5 : 32767  
edge 1 to 0 : 32767  edge 1 to 1 : 0  edge 1 to 2 : 2  edge 1 to 3 : 9  edge 1 to 4 : 32767  edge 1 to 5 : 32767    
edge 2 to 0 : 32767  edge 2 to 1 : 32767  edge 2 to 2 : 0  edge 2 to 3 : 32767  edge 2 to 4 : 10  edge 2 to 5 : 32767  
edge 3 to 0 : 32767  edge 3 to 1 : 32767  edge 3 to 2 : 32767  edge 3 to 3 : 0  edge 3 to 4 : 32767  edge 3 to 5 : 1  
edge 4 to 0 : 32767  edge 4 to 1 : 32767  edge 4 to 2 : 32767  edge 4 to 3 : 4  edge 4 to 4 : 0  edge 4 to 5 : 5    
edge 5 to 0 : 32767  edge 5 to 1 : 32767  edge 5 to 2 : 32767  edge 5 to 3 : 32767  edge 5 to 4 : 32767  edge 5 to 5 : 0  
minimum distance (0th to nth node): 17  
path from 0 to 5th node :   
5 <-- 3 <-- 1 <-- 0   


Time Complexity : O(n^2)  
space complexity : O(n^2)    
![Screenshot 2025-04-13 000151](https://github.com/user-attachments/assets/2a7d0813-00d8-4389-a7b8-84a791c5b604)






 

### ------------------------- Program - 03 ---------------------------  
AIM : To implement Strassen's matrix multiplication algorithm.  
WORKING:  
1. Take the sizes of matrices as input from users. Discard any invalid dimensions (c1 != r2 ) and ensure the dimensions are in powers of 2.
2. The matrices have been initialised by random numbers.
3. Add function adds two matrices in O(n^2) time and sub function subtracts them in O(n^2) time.
4. Conventional function multiplies two matrices of 2 by 2 size hence takes constant time .
5. In strassen function , we divide each of the input matrices into 4 submatrices of dimension n/2 by n/2.
6. Using strassen's equations we calculate Matrices P,Q,R,S,T,U,V and then C11,C12,C21,C22.
  ```
    vector<vector<int>> P = strassen(add(A11, A22, n/2), add(B11, B22, n/2), n/2);
    vector<vector<int>> Q = strassen(add(A21, A22, n/2), B11, n/2);
    vector<vector<int>> R = strassen(A11, sub(B12, B22, n/2), n/2);
    vector<vector<int>>S = strassen(A22, sub(B21, B11, n/2), n/2);
    vector<vector<int>> T = strassen(add(A11, A12, n/2), B22, n/2);
    vector<vector<int>> U = strassen(sub(A21, A11, n/2), add(B11, B12, n/2), n/2);
    vector<vector<int>> V = strassen(sub(A12, A22, n/2), add(B21, B22, n/2), n/2);
  ```

7. The C11,C12,C21,C22 are then combined into 1 matrix C and returned.
8. To compare complexity we have evaluated it 6 times each with a next power of 2 and recorded times.
9. The array size vs time graph shows how the compelxity has reduced from n^3 to n^2.81.
10. As evident, we have used 7 multiplications and 18 additions.

OUTPUT :  
```
enter number of rows and columns of matrix1 4 4
enter number of rows and columns of matrix2 4 4
Matrix A : 
    16    11    17     8
    10    18     8     3
     1    15     6    17
    15     1     2    17
Matrix B : 
    12    17     5     4
    14    12    14    11
     2     7    15     3
    14     1     7     9
Resultant matrix C :
   492   531   545   308
   430   445   443   289
   472   256   424   340
   436   298   238   230
```
Sizes : 2, 4, 8, 16, 32, 64, 128   
Times : 2, 49, 378, 2265, 17893, 113186, 1.07008e+06 (microseconds)  
GRAPH:  
![image](https://github.com/user-attachments/assets/c0691fe1-8ee1-4382-8a41-d1165924bd05)




## Lab - 06      Date: 20-03-2025    
 
### ------------------------- Program - 01 ---------------------------
AIM : Implementation of Kruskal's algorithm.  
WORKING:  
1. A minimum spanning tree (MST) or minimum weight spanning tree for a weighted, connected, and undirected graph is a spanning tree (no cycles and connects all vertices) that has minimum weight.
2. In kruskal's algorithm we first sort the edgelist ( array of structures) in non decreasing order.
3. We create a min heap of edges using minheap and heapify function.
4. No extract the topmost (min weight ) node from the minheap and add it to MST if it does not generate a cycle.
5. Cycle detection is implemented using Disjoint usion and find algorithms.
6. To detect cycle we find the topmost parent of both the endpoints and if both parents are different ,we unite them and add the edge to MST.
7. Otherwise, if both nodes map to same parent then there exists a cycle and that edge must be discarded.
8. This loop continues until n-1 edges have been included or minheap is empty.
9. Note that in case of disjoint graph we will not be getting n-1 edges in the resultant graph hence we may conclude that MST does not exist in that case.

OUTPUT :    
enter no. of vertices in graph : 9  
enter no. of edges in graph : 14  
 Enter 1st vertex, 2nd vertex, and weight: 0 1 4  
 Enter 1st vertex, 2nd vertex, and weight: 0 7 8  
 Enter 1st vertex, 2nd vertex, and weight: 1 2 8  
 Enter 1st vertex, 2nd vertex, and weight: 7 6 1  
 Enter 1st vertex, 2nd vertex, and weight: 7 8 7  
 Enter 1st vertex, 2nd vertex, and weight: 6 8 6  
 Enter 1st vertex, 2nd vertex, and weight: 2 8 2  
 Enter 1st vertex, 2nd vertex, and weight: 2 3 7  
 Enter 1st vertex, 2nd vertex, and weight: 6 5 2  
 Enter 1st vertex, 2nd vertex, and weight: 1 7 11  
 Enter 1st vertex, 2nd vertex, and weight: 3 5 14  
 Enter 1st vertex, 2nd vertex, and weight: 2 5 4  
 Enter 1st vertex, 2nd vertex, and weight: 3 4 9  
 Enter 1st vertex, 2nd vertex, and weight: 5 4 10  
Tree :  
7 to 6  
6 to 5  
2 to 8  
0 to 1  
2 to 5  
2 to 3   
0 to 7    
3 to 4   
GRAPH :  
![Screenshot 2025-03-30 122852](https://github.com/user-attachments/assets/1c72587e-849d-467c-8392-8eb9b827e77c)

MST  :  
![kruskalMST](https://github.com/user-attachments/assets/9ed0da10-5a08-4af5-9838-738e431ea954)

For a DISCONNECTED GRAPH :  
![Screenshot 2025-03-30 121759](https://github.com/user-attachments/assets/41be067e-07c9-434c-8032-6fde833d5ece)  
OUTPUT :    
enter no. of vertices in graph : 7  
enter no. of edges in graph : 8  
 Enter 1st vertex, 2nd vertex, and weight: 0 1 8  
 Enter 1st vertex, 2nd vertex, and weight: 0 2 5  
 Enter 1st vertex, 2nd vertex, and weight: 1 2 9  
 Enter 1st vertex, 2nd vertex, and weight: 1 3 11  
 Enter 1st vertex, 2nd vertex, and weight: 2 4 10  
 Enter 1st vertex, 2nd vertex, and weight: 2 3 15  
 Enter 1st vertex, 2nd vertex, and weight: 3 4 7  
 Enter 1st vertex, 2nd vertex, and weight: 5 6 3  
spanning tree does not exist   

Time complexity : O(E log E)  
Space complexity : O(V²)  
![Screenshot 2025-03-30 192236](https://github.com/user-attachments/assets/10b3cd28-1fcd-4987-819d-5a6ea68287b3)

### ------------------------- Program - 02 ---------------------------
AIM : To implement Prim's algorithm to find MST of a graph input by user.  
WORKING:  
1. Prim's algorithm is a greedy algorithm that finds a minimum spanning tree (MST) for a weighted undirected graph.
2. The algorithm starts by visisting the minimum weight edge of the graph (k,l).
3. It maintains a set of visited nodes and a set of edges that connect visited nodes to unvisited nodes.
4. In this code, the 'cost' matrix represents the adjacency matrix of the graph, and 'edges' is a vector of edges with their weights.
5. The 'Prims' function implements Prim's algorithm.
6. First, it finds the minimum weight edge in the graph and adds it to the MST. This is done by finding the minimum value in the 'cost' matrix.
7. The 'near' vector is used to keep track of the closest visited node to each unvisited node.
8. The algorithm then iterates through the unvisited nodes, selecting the node with the minimum weight edge to a visited node.
9. This selected node and its corresponding edge are added to the MST, and the 'near' vector is updated.
10. The 'tree' vector stores the edges of the MST.
11. The 'minwt' variable keeps track of the total weight of the MST.
12. The algorithm continues until all nodes are visited, or until n-1 edges have been added to the MST.
13. Finally, the MST and its total weight are printed.
14. The 'main' function reads the graph's vertices, edges, and weights from the user, and then calls the 'Prims' function to find the MST.
15. The adjacency matrix is then printed.

OUTPUT :    
enter no. of vertices : 9  
enter no. of edges : 14  
enter source, destination and weight : 0 1 4   
enter source, destination and weight : 0 7 8   
enter source, destination and weight : 1 7 11   
enter source, destination and weight : 7 6 1   
enter source, destination and weight : 1 2 8   
enter source, destination and weight : 2 8 2   
enter source, destination and weight : 7 8 7  
enter source, destination and weight : 6 8 6   
enter source, destination and weight : 2 3 7   
enter source, destination and weight : 2 5 4   
enter source, destination and weight : 6 5 2   
enter source, destination and weight : 3 5 14   
enter source, destination and weight : 5 4 10   
enter source, destination and weight : 3 4 9   

Minimum spanning tree :  
```
---------  
| 6 | 7 |  
---------  
| 5 | 6 |  
---------  
| 2 | 5 |  
---------  
| 8 | 2 |  
---------  
| 3 | 2 |  
---------  
| 0 | 7 |   
---------   
| 1 | 0 |  
---------  
| 4 | 3 |
```
Minimum weight : 37  
GRAPH :  
![Screenshot 2025-03-30 122852](https://github.com/user-attachments/assets/f694ac94-4ae3-438e-a664-98aefd42a691)

MST :  
![Screenshot 2025-03-30 123559](https://github.com/user-attachments/assets/6c0e273c-e1d0-4ad2-9bc2-2b2c97e4794d)


Time complexity : O(v^2)  
Space complexity : O(v^2)    
![Screenshot 2025-03-30 193709](https://github.com/user-attachments/assets/cfd633c0-51eb-42b9-af74-72f90cdc147d)


 
## Lab - 07      Date: 27-03-2025    
 
### ------------------------- Program - 01 ---------------------------
AIM : To implement knapsack 0/1 problem's solution using dynamic programming approach.  
WORKING :  
1. The knapsack01 function takes profit, weights, capacity, and number of items as input.
2. It creates a 2D table table of size (n+1) x (capacity+1) to store the maximum profit for each subproblem.
3. The table is initialized with 0 for the first row and column, representing the base cases.
4. The function then iterates through the table, filling it using the following rules:
5. If the current item's weight is less than or equal to the current capacity, the maximum profit is the maximum of:
    a. The profit of including the current item plus the maximum profit for the remaining capacity and previous items.
    b. The maximum profit for the previous items without including the current item.
6. If the current item's weight is greater than the current capacity, the maximum profit is the same as the maximum profit for the previous items.
7. After filling the table, the function prints the table.
8. It then backtracks through the table to find the selected items that contribute to the maximum profit.
9. The selected items are stored in the selectedItems vector.
10. The function prints the selected items and the maximum profit.
11. The main function takes the number of items and capacity as input.
12. It then takes the profit and weight for each item as input.
13. It prints the original table of profits and weights.
14. Finally, it calls the knapsack01 function to solve the problem and print the results.

OUTPUT :    
enter no. of items : 4  
enter capacity : 8  
enter profit and weight for P0 : 1 2  
enter profit and weight for P1 : 2 3  
enter profit and weight for P2 : 5 4  
enter profit and weight for P3 : 6 5  
Original Table :  
```
-------+-------+-------+-------+-------+
PROFIT |   1   |   2   |   5   |   6   |
-------+-------+-------+-------+-------+
WEIGHT |   2   |   3   |   4   |   5   |
-------+-------+-------+-------+-------+
Result: 
0   0   0   0   0   0   0   0   0   
0   0   1   1   1   1   1   1   1   
0   0   1   2   2   3   3   3   3   
0   0   1   2   5   5   6   7   7   
0   0   1   2   5   6   6   7   8
```
Selected items for maximum profit: P1 P3   
Maximum Profit : 8   

  ![Screenshot 2025-04-01 230824](https://github.com/user-attachments/assets/70f21d64-9fec-4fdd-9460-8ddf43b731c9)

Time complexity : n * capacity  
Space complexity : n * capacity    


 
### ------------------------- Program - 02 ---------------------------
AIM : To find shortest path from source to sink in a multistage graph.  
WORKING :  
1. The code implements a multistage graph problem, finding the shortest path from the start node (0) to the end node (n-1).
2. The countStages function calculates the number of stages in the given graph. It traverses the graph from the start node to the end node, incrementing a counter for each stage.
3. The Multistage function computes the shortest path using dynamic programming.
4. It initializes a vector fdist to store the shortest distance from each node to the end node, initializing the end node's distance to 0 and others to infinity.
5. It also initializes a vector path to store the next node in the shortest path for each node.
6. The function iterates backward from the second-to-last node to the start node, calculating the shortest distance to the end node for each node.
7. For each node, it examines its outgoing edges and updates fdist and path if a shorter path is found.
8. It prints the chosen edge for each node during the backward iteration.
9. After calculating the shortest distances, it reconstructs the shortest path by traversing the path vector.
10. It prints the shortest path and its total cost (the shortest distance from the start node to the end node).
11. The main function takes the number of vertices and edges as input.
12. It creates an adjacency matrix cost to represent the graph's edge weights.
13. It reads the source, destination, and weight for each edge from the user and populates the cost matrix.
14. It calls countEdges to determine the number of stages in the graph.
15. It calls Multistage to find and print the shortest path and its cost.

 OUTPUT : 
 enter no. of vertices : 8  
enter no. of edges : 12  
enter source, destination and weight : 0 1 1   
enter source, destination and weight : 0 2 2   
enter source, destination and weight : 0 3 5    
enter source, destination and weight : 1 4 4  
enter source, destination and weight : 1 5 11   
enter source, destination and weight : 2 4 9    
enter source, destination and weight : 2 5 5   
enter source, destination and weight : 2 6 16     
enter source, destination and weight : 3 6 2   
enter source, destination and weight : 4 7 18  
enter source, destination and weight : 5 7 13  
enter source, destination and weight : 6 7 2  
No. of stages : 4  
chosen edge : 6 7   
chosen edge : 5 7  
chosen edge : 4 7   
chosen edge : 3 6   
chosen edge : 2 5   
chosen edge : 1 4   
chosen edge : 0 3   
The shortest path from 0 to 7 is: 0 ---> 3 ---> 6 ---> 7  
Total cost: 9  
GRAPH :  
![Screenshot 2025-03-30 150858](https://github.com/user-attachments/assets/9b5e261d-a051-46f1-b6b4-53b00e2effed)
![Screenshot 2025-03-30 151033](https://github.com/user-attachments/assets/a5908d9a-cd6f-47b0-90e6-88b56db1fb03)    
![Screenshot 2025-04-01 232449](https://github.com/user-attachments/assets/6d8458fa-3c70-47c6-8711-d0f3272a287a)

Time complexity : O(n^2)
space complexity : O(n^2)


### ------------------------- Program - 03 ---------------------------   
AIM: Implement the backward approach for multistage graph.  
WORKING :  
1. The code implements a multistage graph problem, finding the shortest path from the start node (0) to the end node (n-1).
2. Backward approach is similar to the froward approach except that here we consider distances from immediate preceeding nodes.
3. The loop here steps up from i=2 to n-1 and the minimum cost vertex belonging to previous stage is found out.
4. For each node, it examines its incoming edges and updates bdist and path if a shorter path is found.
5. After calculating the shortest distances, it reconstructs the shortest path by traversing the path vector.
6. It prints the shortest path and its total cost (the shortest distance from the start node to the end node).
7. The main function takes the number of vertices and edges as input.
8. It creates an adjacency matrix cost to represent the graph's edge weights.
9. It reads the source, destination, and weight for each edge from the user and populates the cost matrix.
10. It calls countEdges to determine the number of stages in the graph.
11. It calls Multistage to find and print the shortest path and its cost.

     
OUTPUT :  
enter no. of vertices : 6  
enter no. of edges : 7   
enter source, destination and weight : 0 1 1   
enter source, destination and weight : 0 2 2   
enter source, destination and weight : 1 3 2  
enter source, destination and weight : 2 4 5  
enter source, destination and weight : 1 4 3  
enter source, destination and weight : 3 5 4  
enter source, destination and weight : 4 5 2  
No. of stages : 4  
chosen edge : 1 0  
chosen edge : 2 0  
chosen edge : 3 1  
chosen edge : 4 1  
chosen edge : 5 4  
The shortest path from 0 to 5 is: 0 ---> 1 ---> 4 ---> 5  
Total cost: 6  
![Screenshot 2025-04-03 004547](https://github.com/user-attachments/assets/76e9db24-655d-4984-b7d6-59df5993ca4c)  
![Screenshot 2025-04-03 004625](https://github.com/user-attachments/assets/45a5a08d-d3e8-4848-9712-0b65cf334c80)

Time complexity :  
![Screenshot 2025-04-01 232449](https://github.com/user-attachments/assets/fea3d67a-c5da-4439-a453-3ae14095bd04)


  
### ------------------------- Program - 04 ---------------------------  
AIM: To solve the travelling salesperson problem (recursive approach).  
WORKING:  
1. The travelling salesperson problem is to travel all the nodes of a graph exactly once and return to the source node at the end (hamiltonian graph).
2. To try all possible routes, we maintain a set of vertices which consists of all non visited vertices.
3. The main idea is to find the min path length from { distance of A from neighbour1 + minpath length till neighbour1, distance of A from neighbour2 + minpath length till neighbour2 ... and so on for all vertices}.
4. We recursively find out the path lenghts of all combinations of nodes by the following function call:
```
pathlen= cost[source][set[i]]+travel(cost,set[i],newset,sum);
```
hence we the min pathlen and return it.  
5.Base case is reached when the set is empty, there we simply return the cost[node][source] as the final destination is source itself.  
6. This approach uses recusion and is not optimal as it takes n! time for execution.  

OUTPUT:     
enter no. of vertices : 4   
enter no. of edges : 12                            
enter source, destination and weight : 0 1 16    
enter source, destination and weight : 0 2 11           
enter source, destination and weight : 0 3 6              
enter source, destination and weight : 1 0 8                  
enter source, destination and weight : 1 2 13                
enter source, destination and weight : 1 3 16               
enter source, destination and weight : 2 0 4            
enter source, destination and weight : 2 1 7          
enter source, destination and weight : 2 3 9          
enter source, destination and weight : 3 0 5        
enter source, destination and weight : 3 1 12       
enter source, destination and weight : 3 2 2                 
minimum distance to travel all nodes and return back : 23              
           
              
![Screenshot 2025-04-12 234231](https://github.com/user-attachments/assets/6975a587-21d1-4404-885e-726a33c94cc5)

           
                             
 Timecomplexity : O(n!)          
 Space complexity : O(n^2)           

 
### ------------------------- Program - 05 ---------------------------
AIM : Finding median in O(n) time complexity using partition function.  
WORKING :  
1. Start by taking array as input from user.
2. In the partition function pick the first element as pivot, and place it at its correct position.
3. position is returned to the calling function.
4. if the position is equal to the median (n/2) then median has been found .
5. If the position of the current pivot is in the left of the middle of an array then repeat all the steps for the subarray starting from the starting index and the pivot as the ending index.
6. If the position of the current pivot is in the right of the middle of an array then repeat all the steps for the subarray starting from the pivot index and ending as the previous ending index.


 OUTPUT :
 enter the no. of elements in array 9  
enter the elements 1 7 89 3 7 2 5 0 2  
Median is 3  

Time complexity : O(n)
Space complexity : O(n)     
![Screenshot 2025-04-12 235301](https://github.com/user-attachments/assets/556b06f4-637e-4186-a804-8578bd672f09)

 
### ------------------------- Program - 06 ---------------------------  
AIM: To solve travelling salesman problem using dynamic programming.  
WORKING :  
1. To improve the time complexity we will use dynamic programming approach.
2. to check all possibe paths recursive means computing all permutations of nodes (n!).
3. To avoid recomputation we will use a table that stores the cost of moving to each node after having traversed a particular subset of nodes.
4. we do not need to recompute the distance for the same subset as the total sum will remain same regardless of the order in which nodes are traversed. Only thing that matters is which node is chosen as the immediate previous node to the new unvisited node as that distance will be different with each node of the visited subset.
5. so we calculate the distance of unvisited node v from the subset of visited nodes (u). for each unvisited node we pair it with every visited node of subset and pick the minimum distance.
6. Continue this for every subset of the nodes (2^n).
7. To implement this we use bitmasking : 1 for visited and 0 for unvisited
```
for(int mask=0;mask< (1<<n);mask++){     //subset
        for(int u=0;u<n;u++){                //all visited nodes
            if((mask & (1<<u)) == 0)
                continue;
            for(int v=0;v<n;v++){           // all remaining nodes
                if((mask & (1<<v))== 0){
                    int newmask=(mask | (1<<v));
                    if(cost[u][v]!=INT_MAX && dp[mask][u]!=INT_MAX){
                        dp[newmask][v]=min(dp[newmask][v],dp[mask][u]+cost[u][v]);
                    }
```
8. Finally we find the vertex with minimum distance to the source again.

OUTPUT:  
enter no. of vertices : 5  
enter no. of edges : 10                            
enter source, destination and weight : 0 1 12  
enter source, destination and weight : 1 3 7  
enter source, destination and weight : 3 4 4   
enter source, destination and weight : 4 2 20   
enter source, destination and weight : 0 2 10   
enter source, destination and weight : 0 3 19   
enter source, destination and weight : 0 4 8   
enter source, destination and weight : 1 2 3  
enter source, destination and weight : 1 4 2   
enter source, destination and weight : 3 2 6   
0 --> 1 --> 2 --> 3 --> 4 --> 0    
Minimum path length : 32   
![image](https://github.com/user-attachments/assets/3a944500-0fd4-4c82-a5ba-f966df7ad457)


Time complexity : O(n^2 *(2^n))   
Space complexity : O(n *(2^n))  
![Screenshot 2025-04-13 144526](https://github.com/user-attachments/assets/53ccd1a5-4a94-46b0-b923-01eacb8aeaab)   

 
### ------------------------- Program - 07 ---------------------------   
AIM : To implement Warshall's algorithm .  
WORKING:  
1. Start by taking a cost matrix as input from the user, where cost[i][j] represents the weight of the edge from node i to node j.
2. Initialize matrix A as a copy of the cost matrix.
3. For each node 'k' from 0 to n-1, consider it as an intermediate node.
4. For every pair of nodes (i, j), check if going through node k offers a shorter path.
5. If A[i][k] != INF and A[k][j] != INF and A[i][j] > A[i][k] + A[k][j], then update A[i][j] = A[i][k] + A[k][j].
6. Repeat the above steps for all values of k from 0 to n-1.
7. After all iterations, matrix A will contain the shortest distances between all pairs of nodes.

OUTPUT :  
enter no. of vertices : 4   
enter no. of edges : 6                          
enter source, destination and weight : 0 1 3   
enter source, destination and weight : 0 3 5   
enter source, destination and weight : 1 0 2  
enter source, destination and weight : 1 3 4   
enter source, destination and weight : 2 1 1  
enter source, destination and weight : 3 2 2   
Shortest paths matrix    
   0   3   7   5   
   2   0   6   4   
   3   1   0   5   
   5   3   2   0   

Time complexity : O(n^3)  
Space complexity : O(n^2)    
![Screenshot 2025-04-05 121633](https://github.com/user-attachments/assets/a2d8b2fa-bbf8-45fa-b709-8e62ce88d3ee)



 
## Lab - 08      Date: 03-04-2025    
 
### ------------------------- Program - 01 ---------------------------   
AIM : To implement Knapsack 0/1 problem using sets approach.  
WORKING :  
1. Take the items, their profit, weights and capacity as input from user.
2. The knapsack function is called with the profits, weights, capacity and no. of items as arguments.
3. Create a table with no. of rows= n+1 and no. of columns = capacity + 1.
4. 0th row and 0th column are initialised with 0.
5. We initialise S(0) = {(0,0)} and for subsequent sets S(i,1)={(P,W) | (P - p(i+1) , W - w(i+1) ) belongs to S(i) }
6. S(i+1)=S(i)+S(i,1)
7. To remove suboptimal pairs we use dominance rule that if p(j)<=p(k) and w(j)>w(k) then purge (remove) tuple j
8. The above 2 steps are implemented as MergePurge operations.

OUTPUT:  
enter no. of items : 4       
enter capacity : 10                        
enter profit and weight for P0 : 10 5      
enter profit and weight for P1 : 40 4    
enter profit and weight for P2 : 30 6       
enter profit and weight for P3 : 50 3        
Original Table :    
```
-------+-------+-------+-------+-------+         
PROFIT |  10   |  40   |  30   |  50   | 
-------+-------+-------+-------+-------+
WEIGHT |   5   |   4   |   6   |   3   |
-------+-------+-------+-------+-------+
```
Result:  
```
0   0   0   0   0   0   0     0   0   0   0   
0   0   0   0   0   10  10   10   10   10   10   
0   0   0   0   40  40  40   40   40   50   50   
0   0   0   0   40  40  40   40   40   50   70   
0   0   0   50  50  50  50   90   90   90   90
```
Selected items for maximum profit: P2 P4 
Maximum Profit : 90    
Time complexity :
Space complexity : 
![Screenshot 2025-04-05 102433](https://github.com/user-attachments/assets/de527bb6-68cf-4ff8-a069-65fde2a0625f)


### ------------------------- Program - 02 ---------------------------    
AIM : To implement matrix chain multiplication optimally using dynamic programming.  
WORKING : 
1.Take the no. of matrices and matrix chain sequence as input from user.  
2. Matrix multiplication is not commutative but it is associative and we shall use the associativity property.  
3. create 2d matrices m and s of sizes n+1 and initialise m[i,i] =0.  
4. The idea is m[i,j]= min{ m[i,k]+m[k,j] + p(i-1)*p(k)*p(j)  for all i<=k<j }
5. this idea is implemented as 
```
 for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j=i+l-1;
            m[i][j]=INT16_MAX;
            for(int k=i;k<=j-1;k++){
                int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
```
6. The table m avoid recomputation of matrix multiplications and s gives the sequence of parenthesis by storing the value of k.
7. The print function works recursively by reaching till the individual matrices in each pair of parenthesis.

OUTPUT:  
enter no. of matrices : 4           
enter the chain : 10 15 20 5 10        
((A1 (A2 A3 ))A4 )           

Time complexity : O(n^3)   
Space complexity : O(n^2)    
Graph : 
![Screenshot 2025-04-05 124557](https://github.com/user-attachments/assets/8443d717-f730-41aa-946f-00425cd3ada5)



### ------------------------- Program - 03 ---------------------------  
AIM : To find the longest common subsequence from given strings using dynamic programming.  
WORKING :  
1. Take the strings as inputs from user . let string x has length m and y has lenght n.
2. Create 2 2D vectors c (to store lengths of common subsequence) and b (to store directions) each of sizes((m+1)*(n+1)) .
3. Initialise 1st row and column with 0 as a stirng with 0 length does not have any common subsequence.
4. Then traverse table c row wise and for each cell if the corresponding values of x and y are equal then add 1 to the diagonal length and put a \ sign in b.
5. Otherwise put the value of the above cell or left cell whichever is larger and put a "|" or "<-" accordingly .
6. The length of longest subsequence is present in the last cell.
7. To get the subsequence use the b table and print the letter corresponding to cells with a '\' symbol and call it recursively with the indices pointed by the symbol of that cell.
8. if the symbol is '|' call recursively with i-1 ,j and for '<-' call it with i,j-1.

OUTPUT :                    
enter string X : COMPUTE     
enter string y : OPTION      
LCS:        
OPT                  
length of LCS : 3                 

Time complexity : O(m*n)     
Space complexity : O(m*n)       
Graph :    
![Screenshot 2025-04-13 211358](https://github.com/user-attachments/assets/d5b5135f-0434-4b84-8618-1135a896caef)


  
