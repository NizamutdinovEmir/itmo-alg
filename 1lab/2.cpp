#include <iostream>
using namespace std;
int main() {
    int n, j;
    cin >> n >> j;
    int arr[1000];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    if (j > 0) {
         j = j % n;
        for (int k = 0; k < j; ++k) {
            int last = arr[n - 1];
            int temp = arr[0];
            for (int i = 1; i < n; ++i) {
                int c = arr[i];
                arr[i] = temp;
                temp = c;
            }
            arr[0] = last;
        }
    }
    else{
        j = abs(j) % n;
        for (int k = 0; k < j ; ++k){
            int first = arr[0];
            int temp = arr[n-1];
            for (int i = n - 1; i>-1 ; --i){
                int c = arr[i];
                arr[i] = temp;
                temp = c;
            }
            arr[n-1] = first;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
}