#include <iostream>
#include <cmath>

#include "Vector.hpp"

static const double epsilon = 0.0001;

namespace
{
	static bool is_zero(const double& d)
	{
		return fabs(d) < epsilon;
	}
}

//using namespace F;

bool Vector::ZeroVector(void) const
{
	return is_zero(data_x) && is_zero(data_y);
}

double Vector::MultVect(const Vector& that) const
{
	return data_x * that.data_y - data_y * that.data_x;
}

Vector::Vector() : data_x(0.), data_y(0.) {}

Vector::Vector(double x, double y) : data_x(x), data_y(y) {}


Vector::Vector(const Vector& that) = default;

Vector& Vector::operator =(const Vector& that) = default;


Vector Vector::makePolar(double rad, double alpha)
{
	return Vector(rad * cos(alpha), rad * sin(alpha));
}



double Vector::x(void) const
{
	return data_x;
}

double Vector::y(void) const
{
	return data_y;
}

void Vector::x(double newX)
{
	data_x = newX;
}

void Vector::y(double newY)
{
	data_y = newY;
}



Vector Vector::operator + (const Vector& that) const
{
	return Vector(data_x + that.data_x, data_y + that.data_y);
}

Vector Vector::operator - (const Vector& that) const
{
	return Vector(data_x - that.data_x, data_y - that.data_y);
}

double Vector::operator * (const Vector& that) const
{
	return data_x * that.data_x + data_y * that.data_y;
}

Vector Vector::operator * (const double& that) const
{
	return Vector(data_x * that, data_y * that);
}

Vector Vector::operator / (const double& that) const
{
	if (is_zero(that)) { throw std::overflow_error("Divide by zero exception"); }

	return Vector(data_x / that, data_y / that);
}




Vector& Vector::operator += (const Vector& that)
{
	return *this = Vector(data_x + that.data_x, data_y + that.data_y);
}

Vector& Vector::operator -= (const Vector& that)
{
	return *this = Vector(data_x - that.data_x, data_y - that.data_y);
}

Vector& Vector::operator *= (const double& that)
{
	return *this = Vector(data_x * that, data_y * that);
}

Vector& Vector::operator /= (const double& that)
{
	if (is_zero(that)) { throw std::overflow_error("Divide by zero exception"); }

	return *this = Vector(data_x / that, data_y / that);
}


Vector Vector::operator -() const
{
	return Vector(-data_x, -data_y);
}


bool Vector::operator == (const Vector& that) const
{
	return (data_x == that.data_x) && (data_y == that.data_y);
}

bool Vector::operator != (const Vector& that) const
{
	return !((data_x == that.data_x) && (data_y == that.data_y));
}





Vector& Vector::rotate(double angle)
{
	return *this = Vector(data_x * cos(angle) - data_y * sin(angle), data_x * sin(angle) + data_y * cos(angle));
}

Vector& Vector::rotate(int quad)
{
	bool dir = (quad >= 0); //direction [1 - против часовой / 0 - по часовой]
	int mult = abs(quad); //multiplicity [кратность 90]
	double temp;

	if (mult % 2 == 0)
	{
		return *this = Vector(pow(-1, mult / 2) * data_x, pow(-1, mult / 2) * data_y);
	}
	else
	{
		temp = data_x;
		return *this = Vector(pow(-1, mult / 2 + dir) * data_y, pow(-1, mult / 2 + (1 - dir)) * temp);
	}
}

double Vector::module2(void) const
{
	return *this * *this;
}

double Vector::angle(void) const
{
	if (ZeroVector()) { throw std::overflow_error("Unable to determine the angle of a null vector."); }
	return acos(data_x / length()) * pow(-1, (data_y < 0));
}

double Vector::angle(const Vector& that) const
{
	if (ZeroVector() || that.ZeroVector()) { return 0; }
	if (*this == that) { return 0; }

	return acos((*this * that) / (length() * that.length())) * pow(-1, (angle() < that.angle()));
}

double Vector::length(void) const
{
	return pow(*this * *this, 0.5);
}

double Vector::projection(const Vector& base) const
{
	if (base.ZeroVector()) { return 0; }

	return (*this * base) / base.length();
}

Vector& Vector::normalize(void)
{;
	if (ZeroVector()) { return *this; }

	return *this = Vector(data_x / length(), data_y / length());
}

Vector& Vector::transformTo(const Vector& e1, const Vector& e2)
{
	Vector temp_e1 = e1, temp_e2 = e2;

	temp_e1.normalize();
	temp_e2.normalize();

	return *this = Vector(temp_e1 * *this, temp_e2 * *this);
}

Vector& Vector::transformFrom(const Vector& e1, const Vector& e2)
{
	Vector temp_e1 = e1, temp_e2 = e2, temp_v = *this;
	double determinant = 0;

	temp_e1.normalize();
	temp_e2.normalize();

	determinant = temp_e1.MultVect(temp_e2);
	if (fabs(determinant) < epsilon) { throw std::overflow_error("Divide by zero exception"); }


	data_x = Vector(temp_e2.y(), (-1) * temp_e1.y()) * temp_v / determinant;
	data_y = Vector((-1) * temp_e2.x(), temp_e1.x()) * temp_v / determinant;

	return *this;
}




Vector operator * (const double& lhs, const Vector& rhs)
{
	return rhs * lhs;
}

Vector rotate(const Vector& v, double angle)
{
	Vector temp_v = v;
	return temp_v.rotate(angle);
}

Vector rotate(const Vector& v, int quad)
{
	Vector temp_v = v;
	return temp_v.rotate(quad);
}

double module2(const Vector& v)
{
	return v.module2();
}

double length(const Vector& v)
{
	return v.length();
}

double angle(const Vector& v)
{
	return v.angle();
}

double angle(const Vector& v1, const Vector& v2)
{
	return v1.angle(v2);
}

double projection(const Vector& v, const Vector& base)
{
	return v.projection(base);
}

Vector normalize(const Vector& v)
{
	Vector temp_v = v;
	return temp_v.normalize();
}

Vector transformTo(const Vector& v, const Vector& e1, const Vector& e2)
{
	Vector temp_v = v;
	return temp_v.transformTo(e1, e2);
}
 
Vector transformFrom(const Vector& v, const Vector& e1, const Vector& e2)
{
	Vector temp_v = v;
	return temp_v.transformFrom(e1, e2);
}