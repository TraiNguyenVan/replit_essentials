# replit_essentials

Minimal C++17 starter for Replit — build with `make`, run with `make run-50`.

## Prereqs

- `g++` with C++17, `make`, `clangd` / `clang-tools` (see `replit.nix`)

## Layout

- `src/` — C++ sources
- `include/` — headers
- `data/` — CSV inputs (e.g. `data/contacts_50.csv`)
- `Makefile` — `all`, `run`, `run-50`, `run-100k`, `run-200k`, `run-1m`, `clean`
- `.clang-format` — Google-based style, 4-space indent, 100-col limit

## Quickstart

```bash
make
./build/cpp/demo data/contacts_50.csv
# or
make run-50
make clean
```
