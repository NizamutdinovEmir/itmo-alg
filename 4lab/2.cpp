#include "vector"
#include "iostream"
#include "string"
using namespace std;


vector<vector<int>> PriorityQueue;


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  string argument;

  while (cin >> argument){
    if (argument == "create"){
      PriorityQueue.emplace_back();
    } else if (argument == "insert") {
      int k , x;
      cin >> k >> x;
      PriorityQueue[k].push_back(x);
    } else if (argument == "extract-min") {
      int k;
      cin  >> k;
      if (PriorityQueue[k].empty()) {
        cout << "*" << '\n';
      } else {
        int min = PriorityQueue[k][0];
        int number_i = 0;
        for (int i = 1; i < PriorityQueue[k].size(); ++i) {
          if (PriorityQueue[k][i] < min) {
            min = PriorityQueue[k][i];
            number_i = i;
          }
        }
        cout << min << '\n';
        PriorityQueue[k].erase(PriorityQueue[k].begin() + number_i);

      }
    } else if (argument == "merge") {
      int k , m;
      cin >> k >> m;
      PriorityQueue.emplace_back();  
      auto& merged_queue = PriorityQueue.back();
      merged_queue.reserve(PriorityQueue[k].size() + PriorityQueue[m].size());
      merged_queue.insert(merged_queue.end(), PriorityQueue[k].begin(), PriorityQueue[k].end());
      merged_queue.insert(merged_queue.end(), PriorityQueue[m].begin(), PriorityQueue[m].end());
    }
    else if (argument == "decrease-key") {
      int k , x , y;
      cin >> k >> x >> y;
      for (int i = 0; i < PriorityQueue[k].size();++i) {
        if (PriorityQueue[k][i] == x) {
          PriorityQueue[k][i] = y;
          break;
        }
      }
    }
  }
  return 0;
}