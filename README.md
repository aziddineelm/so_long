# 🎮 So Long

![42](https://img.shields.io/badge/42-Project-blue)
![C](https://img.shields.io/badge/Language-C-blue)
![Status](https://img.shields.io/badge/Status-Completed-success)

**So Long** is a 2D game project from the 42/1337 curriculum that challenges you to create an interactive game using the **MiniLibX** graphical library. Navigate through a maze, collect items, and reach the exit while avoiding obstacles! 

---

## 📋 **Project Description**

The objective of this project is to develop a small 2D game where:
- 🏃 The player moves within a grid-based map
- 💎 Collectibles must be gathered before the exit becomes accessible
- 🚪 The exit can only be used once all collectibles are obtained
- 🎨 Graphics are rendered using **MiniLibX**, a lightweight graphical library
- 🧠 Proper memory management ensures no leaks
- ⚡ Event handling for smooth keyboard controls

This project strengthens your skills in: 
- Graphics programming and rendering
- Event-driven programming
- File parsing and validation
- Memory management
- Pathfinding algorithms

---

## 🛠️ **How It Works**

The game reads a `.ber` map file that defines the layout with the following components:
- `1` - Walls (boundaries)
- `0` - Empty spaces (walkable area)
- `C` - Collectibles
- `E` - Exit
- `P` - Player starting position

The game uses **MiniLibX** to: 
1. Parse and validate the map structure
2. Load sprite images (XPM format)
3. Render the game window
4. Handle keyboard events
5. Update the display based on player movement

---

## 🚀 **Features**

### Mandatory
- ✅ Player movement using WASD or arrow keys
- ✅ Collectible system - gather all items before exit
- ✅ Move counter displayed in terminal
- ✅ Map validation (rectangular, walls, valid path)
- ✅ Proper error handling
- ✅ Memory leak prevention

### Bonus
- 🎯 Enemy and patrol mechanics
- 📊 On-screen move counter
- 🎨 Sprite animations

---

## 📂 **Repository Structure**

```plaintext
so_long/
├── src/
│   ├── finish. c              # Game ending logic
│   ├── get_next_line.c       # File reading utility
│   ├── get_next_line_utils.c # GNL helper functions
│   ├── map_check.c           # Map validation
│   ├── map_destroy.c         # Memory cleanup
│   ├── map_load.c            # Map parser
│   ├── map_render.c          # Rendering engine
│   ├── map_valid_path.c      # Pathfinding validation
│   ├── movements. c           # Player movement logic
│   ├── so_long.c             # Main program
│   ├── so_long.h             # Header file
│   └── utils.c               # Helper functions
│
├── sprites/                  # Game assets (XPM format)
│   ├── player.xpm
│   ├── wall.xpm
│   ├── collectible.xpm
│   └── exit.xpm
│
├── maps/                     # Map files
│   ├── map1.ber             # Example maps
│   └── map2.ber
│
└── Makefile                  # Build configuration
```

---

## 🕹️ **Controls**

| Key | Action |
|-----|--------|
| `W` / `↑` | Move Up |
| `A` / `←` | Move Left |
| `S` / `↓` | Move Down |
| `D` / `→` | Move Right |
| `ESC` | Quit the game |

---

## 🔧 **Installation & Execution**

### Prerequisites
- GCC compiler
- Make
- MiniLibX library
- Linux or macOS

### Build & Run

1. **Clone the repository:**
   ```sh
   git clone https://github.com/aziddineelm/so_long.git
   cd so_long
   ```

2. **Compile the program:**
   ```sh
   make
   ```

3. **Run the game with a map:**
   ```sh
   ./so_long maps/map1.ber
   ```

4. **Clean build files:**
   ```sh
   make clean    # Remove object files
   make fclean   # Remove all compiled files
   make re       # Recompile everything
   ```

---

## 🗺️ **Map Format**

### Valid Map Requirements
- Must be rectangular
- Surrounded by walls (`1`)
- Contains exactly one player (`P`)
- Contains exactly one exit (`E`)
- Contains at least one collectible (`C`)
- Must have a valid path from player to all collectibles and exit

### Example Map (`map. ber`)
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

---

## 📊 **Technical Details**

### Map Validation
The program performs comprehensive validation:
- ✓ File format check (`.ber` extension)
- ✓ Rectangular shape verification
- ✓ Wall enclosure check
- ✓ Component count validation
- ✓ Pathfinding algorithm (flood fill) to ensure winnable map

### Memory Management
- All allocated memory is properly freed
- Image resources are destroyed on exit
- No memory leaks (verified with `valgrind`)

---

## 🐛 **Error Handling**

The program handles various error cases:
- Invalid map format
- Missing components (P, E, or C)
- Non-rectangular maps
- Invalid characters
- No valid path to exit
- File reading errors

Example: 
```sh
./so_long invalid_map.ber
Error: Map is not enclosed by walls
```

---

## 🧪 **Testing**

Test your game with various map configurations:
```sh
./so_long maps/valid_map.ber      # Should work
./so_long maps/no_exit.ber        # Should show error
./so_long maps/invalid_path.ber   # Should show error
```

---

## 📚 **Resources**

- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)

---

## 👤 Author

**aziddineelm** - [GitHub Profile](https://github.com/aziddineelm)

## 👤 Author

**aziddineelm** - [GitHub Profile](https://github.com/aziddineelm)
