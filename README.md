### Содержание src:

#### create_shared_memory.cpp
Данный файл содержит программу, которая *создает область разделяемой памяти размером 1000 байт*, *генерирует* для нее *ключ*  и сохраняет его в файл, и *записывает "Hello world!"* в разделяемую память.

#### read_delete_shrm.cpp
Данный файл содержит программу, которая *считывает ключ* из файла, *обращается к разделяемой памяти по этому ключу и выводит информацию оттуда*, а после *очищает разделяемую память* и удаляет файл, в котором находился ключ.

#### helpers_func.cpp и helpers.hpp
Данные файлы содержат дополнительные функции для того, чтобы не "захламлять файлы", описанные выше.
Содержит функции: 
1) Сохранения ключа в файл;
----
ВАЖНО: НАЗВАНИЕ ФАЙЛА ЗАПИСАНО КАК КОНСТАНТА В ФАЙЛЕ helpers.hpp. Его можно поменять по желанию, изначальное название файла - shared_memory_key.
```cpp
#define FILENAME "shared_memory_key.txt"
```
Строка, записываемая в разделяемую память, записана как константа в файле helpers.hpp. Ее можно поменять по желанию, изначальная строка - "Hello world!". 
```cpp
#define NECESSARY_STR "Hello world!"
```
----
2) Чтение ключа из файла;
3) Функция для вывода ошибки.

#### makefile
Данный файл добавлен для удобства запуска программ отдельно друг от друга.
Чтобы запустить файл create_shared_memory.cpp введите следующее:
```bash
make run_create
```

Чтобы запустить файл read_delete_shrm.cpp введите следующее:
```bash
make run_read
```

#### Docker file
Данный докер файл нужен для корректного запуска программ.
Сначала проверьте, установлен ли у вас docker, потому что он понадобиться для корректной работы (https://www.docker.com/).

Чтобы запустить обе команды в одном контейнере, введите следующие команды:
```bash
docker build -t my_program_container .
docker run --rm my_program_container
```
