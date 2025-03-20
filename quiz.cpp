#include <iostream>

using namespace std;


int func(int arr[], int N) {
    int occur[101] = {};
    for (int i = 0; i < N; i++) {
        if (occur[100 - arr[i]]) return 1;
        occur[arr[i]] = 1;
    }
    return 0;
}


//O(N)




