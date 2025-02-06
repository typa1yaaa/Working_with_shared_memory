#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <errno.h>
#include <cstring>

#define NECESSARY_STR "Hello world!"
#define FILENAME "shared_memory_key.txt"

template <typename T>
void check_error(T result, const char* message){
    if (result == (T)(-1)){
        std::cerr << message << errno << " - " << strerror(errno) << std::endl;
        exit(1);
    }
};

void save_key(int key);

key_t read_key_from_file();

#endif