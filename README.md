# Wordle Helper

A C++20 CLI tool that filters a wordlist to find possible solutions for 
[Wordle](https://www.nytimes.com/games/wordle) puzzles based on known letter
positions and exclusions.

## Building

```bash
cmake -B build -S .
cmake --build build
```

The binary is produced at `build/wordle-helper`.

## Usage

```
wordle-helper -w WORDLIST -c CORRECT -m MISPLACED -a ABSENT
```

All options are required:

| Option | Description |
|---|---|
| `-w, --wordlist` | Path to a newline-separated list of words |
| `-c, --correct` | 5-character string of correctly placed letters. Use `*` for unknown positions |
| `-m, --misplaced` | 5-character string of misplaced letters (present but wrong position). Use `*` for unknown positions |
| `-a, --absent` | String containing all letters known to be absent from the solution |

### Example

If you know the word ends in `t`, has `r` somewhere in the first four positions,
and does **not** contain `a`, `e`, `i`, `o`, `u` or `s`:

```bash
build/wordle-helper \
  -w wordlist.txt \
  -c "****t" \
  -m "*r***" \
  -a "aeious"
```

## Preprocessing a wordlist

You can generate a wordlist for this CLI to use by running the
`preprocess_wordlist.sh` script using any common wordlist.

```bash
./preprocess_wordlist.sh /usr/share/dict/words wordlist.txt
```
