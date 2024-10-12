#include <iostream>
#include <cstdint>
#include <algorithm>
#include "vector"

using namespace std;

std::vector<long long> computePrimeFactors(long long number) {
  std::vector<long long> factors;

  for (long long i = 2; i * i <= number; ++i) {
    while (number % i == 0) {
      factors.push_back(i);
      number /= i;
    }
  }

  if (number > 1) {
    factors.push_back(number);
  }

  return factors;
}

void CountingSort(std::vector<long long>& arr) {
  if (arr.empty()) {
    return;
  }

  long long maxElement = *std::max_element(arr.begin(), arr.end());

  std::vector<long long> count(maxElement + 1, 0);

  for (long long num : arr) {
    count[num]++;
  }
  long long pos = 0;
  for (long long number = 0; number <= maxElement; ++number) {
    for (long long i = 0; i < count[number]; ++i) {
      arr[pos] = number;
      pos++;
    }
  }
}

void SiftUp(vector<long long>& arr, long long index) {
  while (index > 0 && arr[index] < arr[(index - 1) / 2]) {
    swap(arr[index], arr[(index - 1) / 2]);
    index = (index - 1) / 2;
  }
}

void SiftDown(vector<long long>& arr, long long size, long long index) {
  long long smallest = index;
  long long leftChild = 2 * index + 1;
  long long rightChild = 2 * index + 2;

  if (leftChild < size && arr[leftChild] < arr[smallest]) {
    smallest = leftChild;
  }

  if (rightChild < size && arr[rightChild] < arr[smallest]) {
    smallest = rightChild;
  }

  if (smallest != index) {
    swap(arr[index], arr[smallest]);
    SiftDown(arr, size, smallest);
  }
}

long long ExtractMin (vector<long long>& arr, long long n) {
  long long minim = arr[0];
  swap(arr[0] , arr[n-1]);
  arr.pop_back();
  SiftDown (arr, n - 1, 0);
  return minim;
}


void Insert(vector<long long>& arr , long long index ,  long long key) {
  arr.push_back(key);
  SiftUp(arr, index);
}

std::vector<long long> findPrimes(long long n) {
  std::vector<int> sieve(n + 1, 1);
  sieve[0] = sieve[1] = 0;

  std::vector<long long> prime(0);

  for (long long i = 2; i <= n; ++i) {
    if (sieve[i] == 1) {
      prime.emplace_back(i);

      for (long long k = i * i; k <= n; k += i) {
        sieve[k] = 0;
      }
    }
  }

  return prime;
}

vector<long long> prime = findPrimes(5000000);

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int number;
  cin >> number;

  vector<long long> primeans;

  vector <long long> ans;
  for (int i = 0;i<number;++i) {
    uint64_t primedel = ExtractMin(prime , prime.size());
    primeans.emplace_back(primedel);
    ans.push_back(primedel);
    Insert(prime, prime.size() - 1, primedel * primedel);
  }
  std::vector<std::vector<long long>> primeFactorsCache;
  vector<long long> otvet;
  for (int i = 0; i < ans.size(); ++i) {
    primeFactorsCache.push_back(computePrimeFactors(ans[i]));
  }

  for (int j = 0; j < ans.size(); ++j) {
    const std::vector<long long>& primeans = primeFactorsCache[j];

    for (int i = 0; i < primeans.size(); ++i) {
      otvet.push_back(primeans[i]);
    }
  }

  std::cout << otvet.size() << '\n';
  CountingSort(otvet);
  for (int i = 0; i < otvet.size(); ++i) {
    std::cout << otvet[i] << " ";
  }

  return 0;
}



