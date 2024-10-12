#include <iostream>
#include <vector>
#include <string>
using namespace std;

int digit(const string& s, int i) {
  return static_cast<int>(s[s.length() - 1 - i]);
}

void radixSort(vector<string>& A, int t, int m) {
  const int k = 256;

  for (int i = 0; i < t; i++) {
    vector<int> C(k, 0);
    vector<string> B(m);

    for (int j = 0; j < m; j++) {
      int d = digit(A[j], i);
      C[d]++;
    }

    int count = 0;
    for (int j = 0; j < k; j++) {
      int tmp = C[j];
      C[j] = count;
      count += tmp;
    }

    for (int j = 0; j < m; j++) {
      int d = digit(A[j], i);
      B[C[d]] = A[j];
      C[d]++;
    }

    A = B;
  }
}

int main() {
  long long n, k, t;
  cin >> n >> k >> t;

  vector<string> messages(n);
  for (int i = 0; i < n; i++) {
    cin >> messages[i];
  }

  radixSort(messages, t, n);

  for (int i = 0; i < n; i++) {
    cout << messages[i] << endl;
  }

  return 0;
}
