#include <bits/stdc++.h>
using namespace std;
struct Circular_Queue{
    vector<int>arr;
    int front=0,rear=0;
    int size=0;
    Circular_Queue(int n){
        size=n;
        arr.resize(n);
    }
    void enqueue(int x){
        arr[rear]=x;
        rear++;
        rear%=size;
    }
    int dequeue(){
        if(rear==front){
            cout<<"No element to delete"<<endl;
            return -1;
        }
        int temp=arr[front];
        front++;
        return temp;
    }
    void show_queue(){
        if(front==rear){
            cout<<"Queue is empty\n";
            return;
        }
        if(rear>front){
            for(int i=front;i<rear;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            return;
        }
        for(int i=front;i<size;i++){
            cout<<arr[i]<<" ";
        }
        for(int i=0;i<rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    int n;
    cin>>n;
    Circular_Queue* new_queue=new Circular_Queue(n);
    int op;
    cin>>op;
    while(op--){
        int choice;
        cin>>choice;
        if(choice==1){
            int temp;
            cin>>temp;
            new_queue->enqueue(temp);
        }
        else{
            new_queue->dequeue();
        }
        new_queue->show_queue();
    }
    return 0;
}