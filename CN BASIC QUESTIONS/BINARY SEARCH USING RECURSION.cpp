/*
Binary Search (Recursive)
Send Feedback
Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.
Note : If given array size is even, take first mid.
Input format :

Line 1 : Array size

Line 2 : Array elements (separated by space)

Line 3 : x (element to be searched)

Sample Input :
6
2 3 4 5 6 8 
5 
Sample Output:
3 
*/
int binarySearch(int input[], int size, int element) {
    // Write your code here
int start=0;
    int end=size-1;
    while(start < end){
    int mid;
        mid =(start+end)/2;
    if(input[mid] == element){
        return mid;
    }
    if(element > input[mid]){
        start =mid+1;
    }
    if(element < input[mid]){
        end = mid-1;
    }
    }
    return -1;
    
}
