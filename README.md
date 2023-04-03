# C Test For Embedded Linux Course

Author: Nguyen Luong Dinh Hoang\
Contact: fb.com/nguyenluongdinhhoang

# How to build

Make sure you are runnning cmake version > 3.0

```
mkdir build && cd build
cmake ..
make
./test
```

# Read data from file

Accept reading from this format only\
```
fullname:salary
'''
Read sample on data_test.txt\
Run with file name argument\
```
./test ${FILE_NAME}
```
Example
```
./test ../data_test.txt
```
