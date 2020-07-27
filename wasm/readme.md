## Install Emscripten
Instructions here: https://emscripten.org/docs/getting_started/downloads.html
```sh
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh
```

## Build
Make sure Emscripten is activated.
```sh
# In VW root dir
mkdir wasm_build
cd wasm_build
emcmake cmake ../vowpalwabbit/slim/
make -j 4
cd ../wasm
python3 -m http.server
```
