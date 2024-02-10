#include "galba.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <thread>

using namespace std;

vector<int> position; 
int N; 

void drawBoardAndQueens(); 

void render() {
    clear_window();
    drawBoardAndQueens(); 
    display();
}

bool isSafe(int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (position[i] == col || abs(position[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solveNQueensUtil(int row) {
    if (row == N) {
        render(); 
        this_thread::sleep_for(chrono::milliseconds(500)); 
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(row, col)) {
            position[row] = col; 
            render(); 
            this_thread::sleep_for(chrono::milliseconds(100)); 
            solveNQueensUtil(row + 1); 
            position[row] = -1; 
        }
    }
}

void drawBoardAndQueens() {
    int window_width = get_window_width();
    int window_height = get_window_height();
    int cellSize = min(window_width, window_height) / N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            Color cellColor = ((i + j) % 2 == 0) ? white : black;
            draw_rectangle(j * cellSize, i * cellSize, cellSize, cellSize, cellColor);
        }
    }

    for (int i = 0; i < N; ++i) {
        if (position[i] != -1) {
            int centerX = position[i] * cellSize + cellSize / 2;
            int centerY = i * cellSize + cellSize / 2;
            draw_circle(centerX, centerY, cellSize / 2, magenta);
        }
    }
}


int main() {
    cout << "Enter the number of queens: ";
    cin >> N;
    position.resize(N, -1); 

    initialize(720, 720, "N Queens Visualization");

    solveNQueensUtil(0); 

    while (is_window_open()) {
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    return 0;
}
