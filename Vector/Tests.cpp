#include <iostream>
#include "Vector.hpp"
//using namespace std;


int main()
{
	Vector vector(5.5, 4.3);
	vector.x();
	vector.y();
	std::cout << std::endl;

	Vector vector1;
	vector1.x(1.2);
	vector1.y(1.2);
	vector1.x();
	vector1.y();
	std::cout << std::endl;

	Vector vector2(vector1);
	vector2.x();
	vector2.y();
	std::cout << std::endl;

	Vector vector3;
	vector3 = vector1;
	vector3.x();
	vector3.y();
	std::cout << std::endl;



	Vector vector4 = vector1;
	vector4 -= vector1;
	vector4.x();
	vector4.y();
	std::cout << std::endl;

	vector4 += vector1;
	vector4.x();
	vector4.y();
	std::cout << std::endl;

	vector4 *= 5;
	vector4.x();
	vector4.y();
	std::cout << std::endl;

	vector4 /=  3;
	vector4.x();
	vector4.y();
	std::cout << std::endl;



	Vector vector5 = vector1 - vector1;
	vector5.x();
	vector5.y();
	std::cout << std::endl;

	vector5 = vector1 + vector1;
	vector5.x();
	vector5.y();
	std::cout << std::endl;

	vector5 = vector1 * 5;
	vector5.x();
	vector5.y();
	std::cout << std::endl;

	vector5 = vector1 / 3;
	vector5.x();
	vector5.y();
	std::cout << std::endl;

	std::cout << (vector1 == vector1) << std::endl;
	std::cout << (vector1 != vector) << std::endl;

	vector5 = -vector1;
	vector5.x();
	vector5.y();

	std::cout << vector.module2() << std::endl;
	std::cout << module2(vector) << std::endl;
	std::cout << vector.length() << std::endl;
	std::cout << length(vector) << std::endl;
	std::cout << vector.angle() << std::endl;
	std::cout << angle(vector) << std::endl;
	std::cout << vector.angle(vector1) << std::endl;
	std::cout << angle(vector, vector1) << std::endl;
	std::cout << vector.projection(vector1) << std::endl;
	std::cout << projection(vector, vector1) << std::endl;

	std::cout << (vector.normalize() == normalize(vector)) << std::endl;
	vector.normalize().x();
	vector.normalize().y();



	Vector vector_angle;
	vector_angle.x(2);
	vector_angle.y(6);
	vector_angle.rotate(270);
	vector_angle.x();
	vector_angle.y();

	vector_angle.rotate(-180);
	vector_angle.x();
	vector_angle.y();


	vector_angle.rotate(-90);
	vector_angle.x();
	vector_angle.y();

	vector_angle.makePolar(1.4142, 45);
	vector_angle.x();
	vector_angle.y();

	vector_angle.rotate(6.4);
	vector_angle.x();
	vector_angle.y();

	Vector vector_test;
	std::cout << vector_test.makePolar(6, 60).x() << std::endl;
	std::cout << vector_test.makePolar(6, 30).y() << std::endl;

	vector_test.x(6);
	vector_test.y(2);
	vector_test.rotate(270).rotate(-90);
	std::cout << vector_test.x() << std::endl;
	std::cout << vector_test.y() << std::endl;

	vector_test.x(6);
	vector_test.y(2);
	std::cout << rotate(rotate(vector_test, 270), -90).x() << std::endl;
	std::cout << rotate(rotate(vector_test, 270), -90).y() << std::endl;


	//Vector e1(1, 1), e2(1, -1), vector_to(1, 1);
	//vector_to.transformTo(e1, e2);

	//std::cout << vector_to.x() << std::endl;
	//std::cout << vector_to.y() << std::endl;


	Vector e1(1, 1), e2(1, -1), vector_to(1, 1);
	//vector_to.transformFrom(e1, e2);

	//std::cout << transformTo(vector_to, e1, e2).x() << std::endl;
	//std::cout << transformTo(vector_to, e1, e2).y() << std::endl;

	Vector vec(0, 0);
	normalize(vec);

	//std::cout << vector_to.x() << std::endl;
	//std::cout << vector_to.y() << std::endl;

	Vector vector_t(5.5, 4.3);
	Vector vector_copyt;
	vector_copyt = vector_t;

	vector.x(sqrt(3) / 2);
	vector.y(0.5);

	angle(vector);

	return 0;
}