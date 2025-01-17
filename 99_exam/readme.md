
## Подготовка к экзамену

### Общие требования

1. Необходимо реализовать одну из нижеперечисленных задач в **объектно-ориентированной <u>архитектуре</u>** и **<u>стиле</u>**. Это подразумевает:
	- наличие нескольких классов (***сильно*** больше 1)
		- *допускается использование только 1 (`main`) или 2-3 (`+ menu/test`) функций*
	- атомарность (минимизация) сущностей (классов, методов)
		- *каждый класс (метод) выполняет только свою определенную задачу*
	- универсальность (независимость) сущностей:
		- *готовьте свое решение к экспорту (чтобы можно было подключить ваш класс и удобно использовать его готовый функционал в разных реализациях)*
		- *организуйте вывод в консоль как один из возможных вариантов использования*
		- *реализуйте возможность настройки вашего модуля*
1. При решении обязательно использовать долгосрочное хранение данных в файле.

<u>*Несколько советов:*</u>
1. При проектировании выпишите список **данных**, которые будет необходимо хранить в программе.
1. Сгруппируйте их по сущностям (структурам), обобщая по назначению
1. Выделите базовые операции (методы) для этих данных (для работы непосредственно с ними)
1. Перегруппируйте их в классы с учетом методов для работы с данными (сущностями)

- *Как пример универсальности, **всю** работу с консолью можно реализовать в **отдельном** классе (или функции) `Menu`. Этот класс (ф-ию) нужно использовать, например, только в функции `main` и нигде больше.*
- *Весь остальной функционал, подготовленный для работы с меню также будет пригоден для сохранения/чтения данных в файле.*

---
Пример проектирования приложения "Калькулятор" (без учета способа взаимодействия с пользователем):
![тут картинка](Пример_проектирования_калькулятора.png)
<!-- 
### Экзаменационные задания

- [Викторина](./quiz.html)
- [Кошелек](./pocket.html)
- [Файловый менеджер](./file_manager.html)
- [Калькулятор](./calculator.html)
- [Переводчик](./translator.html)
- [Виселица](./hangman.html)
- [Солитер](./freecell.html)
- [Тетрис](./tetris.html)
- [Гонки](./racing.html)
- [Танчики](./tanks.html)
- [Автобатл](./autobattle.html)
- [3-в-ряд](./3-in-line.html) 
-->
