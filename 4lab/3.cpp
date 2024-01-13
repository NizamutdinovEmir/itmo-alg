#include <iostream>
#include <vector>
using namespace std;

struct Sher {;
  long long salary;
  long long time;
  bool work;
  Sher(long long salary , long long time , bool work) : salary(salary) , time(time) , work(work) {}
};


struct LegendaSherPovara {
  std::vector<Sher> povara;

  void siftdown(long long i) {
    while (2 * i + 1 < povara.size()) {
      long long left = 2 * i + 1;
      long long right = 2 * i + 2;
      long long j = left;
      if (right < povara.size() && (povara[right].salary < povara[left].salary)) {
        j = right;
      }
      if (povara[i].salary <= povara[j].salary) {
        break;
      }
      std::swap(povara[i], povara[j]);
      i = j;
    }
  }

  void siftup(long long i) {
    while (povara[i].salary < povara[(i - 1) / 2].salary) {
      std::swap(povara[i], povara[(i - 1) / 2]);
      i = (i - 1) / 2;
    }
  }

  Sher extract_min() {
    Sher min = povara[0];
    povara[0] = povara[povara.size() - 1];
    povara.pop_back();
    siftdown(0);
    return min;
  }

  void insert(long long salary , long long time , bool work = false) {
    povara.emplace_back(salary , time , work);
    siftup(povara.size() - 1);
  }

};


struct HochuSaurmu {
  std::vector<Sher> order;

  void siftdown(long long i) {
    while (2 * i + 1 < order.size()) {
      long long left = 2 * i + 1;
      long long right = 2 * i + 2;
      long long j = left;
      if (right < order.size()) {
        if (order[right].time < order[left].time) {
          j = right;
        } else if (order[right].time == order[left].time && !order[right].work) {
          j = right;
        }
      }
      if (order[i].time < order[j].time) {
        break;
      }
      if (order[i].time == order[j].time) {
        if (order[j].work) {
          break;
        }
      }
      std::swap(order[i], order[j]);
      i = j;
    }
    }


  void siftup(long long i) {
    while (order[i].time < order[(i - 1) / 2].time) {
      std::swap(order[i], order[(i - 1) / 2]);
      i = (i - 1) / 2;
    }
  }

  void insert(long long salary , long long time , bool work) {
    order.emplace_back(salary , time , work);
    siftup(order.size() - 1);
  }

  Sher extractmin() {
    Sher min = order[0];
    order[0] = order[order.size() - 1];
    order.pop_back();
    siftdown(0);
    return min;
  }
};

int main() {
  long long n, m;
  std::cin >> n >> m;

  LegendaSherPovara sherQueue;
  HochuSaurmu orderQueue;

  for (long long i = 0; i < n; ++i) {
    long long salary;
    std::cin >> salary;
    sherQueue.insert(salary,  0 , false);  
  }
  vector<long long> orders(m);
  long long t , f;
  for (long long i = 0;i < m;++i) {
    cin >> t >> f;
    orders[i] = f;
    orderQueue.insert(0, t, true);
  }
    long long answer = 0;
    long long dur_next = 0;
    while (!orderQueue.order.empty()) {
       Sher e = orderQueue.extractmin();
      if (e.work) {
        if (!sherQueue.povara.empty()) {
          Sher s = sherQueue.extract_min();
          answer += orders[dur_next] * s.salary;
          orderQueue.insert(s.salary , e.time+orders[dur_next] , false);
        }
        dur_next += 1;
      }
      else {
        sherQueue.insert(e.salary , 0 , false);
      }
    }
  std::cout << answer << std::endl;

  return 0;
}