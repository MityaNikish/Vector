Реализовать класс **``Vector``** для работы с простыми двумерными векторами на основе ``double``. Класс представляет удобный интерфейс для выполнения всех базовых операций над векторами на плоскости: сложение, вычитание, умножение на скаляр, скалярное произведение, вычисление проекций и углов между векторами, аффинные преобразования, и т.п.

### Постановка задачи

Реализовать класс **``Vector``** в соответствии с приведённым ниже интерфейсом.

```C++
class Vector
{
public:
  Vector(void);
  explicit Vector(double x, double y);

public:
  Vector(const Vector & that);
  Vector & operator =(const Vector & that);

public:
  Vector makePolar(double rad, double alpha);

public:
  double x(void);
  double y(void);
  void x(double newX);
  void y(double newY);

public:
  Vector operator + (const Vector & that);
  Vector operator - (const Vector & that);
  double operator * (const Vector & that);
  Vector operator * (const double & that);
  Vector operator / (const double & that);

public:
  Vector & operator += (const Vector & that);
  Vector & operator -= (const Vector & that);
  Vector & operator *= (const double & that);
  Vector & operator /= (const double & that);

public:
  Vector operator -();

public:
  bool operator == (const Vector & that);
  bool operator != (const Vector & that);

public:
  Vector & rotate(double angle);
  Vector & rotate(int quad);
  double module2(void);
  double angle(void);
  double angle(const Vector & that);
  double length(void);
  double projection(const Vector & base);
  Vector & normalize(void);
  Vector & transformTo(const Vector & e1, const Vector & e2);
  Vector & transformFrom(const Vector & e1, const Vector & e2);

private:
  // поля...
};

Vector operator * (const double & lhs, const Vector & rhs);

Vector rotate(const Vector & v, double angle);
Vector rotate(const Vector & v, int quad);
double module2(const Vector & v);
double length(const Vector & v);
double angle(const Vector & v);
double angle(const Vector & v1, const Vector & v2);
double projection(const Vector & v, const Vector & base);
Vector normalize(const Vector & v);
Vector transformTo(const Vector & v, const Vector & e1, const Vector & e2);
Vector transformFrom(const Vector & v, const Vector & e1, const Vector & e2);
```
### Примечания

1. Для **``public``** и **``protected``** методов класса не допускается изменение названий, а также типов и количества аргументов. Однако, в приведённых фрагментах кода намеренно опущен ряд спецификаторов **``const``** и **``static``**. При реализации необходимо вернуть их на место в соответствии с логикой работы класса.

2. Ряд методов класса и функций на первый взгляд имеет одинаковый функционал. Однако это не так. Одни операции изменяет объект к которому применены, другие оставляют объект неизменным и создают изменённую копию. Приведённый интерфейс позволяет однозначно отделить первые от вторых.

3. Поворот вектора на произвольный угол &mdash; это всегда операция с потерей точности. Базовые математические функции принимают угловые аргументы в радианах, а значит, в частности, поворот на 90 градусов всегда будет происходить с погрешностью. В то же время, для поворотов на угол кратный 90 градусам никакая тригонометрия на самом деле не нужна. Поэтому в приведённом интерфейсе есть 2 варианта функции поворота.

4. Переход из одного базиса в другой представлен 2 функциями / методами: **``transformTo(e1, e2)``** и **``transformFrom(e1, e2)``**. Разберём их подробнее. Пусть в базисе ``(i1, i2)`` записан вектор ``v``. Пусть в другом базисе ``(e1, e2)`` этот же вектор имеет запись ``u``. Пусть вектора ``e1`` и ``e2`` в базисе ``(i1, i2)`` записываются как ``e1_i`` и ``e2_i`` соответственно.  И наоборот, вектора ``i1`` и ``i2`` в базисе ``(e1, e2)`` записываются как ``i1_e`` и ``i2_e``. Тогда переход из одного базиса в другой будет осуществляться следующим вызовом: ``v.transformTo(e1_i, e2_i)``&rarr;``u``. Обратный переход может быть осуществлён двумя способами, либо через вызов ``u.transformTo(i1_e, i2_e)``&rarr;``v``, либо через вызов ``u.transformFrom(e1_i, e2_i)``&rarr;``v``, в зависимости от того, какое представление базиса более удобно.

### Описание интерфейса

- **``Vector(void)``** &mdash; Конструктор по-умолчанию. Инициализация нового экземпляра класса **``Vector``** нулевыми значениями.

- **``Vector(double x, double y)``** &mdash; Покомпонентная инициализация нового экземпляра класса **``Vector``**.

- **``Vector(const Vector & that)``** &mdash; Конструктор копии.

- **``Vector & operator =(const Vector & that)``** &mdash; Оператор присваивания.

- **``Vector makePolar(double rad, double alpha)``** &mdash; Инициализация нового экземпляра класса **``Vector``** из радиуса ``rad`` и угла ``alpha`` к оси X.

- **``double x(void)``** &mdash; доступ к X-компоненту вектора.

- **``double y(void)``** &mdash; доступ к Y-компоненту вектора.

- **``void x(double newX)``** &mdash; Модификация X-компонента вектора.

- **``void y(double newY)``** &mdash; Модификация Y-компонента вектора.

- **``Vector operator + (const Vector & that)``** &mdash; Операция сложения векторов.

- **``Vector operator - (const Vector & that)``** &mdash; Операция вычитания векторов.

- **``double operator * (const Vector & that)``** &mdash; Операция скалярного произведения векторов.

- **``Vector operator * (const double & that)``** &mdash; Операция умножения вектора на скаляр.

- **``Vector operator / (const double & that)``** &mdash; Операция деления вектора на скаляр.

- **``Vector & operator += (const Vector & that)``** &mdash; Операция добавления вектора к данному.

- **``Vector & operator -= (const Vector & that)``** &mdash; Операция вычитания вектора из данного.

- **``Vector & operator *= (const double & that)``** &mdash; Операция умножения данного вектора на скаляр.

- **``Vector & operator /= (const double & that)``** &mdash; Операция деления данного вектора на скаляр.

- **``Vector operator -()``** &mdash; Операция отрицания вектора.

- **``bool operator == (const Vector & that)``** &mdash; Операция проверки векторов на равенство.

- **``bool operator != (const Vector & that)``** &mdash; Операция проверки векторов на неравенство.

- **``Vector & rotate(double angle)``** &mdash; Метод для поворота вектора на произвольный угол ``angle`` (в радианах).

- **``Vector & rotate(int quad)``** &mdash; Метод для поворота вектора на угол, кратный 90 градусам (``+`` &mdash; поворот против часовой, ``-`` &mdash; по часовой).

- **``double module2(void)``** &mdash; Метод, вычисляющий квадрат модуля вектора.

- **``double length(void)``** &mdash; Метод, вычисляющий длину вектора.

- **``double angle(void)``** &mdash; Метод, вычисляющий угол между данным вектором и осью X.

- **``double angle(const Vector & that)``** &mdash; Метод, вычисляющий угол между данным вектором и вектором ``that``.

- **``double projection(const Vector & base)``** &mdash; Метод, вычисляющий проекцию данного вектора на заданный ``base``

- **``Vector & normalize(void)``** &mdash; Нормализация вектора (масштабирование к единичной длине).

- **``Vector & transformTo(const Vector & e1, const Vector & e2)``** &mdash; Преобразование текущего вектора в другую систему координат с базисом ``e1`` и ``e2``.

- **``Vector & transformFrom(const Vector & e1, const Vector & e2)``** &mdash; Преобразование текущего вектора из системы координат с базисом ``e1`` и ``e2``.

#### Стандартные операторы, принимающие в качестве аргументов ``Vector``

- **``Vector operator * (const double & lhs, const Vector & rhs)``** &mdash; Оператор умножения скаляра на вектор.

#### Функции, принимающие в качестве аргументов ``Vector``

- **``Vector rotate(const Vector & v, double angle)``** &mdash; Функция поворота вектора ``v`` на угол ``angle``, заданный в радианах.

- **``Vector rotate(const Vector & v, int quad)``** &mdash; Функция поворота вектора ``v`` на угол кратный 90 градусам.

- **``double module2(const Vector & v)``** &mdash; Функция вычисления квадрата модуля вектора ``v``.

- **``double length(const Vector & v)``** &mdash; Функция, вычисляющая длину вектора ``v``.

- **``double angle(const Vector & v)``** &mdash; Функция вычисления угла между вектором ``v`` и осью X.

- **``double angle(const Vector & v1, const Vector & v2)``** &mdash; Функция вычисления угла между векторами ``v1`` и ``v2``.

- **``double projection(const Vector & v, const Vector & base)``** &mdash; Функция вычисления проекции вектора ``v`` на вектор ``base``.

- **``Vector normalize(const Vector & v)``** &mdash; Функция нормализации векторами ``v``.

- **``Vector transformTo(const Vector & v, const Vector & e1, const Vector & e2)``** &mdash; Функция преобразования вектора ``v`` в систему координат с базисом ``e1`` и ``e2``.

- **``Vector transformFrom(const Vector & v, const Vector & e1, const Vector & e2)``** &mdash; Функция преобразования вектора ``v`` из системы координат с базисом ``e1`` и ``e2``.

### Требования

1. К **``public``** методам, класса **``Vector``** необходимо добавить в нужных местах спецификаторы **``static``** и **``const``**. 
2. Нельзя менять названия **```public```** и **```protected```** методов класса, а также типы и количество аргументов в них.
3. Названия header и source файлов следующие: **```Vector.hpp, Vector.cpp```**.
4. Написать unit test'ы для реализованного класса. 