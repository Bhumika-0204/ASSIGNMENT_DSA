#include<bits/stdc++.h>
using namespace std;
	 void findRepeatingElements(int arr[],int n) {
	    int cnt = 0;
	    int dup[n] ;
	    for(int i=0;i<n-1;i++) {
	        for(int j=i+1;j<n;j++) {
	            if(arr[i]==arr[j]) dup[cnt++] = arr[i];
	        }
	    }
	    cout<<"The repeating elements are: ";
	    for(int i=0;i<cnt;i++) 
	        if(dup[i] != dup[i+1]) cout<<dup[i]<<" ";
	}
	int main() {
        int n;
        cout<<"Enter size of an array:";
        cin>>n;
		int arr[n];
        cout << "Enter elements of an array: ";
        for(int i=0;i<n;i++){
            cin>>arr[i];
        } 
		findRepeatingElements(arr,8);
	}