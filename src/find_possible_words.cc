#include "find_possible_words.h"

#include <algorithm>
#include <map>
#include <ranges>
#include <set>
#include <string>
#include <string_view>

bool matches_correct_letters(std::string_view word,
                             std::string_view correct_letters) {
  return word.size() == correct_letters.size() &&
         std::ranges::all_of(std::views::iota((size_t)0, word.size()),
                             [&correct_letters, &word](const size_t i) {
                               return correct_letters[i] == '*' ||
                                      correct_letters[i] == word[i];
                             });
}

bool contains_no_absent_letters(std::string_view word,
                                const std::set<char> &absent_letters) {
  return std::ranges::none_of(word, [&absent_letters](const char c) {
    return absent_letters.contains(c);
  });
}

bool matches_misplaced_letters(std::string_view word,
                               std::string_view misplaced_letters) {
  if (word.size() != misplaced_letters.size()) {
    return false;
  }

  if (!std::ranges::none_of(std::views::iota((size_t)0, word.size()),
                            [&word, &misplaced_letters](const size_t i) {
                              return word[i] == misplaced_letters[i];
                            })) {
    return false;
  }

  std::map<char, size_t> word_letter_count, misplaced_letter_count;
  for (size_t i = 0; i < word.size(); i++) {
    const char c1 = word[i], c2 = misplaced_letters[i];
    if (auto it = word_letter_count.find(c1); it == word_letter_count.end()) {
      word_letter_count[c1] = 0;
    }
    word_letter_count[c1]++;
    if (c2 == '*') {
      continue;
    }
    if (auto it = misplaced_letter_count.find(c2);
        it == misplaced_letter_count.end()) {
      misplaced_letter_count[c2] = 0;
    }
    misplaced_letter_count[c2]++;
  }

  // If the letter count for a given letter is less in the word than in the
  // misplaced letters, return false
  for (const auto &[letter, count] : misplaced_letter_count) {
    if (auto it = word_letter_count.find(letter);
        it == word_letter_count.end() || it->second < count) {
      return false;
    }
  }

  return true;
}

std::vector<std::string> find_possible_words(
    const std::vector<std::string> words, std::string_view correct_letters,
    std::string_view misplaced_letters, std::string_view absent_letters) {
  const std::set<char> absent_letters_set(absent_letters.begin(),
                                          absent_letters.end());

  auto v = words |
           std::views::filter([&absent_letters_set](const std::string &word) {
             return contains_no_absent_letters(word, absent_letters_set);
           }) |
           std::views::filter([&correct_letters](const std::string &word) {
             return matches_correct_letters(word, correct_letters);
           }) |
           std::views::filter([&misplaced_letters](const std::string &word) {
             return matches_misplaced_letters(word, misplaced_letters);
           });

  std::vector<std::string> possible_words;
  for (const std::string &c : v) {
    possible_words.push_back(c);
  }

  return possible_words;
}