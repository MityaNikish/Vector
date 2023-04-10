#ifndef __vector_h
#define __vector_h

class Vector final
{
public:
	Vector(void); //конструктор создания
	explicit Vector(double x, double y); //констру-ктор создания + инициализация

public:
	Vector(const Vector& that); //коструктор копирования
	Vector& operator =(const Vector& that); //операто присваивания-копирования

public:
	static Vector makePolar(double rad, double alpha);  //инициализация нового экземпляра класса

public:
	double x(void) const; //GETер для X координаты
	double y(void) const; //GETер для Y координаты
	void x(double newX); //SETер для X координаты
	void y(double newY); //SETер для Y координаты

public: //операторы
	Vector operator + (const Vector& that) const;
	Vector operator - (const Vector& that) const;
	double operator * (const Vector& that) const;
	Vector operator * (const double& that) const;
	Vector operator / (const double& that) const;

public:
	Vector& operator += (const Vector& that);
	Vector& operator -= (const Vector& that);
	Vector& operator *= (const double& that);
	Vector& operator /= (const double& that);

public:
	Vector operator -() const;

public:
	bool operator == (const Vector& that) const;
	bool operator != (const Vector& that) const;

public:  //методы
	Vector& rotate(double angle);
	Vector& rotate(int quad);
	double module2(void) const;
	double angle(void) const;
	double angle(const Vector& that) const;
	double length(void) const;
	double projection(const Vector& base) const;
	Vector& normalize(void);
	Vector& transformTo(const Vector& e1, const Vector& e2);
	Vector& transformFrom(const Vector& e1, const Vector& e2);

private:  //поля с координатами X и Y
	double data_x, data_y;
	double MultVect(const Vector& that) const;
	bool ZeroVector(void) const;
};

//функции над классом

Vector operator * (const double& lhs, const Vector& rhs);

Vector rotate(const Vector& v, double angle);
Vector rotate(const Vector& v, int quad);
double module2(const Vector& v);
double length(const Vector& v);
double angle(const Vector& v);
double angle(const Vector& v1, const Vector& v2);
double projection(const Vector& v, const Vector& base);
Vector normalize(const Vector& v);
Vector transformTo(const Vector& v, const Vector& e1, const Vector& e2);
Vector transformFrom(const Vector& v, const Vector& e1, const Vector& e2);

#endif