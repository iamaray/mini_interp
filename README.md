# mini_interp

A small interpreter for an extremely simple "toy" programming language. The intepreter -- with its corresponding tokenization, lexing, and parsing -- is fully written in C.

## Toy Language Features

The toy language allows for the following very basic features:

- Variable assignment (int types only)
- While loops
- Basic mathematical operations (`+`, `-`, `*`, `/`)
- Printing to console
- Comments with `//` syntax
- Comparison operators (`==`, `!=`, `<=`, `<=`, `<`, `>`, `%`)

## To-Do

- [x] Implement tokenization and dynamic token list.
- [x] Implement lexer.
    - [x] Small lexing optimizations -- lookup table for single-char operators and switch statements.
- [ ] Implment parser.
    - [x] AST definition and basic operations.
    - [x] Global variables for token list navigation.
    - [ ] Parsing functionality.
