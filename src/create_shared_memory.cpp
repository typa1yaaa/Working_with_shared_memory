#include <sys/shm.h>
#include "helpers_func.hpp"

int main(){
    key_t key = ftok("/create_shared_memory.cpp", 'R'); // Стабильный ключ
    check_error(key, "Key creation error: ");
    
    int sharedmemory_id = shmget(key, 1000, IPC_CREAT | 0666);
    check_error(sharedmemory_id, "Error creating a shared memory segment: ");
    
    char *sharedmemory_ptr = (char*)shmat(sharedmemory_id, NULL, 0);
    check_error(sharedmemory_ptr, "Error connecting to shared memory: ");
    
    strcpy(sharedmemory_ptr, NECESSARY_STR); // Записываем нужную строку в разделяемую память
    std::cout << "Key of shared memory: " << key << std::endl;
    save_key(key);
    
    return 0;
}
