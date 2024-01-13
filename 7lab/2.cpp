#include <iostream>
#include <string>
#include <map>
#include <vector>

struct Node {
  int pos;
  char next;
};

std::vector<Node> LZ78(const std::string& message) {
  std::map<std::string , int> a;
  std::vector<Node> ans;
  std::string buff = "";
  for (int i = 0; i < message.size(); ++i) {
    if (a.find(buff + message[i]) != a.end()) {
      buff += message[i];
    } else {
      ans.push_back({a[buff], message[i]});
      a[buff + message[i]] = a.size();
      buff = "";
    }
  }

  if (!buff.empty()) {
    ans.push_back({a[buff], '\0'});
  }

  return ans;
}

int main() {
  std::string input;
  std::cin >> input;
  std::vector<Node> result = LZ78(input);

  for (const auto& node : result) {
    std::cout << node.pos << " " << node.next << '\n';
  }
  return 0;
}
