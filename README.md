# sdl-rpg-battle-system

A small game that just animates a few characters, and a menu to start and stop animation.
The purpose of this was to simplify an animation system I created for [another project](https://github.com/Reesy/tkyo-spaghetti)

A live example can be run here [Click me!](https://jim.wales/rpg.html)

<img src="rpg_pic.png" style="width: 500px" > 

## Supported platforms

|  Platform         |  Status   |
| ----------------- | --------- |
| Windows - MingGW  |   ✔️      |
| Windows - MSVC    |   ✔️      |
| OSX               |   ✔️      |
| Browser - Emscripten  | ✔️   |

## Cloning: 

Through CLI: 

```
git clone https://github.com/Reesy/sdl-rpg-battle-system
```


Graphically (this will also generate a project on your profile) 

![image](https://user-images.githubusercontent.com/5430483/159441936-843331ee-820d-4dad-af03-f1a1d31b3383.png)


## Building: 
This project has a dependency on SDL2 and SDL_image (which I have bundled under /libs) but can be found at libsdl.org.

<dl>
    <dt> Requirements<dt>
    <dd style='color:red'> CMake -- required to build this project </dd>
<dl>

To build a Visual Studios project (the .vcxproj file will be placed in the sdl2-emscripten-project-template/build folder)

```
cmake . -B build
```
    
To build a release on OSX or MinGW (if using ```-G "MinGW Makefiles"```):

```
cmake . -B build
make
```

To build for browser with Emscripten (requires emscripten installed and on the path): 

```
emcmake cmake . -B build 
```

To build with debug symbols (on OSX):
```
cmake -DCMAKE_BUILD_TYPE=Debug . -B build
make
```

<div style='color:red'> The 'resources' folder needs to exist in the same directory as the .exe file (on OSX it will be automatically bundled into the app</div>


## Manual building without CMake    

Manually building with MinGW for 32bit:

```
g++ ../src/main.cpp -o testApp \
    -I ../libs/mingw/SDL2-2.0.14/i686-w64-mingw32/include/SDL2  \
    -I ../libs/mingw/SDL2_image-2.0.5/i686-w64-mingw32/include/SDL2 \
    -L ../libs/mingw/SDL2-2.0.14/i686-w64-mingw32/lib/ \
    -L ../libs/mingw/SDL2_image-2.0.5/i686-w64-mingw32/lib/ \
    -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
```

Manually building with emscripten
```
    emcc src/main.cpp -s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -O3 -o index.js
```
    
    
## Building and hosting on the web

Serving the file using httpserver with Python 2: ```python -m SimpleHTTPServer 8080``` 

    
    
## Debugging
    
This project comes with a .vscode folder prebundled to make debugging easier, for this to work two plugins are necessary 

<dl>
    <dt> Recommended Plugins<dt>
    <dd style='color:green'>C/C++ Plugin </dd>
    <dd style='color:green'>CodeLLDB* </dd>
<dl>

\*CodeLLDB is only recommended for debugging on modern OSX versions

SDL2 can be found https://www.libsdl.org/

 
