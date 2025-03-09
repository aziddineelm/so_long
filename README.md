# So Long

**So Long** is a project from the 42/1337 curriculum that involves creating a simple 2D game using the **MiniLibX** graphical library. The goal is to navigate a character through a map, collecting items and reaching the exit while avoiding enemies.

---

## 📋 **Project Description**  
The objective of this project is to develop a small game where:
- The player moves within a grid-based map.
- The game includes collectibles that the player must gather before reaching the exit.
- Basic enemy mechanics may be implemented to increase difficulty.
- The game is displayed using **MiniLibX**, a lightweight graphical library.
- The program follows proper memory management to prevent leaks.

This project strengthens your skills in handling graphics, managing events, and optimizing game logic in C.

---

## 🛠️ **How It Works**  
The game reads a map file that defines the layout, including walls, collectibles, the player, and the exit. Using **MiniLibX**, it renders the map and allows the player to move using keyboard inputs.

---

## 🚀 **Features**  
- Player movement using keyboard controls.
- Collectibles that must be gathered before exiting.
- Basic enemy AI (optional for bonus).
- Real-time rendering using **MiniLibX**.
- Efficient memory handling to prevent leaks.

---

## 📂 **Repository Structure**  

```plaintext
.
├── src
│   ├── finish.c
│   ├── get_next_line.c
│   ├── get_next_line_utils.c
│   ├── map_check.c
│   ├── map_destroy.c
│   ├── map_load.c
│   ├── map_render.c
│   ├── map_valid_path.c
│   ├── movements.c
│   ├── so_long.c
│   ├── so_long.h
│   ├── utils.c
│
├── sprites
│   ├── player.xpm
│   ├── wall.xpm
│   ├── collectible.xpm
│   ├── exit.xpm
│   ├── ...
├── maps
│   ├── map1.ber
│   ├── map2.ber
│
└── Makefile
```

---

## 🕹️ **Controls**  
- `W` / `↑` - Move Up  
- `A` / `←` - Move Left  
- `S` / `↓` - Move Down  
- `D` / `→` - Move Right  
- `ESC` - Quit the game  

---

## 🔧 **Installation & Execution**  
1. Clone the repository:  
   ```sh
   git clone https://github.com/yourusername/so_long.git
   cd so_long
   ```  
2. Compile the program:  
   ```sh
   make
   ```  
3. Run the game with a map file:  
   ```sh
   ./so_long maps/map1.ber
   ```  

---

## 📜 **Credits**  
This project is part of the **42/1337 curriculum** and was developed using **MiniLibX**. Special thanks to the 42 community for guidance and resources!

