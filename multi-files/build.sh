#!/bin/bash
emcc functions.cpp -Os -s WASM=1 -s SIDE_MODULE=1 -o functions.wasm
echo
echo '=> Done'
