#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> findWords(vector<string> &words) {
    // FIXME
    return {};
  }
};

void TestFindWords() {
  Solution s;
  {
    vector<string> words{"Hello", "Alaska", "Dad", "Peace"};
    vector<string> expected{"Alaska", "Dad"};
    assert(expected == s.findWords(words));
  }
  {
    vector<string> words{"omk"};
    vector<string> expected;
    assert(expected == s.findWords(words));
  }
  {
    vector<string> words{"adsdf", "sfd"};
    vector<string> expected{"adsdf", "sfd"};
    assert(expected == s.findWords(words));
  }
}

int main() {
  TestFindWords();
  std::cout << "Ok!" << std::endl;
  return 0;
}
