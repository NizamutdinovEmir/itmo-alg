#include <iostream>
using namespace std;
int main(){
    int n , sum = 0 , currentsum = 0;
    cin>>n;
    int array[8000000];
    for (int i = 0; i<n;++i){
        cin >> array[i];
        sum += array[i];
    }
    int flag = 0;
    for(int k = 0; k < n;++k){
        currentsum += array[k];
        if (currentsum - array[k] == sum - currentsum){
            cout << k;
            flag = 1;
            break;
        }

    }
    if (flag == 0){
        cout<<-1;
    }
    return 0;
}
