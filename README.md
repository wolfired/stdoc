# stdoc

just a chs doc repo for c stdlib

# usage

```bash

# clone
git clone --recurse-submodules git@github.com:wolfired/stdoc.git && \
git -C ./doxygen-awesome-css checkout v1.5.0

# build, install
cmake -DCMAKE_INSTALL_PREFIX=/home/bed -B ./build && \
cmake --build ./build && \
cmake --install ./build

# gen doc
doxygen

# run web server
python -m http.server -b 0.0.0.0 -d ./html 8000

```
