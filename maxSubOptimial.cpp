#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){        
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    long long currSum = 0, count = 0;
    unordered_map<long long, int> mp;
    mp[0] = 1;

    for(int i = 0; i < n; i++){
        currSum += arr[i];

        if(mp.find(currSum - target) != mp.end()){
            count += mp[currSum - target];
        }

        mp[currSum]++;
    }

    cout << count;
}