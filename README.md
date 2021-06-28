# among3D
 Dynamic view inside a maze using ray-casting method. Inspired by the Among Us and the Wolfenstein 3D.
 
 ![Screenshot](/img/logo.png)


## Features
- Moving through the maze.
- Rotating the camera.
- Colliding with a walls.
- Presence of sprites.
- Shadows. 
- Minimap.
- Saving a screenshot (**--save** option as second argument). 

## Configurations
Programm uses a path to the config file as first argument. Through config file you can:
- Change player start position and spawning orientation.
- Change textures of walls and sprites.
- Change color of ceiling and floor.
- Change sprites positions.
- Change window size.
- Change map.

## Controls
- **WASD** to move
- **Left/Right** directional keys to rotate camera
- **ESC / red cross** to quit

## Quick start

```bash
git clone https://github.com/anvv5/among3D.git ; cd among3D ; make ; ./among3D default.map ;

```

