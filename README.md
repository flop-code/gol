# gol
This is a C implementation of Conway's Game Of Live, that uses Raylib for graphics.

<div align="center"> 
  <img width="300px" src="https://i.postimg.cc/pXyftt8L/image2.jpg" alt="Screenshot1"/>
   <img width="300px" src="https://i.postimg.cc/MHLjGvRK/image.jpg" alt="Screenshot2"/>
  <i><p>Screenshots</p></i>
</div>

## Build & Run
Dependencies (should be in *PATH*):
- make
- wget
- gcc (*Linux / MacOS*) or mingw64 (*Windows*)
- tar (*Linux / MacOS*) or unzip (*Windows*)

### Linux / MacOS
Building is very simple and automized. First of all clone the project and cd into it.

Now run the following command:
```sh
make
```

For the first-time build it downloads Raylib's binary files (it automatically detects OS) using `wget`.

As a result, you will have the `gol` (*Linux / MacOS*) or `gol.exe` (*Windows*) output file generated, which you can run to start the game.

### Windows
Because of the use of Unix-specific terminal commands inside of the build system, there is no support for natively building for Windows in the current version.

**Consider using WSL or Cygwin**

However, if you have MinGW64 installed, you can cross-compile the project for Windows.

To do it, first of all clear currently installed Raylib binaries:

```sh
make clean
```

And then run the `make` with `target` argument setted to `Windows_NT`:

```sh
make target=Windows_NT
```

By default, it will use `x86_64-w64-mingw32-gcc` compiler to do this, but you can change it by providing `compiler` argument:

```sh
make target=Windows_NT compiler=mingw64-gcc
```

## Usage
The game is started in the edit mode, in which you can place or erase the cells out of the game field.

Hover and click on the left mouse button to draw a new cell, or click on the right mouse button to erase the cell.

Press the space bar to switch between edit and simulation mode.

While being in the edit mode, press on `H` key get a list of the hotkeys.

Have fun!

## Milestones
- [x] **v1.0**
- [x] Improve the build system
- [x] Add the "Help" window
- [x] Add the clear button
- [ ] Add the speed change button
- [ ] **v1.1**
