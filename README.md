## cub3d

project of 42 school where it is necessary to create a game in C, similar to the famous game of the 90s Wolfeinstein 3D, which became the first FPS in history. the project was created using the minilibX graphics library. https://github.com/42Paris/minilibx-linux

the project is based on a first-person 3D representation of the maze using raycasting technology, similar to Wolfenstein 3D.

textures are assigned separately for each side. the map can be changed adhering to the rules of building a map.

all functions written in the project were implemented independently without using standard libraries.

the project was made in accordance with the school design code standard in the C language.

![](cub3d.gif)

### how to use
the project will work only on linux.
```
make
./cub3d map/map.cub
```
use `W` `A` `S` `D` to move and `←` `→` to rotate the camera. `esc` to close the game.

to take a screenshot before the game.
```
./cub3d map/map.cub --save
```
