#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long arr[100000];
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  bool ans = true;
  for (int i = 1; i <= n; ++i) {
    if (2 * i <= n && arr[i] > arr[2 * i]) {
      ans = false;
      break;
    }
    if (2 * i + 1 <= n && arr[i] > arr[2 * i + 1]) {
      ans = false;
      break;
    }
  }
  if (ans) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}
