# 🌊 Percolation Simulator
> **A high-performance C++ engine to visualize phase transitions and graph connectivity.**

![C++](https://img.shields.io/badge/C++-17-blue.svg) ![SFML](https://img.shields.io/badge/SFML-3.0-green.svg) ![License](https://img.shields.io/badge/License-MIT-lightgrey.svg)

## 📖 About The Project
This project simulates the **Percolation Threshold** problem using a dynamic grid system. It answers the fundamental question: *"If sites are independently open with probability $p$, at what threshold does the system become fully connected from top to bottom?"*

Built from scratch in **C++**, it features a custom **Union-Find data structure** to handle millions of dynamic connectivity checks in real-time, coupled with an interactive visualization using **SFML 3.0**.

### Key Features
* **⚡ Optimized Engine:** Uses *Weighted Quick-Union with Path Compression* for near-constant time $O(\alpha(N))$ connectivity checks.
* **🎮 Interactive Visualizer:** Real-time rendering of grid states (Blocked, Open, and Percolating/Full).
* **📈 Monte Carlo Simulation:** Validates the critical percolation threshold $p^* \approx 0.593$ experimentally.
* **🔥 Rain Mode:** Press `SPACE` to randomly open sites and watch the phase transition happen live.

---

## 🖼️ Demo

### 1. The Phase Transition (Visual)
*(Add your GIF of the simulation here)*
> *Cyan cells represent the "Giant Component" — water flowing from the virtual top source.*

### 2. The Math (Experimental Data)
*(Add your Python Sigmoid Graph here)*
> *The probability of percolation jumps sharply from 0 to 1 at exactly $p = 0.593$.*

---

## 🛠️ Technical Implementation

### Data Structures
The core of the simulation is the **Disjoint Set Union (DSU)**.
* **Virtual Sites:** To optimize percolation checks, the system uses a *Virtual Top* and *Virtual Bottom* node.
* **Complexity:**
    * `union()`: $O(\alpha(N))$
    * `connected()`: $O(\alpha(N))$
    * *Where $\alpha$ is the Inverse Ackermann function (effectively constant).*

### The Files
* `UnionFind.cpp`: The low-level data structure implementation.
* `Percolation.cpp`: Manages the $N \times N$ grid logic and mapping 2D coordinates to 1D indices.
* `visualizer.cpp`: The SFML graphics loop, handling user input and rendering sprites/shapes.
* `simulation.cpp`: A headless Monte Carlo runner to generate CSV data for statistical analysis.

---

## 🚀 Getting Started

### Prerequisites
* **C++ Compiler** (Clang or GCC) supporting C++17.
* **SFML 3.0** (Graphics Library).

**Installing SFML on macOS (Homebrew):**
```bash
brew install sfml


Installation
Clone the repo:
Bash
git clone [https://github.com/yourusername/percolation-sim.git](https://github.com/yourusername/percolation-sim.git)
cd percolation-sim


🏗️ Compiling & Running
1. The Visual Simulator: Use this command to link SFML correctly (adjust paths if not using Homebrew):

Bash
clang++ visualizer.cpp Percolation.cpp UnionFind.cpp -o visual_sim -std=c++17 \
-I/opt/homebrew/include \
-L/opt/homebrew/lib \
-lsfml-graphics -lsfml-window -lsfml-system

Run it:

Bash
./visual_sim





