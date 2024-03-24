#include <bits/stdc++.h>
using namespace std;
void print(int start, int end, int arr[])
{
    if (start == end)
    {
        for (int i = 0; i <= end; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = start; i <= end; i++)
    {
        int temp = arr[i];
        arr[i] = arr[start];
        arr[start] = temp;
        print(start + 1, end, arr);
        temp = arr[i];
        arr[i] = arr[start];
        arr[start] = temp;
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(auto &x:arr)cin>>x;
    print(0,n-1,arr);
    return 0;
}