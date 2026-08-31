#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the numbers of array: ";
    for(int i = 0; i<n; i++){
        cin >> *(arr+i);
    }
    int *start = arr; //first element
    int *end = arr + n -1; //last element
    while(start<end){
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;

        
    }
    cout << "Revered array: ";
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}