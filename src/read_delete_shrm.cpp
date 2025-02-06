#include <sys/shm.h>
#include "helpers_func.hpp"

int main(){
    key_t key = read_key_from_file(); 

    int sharedmemory_id = shmget(key, 100, 0666);
    check_error(sharedmemory_id, "Error getting shared memory segment: ");
    
    char* sharedmemory_ptr = (char*)shmat(sharedmemory_id, NULL, 0);
    check_error(sharedmemory_ptr, "Error connecting to shared memory: ");

    std::cout << sharedmemory_ptr << std::endl; // Выводим значение из разделяемой памяти
    
    if (shmdt(sharedmemory_ptr) == -1) { // Очищаем разделяемую память
        std::cerr << "Error disconnecting from shared memory: " << errno << " - " << strerror(errno) << std::endl;
        exit(1);
    }

    if (remove(FILENAME) != 0) { // Удаляем файл, в котором был ключ разделяемой памяти
        std::cerr << "Error deleting the file" << std::endl;
        exit(1);
    }

    return 0;
}