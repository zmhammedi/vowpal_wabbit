## Install Emscripten
Instructions here: https://emscripten.org/docs/getting_started/downloads.html
```sh
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh
```

## Prepare dependencies
```
./wasm/prepare.sh
```

## Build
Make sure Emscripten is activated.
```sh
# In VW root dir
git submodule update --init --recursive
mkdir wasm_build
cd wasm_build
emcmake cmake .. -DSTATIC_LINK_VW_JAVA=on -DVW_INSTALL=off -DBUILD_TESTS=off -DGIT_SUBMODULE=off
make -j 4
cd ../wasm
python3 -m http.server
```
