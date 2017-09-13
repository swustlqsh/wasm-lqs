#!/bin/bash
emcc nbody.c -O3 -s BINARYEN=1 -s SIDE_MODULE=1 -o nbody.wasm
echo

echo ' => Done'
