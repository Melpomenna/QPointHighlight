# QPointHighlight
Проект с использование Qt по генерации точек на Widget и их выделению, с созданием окружностей для выделенных точек

# Функциональные требования

1) Рандомно распределяет 50 точек размером 16х16 на виджете размером 800х800.

2) Пользователь должен иметь возможность с помощью мыши выделить точку.

3) Вокруг выделенной точки нужно визуализировать окружность радиусом 35 пикселей.

4) В интерфейсе программы вывести количество точек, находящихся внутри окружности.

5) Добавить в интерфейс программы возможность регулировать количество генерируемых точек от 10 до 500 и размер радиуса от 10 до 100.

# Используемые технологии
1) C++17
2) CMake 4.0.0
3) Visual Studio 2022 (Preview), cl - 19.43.34810 for x64
4) Intel VTune - профилирование CPU
5) NVTX - профилирование GPU
6) GTest - для Unit тестов
7) Benchmark - google
8) Qt 6.9.0

# Установка на Windows (протестированно)

Release:
```bash
cmake --preset=release-Windows
cmake --build --preset=release-Windows --config=Release
windeployqt6 .\build\release\build\Release\PointHighlight.exe
```

Debug:
```bash
cmake --preset=debug-Windows
cmake --build --preset=debug-Windows --config=Debug
```

После этого приложение можно запускать

# Установка Linux (Не протестированнло)

Release:
```bash
cmake --preset=release-Linux
cmake --build --preset=release-Linux --config=Release
```

Debug:
```bash
cmake --preset=debug-Windows
cmake --build --preset=debug-Windows --config=Debug
```

После этого приложение можно запускать

# Запуск тестов

Собрать согласно инструкции выше

## Windows
Release:
```bash
ctest --preset=release-Windows
```

Debug:
```bash
ctest --preset=debug-Windows
```

## Linux

## Windows
Release:
```bash
ctest --preset=release-Linux
```

Debug:
```bash
ctest --preset=debug-Linux
```

# Запуск бенчмарков

Собрать согласно инструкции выше

Debug:
```bash
./build/debug/build/Debug/Benchmark.exe
```

Release:
```bash
./build/release/build/Release/Benchmark.exe
```