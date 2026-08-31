#include <iostream>
using namespace std;
int main(){
    int a,b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    if(b!=0){
        cout << "a+b: " << a+b << endl;
        cout << "a-b: " << a-b << endl;
        cout << "a*b: " << a*b << endl;
        cout << "a/b: " << a/b << endl;
    } else{
        cout << "Not defined";
    }
}