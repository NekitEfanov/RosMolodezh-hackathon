Реализованная функциональность:
1. Полностью реализовано главное меню приложения.
2. Реализован фундамент и удобная структура приложения для реализации остального функционала.
3. Сделана возможность протестировать корректную работу главного меню.
4. Реализован интерфейс Админ-Панели

Особенность проекта в следующем:
1. Легкая масштабируемость.
2. Кроссплатформенность с легкой поддержкой кода.
3. Вся система в целом должна быть стабильной.
4. Можно добиться высокой производительности и приятного отклика для пользователя.

Основной стек технологий всего проекта:
1. C++/Qt/nlohmann_json
2. Html/css/js
3. Python/MySql

СРЕДА ЗАПУСКА OnBoardingApp-cpp:
1. Qt
2. CMake
3. VS code / Clion / Visual Studio 
4. MSVC/GCC

УСТАНОВКА:
1. https://www.qt.io/download (Download Qt for open source use)
2. https://cmake.org/
3. https://visualstudio.microsoft.com/ru/

СБОРКА OnBoardingApp-cpp:
1. git clone репозитория
2. cd /OnBoardingApp-cpp
3. mkdir build
4. cmake .. -A x64 -DCMAKE_PREFIX_PATH="C:\Qt\5.14.2\msvc2017_64\lib\cmake\Qt5" Версии могут отличаться.
