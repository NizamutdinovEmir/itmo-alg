#include <iostream>
using namespace std;

int evklid(int a , int b){
    while (a!=b){
        if (a > b){
            a = a - b;
        }
        else{
            b = b - a;
        }
    }
    return a;
}
int main(){
    int x , y;
    cin >> x >> y;
    cout << (evklid(x , y));
    return 0;
}