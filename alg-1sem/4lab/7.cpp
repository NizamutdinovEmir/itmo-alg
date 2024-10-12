#include <cinttypes>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#define int32_t long long

const int32_t kMax = 9;
const int32_t kNumberOfElements = 135;
const int32_t kBase = 1000000000;

struct int2023_t {
  uint32_t bytes[kNumberOfElements] = {0};
  int32_t highbit = -1;
};

int2023_t from_int(uint32_t i) {
  int2023_t ans;
  ans.bytes[0] = i % kBase;
  ans.bytes[1] = i / kBase;
  if (i > kBase - 1) {
    ans.highbit = 1;
  } else {
    ans.highbit = 0;
  }
  return ans;
}

int2023_t from_string(const std::string& buff) {
  int2023_t ans;
  std::string LineNotToLongBase = "";
  for (int i = buff.size() - 1; i >= 0; --i) {
    LineNotToLongBase += buff[i];
    if (LineNotToLongBase.size() == kMax || i == 0) {
      std::reverse(LineNotToLongBase.begin(), LineNotToLongBase.end());
      uint64_t b = stoull(LineNotToLongBase);
      ans.highbit++;
      ans.bytes[ans.highbit] = b;
      LineNotToLongBase = "";
    }
  }
  return ans;
}

int2023_t operator+(const int2023_t& lhs, const int2023_t& rhs) {
  int2023_t ans;
  uint64_t carry = 0;
  int32_t maxim = std::max(lhs.highbit, rhs.highbit);
  for (int32_t i = 0; i <= maxim + 1; ++i) {
    uint64_t sum = carry + lhs.bytes[i] + rhs.bytes[i];
    ans.bytes[i] = sum % kBase;
    carry = sum / kBase;
    ans.highbit = i;
  }

  if (ans.bytes[ans.highbit] == 0) {
    ans.highbit--;
  }
  return ans;
}

std::ostream& operator<<(std::ostream& stream, const int2023_t& value) {
  if (value.highbit == -1) {
    stream << 0;
  } else {
    stream << value.bytes[value.highbit];
    for (int32_t i = value.highbit - 1; i >= 0; --i) {
      stream << std::setfill('0') << std::setw(9) << (value.bytes[i]);
    }
  }
  return stream;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int32_t n;
  std::cin >> n;
  int2023_t sum = from_int(0);
  for (int32_t i = 0; i < n; ++i) {
    std::string temp;
    std::cin >> temp;
    int2023_t value = from_string(temp);
    sum = sum + value;
  }

  std::cout << sum;

  return 0;
}
