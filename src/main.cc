#include "find_possible_words.h"
#include "read_wordlist.h"

#include <CLI/CLI.hpp>
#include <fstream>
#include <iostream>
#include <optional>
#include <string>

int main(int argc, char **argv) {
  CLI::App app{"Wordle Helper"};
  std::optional<std::string> wordlist_path;
  std::string_view correct_letters, misplaced_letters, absent_letters;
  argv = app.ensure_utf8(argv);

  app.add_option("-w,--wordlist", wordlist_path, "path to a wordlist to use");
  app.add_option("-c,--correct", correct_letters,
                 "Correctly placed letters in the word. Use `*` for any "
                 "letters that aren't correctly placed");
  app.add_option("-m,--misplaced", misplaced_letters,
                 "Letters that have been misplaced, but are still present in "
                 "the word. Use `*` for any letters that are not misplaced.");
  app.add_option("-a,--absent", absent_letters,
                 "All letters that are not present in the word");

  CLI11_PARSE(app, argc, argv);

  std::ifstream wordlist_file(*wordlist_path);
  const std::vector<std::string> wordlist = read_wordlist(wordlist_file);
  wordlist_file.close();

  const std::vector<std::string> &possible_words = find_possible_words(
      wordlist, correct_letters, misplaced_letters, absent_letters);
  if (possible_words.empty()) {
    std::cout << "Found no matching words..." << std::endl;
  }
  for (const auto &word : possible_words) {
    std::cout << word << std::endl;
  }
}