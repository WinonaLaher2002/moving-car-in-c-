# 🚗 Moving Car with Rain — Version 2 (Modern C++)

> **Version 2** of the Moving Car project, rewritten from **Turbo C++** (Version 1) to **Modern C++ using SFML**.

---

## 📋 About the Project

This project simulates an animated moving car with rain using modern C++ graphics.  
It was originally written in **Turbo C++ (Version 1)** using old BGI graphics libraries, and has now been upgraded to **Modern C++ with SFML (Version 2)**.

---

## 🔄 Version History

| Version | Language | Graphics Library | Platform |
|---------|----------|-----------------|----------|
| v1 | Turbo C++ | BGI (`graphics.h`) | DOS / Windows (Turbo C++ 3.0) |
| v2 | Modern C++ (C++17) | SFML | Windows / Linux / macOS |

---

## ✨ Features

- 🌧️ Animated rain drops falling from the sky
- 🚗 Car with body, roof, and wheels drawn using SFML shapes
- 🎨 Random car color every frame
- 🛣️ Dark gray road at the bottom of the screen
- ⌨️ Press any key to exit

---

## 🔧 What Changed from Version 1 to Version 2

| Version 1 (Turbo C++) | Version 2 (Modern C++) |
|----------------------|----------------------|
| `#include <graphics.h>` | `#include <SFML/Graphics.hpp>` |
| `#include <conio.h>` | Standard `sf::Event` |
| `#include <dos.h>` | Removed |
| `void main()` | `int main()` |
| `initgraph()` | `sf::RenderWindow` |
| `fillellipse()` | `sf::CircleShape` |
| `kbhit()` | `sf::Event::KeyPressed` |
| `delay(100)` | `setFramerateLimit(10)` |
| `randomize()` / `random()` | `srand()` / `rand()` |
| Runs only on DOS/Turbo C++ | Runs on Windows, Linux, macOS |

---

## 🚀 How to Run

### Requirements
- C++17 compatible compiler (`g++` or `MSVC`)
- [SFML Library](https://www.sfml-dev.org/) installed

### Linux / Ubuntu
```bash
# Install SFML
sudo apt-get install libsfml-dev

# Compile
g++ -o main main.cpp -lsfml-graphics -lsfml-window -lsfml-system

# Run
./main
```

### Windows
```bash
# Download SFML from https://www.sfml-dev.org/download.php
# Then compile:
g++ -o main main.cpp -lsfml-graphics -lsfml-window -lsfml-system
main.exe
```

---

## 🗂️ Project Structure

```
moving-car-in-c/
├── main.cpp                        # Main source code (Modern C++ + SFML)
├── .github/
│   └── workflows/
│       └── c-cpp.yml               # GitHub Actions CI workflow
└── README.md                       # This file
```

---

## ⚙️ GitHub Actions CI

This project uses **GitHub Actions** to automatically build and verify the code on every push.

```yaml
- Install SFML on Ubuntu
- Compile main.cpp with g++
- Verify binary exists
```

✅ Build status: Passing

---

## 👩‍💻 Author

**WinonaLaher2002**  
GitHub: [github.com/WinonaLaher2002](https://github.com/WinonaLaher2002)

---

## 📝 License

This project is for educational purposes.
