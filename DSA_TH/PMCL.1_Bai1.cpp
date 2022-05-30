#include <iostream>
#include <algorithm>
using namespace std;
// câu 1
void QuickSort(int a[], int left, int right)
{
    int i, j, x;
    x = a[(left + right) / 2];
    i = left;
    j = right;
    while (i < j)
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        QuickSort(a, left, j);
    if (i < right)
        QuickSort(a, i, right);
}
int main()
{
    int n;
    cout << "Nhap so phan tu trong mang: ";
    cin >> n;
    int *a = new int[n];
    // khoi tao mang F(n)
    QuickSort(a, 0, n - 1);
    cout << "Nhap index k: ";
    int k;
    cin >> k;
    cout << a[k];
    return 0;
}
