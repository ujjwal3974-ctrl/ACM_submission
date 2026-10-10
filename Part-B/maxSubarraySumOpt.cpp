#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int size, target;
    cin>>size>>target;
    vector<int> arr(size);
    for(int i = 0 ; i < size; i++){
        cin >> arr[i]; 
    }

    int count = 0;
    for(int i = 0; i < size; i++){
        int currSum = 0;
        for(int j = i; j < size; j++){
            currSum += arr[j];
            if(currSum == target) count++;
        }
    }

    cout<<"Count: "<<count;
}