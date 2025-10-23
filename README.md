# ♟️ N-Queens Visualization (SFML)

A visual backtracking demo that solves the **N-Queens problem** using **C++ + SFML**.  
Each step of the recursive search is rendered in real time, showing how queens are placed and removed on the board.

---

## 🧩 Overview
This program visualizes the process of solving the classic N-Queens puzzle —  
placing N queens on an N×N chessboard so that no two queens share the same row, column, or diagonal.

- Written in **C++17**
- Uses **SFML** for window rendering and simple shapes  
- Renders each recursion step dynamically with short delays  
- Shows backtracking visually as queens are removed and replaced  

---

## 🧠 Algorithm
Implemented with recursive **backtracking**:

```cpp
bool isSafe(int row, int col);
void solveNQueensUtil(int row);
