# mini_interp

A small interpreter for an extremely simple "toy" programming language. The intepreter -- with its corresponding tokenization, lexing, and parsing -- is fully written in C.

The ultimate goal is to slowly expand this into a GPU-accelerated language for scientific computing and deep learning.

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
- [ ] Implement parser.
    - [x] AST definition and basic operations.
    - [x] Global variables for token list navigation.
    - [ ] Parsing functionality.
- [ ] Enhance core language capabilities.
    - [ ] More numeric data types: floats, doubles, etc.
    - [ ] Custom typing (struct-like) functionality.
    - [ ] Functions
- [ ] Numerical computing capabilities.
    - [ ] Tensors & tensor manipulations.
    - [ ] Basic DL constructions (linear & conv layers, activation functs, etc.)
    - [ ] Comp. graph + autodiff.
    - [ ] A library of numerical algorithms (quadrature, FFT, etc.).
- [ ] GPU acceleration
    - [ ] CUDA interfacing.