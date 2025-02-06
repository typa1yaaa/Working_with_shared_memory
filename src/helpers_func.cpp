#include "helpers_func.hpp"

void save_key(int key){
    std::ofstream key_file(FILENAME);

    // проверка на попытку перезаписать информацию в файл
    if (!key_file){
        std::cerr << "You have already saved the key" << std::endl;
        return;
    }

    key_file << key;
    key_file.close();

    if (chmod(FILENAME, S_IRUSR | S_IRGRP | S_IROTH) == -1) {  // Запрет для изменения файла 
        std::cerr << "Error setting file permissions" << std::endl;
        exit(1);
    }
}

key_t read_key_from_file() {
    std::ifstream key_file(FILENAME);
    if (!key_file) {
        std::cerr << "Error opening file to read key" << std::endl;
        exit(1);
    }

    key_t key;
    key_file >> key;
    if (key_file.fail()) {
        std::cerr << "Error reading key from file" << std::endl;
        exit(1);
    }
    
    return key;
}