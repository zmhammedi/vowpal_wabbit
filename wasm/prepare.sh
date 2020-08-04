#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
VW_BASE_DIR=${SCRIPT_DIR}/..

if [ ! -z "$(git status --porcelain)" ]; then
    echo Working dir must be clean
    exit 1
fi

cd $VW_BASE_DIR
git apply $SCRIPT_DIR/diff.patch

mkdir external
cd external
cp $SCRIPT_DIR/external.CMakeLists.txt CMakeLists.txt

git clone https://github.com/jackgerrits/boost.git
cd boost
git checkout boost-1.69.0-pruned
git submodule update --init --recursive
cd ..

git clone https://github.com/jackgerrits/boost-cmake
cd boost-cmake
git checkout git_support_patched
cd ..

git clone https://github.com/jackgerrits/zlib.git
cd zlib
git checkout v1.2.11_patched
cd ..
