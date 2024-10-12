#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

struct Segment {
  long double left;
  long double right;
};

std::vector<Segment> defineSegments(const std::vector<char>& letters, const std::vector<double>& probability) {
  std::vector<Segment> segment(letters.size());
  double l = 0;
  for (int i = 0; i < letters.size(); ++i) {
    segment[i].left = l;
    segment[i].right = l + probability[i];
    l = segment[i].right;
  }
  return segment;
}

long double arithmeticCoding(const std::vector<char>& letters, const std::vector<double>& probability, const std::string& s) {
  std::vector<Segment> segment = defineSegments(letters, probability);
  long double left = 0;
  long double right = 1;
  for (int i = 0; i < s.size(); ++i) {
    double new_right = left + (right - left) * segment[s[i] - 97].right;
    double new_left = left + (right - left) * segment[s[i] - 97].left;
    left = new_left;
    right = new_right;
  }
  return left;
}

int main() {
  std::string s;
  std::cin >> s;
  std::vector<char> letters;
  int count[26]{};
  for (char i : s) {
    count[i - 97]++;
  }


  std::vector<double> probability;
  for (int i = 0;i < 26;++i) {
    letters.push_back(i+97);
    probability.push_back((double) count[i] / s.size());
  }



  long double result = arithmeticCoding(letters, probability, s);
  std::cout << std::fixed << std::setprecision(10) << result << std::endl;

  return 0;
}
