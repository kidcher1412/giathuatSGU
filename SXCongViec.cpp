#include<iostream>
#define MAX 100
int s[MAX], e[MAX];
int N;
using namespace std;

void swap(int i, int j)
    {
        int tmp = e[i];
        e[i] = e[j];
        e[j] = tmp;
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }

void qsort(int a[], int start, int end)
{
        // quicksort theo thời gian kết thúc
        if (start >= end)
            return;
        int index = rand() % (start-end) + start;
        int pivot = a[index];
        int k = start - 1;
        swap(index, end);
        for (int i = start; i < end; i++)
        if (a[i] < pivot)
        {
            k++;
            swap(i, k);
        }
        k++;
        swap(k, end);
        qsort(a, start, k-1);
        qsort(a, k+1, end);
}

void proc()
{
        // xử lí
        int res = 1;
        int end = e[0];
        for (int i = 1; i < N; i++)
        {
            if (e[i] == end)
                continue;
            if (s[i] >= end)
            {
                res++;
                end = e[i];
            }
        }
        printf("%d\n", res);
}
int main()
{
            scanf("%d", &N);
            for (int i = 0; i < N; i++)
                scanf("%d %d", &s[i], &e[i]); //nhập vào thời bắt đầu và kết thúc của task i
            qsort(e, 0, N-1); // sort theo thời gian kết thúc
            proc(); // xử lí 
    }
