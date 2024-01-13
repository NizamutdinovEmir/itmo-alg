#include <iostream>
#include <vector>
#include <string>
using namespace std;

void merge(vector<pair<long long, long long>>& a, long long left, long long mid, long long right) {
  long long it1 = 0, it2 = 0;
  vector<pair<long long, long long>> temp(right - left);

  while (left + it1 < mid && mid + it2 < right) {
    if (a[left + it1].first > a[mid + it2].first || (a[left + it1].first == a[mid + it2].first && a[left + it1].second >= a[mid + it2].second)) {
      temp[it1 + it2] = a[left + it1];
      it1 += 1;
    } else {
      temp[it1 + it2] = a[mid + it2];
      it2 += 1;
    }
  }

  while (left + it1 < mid) {
    temp[it1 + it2] = a[left + it1];
    it1 += 1;
  }

  while (mid + it2 < right) {
    temp[it1 + it2] = a[mid + it2];
    it2 += 1;
  }

  for (int i = 0; i < it1 + it2; ++i) {
    a[left + i] = temp[i];
  }
}

void mergeSort(vector<pair<long long, long long>>& a, long long left, long long right) {
  if (left + 1 < right) {
    long long mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  long long n;
  cin >> n;
  vector<pair<long long, long long>> rating(n);
  vector<pair<long long, long long>> gonorar(n);

  for (long long i = 0; i < n; ++i) {
    long long cod, rat, gon;
    cin >> cod >> rat >> gon;
    rating[i] = {rat, cod};
    gonorar[i] = {gon, cod};
  }

  string ans;
  long long m;
  cin >> m;
  vector<bool> ansCities(m);

  for (long long i = 0; i < m; ++i) {
    cin >> ans;
    ansCities[i] = (ans == "YES");
  }

  mergeSort(rating, 0, n);
  mergeSort(gonorar, 0, n);

  vector<long long> cities;
  vector<long long> call;
  long long index = 0;
  int index2 = 0;
  for (int index1 = 0;index1 < n;++index1) {
    long long codeRat = rating[index1].second;
    long long codeGon = gonorar[0].second;

    if (codeGon == codeRat) {
      cities.push_back(codeRat);
      gonorar.erase(gonorar.begin());
    } else {
      if (index != m) {
        call.push_back(codeRat);
        if (ansCities[index]) {
          cities.push_back(codeRat);
        }
        index++;
      }
    }
  }

  for (long long code : call) {
    cout << code << " ";
  }
  cout << "\n";
  for (long long city : cities) {
    cout << city << " ";
  }

  return 0;
}
