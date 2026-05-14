# Storm-Chess-Engine
uci compatible chess engine without ui

## goals:

### Bitboard representation
efficient piece encoding for fast move generation.
### Board state tracking
castling rights, en‑passant, halfmove clock, repetition detection.
### Move generation
start with pseudo‑legal moves, then filter into fully legal moves.
### Search algorithms
minimax/negamax as the baseline.

## advanced search and evaluation
### Alpha‑beta pruning
mandatory optimization for minimax/negamax.
### Move ordering
heuristics like killer moves, history heuristic.
### Quiescence search
avoid horizon effect by extending tactical positions.
### Transposition tables
hash positions to reuse results.
### Iterative deepening
improves move ordering and time management.
### Monte Carlo Tree Search
experimental alternative to minimax, more for exploration than functionality
### NNUE integration
neural network evaluation function, long term goal

## additional features
### Perft testing
validate move generation correctness.
### FEN/PGN parsing
load/save positions and games.
### UCI protocol
communicate with GUIs like Arena or Lichess.
### Time management
allocate search depth based on clock.
### Opening book
optional but can significantly boost engine rating
### Endgame tablebases
will need to store exact solutions for small endgames.

