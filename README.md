# 🎮 Doodle Jump – SDL-Based 2D Platformer Game

A faithful recreation of the classic **Doodle Jump** arcade-style game developed using **C++** and **SDL2 (Simple DirectMedia Layer)**. This project features real-time platform physics, dynamic background rendering, and sprite animation — designed to provide a smooth, responsive gameplay experience in a 2D vertical-scrolling world.

---

## 🧩 Motivation

Game development offers a rich ground for applying and improving programming skills — from object-oriented design and memory management to event-driven systems and graphics rendering. This project was undertaken as a personal challenge to **build a full game from scratch** using low-level graphics handling, while recreating the addictive mechanics of a well-known game.

---

## 🕹️ Features

- 🟩 **Jumping Mechanics**: Responsive jump logic that emulates vertical bouncing based on player velocity and gravity.
- 🧱 **Procedural Platform Generation**: New platforms are generated as the player ascends, creating an infinite-scrolling experience.
- 🪂 **Collision Detection**: Accurate player-to-platform collision system to detect landings and prevent falling through.
- 🌌 **Scrolling Background**: Simulates vertical progression by scrolling elements downward as the player climbs.
- 🎨 **Custom Sprites**: Uses bitmap images for player, background, and platform graphics, loaded via SDL surfaces.
- 🎯 **Game Over Handling**: Detects when the player falls off-screen and gracefully ends the session.

---

## 🔧 Technologies Used

- **C++** – Core game logic and object-oriented design.
- **SDL2** – Handles rendering, input, surfaces, and textures.
- **Bitmap Graphics** – For lightweight and fast asset loading.
- **Object-Oriented Design** – Classes for player, platform, and game environment.

---

## 🧪 Learning Outcomes

- Proficiency in **SDL2 rendering pipeline** and **surface-to-texture management**
- Understanding of **game physics**, especially gravity and bounce simulation
- Development of a **real-time input and rendering loop**
- Deeper experience in **structuring a non-trivial C++ application**

---

## 🚀 How to Run

1. Make sure **SDL2** is installed on your system (headers and libraries).
2. Clone this repository:
   ```bash
   git clone https://github.com/Farbod-Pourreza/Doodle-jump.git
   cd Doodle-jump
3. Compile the source code:
   ```bash
   g++ main.cpp -o DoodleJump -lSDL2
   
   You may need to adjust include/linker flags depending on your setup.

4. Run the game:
   ```bash
   ./DoodleJump
