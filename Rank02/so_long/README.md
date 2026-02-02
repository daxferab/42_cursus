# 🎮 So Long - 42 School Project

Welcome to **So Long**! 🎉 This is an exciting project from **Rank 2** at 42 School that introduces us to **2D game programming** and **graphics libraries**. The goal is to create a simple 2D game where the player must collect all items and reach the exit, all while learning the fundamentals of game development and the MLX graphics library.

Build your own **2D top-down adventure game** with sprites, animations, and player controls! 🚀

---

### 📂 Project Structure

so_long/
├── include/so_long.h      # Header file (.h)  
├── src/                   # Source files (.c)  
│   ├── main.c             # Main program entry point  
│   ├── hook.c             # Input handling and game logic  
│   ├── errors.c           # Error handling and validation  
│   ├── free.c             # Memory management  
│   ├── initialize/        # Game initialization  
│   │   ├── draw_map.c     # Map rendering functions  
│   │   ├── draw_tools.c   # Drawing utilities  
│   │   └── init_map.c     # Map initialization  
│   └── parse/             # Map parsing and validation  
│       ├── arg_validation.c # Argument validation  
│       ├── map_utils.c    # Map utility functions  
│       ├── map_utils2.c   # Additional map utilities  
│       ├── map_is_player_exit.c # Player/exit validation  
│       └── map_validation.c # Map structure validation  
├── obj/                   # Object files directory  
├── lib/                   # External libraries  
│   ├── libft/             # Libft library  
│   └── mlx/               # MLX42 graphics library  
├── maps/                  # Game maps (.ber files)  
│   ├── small.ber          # Small test map  
│   ├── big.ber            # Large test map  
│   ├── maptry.ber         # Default test map  
│   └── error_maps/        # Invalid maps for testing  
├── textures/              # Game sprites and textures  
│   ├── player.png         # Player character sprite  
│   ├── collect.png        # Collectible item sprite  
│   ├── collected.png      # Collected item sprite  
│   ├── floor.png          # Floor tile sprite  
│   ├── wall*.png          # Wall tile sprites  
│   ├── closedExit.png     # Closed exit sprite  
│   └── openExit.png       # Open exit sprite  
├── .gitignore  
├── Makefile               # Makefile to compile the project  
└── README.md              # This file  

---

### 🎯 Game Mechanics

#### 🎮 Core Gameplay
- **Objective**: Collect all collectible items ('C') and reach the exit ('E')
- **Movement**: Use WASD or arrow keys to move the player ('P')
- **Win condition**: Collect all items, then reach the exit
- **Move counter**: Track the number of moves made
- **Real-time graphics**: Smooth 2D rendering with MLX42

#### 🗺️ Map Elements
- **`1`** - Wall (impassable terrain)
- **`0`** - Floor (walkable terrain)
- **`P`** - Player starting position (exactly one required)
- **`C`** - Collectible items (at least one required)
- **`E`** - Exit (exactly one required)

#### 🎨 Visual Features
- **Sprite-based graphics**: Custom PNG textures for all elements
- **Dynamic visuals**: Exit changes appearance when all items are collected
- **Tile-based rendering**: Each map cell displays appropriate sprite
- **Window management**: Proper window creation and event handling

---

### 🧠 Core Components

#### 🎯 Game Engine
- **Initialization**: Sets up MLX window, loads textures, parses map
- **Game loop**: Handles input, updates game state, renders graphics
- **Input handling**: Keyboard event processing for player movement
- **Rendering**: Efficient sprite drawing and map visualization

#### 🗺️ Map System
- **Map parsing**: Reads .ber files and validates format
- **Map validation**: Ensures valid game rules and structure
- **Collision detection**: Prevents movement through walls
- **Path validation**: Ensures map is solvable (all items and exit reachable)

#### 🎮 Player System
- **Movement logic**: Handles player position updates
- **Collision system**: Checks for valid moves
- **Item collection**: Tracks collected items and updates game state
- **Win detection**: Checks for victory conditions

---

## 🛠️ How to Use

### 📦 Compilation

To compile the game, run:

```bash
make
```

This will:
1. Compile libft library
2. Build MLX42 graphics library
3. Create the `so_long` executable

### 🧩 Usage

Launch the game with a map file:

```bash
./so_long [map_file.ber]
```

### 💡 Usage Examples

#### Basic Gameplay
```bash
# Play with the default test map
make run
# or
./so_long maps/maptry.ber

# Play with a small map
./so_long maps/small.ber

# Play with a larger map
./so_long maps/big.ber
```

#### Controls
- **W** or **↑** - Move up
- **A** or **←** - Move left  
- **S** or **↓** - Move down
- **D** or **→** - Move right
- **ESC** - Exit game
- **Red X** - Close window

---

## 🗺️ Map Format (.ber files)

### Map Rules
1. **Rectangular shape**: Maps must be rectangular
2. **Wall borders**: Maps must be surrounded by walls ('1')
3. **Required elements**:
   - Exactly one player ('P')
   - Exactly one exit ('E')
   - At least one collectible ('C')
4. **Valid path**: Player must be able to reach all collectibles and the exit
5. **Valid characters**: Only '0', '1', 'P', 'C', 'E' allowed

### Example Map
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

---

## ✅ Project Requirements

- ✅ Use MLX42 graphics library
- ✅ Create a 2D game with sprite graphics
- ✅ Implement player movement with WASD/arrow keys
- ✅ Display move counter in terminal
- ✅ Handle window events (close button, ESC key)
- ✅ Parse and validate .ber map files
- ✅ Ensure maps are solvable (valid path exists)
- ✅ Implement collectible items and exit mechanics
- ✅ No memory leaks
- ✅ Error handling for invalid maps/arguments

---

## 🎨 Graphics and Textures

### Sprite System
The game uses PNG textures for all visual elements:

- **Player sprite**: Animated character representation
- **Wall sprites**: Different wall variations (top, bottom, left, right, center)
- **Floor sprite**: Walkable ground texture
- **Collectible sprites**: Items to collect (with collected state)
- **Exit sprites**: Closed and open exit states

### Visual Design
- **Tile-based rendering**: Each map cell is 64x64 pixels
- **Consistent art style**: Cohesive visual theme
- **State-based graphics**: Visual feedback for game state changes

---

## 🚨 Error Handling

The game handles various error conditions:

- **Invalid arguments**: Wrong number of arguments
- **File errors**: Map file not found or unreadable
- **Map validation**: Invalid map structure or characters
- **Path validation**: Unreachable collectibles or exit
- **Graphics errors**: MLX initialization or texture loading failures
- **Memory allocation**: Out of memory conditions

All errors display descriptive messages and exit gracefully.

---

## 🧪 Testing & Validation

### Map Testing
```bash
# Test with valid maps
./so_long maps/small.ber
./so_long maps/big.ber

# Test with invalid maps (should show errors)
./so_long maps/error_maps/no_exit.ber
./so_long maps/error_maps/no_player.ber
./so_long maps/error_maps/no_collectibles.ber
```

### Gameplay Testing
- **Movement**: Test all direction keys
- **Collection**: Verify all items can be collected
- **Win condition**: Ensure game ends when all items collected and exit reached
- **Move counter**: Verify move count is accurate
- **Window events**: Test ESC key and close button

---

## 💡 Key Learning Objectives

- **Graphics Programming**: Introduction to 2D graphics and rendering
- **Event-Driven Programming**: Handling user input and window events
- **Game Development**: Basic game loop and state management
- **Memory Management**: Proper allocation and cleanup of graphics resources
- **File Parsing**: Reading and validating external file formats
- **Algorithm Design**: Pathfinding and map validation algorithms
- **Library Integration**: Working with external graphics libraries

---

## 🚀 Advanced Features

### Performance Optimizations
- **Efficient rendering**: Only redraw changed elements
- **Texture caching**: Load textures once at startup
- **Optimized collision detection**: Fast boundary checking

### Extensibility
The codebase is designed for easy extension:
- **Modular structure**: Separate parsing, rendering, and game logic
- **Configurable graphics**: Easy to swap textures
- **Scalable map system**: Support for different map sizes

---

## 🔍 Technical Details

### MLX42 Integration
- **Modern graphics**: Uses MLX42 for hardware-accelerated rendering
- **Cross-platform**: Compatible with modern systems
- **Event handling**: Robust input and window management

### Memory Management
- **Proper cleanup**: All allocated memory is freed
- **Error recovery**: Graceful handling of allocation failures
- **Resource management**: Textures and graphics resources properly managed

---

## 🎯 Game Development Tips

1. **Start simple**: Begin with basic movement and rendering
2. **Test incrementally**: Validate each feature as you build
3. **Handle errors**: Robust error checking prevents crashes
4. **Design for extension**: Modular code allows easy feature addition
5. **Optimize last**: Focus on functionality before performance

---

*Made with ❤️ at 42 Madrid*
