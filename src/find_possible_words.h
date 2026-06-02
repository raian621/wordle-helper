#ifndef WORDLE_HELPER_FIND_POSSIBLE_WORDS_H
#define WORDLE_HELPER_FIND_POSSIBLE_WORDS_H

#include <string>
#include <string_view>
#include <vector>

std::vector<std::string> find_possible_words(
    const std::vector<std::string> words, std::string_view correct_letters,
    std::string_view misplaced_letters, std::string_view absent_letters);

#endif