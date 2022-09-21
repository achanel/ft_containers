# ft_containers

Стандартная библиотека предоставляет различные типобезопасные контейнеры для хранения коллекций связанных объектов.
Контейнеры — это шаблоны классов. При объявлении переменной контейнера указывается тип элементов, которые будет хранить контейнер.
Контейнеры могут создаваться с использованием списков инициализаторов. Они имеют функции-члены для добавления и удаления элементов и выполнения других операций.
Итерация элементов в контейнере и доступ к отдельным элементам осуществляются с помощью итераторов.
Итераторы можно использовать явным образом с помощью их функций-членов и операторов и глобальных функций.
Вы можете также использовать их неявно, например с помощью цикла range-for.
Итераторы для всех контейнеров стандартной библиотеки C++ имеют общий интерфейс, но каждый контейнер определяет собственные специализированные итераторы.
Контейнеры можно разделить на три категории: последовательные контейнеры, ассоциативные контейнеры и контейнеры-адаптеры.

# SUMMARY

You have to reimplement the following C++ containers:
- [x] Vector ([std::vector])
- [x] Stack ([std::stack])
- [x] Map ([std::map])
- [x] Set ([std::set])

[std::vector]: http://www.cplusplus.com/reference/vector/vector
[std::stack]: http://www.cplusplus.com/reference/stack/stack
[std::map]: http://www.cplusplus.com/reference/map/map
[std::set]: http://www.cplusplus.com/reference/set/set

# RUN

* For VECTOR:
```bash
c++ -std=c++98 -Wall -Wextra -Werror main_vector.cpp
```
* For STACK:
```bash
c++ -std=c++98 -Wall -Wextra -Werror main_stack.cpp
```
* For MAP:
```bash
c++ -std=c++98 -Wall -Wextra -Werror main_map.cpp
```
* For SET:
```bash
c++ -std=c++98 -Wall -Wextra -Werror main_set.cpp
```
# LINKS

https://cplusplus.com/
https://cppreference.com/
