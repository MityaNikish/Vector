����������� ����� **``Vector``** ��� ������ � �������� ���������� ��������� �� ������ ``double``. ����� ������������ ������� ��������� ��� ���������� ���� ������� �������� ��� ��������� �� ���������: ��������, ���������, ��������� �� ������, ��������� ������������, ���������� �������� � ����� ����� ���������, �������� ��������������, � �.�.

### ���������� ������

����������� ����� **``Vector``** � ������������ � ���������� ���� �����������.

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
  // ����...
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
### ����������

1. ��� **``public``** � **``protected``** ������� ������ �� ����������� ��������� ��������, � ����� ����� � ���������� ����������. ������, � ���������� ���������� ���� ��������� ������ ��� �������������� **``const``** � **``static``**. ��� ���������� ���������� ������� �� �� ����� � ������������ � ������� ������ ������.

2. ��� ������� ������ � ������� �� ������ ������ ����� ���������� ����������. ������ ��� �� ���. ���� �������� �������� ������ � �������� ���������, ������ ��������� ������ ���������� � ������� ��������� �����. ���������� ��������� ��������� ���������� �������� ������ �� ������.

3. ������� ������� �� ������������ ���� &mdash; ��� ������ �������� � ������� ��������. ������� �������������� ������� ��������� ������� ��������� � ��������, � ������, � ���������, ������� �� 90 �������� ������ ����� ����������� � ������������. � �� �� �����, ��� ��������� �� ���� ������� 90 �������� ������� ������������� �� ����� ���� �� �����. ������� � ���������� ���������� ���� 2 �������� ������� ��������.

4. ������� �� ������ ������ � ������ ����������� 2 ��������� / ��������: **``transformTo(e1, e2)``** � **``transformFrom(e1, e2)``**. ������� �� ���������. ����� � ������ ``(i1, i2)`` ������� ������ ``v``. ����� � ������ ������ ``(e1, e2)`` ���� �� ������ ����� ������ ``u``. ����� ������� ``e1`` � ``e2`` � ������ ``(i1, i2)`` ������������ ��� ``e1_i`` � ``e2_i`` ��������������.  � ��������, ������� ``i1`` � ``i2`` � ������ ``(e1, e2)`` ������������ ��� ``i1_e`` � ``i2_e``. ����� ������� �� ������ ������ � ������ ����� �������������� ��������� �������: ``v.transformTo(e1_i, e2_i)``&rarr;``u``. �������� ������� ����� ���� ���������� ����� ���������, ���� ����� ����� ``u.transformTo(i1_e, i2_e)``&rarr;``v``, ���� ����� ����� ``u.transformFrom(e1_i, e2_i)``&rarr;``v``, � ����������� �� ����, ����� ������������� ������ ����� ������.

### �������� ����������

- **``Vector(void)``** &mdash; ����������� ��-���������. ������������� ������ ���������� ������ **``Vector``** �������� ����������.

- **``Vector(double x, double y)``** &mdash; �������������� ������������� ������ ���������� ������ **``Vector``**.

- **``Vector(const Vector & that)``** &mdash; ����������� �����.

- **``Vector & operator =(const Vector & that)``** &mdash; �������� ������������.

- **``Vector makePolar(double rad, double alpha)``** &mdash; ������������� ������ ���������� ������ **``Vector``** �� ������� ``rad`` � ���� ``alpha`` � ��� X.

- **``double x(void)``** &mdash; ������ � X-���������� �������.

- **``double y(void)``** &mdash; ������ � Y-���������� �������.

- **``void x(double newX)``** &mdash; ����������� X-���������� �������.

- **``void y(double newY)``** &mdash; ����������� Y-���������� �������.

- **``Vector operator + (const Vector & that)``** &mdash; �������� �������� ��������.

- **``Vector operator - (const Vector & that)``** &mdash; �������� ��������� ��������.

- **``double operator * (const Vector & that)``** &mdash; �������� ���������� ������������ ��������.

- **``Vector operator * (const double & that)``** &mdash; �������� ��������� ������� �� ������.

- **``Vector operator / (const double & that)``** &mdash; �������� ������� ������� �� ������.

- **``Vector & operator += (const Vector & that)``** &mdash; �������� ���������� ������� � �������.

- **``Vector & operator -= (const Vector & that)``** &mdash; �������� ��������� ������� �� �������.

- **``Vector & operator *= (const double & that)``** &mdash; �������� ��������� ������� ������� �� ������.

- **``Vector & operator /= (const double & that)``** &mdash; �������� ������� ������� ������� �� ������.

- **``Vector operator -()``** &mdash; �������� ��������� �������.

- **``bool operator == (const Vector & that)``** &mdash; �������� �������� �������� �� ���������.

- **``bool operator != (const Vector & that)``** &mdash; �������� �������� �������� �� �����������.

- **``Vector & rotate(double angle)``** &mdash; ����� ��� �������� ������� �� ������������ ���� ``angle`` (� ��������).

- **``Vector & rotate(int quad)``** &mdash; ����� ��� �������� ������� �� ����, ������� 90 �������� (``+`` &mdash; ������� ������ �������, ``-`` &mdash; �� �������).

- **``double module2(void)``** &mdash; �����, ����������� ������� ������ �������.

- **``double length(void)``** &mdash; �����, ����������� ����� �������.

- **``double angle(void)``** &mdash; �����, ����������� ���� ����� ������ �������� � ���� X.

- **``double angle(const Vector & that)``** &mdash; �����, ����������� ���� ����� ������ �������� � �������� ``that``.

- **``double projection(const Vector & base)``** &mdash; �����, ����������� �������� ������� ������� �� �������� ``base``

- **``Vector & normalize(void)``** &mdash; ������������ ������� (��������������� � ��������� �����).

- **``Vector & transformTo(const Vector & e1, const Vector & e2)``** &mdash; �������������� �������� ������� � ������ ������� ��������� � ������� ``e1`` � ``e2``.

- **``Vector & transformFrom(const Vector & e1, const Vector & e2)``** &mdash; �������������� �������� ������� �� ������� ��������� � ������� ``e1`` � ``e2``.

#### ����������� ���������, ����������� � �������� ���������� ``Vector``

- **``Vector operator * (const double & lhs, const Vector & rhs)``** &mdash; �������� ��������� ������� �� ������.

#### �������, ����������� � �������� ���������� ``Vector``

- **``Vector rotate(const Vector & v, double angle)``** &mdash; ������� �������� ������� ``v`` �� ���� ``angle``, �������� � ��������.

- **``Vector rotate(const Vector & v, int quad)``** &mdash; ������� �������� ������� ``v`` �� ���� ������� 90 ��������.

- **``double module2(const Vector & v)``** &mdash; ������� ���������� �������� ������ ������� ``v``.

- **``double length(const Vector & v)``** &mdash; �������, ����������� ����� ������� ``v``.

- **``double angle(const Vector & v)``** &mdash; ������� ���������� ���� ����� �������� ``v`` � ���� X.

- **``double angle(const Vector & v1, const Vector & v2)``** &mdash; ������� ���������� ���� ����� ��������� ``v1`` � ``v2``.

- **``double projection(const Vector & v, const Vector & base)``** &mdash; ������� ���������� �������� ������� ``v`` �� ������ ``base``.

- **``Vector normalize(const Vector & v)``** &mdash; ������� ������������ ��������� ``v``.

- **``Vector transformTo(const Vector & v, const Vector & e1, const Vector & e2)``** &mdash; ������� �������������� ������� ``v`` � ������� ��������� � ������� ``e1`` � ``e2``.

- **``Vector transformFrom(const Vector & v, const Vector & e1, const Vector & e2)``** &mdash; ������� �������������� ������� ``v`` �� ������� ��������� � ������� ``e1`` � ``e2``.

### ����������

1. � **``public``** �������, ������ **``Vector``** ���������� �������� � ������ ������ ������������� **``static``** � **``const``**. 
2. ������ ������ �������� **```public```** � **```protected```** ������� ������, � ����� ���� � ���������� ���������� � ���.
3. �������� header � source ������ ���������: **```Vector.hpp, Vector.cpp```**.
4. �������� unit test'� ��� �������������� ������. 