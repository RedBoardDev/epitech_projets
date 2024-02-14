<h1 align="center">RayTracer</h1>

A 3D Rendering Engine, made modulable & extensible with the use of .so files

> Read `./doc/implementation.md` to learn about how you can implement your own primitives / components into the rendering engine.

# Usage

    1. make
    2. ./raytracer [scene file path]

# Features

* 3D Rendering
* Modulable & Extensible
* Configurable Scenes

# Scenes

You can find some scenes example files in Core/Parzer/scenes, you can also create your own scenes files.

To do so, follow the syntax in the example files, you can add the following primitives :

* Sphere
* Plane

You can also add the following components :

* Light (ambient & directional)

Please note that it is **mandatory** to add a camera component to your scene, otherwise you won't render anything.

# Architecture

TODO

# Authors

### Léo Baldachino

* Github: [@Leo Leo](https://github.com/LeoBaldachino)
* Mail: leo.baldachino@epitech.eu

### Younes Boufrioua

* Github: [@Younes Boufrioua](https://github.com/TourreTV)
* Mail: younes.boufrioua@epitech.eu

### Thomas Ott

* Github: [@Thomas Ott](https://github.com/RedBoardDev)
* Mail: thomas.ott@epitech.eu
