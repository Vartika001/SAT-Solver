<div id="top"></div>


<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>  <a href="#about-the-sat-solver">About The Project</a>    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
      </ul>
    </li>
    </ol>
</details>
<br>

<!-- ABOUT THE PROJECT -->
## About the Sat-solver
Sat-solver is written in cpp programming language.Implementation of SAT solver using Davis–Putnam–Logemann–Loveland (DPLL) algorithm.It is a complete, backtracking-based search algorithm for deciding the satisfiability of propositional logic formulae in conjunctive normal form, i.e. for solving the CNF-SAT problem.

## Heuristics
We have applied the following heuristics :-

1. Repeated Unit Propagation: Unit propagation is a procedure of automated theorem that can simplify a set of (usually propositional) clauses. We look out for unit clauses throughout the set of clauses. In our method, we follow repeated unit propagation i.e we follow the same process of eliminating unit clauses until we are left with no unit clauses. If the literal 'k' is present in any unit clause, we eliminate all the clauses containing 'k' and reduce the size of all the literals containing '-k' by eliminating '-k'. It is entirely based on the fact that a unit clause must be true in order to satisfy the formulae.

2. Elimination of singular clauses: They are the clauses with only one literal. Say, the literal present in the clause is 'a'. Then, 'a' would be asserted 'TRUE' and all the clauses containing 'a' would be eliminated. Now the literals '-a' are 'FALSE'. Therefore, they are eliminated from each and every clause.

<!-- GETTING STARTED -->
## Getting Started

To use the sat-solver programme, simply write the following command in your code editor terminal to compile the code
* npm
  ```sh
   g++ solver.cpp
  ```
Use the command given below to run the programme
* npm
  ```sh
   ./a.out
  ```

## Input format
The input is a cnf file in DIMACS format.

## Output format
The output will consist of three parts:

1. SATISFIABLE or UNSATISFIABLE.
2. A model if the formulae is SATISFIABLE.
3. Execution time in seconds.

   

## Prerequisites
1. g++ (or any other C++ compiler) with C++11 support
2. GNU make

<!-- ### THANK YOU -->
