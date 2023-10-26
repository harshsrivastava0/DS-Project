#include<iostream>
#include<vector>
using namespace std;
class queue{
    public:
    int front;
    int last;
    vector<int> v;
    queue(){
        front = -1;
        last = -1;
    }
    void enqueue(int data){
        v.push_back(data);
        last++;
        if(last==0){
            front = 0;
        }
    }

    void dequeue(){
        if(front == last){
            front = -1;
            last = -1;
            v.clear();
        }
        else{
            front++;
        }
    }

    int getfront(){
        if(front == -1){
            return -1;
        }
        return v[front];
    }

    bool isempty(){
        return front == -1;
    }
};
int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.enqueue(40);
    while(!q.isempty()){
        cout<<q.getfront()<<" ";
        q.dequeue();
    }
    return 0;
}