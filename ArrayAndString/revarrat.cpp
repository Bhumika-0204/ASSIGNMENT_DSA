#include <iostream>
using namespace std;
void swapnum(int &a,int &b){
    a=a+b;
    b=a-b;
    a=a-b;
}
int main() {
    cout << "Hello Bhumika!" << endl;
    int n;
    cout<<"Enter value of n:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int start=0;
    int end=n-1;
    while(start<end){
        swapnum(arr[start],arr[end]);
        start++;
        end--;
    }
    cout<<"Reversed Array:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}
