#include <stdio.h>
// Hàm đổi chỗ 2 số nguyên
void swap(int &xp, int &yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}
// Hàm selection sort
void selectionSort(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n-1; i++)
    {
    // Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
        min = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
    // Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
        swap(arr[min], arr[i]);
    }
}
/* Hàm xuất mảng */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: n ");
    printArray(arr, n);
    return 0;
}
// Độ  phức tạp thuật toán:

// Trường hợp tốt: O(n^2)
// Trung bình: O(n^2)
// Trường hợp xấu: O(n^2)

// Không gian bộ nhớ sử dụng: O(1)












