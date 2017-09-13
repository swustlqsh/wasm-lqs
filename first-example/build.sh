#!/bin/bash
emcc hello.c -s WASM=1 -o hello.html
echo
echo 'Compile done.'
