cd ../build
cmake -S .. -B . -G "Unix Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++

make 
cd ../scripts