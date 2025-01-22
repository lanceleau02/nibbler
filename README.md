<div align="center">

![](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRmslJ_2rNASJmkAmLzxnABBjPo1Xj1Yz-ONw&s)

# **nibbler**

**C++ Project**

</div>

## Features

- Implement a Snake-like game with dynamic gameplay.
- Create a modular graphics system supporting multiple libraries (e.g., SDL, SFML, Raylib).
- Handle real-time user input for snake movement.
- Include a scoring system based on food collection.
- Manage game state transitions (start, play, pause, game over).
- Ensure smooth gameplay with adjustable speed and grid size.
- Maintain cross-platform compatibility for different environments.

## Installation

1. Clone the repository:

```bash
git clone https://github.com/lanceleau02/nibbler.git
```

2. Navigate to the project directory:

```bash
cd nibbler
```

The project provides two ways of installation, one uses Meson and the other uses Docker. 

### Using Meson

1. Setup the project:

```bash
make setup
```

2. Compile the program:

```bash
make
```

### Using Docker

1. Build the Docker:

```bash
make docker-build
```

2. Run the Docker:

```bash
make docker-run
```

## Usage

To run the program, you can use:

```bash
./nibbler <width> <height>
```

Or use the Makefile:

```bash
make run
```

## License

This project is licensed under the **42 School** License.

- **Educational Use Only**: This project is intended for educational purposes at the 42 School as part of the curriculum.
- **Non-commercial Use**: The code may not be used for commercial purposes or redistributed outside of the 42 School context.
- **No Warranty**: The project is provided "as-is", without any warranty of any kind.

For more details, see the [LICENSE](https://github.com/lanceleau02/nibbler/blob/main/LICENSE) file.

## Resources

- [Name mangling (C++ only) (IBM Documentation)](https://www.ibm.com/docs/en/i/7.5?topic=linkage-name-mangling-c-only)
- [C++ dlopen mini HOWTO (The Linux Documentation Project)](https://tldp.org/HOWTO/html_single/C++-dlopen/)
- [Documentation of SFML 2.6.1 (SFML)](https://www.sfml-dev.org/documentation/2.6.1/)
- [raylib (Raylib)](https://www.raylib.com/)
- [SDL2/FrontPage (SDL Wiki)](https://wiki.libsdl.org/SDL2/FrontPage)
- [Running Meson (The Meson Build system)](https://mesonbuild.com/Running-Meson.html)