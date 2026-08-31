#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter numbers: ";
    for(int i = 0; i<n; i++){
        cin >> *(arr+i);
    }
    int max_val = *arr; //points to first element of array (zeroth index)
    int min_val = *arr;
    int second_max = INT_MIN;

    for(int i = 1; i<n; i++){
        int current_val = *(arr+i); // points to second element and thus continues
        if(current_val < min_val){
            min_val = current_val;
        }
        if(current_val > max_val){
            second_max = max_val;
            max_val = current_val;
        }
        else if(current_val > second_max && current_val != max_val){
            second_max = current_val;
        }
    }
    cout << "Maximum = " << max_val << endl;
    cout << "Minimum = " << min_val << endl;

    if(second_max == INT_MIN){
        cout << "Second largest = Does not exist" << endl;
    } else {
        cout << "Second Largest = " << second_max << endl;
    }
    return 0;
}