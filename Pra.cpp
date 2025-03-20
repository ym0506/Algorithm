#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


void insert(int idx, int num, int arr[], int& len) {
    for (int i = len; i > idx; i--) {
        arr[i] = arr[i-1];
    }
    arr[idx] = num;
    len++;
}

void erase(int idx, int arr[], int& len) {
    for (int i = idx; i < len-1; i++) {
        arr[i] = arr[i+1];
    }
    len--;
}

void print(int arr[], int& len) {
    for (int i = 0; i < len; i++) {
        
}
 
//155p 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
//176p 




