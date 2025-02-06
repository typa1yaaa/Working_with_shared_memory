### Содержание src:
#### create_shared_memory.cpp
Данный файл содержит программу, которая *создает область разделяемой памяти размером 1000 байт*, *генерирует и сохраняет* для нее *ключ*, и *записывает "Hello world!"* в данную разделяемую память.
#### read_delete_shrm.cpp
Данный файл содержит программу, которая *считывает ключ* из файла, *обращается к разделяемой памяти по этому ключу и выводит информацию оттуда*, а после *очищает разделяемую память*.
#### helpers_func.cpp и helpers.hpp
Данные файлы содержат дополнительные функции для того, чтобы не захламлять файлы, описанные выше.
Содержит функции: 
1) Сохранения ключа в файл 
----
ВАЖНО: НАЗВАНИЕ ФАЙЛА ЗАПИСАНО КАК КОНСТАНТА В ФАЙЛЕ helpers.hpp. Его можно поменять по желанию
```cpp
#define FILENAME "shared_memory_key.txt"
```
----
