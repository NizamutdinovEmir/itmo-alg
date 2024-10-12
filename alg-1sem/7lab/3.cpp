#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

std::vector<int> answer(26, 0);

void quicksort(vector<int>& a, int l, int r) {
  int i = l;
  int j = r;
  int mid = a[(l+r) / 2];
  while (i <= j) {
    while ((a[i]) > (mid)) {
      i++;
    }
    while ((a[j]) < (mid)) {
      j--;
    }
    if (i <= j) {
      swap(a[i], a[j]);
      i++;
      j--;
    }
  }
  if (l < j) {
    quicksort(a, l, j);
  }
  if (i < r) {
    quicksort(a, i, r);
  }
}

vector<int> countarray(const string& a) {
  int maxim = 0;
  for (int i = 0; i < a.size(); ++i) {
    maxim = max(a[i] - 97, maxim);
  }
  vector<int> count(maxim + 1);
  for (int i = 0; i < a.size(); ++i) {
    count[a[i] - 97]++;
  }
  return count;
}

struct MinHeapNode {
  char data;
  int freq;
  MinHeapNode *left, *right;
  MinHeapNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

void siftdown(vector<MinHeapNode*>& heap, int i) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int smallest = i;

  if (left < heap.size() && heap[left]->freq < heap[smallest]->freq)
    smallest = left;

  if (right < heap.size() && heap[right]->freq < heap[smallest]->freq)
    smallest = right;

  if (smallest != i) {
    swap(heap[i], heap[smallest]);
    siftdown(heap, smallest);
  }
}

MinHeapNode* extractMin(vector<MinHeapNode*>& heap) {
  if (heap.empty()) return nullptr;

  MinHeapNode* minNode = heap[0];
  heap[0] = heap.back();
  heap.pop_back();

  siftdown(heap, 0);

  return minNode;
}

void buildHeap(vector<MinHeapNode*>& heap) {
  int n = heap.size();
  for (int i = (n / 2) - 1; i >= 0; --i) {
    siftdown(heap, i);
  }
}

void printCodes(MinHeapNode* root, string str) {
  if (!root) return;

  if (!root->left && !root->right) {
    answer[root->data - 97] = str.size();
  }

  printCodes(root->left, str + "0");
  printCodes(root->right, str + "1");
}

void HuffmanCodes(vector<pair<char, int>> nodes, int size) {
  vector<MinHeapNode*> heap;
  for (int i = 0; i < size; ++i) {
    heap.push_back(new MinHeapNode(nodes[i].first, nodes[i].second));
  }

  buildHeap(heap);

  while (heap.size() > 1) {
    MinHeapNode* left = extractMin(heap);
    MinHeapNode* right = extractMin(heap);

    MinHeapNode* top = new MinHeapNode('$', left->freq + right->freq);
    top->left = left;
    top->right = right;

    heap.push_back(top);
    buildHeap(heap);
  }
  printCodes(heap[0], "");
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  string s;
  cin >> s;
  int freqs[26]{0};

  for (int i = 0; i < s.size(); ++i) {
    freqs[(int)s[i] - 97]++;
  }

  std::vector<pair<char, int>> nodes;

  for (int i = 0; i < 26; ++i) {
    if (freqs[i] > 0) {
      nodes.push_back(make_pair((char)i + 97, freqs[i]));
    }
  }

  HuffmanCodes(nodes, nodes.size());

  int ans = 0;
  for (int i = 0; i < 26; ++i) {
    ans += freqs[i] * answer[i];
  }
  cout << ans;
}
