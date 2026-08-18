# OpenGLPlayground

Open playground for developing components for a custom 3D game engine in C++. Built with Qt and OpenGL; open `PlaygroundModule.pro` in Qt Creator (or run qmake on it) to build.

Requires **OpenGL 4.2 Core Profile**. The context is requested in `main.cpp` (`QSurfaceFormat` version 4.2, core profile, 24-bit depth, 4x MSAA). Most shaders use GLSL `#version 410 core`; text and skybox fragment shaders use `#version 330 core`.

![Screen shots](https://github.com/GunnarKarlsson/OpenGLplayground/raw/master/ss1.png)

## Functionality

- Qt `QOpenGLWindow` game loop (init / update / render)
- Scene abstraction (`Scene` / `GameScene`)
- First-person camera (arrow keys move, left-mouse drag looks)
- Shader compile/load and lookup (`Shader` / `ShaderManager`)
- Asset loading from the Qt resource system (`AssetManager`)
- Textured cube with a point light (light shown as a small cube)
- Wavefront `.obj` model loading via Assimp (meshes with position, scale, rotation)
- Cubemap skybox
- FreeType font rendering for HUD text
- Textured 2D HUD quad

## Dependencies

- Qt (Widgets + OpenGL)
- [glm](https://glm.g-truc.net)
- [assimp](http://www.assimp.org/)
- [stb_image](https://github.com/nothings/stb) (bundled as `stb_image.h`)
- [freetype](https://www.freetype.org/)

## License

This project's source code is licensed under the [MIT License](LICENSE).

Third-party assets are **not** covered by that license. Models, textures, skybox images, and fonts remain under their original licenses from the sources listed below. Bundled third-party code such as `stb_image.h` also keeps its own license.

## Asset sources

- models and HUD tile from [Kenney](https://kenney.nl)
- skybox from [custommapmakers](http://www.custommapmakers.org/skyboxes.php)
- fonts from [1001 Free Fonts](https://www.1001freefonts.com)

## Project structure

Sibling directories expected next to this repo:

```
your_dir/
├── OpenGLPlayground/
├── glm/
├── assimp/
├── freetype/
```

## Building Assimp

```
git clone https://github.com/assimp/assimp.git
cd assimp
mkdir build
cd build
cmake ..
```
