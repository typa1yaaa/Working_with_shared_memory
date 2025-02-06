FROM gcc:11.3.0

RUN apt-get update && apt-get install -y \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

ENV CXXFLAGS="-std=c++17 -O2" 
ENV CC=gcc
ENV CXX=g++

COPY . .

# Компилируем первую программу
RUN g++ $CXXFLAGS -o create_shared_memory_program create_shared_memory.cpp helpers_func.cpp

# Компилируем вторую программу
RUN g++ $CXXFLAGS -o read_delete_shrm_program read_delete_shrm.cpp helpers_func.cpp

# Запускаем обе программы поочередно в одном контейнере
CMD ["sh", "-c", "./create_shared_memory_program && ./read_delete_shrm_program"]
