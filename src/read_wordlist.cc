#include "read_wordlist.h"
#include <string>
#include <vector>

std::vector<std::string> read_wordlist(std::istream &wordlist_source) {
  std::vector<std::string> words;
  std::string line;

  while (std::getline(wordlist_source, line)) {
    words.push_back(line);
  }

  return words;
}