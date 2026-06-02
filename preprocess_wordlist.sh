#!/usr/bin/env bash

if [[ $# -ne 2 ]]; then
  echo "Usage: $0 <wordlist-path> <preprocessed-output-path>"
fi

WORDLIST_PATH=$1
PREPROCESSED_WORDLIST_OUTPUT_PATH=$2

cat ${WORDLIST_PATH} \
  | awk 'length($1) == 5 { print $1 }' \
  | tr A-Z a-z | grep -E '\w{5}' \
  > ${PREPROCESSED_WORDLIST_OUTPUT_PATH}
