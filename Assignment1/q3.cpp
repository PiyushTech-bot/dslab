#include <iostream>
using namespace std;
int main(){
    int a,b,c, largest;
    cout << "Enter three integers: ";
    cin >> a >> b >> c;
    largest = a;
    if(b>largest){
        largest =b;
    }
    if(c>largest){
        largest =c;
    }
    cout << "Largest: " << largest << endl;
    if(largest/2==0){
        cout << "Number is even";
    } else{
        cout << "Number is odd";
    }
}