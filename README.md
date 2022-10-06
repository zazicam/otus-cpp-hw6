# otus-cpp-hw6

## Задание
Разработать шаблонный класс 2-мерной разреженой бесконечной матрицы, заполненной значениями по-умолчанию.
Матрица должна хранить только заполненные значения, то есть элементы, значения которых были установлены явно с помощью оператора присваивания. Присвоение элементу значения по-умолчанию должно освобождать память из под этого элемента.

Класс матрицы должен поддерживать итерирование по всем элементам матрицы с помощью rande-for цикла.
Подготовить не менее 5 тестов с использованием фреймворка Google Tests. Сборку программы реализовать с помощью утилиты CMake.

Create 2-dimensional sparce infinite size matrix filled with
default values. Matrix mush store only filled elements, i.e.
elements that were set by operator=

Assignment the default value to some element must free this element.

## Сборка программы
Для сборки программы под ОС Linux необходимо поставить библиотеку google tests framework:
```
sudo apt install libgtest-dev
```

Далее порядок сборки стандартный: клонируем репозитарий, создаем папку build, делаем cmake и make
```
git clone https://github.com/zazicam/otus-cpp-hw6
cd otus-cpp-hw6
mkdir build
cd build
cmake ..
make
```

После этого в папке build должны появиться 2 программы: 
* matrix - пример заполнения матрицы и итерирования по ней с выводом значений элементов,
* test_matrix - минимальный набор тестов для поддержания кода в рабочем состоянии.


