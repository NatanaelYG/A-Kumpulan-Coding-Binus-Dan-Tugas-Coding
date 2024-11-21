import numpy as np
import time
import curses

# Game Variables
grid_height = 20
grid_width = 10
next_piece = True
game_over = False

# Scoring
lines_cleared = 0
score = 0

# Color Setup
colors = {
    'red': 1,
    'green': 2,
    'yellow': 3,
    'blue': 4,
    'magenta': 5,
    'cyan': 6,
    'white': 7,
}

# Shape Data
shape_data = {
    'O': {
        'coords': [(0, 0), (0, 1), (1, 0), (1, 1)],
        'color': 'yellow',
    },
    'I': {
        'coords': [(0, 2), (0, 1), (0, 0), (0, 3)],
        'color': 'cyan',
    },
    'S': {
        'coords': [(0, 1), (0, 2), (1, 0), (1, 1)],
        'color': 'green',
    },
    'Z': {
        'coords': [(0, 0), (0, 1), (1, 1), (1, 2)],
        'color': 'red',
    },
    'J': {
        'coords': [(0, 0), (0, 1), (0, 2), (1, 2)],
        'color': 'blue',
    },
    'L': {
        'coords': [(0, 2), (0, 1), (0, 0), (1, 0)],
        'color': 'magenta',
    },
    'T': {
        'coords': [(0, 1), (0, 0), (0, 2), (1, 1)],
        'color': 'white',
    },
}

def main(stdscr):
    # Curses Setup
    curses.curs_set(0)
    curses.init_pair(1, curses.COLOR_RED, curses.COLOR_BLACK)
    curses.init_pair(2, curses.COLOR_GREEN, curses.COLOR_BLACK)
    curses.init_pair(3, curses.COLOR_YELLOW, curses.COLOR_BLACK)
    curses.init_pair(4, curses.COLOR_BLUE, curses.COLOR_BLACK)
    curses.init_pair(5, curses.COLOR_MAGENTA, curses.COLOR_BLACK)
    curses.init_pair(6, curses.COLOR_CYAN, curses.COLOR_BLACK)
    curses.init_pair(7, curses.COLOR_WHITE, curses.COLOR_BLACK)

    # Create the grid
    grid = np.zeros((grid_height, grid_width))

    while not game_over:
        # Draw the grid
        for i in range(grid_height):
            for j in range(grid_width):
                if grid[i][j] == 0:
                    stdscr.addstr(i, j*2, ' ')
                else:
                    color = shape_data[next_piece]['color']
                    stdscr.attron(curses.color_pair(colors[color]))
                    stdscr.addstr(i, j*2, '[]')
                    stdscr.attroff(curses.color_pair(colors[color]))
        stdscr.refresh()

        # Control the pieces
        if next_piece:
            piece = next_piece
            next_piece = random.choice(list(shape_data.keys()))
            rotation = 0
            position = (grid_width // 2 - 1, 0)
        else:
            key = stdscr.getch()
            if key == ord('q'):
                break
            elif key == ord('a'):
                position = (position[0] - 1, position[1])
            elif key == ord('d'):
                position = (position[0] + 1, position[1])
            elif key == ord('s'):
                position = (position[0], position[1] + 1)
            elif key == ord('w'):
                rotation = (rotation + 1) % 4

        # Draw the new piece
        for coord in shape_data[piece]['coords']:
            new_coord = rotate(coord, rotation) + position
            if valid(new_coord, grid):
                grid[new_coord] = 1

        # Handle lines
        for i in range(grid_height):
            if all(grid[i]):
                grid = np.delete(grid, i, 0)
                grid = np.vstack((grid, np.zeros(grid_width))))
                lines_cleared += 1
                score += 100

        # Update the score
        stdscr.addstr(grid_height, 0, f'Score: {score}')
        stdscr.refresh()

        # Check for game over
        if np.any(grid[0]):
            game_over = True

        # Sleep
        time.sleep(0.2)

curses.wrapper(main)