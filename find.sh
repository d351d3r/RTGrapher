#!/bin/bash

# Используйте текущую директорию в качестве корневой
root_folder="$PWD"

# Используйте find для поиска файлов C++ (.cpp, .hpp) и CMakeLists.txt, исключая папку build
find "$root_folder" -type d -name build -prune -o \( -iname "*.cpp" -o -iname "*.hpp" -o -iname "CMakeLists.txt" \) -print | while read file
do
    echo "Путь файла: $file"
    # Вывод содержимого файла
    echo "Содержимое файла:"
    cat "$file"
    # Вставьте разделитель для удобства чтения
    echo "--------------------------------"
done

