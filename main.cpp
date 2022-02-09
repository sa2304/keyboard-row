#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> findWords(vector<string>& words) {
    vector<string> rows{
        "qwertyuiop"s,
        "asdfghjkl"s,
        "zxcvbnm"s
    };
    for (auto& row: rows) {
      sort(row.begin(), row.end());
    }

    vector<string> valid_words;
    string intersection;
    for (auto& word: words) {
      intersection.reserve(word.length());
      string letters = word;
      for_each(letters.begin(), letters.end(), [](char& c) {
        c = tolower(c);
      });
      sort(letters.begin(), letters.end());
      auto u = unique(letters.begin(), letters.end());
      letters.resize(distance(letters.begin(), u));

      for (const auto& alphabet: rows) {
        intersection.clear();
        set_intersection(alphabet.begin(), alphabet.end(),
                         letters.begin(), letters.end(),
                         back_inserter(intersection));
        if (0 < intersection.length()) {
          if (letters.length() == intersection.length()) {
            valid_words.push_back(word);
          }
          break;
        }
      }
    }

    return valid_words;
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
