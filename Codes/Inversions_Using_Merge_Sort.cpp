#include <bits/stdc++.h>
using namespace std;
int merge_arrays(int start1,int end1,int start2,int end2,int arr[]){
    int len1=(end1-start1)+1;
    int len2=(end2-start2)+1;
    int tot_len=len1+len2;
    int new_arr[tot_len];
    int curr1=0,curr2=0;
    int ans=0;
    for(int i=0;i<tot_len;i++){
        if((curr2>=len2)||(curr1<len1&&(arr[start1+curr1]<arr[start2+curr2]))){
            new_arr[i]=arr[start1+curr1];
            curr1++;
        }
        else{
            ans+=(len1-curr1);
            new_arr[i]=arr[start2+curr2];
            curr2++;
        }
    }
    for(int i=0;i<tot_len;i++){
        arr[start1+i]=new_arr[i];
    }
    return ans;
}
int merge_sort(int low,int high,int arr[]){
    if(low==high)return 0;
    int mid=(low+high)/2;
    int val1=merge_sort(low,mid,arr);
    int val2=merge_sort(mid+1,high,arr);
    int val3=merge_arrays(low,mid,mid+1,high,arr);
    return val1+val2+val3;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &x:arr)cin>>x;
    cout<<merge_sort(0,n-1,arr)<<endl;
    cout<<endl;
}