## WebAssembly实战
==by 李秋生 September 13, 2017 1:30 PM==
本文档包含了编译脚本和编译好的可执行文件，只需再有一个支持 WebAssembly 的浏览器就可以直接运行
### 配置开发调试环境
#### 安装编译工具
参考官方 [Developer’s Guide](http://webassembly.org/getting-started/developers-guide/) 和 [Advanced Tools](http://webassembly.org/getting-started/advanced-tools/)，需要安装的工具有：
   -  [Emscripten](http://kripken.github.io/emscripten-site/)
   -  [Binaryen](https://github.com/WebAssembly/binaryen)
   -  [WABT (WebAssembly Binary Toolkit)](https://github.com/WebAssembly/wabt)

==安装之前先检查系统依赖 参考 [toolchain_what_is_needed](https://kripken.github.io/emscripten-site/docs/building_from_source/toolchain_what_is_needed.html#toolchain-what-you-need),然后下载源码,编译安装 ==
#### 浏览器配置
作为一个新技术，之所以说 WebAssembly 前途明媚，不仅是因为 W3C 成立了专门的 Webassembly Community Group，被标准认可；也是因为这次各大主流浏览器厂商（难得的）达成了一致，共同参与规范的讨论，在自家的浏览器里都实现了。
在主流版本里开启 flag 也是可以使用 WebAssembly 的：
- Chrome: 打开 chrome://flags/#enable-webassembly，选择 enable
- Firefox: 打开 about:config 将 javascript.options.wasm 设置为 true

#### 快速体验 WebAssembly
快速体验 WebAssembly ？最简单的办法就是找个支持 WebAssembly 的浏览器，打开控制台，把下列代码粘贴进去。
##### 程序代码
WebAssembly.compile(new Uint8Array(`
  00 61 73 6d  01 00 00 00  01 0c 02 60  02 7f 7f 01
  7f 60 01 7f  01 7f 03 03  02 00 01 07  10 02 03 61
  64 64 00 00  06 73 71 75  61 72 65 00  01 0a 13 02
  08 00 20 00  20 01 6a 0f  0b 08 00 20  00 20 00 6c
  0f 0b`.trim().split(/[\s\r\n]+/g).map(str => parseInt(str, 16))
)).then(module => {
  const instance = new WebAssembly.Instance(module)
  const { add, square } = instance.exports

  console.log('2 + 4 =', add(2, 4))
  console.log('3^2 =', square(3))
  console.log('(2 + 5)^2 =', square(add(2 + 5)))

})
##### 运行结果
如果报错，说明你的浏览器不支持 WebAssembly ；如果没报错，代码的运行结果如下（还会返回一个 Promise）：
   `2 + 4 = 6`
   `3^2 = 9`
   `(2 + 5)^2 = 49`

### WebAssembly Standalone
By default **emcc** creates a combination of JS files and WebAssembly, where the JS loads the WebAssembly which contains the compiled code. There is also progress towards an option to emit standalone WebAssembly files, which is detailed here.
**Usage**
emcc [params for your input files, optimization level, etc.] -s WASM=1 -s SIDE_MODULE=1 -o target.wasm



