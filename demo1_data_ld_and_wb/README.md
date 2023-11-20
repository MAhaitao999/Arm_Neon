### 在交叉编译环境里安装zlib和libpng

```
wget wget https://sourceforge.net/projects/libpng/files/zlib/1.2.11/zlib-1.2.11.tar.gz
tar -zxvf zlib-1.2.11.tar.gz
cd zlib-1.2.11/
export CC=/usr/bin/aarch64-linux-gnu-gcc
./configure --prefix=/usr/aarch64-linux-gnu/third-party/zlib-1.2.11
make
sudo make install

```

```
wget https://sourceforge.net/projects/libpng/files/libpng16/1.6.40/libpng-1.6.40.tar.gz
tar -zxvf libpng-1.6.40.tar.gz
export CFLAGS="-I/usr/aarch64-linux-gnu/third-party/zlib-1.2.11/include"
export LDFLAGS="-L/usr/aarch64-linux-gnu/third-party/zlib-1.2.11/lib"
./configure --host=aarch64 --prefix=/usr/aarch64-linux-gnu/third-party/libpng-1.6.40
make
sudo make install
```

### 编译自己的demo

```
aarch64-linux-gnu-gcc util.c test.c -o test -I/usr/aarch64-linux-gnu/third-party/libpng-1.6.40/include/ -L/usr/aarch64-linux-gnu/third-party/libpng-1.6.40/lib -L/usr/aarch64-linux-gnu/third-party/zlib-1.2.11/lib -lpng16 -lpng -lm -lz
```

### 执行demo

```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/aarch64-linux-gnu/third-party/libpng-1.6.40/lib
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/aarch64-linux-gnu/third-party/zlib-1.2.11/lib

qemu-aarch64 -L /usr/aarch64-linux-gnu/ ./test
```
