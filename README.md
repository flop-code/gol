# gol
This is a C implementation of Conway's Game Of Live, that uses Raylib for graphics.

<div align="center"> 
  <img width="300px" src="https://i.postimg.cc/pXyftt8L/image2.jpg" alt="Screenshot1"/>
   <img width="300px" src="https://i.postimg.cc/MHLjGvRK/image.jpg" alt="Screenshot2"/>
  <i><p>Screenshots</p></i>
</div>

## Build & Run
Dependencies (should be in *PATH*):
- git
- gcc

### Linux / BSD / MacOS
First of all, clone the project and cd into it.

For the first-time build, you will need to fetch and build Raylib.
The build system can do it automatically, you just need to run the following command:

```sh
make build_raylib
```

It uses Git to clone a specific part of the Raylib repo and then compiles it using GCC.

As a result, you will have 2 generated files inside of the `lib` directory, which then will be used to build the project.

To build the project, run the following command:

```sh
make
```

As a result of this step, you will have the `main.out` file generated, which you can run to start the game.

### Windows
There is no support for Windows in the current version of the build system.

**Consider using WSL or Cygwin to emulate the Linux environment.**

But if you still want to build it natively, follow the steps below:

You still can run the `download_raylib` target to fetch Raylib sources:

```sh
make download_raylib
```

This command will fetch the sources and place them into the `raylib/src` directory.

Then you need to build the Raylib, and place the `raylib.h` header and `libraylib.lib` files inside of the `lib` directory.

Then compile the project (also including `lib/raylib.h` header and link it with `opengl32`, `gdi32`, `winmm`, and `lib/libraylib.lib` itself).

## Usage
The game is started in the edit mode, in which you can place or erase the cells out of the game field.

Hover and click on the left mouse button to draw a new cell, or click on the right mouse button to erase the cell.

Press the space bar to switch between edit and simulation mode.

Have fun!

## Milestones
- [x] **v1.0**
- [ ] Add the releases.
- [x] Add the clear button.
- [ ] Add the speed change button.
- [ ] Make the window resizable and adaptive.
- [ ] **v1.1**
