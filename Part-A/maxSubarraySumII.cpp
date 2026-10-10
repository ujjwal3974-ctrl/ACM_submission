#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, target;
    cin>>n>>target;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    int count = 0;
    for(int i =0; i < n; i++){
        int currSum = 0;
        for(int j = i; j < n; j++){
            currSum += arr[j];
            if(currSum == target){
                count++;
            }
        }
    }

    cout<<"Number of subarrays with sum "<<target<<" is "<<count;


}