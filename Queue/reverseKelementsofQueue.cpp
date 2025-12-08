#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void display(queue<int> q){
    int n=q.size();
    for(int i=1;i<=n;i++){
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}
void reverseKElements(queue<int> &q,int k){
    stack<int> s;
    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    int t=q.size()-k;
    for(int i=0;i<t;i++){
        int x=q.front();
        q.pop();
        q.push(x);
    }
}
int main(){
    queue<int> q;
    cout<<"Enter number of elements:";
    int x;
    cin>>x;
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<x;i++){
        int y;
        cin>>y;
        q.push(y);
    }
    display(q);
    int k;
    cout<<"Enter k:";
    cin>>k;
    reverseKElements(q,k);
    display(q);
}
