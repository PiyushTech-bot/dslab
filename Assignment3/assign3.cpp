#include <iostream>
using namespace std;

long long factorial(int n){
    if(n == 0) return 1;
    return n * factorial(n - 1);
}
int fibonacci(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}
int sum_dig(int n){
    if(n<10) return n;
    return (n % 10) + sum_dig(n/10); 
}
bool is_palindrome(const string& s, int start, int end){
    if(start >= end ) return true;
    if(s[start] != s[end]) return false;
    return is_palindrome(s, start + 1, end -1);
}
bool is_palindrome(const string& s){
    return is_palindrome(s, 0, s.size() - 1);
}


int main(){
    cout << "The factorial of n = 5: " << factorial(5) <<  endl;
    cout << "7th fibonacci number is: " << fibonacci(7) << endl;
    cout << "Sum of the digits of 12: " << sum_dig(12) << endl;
    cout << is_palindrome("sattu");
    return 0;
}