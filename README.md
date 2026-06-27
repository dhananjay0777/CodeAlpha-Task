# CodeAlpha

Welcome to this repository! This collection features two fundamental C++ console applications that demonstrate file-system interaction, structure design, and classic programmatic problem-solving through backtracking algorithms.

---

## 🛠️ Included Applications

### 1. Authentication System
A complete user credential management platform compiled within the `logIn.cpp` file[cite: 1]. It handles localized state storage by reading and writing to an external flat-file database (`loginData.txt`)[cite: 1].

* **Sign-Up Pipeline:** Collects a unique username, validation email, and secure password from the user[cite: 1]. It parses and appends this data safely into the database utilizing asterisk delimiters (`*`)[cite: 1].
* **Login Verification:** Validates incoming user entries dynamically against the stored matrix inside the database file to grant or deny system access[cite: 1].
* **Credential Recovery:** Features an integrated "Forget Password" path that securely retrieves an account password if the matching username and email fields pass validation[cite: 1].

### 2. Matrix Sudoku Solver
An optimized, recursive computational algorithm built inside the `suduku_solver.cpp` file that instantly solves standard 9x9 puzzle grids[cite: 2].

* **Backtracking Engine:** Systematically scans rows and columns for empty spaces (`0`) and recursively samples numbers 1 through 9 to seek a valid computational matrix path[cite: 2].
* **Safety Constraint Matrix:** Evaluates target coordinates instantly against horizontal rows, vertical columns, and regional 3x3 grid spaces to ensure strict alignment with puzzle logic rules before final placement[cite: 2].

---

## 🚀 Execution & Compilation

Ensure you have a standard C++ compiler installed (like `g++`). Use the terminal commands below to compile and execute each individual file.

### Running the Authentication System
```bash
g++ logIn.cpp -o logIn
./logIn
