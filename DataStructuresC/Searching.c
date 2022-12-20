// Binary Search In C
#include <stdio.h>
int binarySearch(int arr[], int l, int r, int x){
    if(r >= l){
        int mid = l+(r-l)/2;
        if(arr[mid] == x)
            return mid;
        if(arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
    }
}

int main(){
    int arr[] = {2,3,4,20,30};
    int x = 20;
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = binarySearch(arr,0,n-1,x);
    if(result == -1){
        printf("Element is not found\n");
    } else {
        printf("Element is found at %d", result);
    }
}
// Linear Search
#include<stdio.h>

int main() {
    // declaration of the array and other variables
    int arr[20], size, key, i, index;
    printf("Number of elements in the list: ");
    scanf("%d", &size);

    printf("Enter elements of the list: ");
    // loop for the input of elements from 0 to number of elements-1
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search ie. key element: ");
    scanf("%d", &key);

    // loop for traversing the array from 0 to the number of elements-1
    for (index = 0; index < size; index++)
        if (arr[index] == key) // comparing each element with the key element
            break; // cursor out of the loop when a key element found

    if (index < size) // condition to check whether previous loop partially traversed or not
        printf("Key element found at index %d", index); // printing the index if key found
    else
        printf("Key element not found");

    return 0;
}

// C code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1

#include <stdio.h>

int search(int arr[], int N, int x)
{
    int i;
    for (i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    int result = search(arr, N, x);
    (result == -1)
    ? printf("Element is not present in array")
    : printf("Element is present at index %d", result);
    return 0;
}
//Output
//Element is present at index 3
//Time complexity: O(N)
//Auxiliary Space: O(1)




