# Developer Playground & Code Sandbox

> A personal development sandbox containing language experiments, syntax drills, and algorithm prototypes across various programming languages.

---

## 1. Overview & Context

This repository serves as a personal testing ground and educational sandbox for exploring programming languages, language-specific paradigms, algorithms, and interface frameworks. It contains exploratory code written in C, Python, Java, and upcoming experiments in Rust.

Key technologies utilized:
- **Languages:** C (C11), Python 3, Java, Rust
- **Paradigms & Frameworks:** Manual memory management in C, Object-Oriented GUI programming (Java Swing), 2D game loops (Python Arcade)

---

## 2. Architecture & Design

- **Core Components:**
  - `C/`: Low-level experiments covering pointers, dynamic memory allocation, and custom linked data structures.
  - `PYTHON/`: 2D arcade shooter game prototype exploring game loops, sprite movement, and event handling.
  - `JAVA/`: Implementation of Conway's Game of Life utilizing Java Swing for grid rendering.
  - `RUST/`: Reserved directory designated for upcoming low-level memory safety and concurrency exercises.
- **IPC / Protocols / Data Flow:**
  - Isolated standalone applications and scripts with direct console or graphical output.
- **Constraints / Design Decisions:**
  - Independent micro-projects with zero shared dependencies across subdirectories.

```
playground/
├── C/         ──► Manual memory management (structs, linked lists, strings)
├── PYTHON/    ──► Arcade 2D game loop prototype (arcade_shooter)
├── JAVA/      ──► Event-driven GUI & cellular automaton (Conway's Game of Life)
└── RUST/      ──► Upcoming systems programming experiments
```

---

## 3. Directory Structure

```text
.
├── C/                  # C language experiments
│   └── C_basics/       # Basic memory drills (structs, lists, strings)
├── JAVA/               # Java object-oriented experiments
│   └── src/            # Conway's Game of Life implementation in Swing
├── PYTHON/             # Python prototypes
│   └── arcade_shooter/ # 2D game loop prototype using Arcade library
├── RUST/               # Reserved for Rust systems programming experiments
├── .gitignore          # Git exclusion rules
└── README.md           # Documentation
```

---

## 4. Technical Deep-Dive / Key Features

### C Data Structures & Pointer Operations (`C/C_basics/`)
- **Path:** `C/C_basics/`
- **Domain & Tech:** C11, pointer arithmetic, memory allocation (`malloc`, `free`)
- **Implementation Details:** Small standalone examples practicing linked list manipulation (`list.c`), struct memory alignment and initialization (`struct.c`), and string scanning routines (`string.c`).

### Python Arcade Shooter (`PYTHON/arcade_shooter/`)
- **Path:** `PYTHON/arcade_shooter/Arcade_shoooter.py`
- **Domain & Tech:** Python 3, Arcade library, game loops
- **Implementation Details:** Implements a classic 2D scrolling arcade shooter. Handles keyboard input dispatching, continuous sprite rendering cycles, and basic collision detection algorithms.

### Conway's Game of Life in Java Swing (`JAVA/src/`)
- **Path:** `JAVA/src/Hra_zivot.java`
- **Domain & Tech:** Java, Swing GUI, cellular automata
- **Implementation Details:** Implements Conway's 2D cellular automaton. Manages a 2D state matrix, applies birth and survival rules on periodic tick intervals, and renders active cells on a responsive Swing canvas.

---

## 5. Prerequisites & Environment

- **OS / Platform:** Linux (Fedora, Ubuntu)
- **Compilers / Runtimes:** GCC (C11), Python 3.10+, OpenJDK 17+, Cargo / Rustc
- **System Dependencies / Daemons:** Python `arcade` library, Java Swing runtime

---

## 6. Build & Installation

```bash
# Clone the repository
git clone git@github.com:xLumar00/playground.git
cd playground

# Compile a C experiment
gcc -std=c11 -Wall -Wextra C/C_basics/list.c -o list_demo

# Install Python Arcade dependency for the shooter game
pip install arcade
```

---

## 7. Usage & Examples

```bash
# Execute compiled C linked list demo
./list_demo

# Launch Python arcade shooter prototype
python3 PYTHON/arcade_shooter/Arcade_shoooter.py

# Compile and run Java Conway's Game of Life
javac JAVA/src/Hra_zivot.java JAVA/src/NastavenieOkna.java
java -cp JAVA/src Hra_zivot
```

---

## 8. Engineering Post-Mortem & Known Issues

- **Inconsistent Build Tooling:** Subdirectories rely on manual compiler commands rather than centralized Makefiles or build configurations.
- **Absence of Automated Test Suites:** Toy experiments lack unit tests or automated regression suites.
- **Precompiled Binaries Removed:** Previous revisions retained compiled executable binaries; cleaned and replaced with strict `.gitignore` rules.

---

## 9. Roadmap & Future Improvements

- [ ] Implement Rust memory safety drills and CLI utilities in `RUST/`.
- [ ] Add simple Makefiles for the C exploration directory.
- [ ] Refactor Python game assets into standardized directory packaging.

---

## 10. Notes / Attribution

- **Author:** Marek Lupták (`xLumar00`)
- **License:** Educational / Personal Sandbox
