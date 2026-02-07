# Google Docs Lite

## Problem Statement
Design a simplified document editor supporting text and images.

## Features
- Add text elements
- Add image elements
- Render document
- Memory-safe using `std::unique_ptr`

## Design Overview
- Follows SOLID principles
- Layered architecture (Editor, Core, Renderer)
- Polymorphic document elements

## Build Instructions
```bash
mkdir build
cd build
cmake ..
cmake --build .
./app
