#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point blocks[4];
} Tetromino;

int board[BOARD_HEIGHT][BOARD_WIDTH];

void clearBoard() {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = 0;
        }
    }
}

void drawBoard() {
    system("clear");

    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (board[i][j] != 0) {
                printf("[]");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void drawTetromino(Point blocks[4]) {
    for (int i = 0; i < 4; i++) {
        int x = blocks[i].x;
        int y = blocks[i].y;
        board[y][x] = 1;
    }
}

void moveTetromino(Point blocks[4], int dx, int dy) {
    for (int i = 0; i < 4; i++) {
        blocks[i].x += dx;
        blocks[i].y += dy;
    }
}

int checkCollision(Point blocks[4]) {
    for (int i = 0; i < 4; i++) {
        int x = blocks[i].x;
        int y = blocks[i].y;

        if (x < 0 || x >= BOARD_WIDTH || y >= BOARD_HEIGHT || board[y][x] != 0) {
            return 1; // Collision with walls or existing blocks
        }
    }

    return 0; // No collision
}

void mergeTetromino(Point blocks[4]) {
    for (int i = 0; i < 4; i++) {
        int x = blocks[i].x;
        int y = blocks[i].y;

        if (y >= 0) {
            board[y][x] = 1; // Mark the cell as occupied
        }
    }
}

void rotateTetromino(Point blocks[4]) {
    // Simple rotation for demonstration (not recommended for a real game)
    // Rotate by swapping x and y values
    for (int i = 0; i < 4; i++) {
        int temp = blocks[i].x;
        blocks[i].x = blocks[i].y;
        blocks[i].y = temp;
    }
}

void clearLines() {
    for (int i = BOARD_HEIGHT - 1; i >= 0; i--) {
        int lineFull = 1;

        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (board[i][j] == 0) {
                lineFull = 0;
                break;
            }
        }

        if (lineFull) {
            // Clear the full line
            for (int k = i; k > 0; k--) {
                for (int j = 0; j < BOARD_WIDTH; j++) {
                    board[k][j] = board[k - 1][j];
                }
            }

            // Clear the topmost line
            for (int j = 0; j < BOARD_WIDTH; j++) {
                board[0][j] = 0;
            }

            i++; // Recheck the current line
        }
    }
}

int main() {
    srand(time(NULL));

    while (1) {
        clearBoard();

        Point blocks[4] = {
            {BOARD_WIDTH / 2, 0},
            {BOARD_WIDTH / 2, 1},
            {BOARD_WIDTH / 2, 2},
            {BOARD_WIDTH / 2, 3}
        };

        int gameOver = 0;

        while (!gameOver) {
            drawBoard();
            drawTetromino(blocks);

            char key = getchar();
            switch (key) {
                case 'a':
                    moveTetromino(blocks, -1, 0);
                    if (checkCollision(blocks)) {
                        moveTetromino(blocks, 1, 0);
                    }
                    break;
                case 'd':
                    moveTetromino(blocks, 1, 0);
                    if (checkCollision(blocks)) {
                        moveTetromino(blocks, -1, 0);
                    }
                    break;
                case 's':
                    moveTetromino(blocks, 0, 1);
                    if (checkCollision(blocks)) {
                        moveTetromino(blocks, 0, -1);
                        mergeTetromino(blocks);
                        clearLines();
                        gameOver = 1; // For simplicity, end the game after one piece
                    }
                    break;
                case 'w':
                    rotateTetromino(blocks);
                    if (checkCollision(blocks)) {
                        // If rotation causes collision, revert the rotation
                        rotateTetromino(blocks);
                        rotateTetromino(blocks);
                        rotateTetromino(blocks);
                    }
                    break;
                case 'q':
                    gameOver = 1;
                    break;
            }
        }
    }

    return 0;
}

