#ifndef WORDLE_HELPER_WORDLIST_H
#define WORDLE_HELPER_WORDLIST_H

#include <istream>
#include <string>
#include <vector>

std::vector<std::string> read_wordlist(std::istream& wordlist_source);

#endif