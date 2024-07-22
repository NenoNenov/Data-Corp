# Data-Corp
Документация и инструкции за използване не Inventory Management System (IMS)

Описание на проекта 
Този проект представлява система за управление на инвентар, която позволява на потребителите да добавям, обновяват, изтриват и търсят в инвентара. Системата предоставя възможност за генериране на отчет за всички продукти в инвентара и тяхното филтриране по количество.

Структура на проекта
Проекта се състои от следните основни компоненти
•	’main.cpp’ - Главният файл, който стартира програмата и извиква менюто.
•	’inventory.h’ и ’inventory.cpp’ - Дефиниция и имплементация на класа Inventory, който управлява артикулите в инвентара.
•	’ menu.h’ и  menu.cpp’ - Дефиниция и имплементация на класа Menu, който предоставя интерфейс за взаимодействие с потребителя.
•	’utils.h’ и’ utils.cpp’ - Включва утилити функции като clearConsole(), за изчистване на екрана.
•	’validator.h’ и ’validator.cpp’ - Включва функции за валидация на входните данни.

Инструкции за използване
1.Компилация и стартиране на проекта:

•	Отворете проекта във Visual Studio.
•	В Solution Explorer, щракнете с десния бутон върху решението и изберете Build Solution (или натиснете Ctrl + Shift + B).
•	След като проектът бъде успешно компилиран, стартирайте програмата, като натиснете Ctrl + F5 или като изберете Debug > Start Without Debugging.

2.Работно меню
•	След стартиране на програмата, ще видите меню с различни опции:
1. Add Item 
2. Update Item 
3. Delete Item 
4. Search Item by Name 
5. Search Item by ID 
6. Filter Items by Quantity 
7. Generate Report 8. Exit

Изберете опция, като въведете съответното число и натиснете  ‘Enter’

Описание на функциите 
Клас ‘Inventory’
•	addItem(const std::string& name, int quantity, double price, const std::string& supplier):
o	Добавя нов артикул в инвентара.
o	Параметри: име на артикула, количество, цена, доставчик.
•	updateItem(int id, int quantity, double price, const std::string& supplier):
o	Обновява съществуващ артикул в инвентара.
o	Параметри: ID на артикула, ново количество, нова цена, нов доставчик.
•	deleteItem(int id):
o	Изтрива артикул от инвентара по ID.
o	Параметър: ID на артикула.
•	searchItemByName(const std::string& name):
o	Търси артикули по име.
o	Параметър: име на артикула.
o	Връща: вектор с намерените артикули.
•	searchItemByID(int id):
o	Търси артикул по ID.
o	Параметър: ID на артикула.
o	Връща: намерения артикул.
•	filterItemsByQuantity(int minQuantity, int maxQuantity):
o	Филтрира артикули по количество.
o	Параметри: минимално количество, максимално количество.
o	Връща: вектор с филтрираните артикули.
•	generateReport():
o	Генерира отчет за всички артикули в инвентара.
o	Връща: вектор с всички артикули.

Клас 'Menu'

•	Menu(Inventory& inventory):
o	Конструктор, който приема референция към обект от тип Inventory.
•	void handleMenu():
o	Основният метод за управление на менюто и обработка на потребителските входове.
•	void addItem():
o	Метод за добавяне на артикул.
•	void updateItem():
o	Метод за обновяване на артикул.
•	void deleteItem():
o	Метод за изтриване на артикул.
•	void searchItemByName():
o	Метод за търсене на артикул по име.
•	void searchItemByID():
o	Метод за търсене на артикул по ID.
•	void filterItemsByQuantity():
o	Метод за филтриране на артикули по количество.
•	void generateReport():
o	Метод за генериране на отчет за всички артикули.
•	void printItem(const Item& item):
o	Метод за отпечатване на детайлите на артикул.
Клас Validator
•	static bool validateString(const std::string& str, size_t minLength, size_t maxLength):
o	Валидира дали дължината на низа е в допустимите граници.
o	Параметри: низ, минимална дължина, максимална дължина.
o	Връща: булева стойност (true ако е валиден, false в противен случай).
•	static bool validateQuantity(int quantity):
o	Валидира дали количеството е положително число.
o	Параметър: количество.
o	Връща: булева стойност (true ако е валиден, false в противен случай).
•	static bool validatePrice(double price):
o	Валидира дали цената е положително число.
o	Параметър: цена.
o	Връща: булева стойност (true ако е валидна, false в противен случай).
