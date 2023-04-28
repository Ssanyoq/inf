
# Общая информация
В этом репозитории лежат все 6 лабораторных работ, которые я делал в рамках предмета 1 семестра "Информатика и основы программирования".
<br>
Теперь про структуру проекта:
- В лабораторных реализованы `Makefile`-ы, поэтому можно не беспокоиться о компиляции и просто запустить `make`. В первых 2 лабораторных они пока не реализованы, ведь там для сборки нужен только 1 файл.
- В некоторых лабораторных из-за специфики заданий есть несколько опций компиляции(просто `make` может не сработать, надо будет писать например `make bench`). Для подробной информации об опциях можно либо просто открыть `Makefile` в интересующей папке, либо прочитать описание лаб ниже.
- Все исполняемые файлы и некоторые другие временные файлы, например `.o`, хранятся в `build/` для удобного исключения их с помощью `.gitignore`

<br>  

---

<br>  

# Описание лаб

- [Лаба 1](#Лаба-1)
- [Лаба 2](#Лаба-2)
- [Лаба 3](#Лаба-3)
- [Лаба 4](#Лаба-4)
- [Лаба 5](#Лаба-5)
- [Лаба 6](#Лаба-6)

<br>  

---

## Лаба 1
### Random assignment:

- Написать программу, которая при вводе числа выводит его уникальныые цифры, порядок следования важен. Пример - `12321` -> `123`, `-422323` -> `-423` 
- Самое классное решение лежит в `uniq_final.c`

---
## Лаба 2
### Random assignment:
- Вычислить $$\sin^3(x)=\frac{3}{4}(\frac{8x^3}{3!}-\frac{80x^5}{5!}+\frac{728x^7}{7!}-...) = \frac{3}{4}\sum_{n=1}^\infty (-1)^{n+1}\frac{3^{2n}-1}{(2n + 1)!}x^{2n-1}$$
Лабораторная работа №2 «Вычисление значений числовых рядов и функций с заданной точностью»<br>
Необходимо спроектировать и реализовать на языке C две программы, позволяющие вычислять значения некоторой заданной функции.
Программа №1 должна обеспечивать возможность вычисления значения функции при определённых значениях параметров, указанных пользователем. При этом, пользователь должен иметь возможность указать количество членов ряда, которое необходимо использовать при вычислениях.
Ключевым компонентом программы №1 должна быть некоторая функция, на вход которой передаются значения параметров и количество членов ряда, необходимое для проведения вычислений. Возвращаемым значением для указанной функции должно быть вычисленное значение.
Программа No 2 должна обеспечивать возможность вычисления значения функции при определённых значениях параметров, указанных пользователем. При этом, пользователь должен иметь возможность указать точность, с которой должно быть вычислено значение функции.
Ключевым компонентом программы No 2 должна быть некоторая функция, на вход которой передаются значения параметров и точность, с которой необходимо вычислить результат. В качестве результата функция должна возвращать вычисленное значение и количество членов ряда, которое потребовалось вычислить для обеспечения заданной точности (данное значение необходимо вернуть через параметр).
Примечания:
1. Логически законченные части алгоритмов решения задачи должны быть оформлены в виде отдельных функций с параметрами. Использование глобальных переменных не допускается.
2. Исходные коды программ должны быть логичным образом разбиты на несколько файлов.
3. Программы должны осуществлять проверку корректности вводимых данных и, в случае ошибок, выдавать соответствующие сообщения, после чего продолжать работу.
4. Программа должна корректным образом работать с памятью, для проверки необходимоиспользовать соответствующие программные средства, например: `valgrind` (при тестировании и отладке программы ее необходимо запускать командой вида `valgrind ./lab2`, а при анализе производительности — `./lab2`).

- Исполняемый файл создается в `lab2/build/` для того, чтобы не засорять основную папку и для удобного игнорирования файлов в `.gitignore`
---
## Лаба 3
### Random assignment:
- Вариант №9
Индивидуальное задание <br>
В исходной последовательности целых чисел найти те, цифры в записи которых расположены <br>
строго по убыванию при чтении слева направо. Сформировать из данных чисел новую последовательность, удалив их из исходной. <br>  <br>
Правила изменения размера выделенной под массив области памяти <br>
Размер выделенной под массив области памяти задаётся пользователем вручную через соответствующие пунты меню.
Любые операции по изменению размера выделенной области памяти выполняются только по явному запросу со стороны пользователя.

Лабораторная работа №3 «Работа с массивами данных» <br>
Необходимо спроектировать и реализовать на языке C программу, осуществляющую по запросам пользователя ввод, обработку и вывод последовательности данных, которая представляется в виде массива. <br>
Программа должна реализовывать следующую функциональность:
1. Инициализация массива (заполнение массива в цикле). 
2. Вставка нового элемента в массив по индексу.
3. Удаление элемента массива по индексу.
4. Обработка данных (в соответствии с индивидуальным заданием). 
5. Вывод текущего состояния массива.
- Примечания:
1. Взаимодействие программы с пользователем должно быть выстроено с помощью диалогового меню. Штатный способ завершения работы программы — через соответствующий пункт диалогового меню.
2. Программа должна осуществлять проверку корректности вводимых данных и,в случае ошибок, выдавать соответствующие сообщения, после чего продолжать работу.
3. Обрабатываемые последовательности должны быть представлены в виде массива элементов, которые имеют соответствующий тип данных.
4. Память под массивы обрабатываемых данных должна выделяться и освобождаться динамически, с использованием функций `calloc()`, `malloc()`, `realloc()` и `free()` из состава стандартной библиотеки.
5. Использование VLA (массивов переменной длины) не допускается.
6. Приудаленииэлементамассивасуказанныминдексом,элементымассивасбольшиминдексом должны «сдвигаться влево».
7. При вставке в массив нового элемента по индексу, значение которого превышает максимально допустимое (оно соответствует длине массива), необходимо осуществлять вставку в конец массива.
8. Логически законченные части алгоритма решения задачи должны быть оформлены в виде отдельных функций с параметрами. Использование глобальных переменных не допускается.
9. Исходные коды программы должны быть логичным образом разбиты на несколько файлов (необходимо использовать как `*.c`-файлы, так и `*.h`-файлы).
10. Согласно условиям индвидуального задания,может требоваться наличие нескольких исходных последовательностей. В таком случае, пользователь должен иметь возможность интерактивного взаимодействия с каждой из них.
11. Программа должна корректным образом работать с памятью,для проверки необходимо использовать соответствующие программные средства, например: `valgrind` (при тестировании и отладке программы необходимо запускать её командой вида `valgrind ./lab3`).

<br><br>
В этой лабораторной реализован `Makefile` с единственной опцией. Использование: `make`

---
## Лаба 4
### Random assignment:
- Вариант №30 Задание Продублировать все гласные буквы в строке.

Лабораторная работа № 4 «Работа со строками» <br>
Из входного потока вводится произвольное количество строк произвольной длины. Каждая строка в общем случае содержит одно или более слов, разделенных пробелами и/или знаками табуляции.<br>
Завершение ввода определяется концом файла. Для каждой входной строки формируется новая выходная строка, в которую помещается результат. В полученной строке слова разделяются только одним пробелом, пробелов в её начале и в конце быть не должно. Введённая и сформированная строки <br>
выводятся на экран в двойных кавычках. <br>
В ходе выполнения лабораторной работы должны быть разработаны:
1. Программа, использующая функцию `readline()` из состава библиотеки GNU readline для
ввода строк и функции стандартной библиотеки для их обработки (`<string.h>`).
2. Программа, идентичная п. 1, за исключением того, что все библиотечные функции заменены
на собственную реализацию данных функций, представленную в отдельных файлах (например:
`mystring.h`, `mystring.c`).
Отчётность по выполнению лабораторной работы должна включать:
1. Блок-схему алгоритма работы основной программы.
2. Блок-схемы алгоритмов работы функций по обработке строк.
3. Исходные коды всех программ.
4. Тестовые наборы для программ п. 1 и п. 2.
5. Сравнительный анализ времени, потраченного на решение задачи программами п. 1 и п. 2 (на
конкретных примерах).
- Примечания:
1. Каждая строка представлена на физическом уровне вектором.
2. Использование массивов переменной длины (VLA — variable length arrays) не допускается.
3. Ввод строк должен быть организован с помощью функции `scanf()` со спецификациями для
ввода строк. Использование функций семейства `gets()`, `getchar()`, а также спецификаций
`%с` и `%m` в `scanf()` не допускается.
4. Целочисленные и строковые константы, используемые в формулировках индивидуальных заданий, должны быть заданы в исходном коде с помощью директив препроцессора #define.
5. Программа должна корректным образом завершаться при обнаружении EOF — конца файла (в
`UNIX`-подобных ОС инициируется нажатием клавиш `Ctrl + D`, в Windows — `Ctrl + Z`).
6. Логически законченные части алгоритма решения задачи должны быть оформлены в виде отдельных функций с параметрами.
1
7. Исходные коды программ должны быть логичным образом разбиты на несколько файлов (необходимо использовать как *.c-файлы, так и *.h-файлы).
8. Использование глобальных переменных не допускается.
9. Программы должна корректным образом работать с памятью. Для проверки необходимо использовать соответствующие программные средства, например, `valgrind` (при тестировании
и отладке программ п. 1 и п. 2 необходимо запускать их командой вида `valgrind ./lab4`,
а при анализе производительности — `./lab4`).

<br><br>
В этой лабораторной есть `Makefile` со следующими опциями:
- `make 1`: компиляция варианта программы с использованием стандартной библиотеки `string.h`
- `make 2`: компиляция программы с самописными реализациями функций `string.h`
<br> Также есть другие опции
---
## Лаба 5
