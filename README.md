# OpenGLPlayground

Starter-pack for experimenting with OpenGL in Qt. Contains some basic elements to get up and running:
+ flat shading with light source represented by small cube
+ textured cube
+ wavefront .obj model loading
+ skybox
+ mouse and keyboard input to move camera
+ font rendering
+ HUD quad with texture

![Screen shots](https://github.com/GunnarKarlsson/OpenGLplayground/raw/master/ss1.png)

Dependencies;
+ glm https://glm.g-truc.net
+ assimp http://www.assimp.org/
+ stb_image https://github.com/nothings/stb
+ freetype https://www.freetype.org/

Asset sources:
+ models and hud tile from kenney: https://kenney.nl
+ skybox from customapmakers http://www.custommapmakers.org/skyboxes.php
+ fonts from https://www.1001freefonts.com

Project structure:
```
your_dir/
├── OpenGLPlayground/
├── glm/
├── assimp/
├── freetype/
```

Misc:

How to build assimp
```
git clone https://github.com/assimp/assimp.git
cd assimp
mkdir build
cd build
cmake ..
```
