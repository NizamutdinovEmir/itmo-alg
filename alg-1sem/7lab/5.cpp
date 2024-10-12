#include "iostream"
#include "string"

using namespace std;

void decode(string& s , string& s2 , int k) {
  int diff = 0;
  int diff1 = 0;
  int diff2 = 0;
  auto itPavel = s.begin();
  auto itVanya = s2.begin();
  while (itPavel != s.end() && itVanya != s2.end()) {
    char chPavel = *itPavel++;
    int countPavel = 0;

    while (itPavel != s.end() && isdigit(*itPavel)) {
      countPavel = countPavel * 10 + (*itPavel - '0');
      ++itPavel;
    }

    char chVanya = *itVanya++;
    int countVanya = 0;

    while (itVanya != s2.end() && isdigit(*itVanya)) {
      countVanya = countVanya * 10 + (*itVanya - '0');
      ++itVanya;
    }


    for (int i = 0; i < countPavel; ++i) {
      if (chPavel != chVanya) {
        ++diff1;
      }
    }
    for (int i = 0; i < countVanya; ++i) {
      if (chPavel != chVanya) {
        ++diff2;
      }
    }
    diff = max(diff1 , diff2);
    if (diff > k) {
      cout << "No";
      return;
    }
  }

  if (diff <= k) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int n , m , k;
  cin >> n >> m >> k;
  string first , second;
  cin >> first >> second;
  decode(first , second , k);
  return 0;

}