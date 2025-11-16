#include<iostream>
using namespace std;
class solution{
    public:

    int linearSearch(int arr[],int n,int key){
        for(int i=0;i<n;i++){
            if(arr[i]==key)
            return i;
        }
        return -1;
    }
    int binarySearch(int arr[],int low,int high,int key){
        if(high<low) return -1;
        int mid=(high+low)/2;
        if(key==arr[mid]) return mid;
        if(key>arr[mid]) return binarySearch(arr,mid+1,high,key);
        return binarySearch(arr,low,mid-1,key);
    }
};
int main(){
    int n,key;
    cout<<"Enter size of an array:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of an array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter element to be searched:";
    cin>>key;
    int low=0;
    int high=n-1;
    solution obj;
    cout<<"Result using Linear Search:";
    int linres=obj.linearSearch(arr,n,key);
    cout<<linres;
    cout<<endl<<"REsult using Binary Search:";
    int binres=obj.binarySearch(arr,low,high,key);
    cout<<binres;
}