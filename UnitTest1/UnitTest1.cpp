#include "CppUnitTest.h"
#include "..\Vector\Vector.hpp"

#define PI 3.14159265
#define epsilon 0.0001

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

bool equality_check(const double& d1, const double& d2)
{
	return (fabs(d1 - d2) < epsilon);
}

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Test_ConstructorXY)
		{
			Vector vector(5.5, 4.3);
			Assert::IsTrue(equality_check(vector.x(), 5.5));
			Assert::IsTrue(equality_check(vector.y(), 4.3));
		}

		TEST_METHOD(Test_ConstructorEmpty)
		{
			Vector vector;
			vector.x(5.5);
			vector.y(4.3);
			Assert::IsTrue(equality_check(vector.x(), 5.5));
			Assert::IsTrue(equality_check(vector.y(), 4.3));
		}

		TEST_METHOD(Test_ConstructorCopy)
		{
			Vector vector(5.5, 4.3);
			Vector vector_copy1(vector);
			Vector vector_copy2 = vector;

			Assert::IsTrue(equality_check(vector_copy1.x(), 5.5));
			Assert::IsTrue(equality_check(vector_copy1.y(), 4.3));

			Assert::IsTrue(equality_check(vector_copy2.x(), 5.5));
			Assert::IsTrue(equality_check(vector_copy2.y(), 4.3));
		}

		TEST_METHOD(Test_Appropriation)
		{
			Vector vector(5.5, 4.3);
			Vector vector_copy;
			vector_copy = vector;

			Assert::IsTrue(equality_check(vector_copy.x(), 5.5));
			Assert::IsTrue(equality_check(vector_copy.y(), 4.3));
		}

		TEST_METHOD(Test_DifferenceEquals)
		{
			Vector vector1(5.5, 4.3);
			Vector vector2(1.2, 2.3);
			vector1 -= vector2;

			Assert::IsTrue(equality_check(vector1.x(), 4.3));
			Assert::IsTrue(equality_check(vector1.y(), 2.0));
		}

		TEST_METHOD(Test_SumEquals)
		{
			Vector vector1(5.5, 4.3);
			Vector vector2(1.2, 2.3);
			vector1 += vector2;

			Assert::IsTrue(equality_check(vector1.x(), 6.7));
			Assert::IsTrue(equality_check(vector1.y(), 6.6));
		}

		TEST_METHOD(Test_MultiplicationEquals)
		{
			Vector vector(5.1, 4.1);
			vector *= 5;

			Assert::IsTrue(equality_check(vector.x(), 25.5));
			Assert::IsTrue(equality_check(vector.y(), 20.5));
		}

		TEST_METHOD(Test_DivisionEquals)
		{
			Vector vector(5.5, 10.0);
			vector /= 5;

			Assert::IsTrue(equality_check(vector.x(), 1.1));
			Assert::IsTrue(equality_check(vector.y(), 2.0));
		}

		TEST_METHOD(Test_Difference)
		{
			Vector vector1(5.5, 4.3);
			Vector vector2(1.2, 2.3);
			Vector vector = vector1 - vector2;

			Assert::IsTrue(equality_check(vector.x(), 4.3));
			Assert::IsTrue(equality_check(vector.y(), 2.0));


			Assert::IsTrue(equality_check(vector1.x(), 5.5));
			Assert::IsTrue(equality_check(vector1.y(), 4.3));

			Assert::IsTrue(equality_check(vector2.x(), 1.2));
			Assert::IsTrue(equality_check(vector2.y(), 2.3));
		}

		TEST_METHOD(Test_Sum)
		{
			Vector vector1(5.5, 4.3);
			Vector vector2(1.2, 2.3);
			Vector vector = vector1 + vector2;

			Assert::IsTrue(equality_check(vector.x(), 6.7));
			Assert::IsTrue(equality_check(vector.y(), 6.6));


			Assert::IsTrue(equality_check(vector1.x(), 5.5));
			Assert::IsTrue(equality_check(vector1.y(), 4.3));

			Assert::IsTrue(equality_check(vector2.x(), 1.2));
			Assert::IsTrue(equality_check(vector2.y(), 2.3));
		}

		TEST_METHOD(Test_MultiplicationVectorVector)
		{
			Vector vector1(1.2, 5.0);
			Vector vector2(5.0, 1.2);

			Assert::IsTrue(equality_check(vector1 * vector2, 12.0));

			Assert::IsTrue(equality_check(vector1.x(), 1.2));
			Assert::IsTrue(equality_check(vector1.y(), 5.0));

			Assert::IsTrue(equality_check(vector2.x(), 5.0));
			Assert::IsTrue(equality_check(vector2.y(), 1.2));
		}


		TEST_METHOD(Test_MultiplicationVectorScalar1)
		{
			Vector vector1(1.2, 5.0);
			Vector vector = vector1 * 5;

			Assert::IsTrue(equality_check(vector.x(), 6.0));
			Assert::IsTrue(equality_check(vector.y(), 25.0));

			Assert::IsTrue(equality_check(vector1.x(), 1.2));
			Assert::IsTrue(equality_check(vector1.y(), 5.0));
		}

		TEST_METHOD(Test_MultiplicationVectorScalar2)
		{
			Vector vector(1.2, 5.0);

			Assert::IsTrue(equality_check(operator*(5, vector).x(), 6.0));
			Assert::IsTrue(equality_check(operator*(5, vector).y(), 25.0));

			Assert::IsTrue(vector.x() == 1.2);
			Assert::IsTrue(equality_check(vector.y(), 5.0));
		}

		TEST_METHOD(Test_Division)
		{
			Vector vector1(3.0, 6.0);
			Vector vector = vector1 / 3;

			Assert::IsTrue(equality_check(vector.x(), 1.0));
			Assert::IsTrue(equality_check(vector.y(), 2.0));

			Assert::IsTrue(equality_check(vector1.x(), 3.0));
			Assert::IsTrue(equality_check(vector1.y(), 6.0));
		}

		TEST_METHOD(Test_LogEquals)
		{
			Vector vector1(1.2, 5.0);
			Vector vector = vector1;

			Assert::IsTrue((vector == vector1));
		}

		TEST_METHOD(Test_LogNotEquals)
		{
			Vector vector1(1.2, 5.0);
			Vector vector = vector1 * 2;

			Assert::IsTrue((vector != vector1));
		}

		TEST_METHOD(Test_Negation)
		{
			Vector vector1(1.2, 5.0);
			Vector vector = -vector1;

			Assert::IsTrue(equality_check(vector.x(), -1.2));
			Assert::IsTrue(equality_check(vector.y(), -5.0));
		}

		TEST_METHOD(Test_Module2)
		{
			Vector vector;

			//test1
			vector.x(1.2);
			vector.y(5.0);

			Assert::IsTrue(equality_check(module2(vector), 26.44));
			Assert::IsTrue(equality_check(vector.module2(), 26.44));

			//test2
			vector.x(0);
			vector.y(0);

			Assert::IsTrue(equality_check(module2(vector), 0));
			Assert::IsTrue(equality_check(vector.module2(), 0));

		}

		TEST_METHOD(Test_Lenght)
		{
			Vector vector;

			//test1
			vector.x(3.0);
			vector.y(4.0);

			Assert::IsTrue(equality_check(length(vector), 5.0));
			Assert::IsTrue(equality_check(vector.length(), 5.0));

			//test2
			vector.x(0);
			vector.y(0);

			Assert::IsTrue(equality_check(length(vector), 0));
			Assert::IsTrue(equality_check(vector.length(), 0));
		}

		TEST_METHOD(Test_AngleVectorAndOX)
		{
			Vector vector;

			//test1
			vector.x(5);
			vector.y(5);

			Assert::IsTrue(equality_check(angle(vector), PI/4));
			Assert::IsTrue(equality_check(vector.angle(), PI / 4));


			//test2
			vector.x(sqrt(3)/2);
			vector.y(0.5);

			Assert::IsTrue(equality_check(angle(vector), PI / 6));
			Assert::IsTrue(equality_check(vector.angle(), PI / 6));

			//test3
			vector.x(1);
			vector.y(-1);

			Assert::IsTrue(equality_check(angle(vector), -PI / 4));
			Assert::IsTrue(equality_check(vector.angle(), -PI / 4));


			//test4
			vector.x(-1);
			vector.y(-1);

			Assert::IsTrue(equality_check(angle(vector), - 3 * PI / 4));
			Assert::IsTrue(equality_check(vector.angle(), - 3 * PI / 4));

			//test5
			vector.x(-1);
			vector.y(1);

			Assert::IsTrue(equality_check(angle(vector), 3 * PI / 4));
			Assert::IsTrue(equality_check(vector.angle(), 3 * PI / 4));

			//test6
			vector.x(-20);
			vector.y(0);

			Assert::IsTrue(equality_check(angle(vector), PI));
			Assert::IsTrue(equality_check(vector.angle(), PI));

			//test7
			vector.x(sqrt(3) / 2);
			vector.y(0.5);

			Assert::IsTrue(equality_check(angle(vector), PI / 6));
			Assert::IsTrue(equality_check(vector.angle(), PI / 6));

			//test8
			vector.x(0.5);
			vector.y(sqrt(3) / 2);

			Assert::IsTrue(equality_check(angle(vector), PI / 3));
			Assert::IsTrue(equality_check(vector.angle(), PI / 3));
		}

		TEST_METHOD(Test_AngleVectorAndVector)
		{
			Vector vector1, vector2;

			//test1
			vector1.x(1.5); 
			vector1.y(5);
			vector2.x(-5); 
			vector2.y(1.5);


			Assert::IsTrue(equality_check(angle(vector1, vector2), -PI / 2));
			Assert::IsTrue(equality_check(vector1.angle(vector2), -PI / 2));


			//test2
			vector1.x(2.5 * sqrt(3));
			vector1.y(2.5);
			vector2.x(1);
			vector2.y(sqrt(3));


			Assert::IsTrue(equality_check(angle(vector1, vector2), -PI / 6));
			Assert::IsTrue(equality_check(vector1.angle(vector2), -PI / 6));

			//test3
			vector1.x(1);
			vector1.y(-1);
			vector2.x(1);
			vector2.y(1);


			Assert::IsTrue(equality_check(angle(vector1, vector2), -PI / 2));
			Assert::IsTrue(equality_check(vector1.angle(vector2), -PI / 2));
		}

		TEST_METHOD(Test_Projection)
		{
			Vector vector1, vector2;

			//test1
			vector1.x(6.21);
			vector1.y(5);
			vector2.x(1);
			vector2.y(0);


			Assert::IsTrue(equality_check(projection(vector1, vector2), 6.21));
			Assert::IsTrue(equality_check(vector1.projection(vector2), 6.21));


			//test2
			vector1.x(3);
			vector1.y(3);
			vector2.x(3);
			vector2.y(-3);


			Assert::IsTrue(equality_check(projection(vector1, vector2), 0));
			Assert::IsTrue(equality_check(vector1.projection(vector2), 0));

			//test3
			vector2.x(1);
			vector2.y(2);


			Assert::IsTrue(equality_check(projection(vector1, vector2), (9 / sqrt(5))));
			Assert::IsTrue(equality_check(vector1.projection(vector2), (9 / sqrt(5))));
		}

		TEST_METHOD(Test_Normalize)
		{
			Vector vector;
			
			//test1
			vector.x(1);
			vector.y(0);

			Assert::IsTrue(equality_check(normalize(vector).x(), 1) && equality_check(normalize(vector).y(), 0));
			
			vector.normalize();
			Assert::IsTrue(equality_check(vector.x(), 1) && equality_check(vector.y(), 0));

			//test2
			vector.x(3);
			vector.y(4);

			Assert::IsTrue(equality_check(normalize(vector).x(), 0.6) && equality_check(normalize(vector).y(), 0.8));

			vector.normalize();
			Assert::IsTrue(equality_check(vector.x(), 0.6) && equality_check(vector.y(), 0.8));

			//test3
			vector.x(PI);
			vector.y(PI/2);

			Assert::IsTrue(equality_check(normalize(vector).x(), sqrt(0.8)) && equality_check(normalize(vector).y(), sqrt(0.2)));

			vector.normalize();
			Assert::IsTrue(equality_check(vector.x(), sqrt(0.8)) && equality_check(vector.y(), sqrt(0.2)));

		}

		TEST_METHOD(Test_Rotate90)
		{
			Vector vector(-2, -6);
			Vector vector_angle(2, 6);

			Assert::IsTrue(equality_check(angle(vector, vector_angle), -PI));

			Assert::IsTrue(equality_check(rotate(rotate(vector_angle, 3), -1).x(), vector.x()));
			Assert::IsTrue(equality_check(rotate(rotate(vector_angle, 3), -1).y(), vector.y()));

			vector_angle.rotate(3).rotate(-1);
			
			Assert::IsTrue(equality_check(vector_angle.x(), vector.x()));
			Assert::IsTrue(equality_check(vector_angle.y(), vector.y()));
		}

		TEST_METHOD(Test_Rotate)
		{
			Vector vector(1, 0);

			Assert::IsTrue(equality_check(rotate(vector, PI/4).x(), sqrt(2) / 2));
			Assert::IsTrue(equality_check(rotate(vector, PI/4).y(), sqrt(2) / 2));
		}

		TEST_METHOD(Test_MakePolar)
		{
			Vector vector;
			
			Assert::IsTrue(equality_check(vector.makePolar(5, PI/6).x(), 2.5 * sqrt(3)));
			Assert::IsTrue(equality_check(vector.makePolar(4, PI/3).y(), 2 * sqrt(3)));

		}

		TEST_METHOD(Test_TransformTo)
		{
			Vector e1(1, 1), e2(1, -1), vector;

			//test1
			vector.x(1);
			vector.y(1);

			Assert::IsTrue(equality_check(transformTo(vector, e1, e2).x(), sqrt(2)));
			Assert::IsTrue(equality_check(transformTo(vector, e1, e2).y(), 0));
			
			vector.transformTo(e1, e2);
			Assert::IsTrue(equality_check(vector.x(), sqrt(2)));
			Assert::IsTrue(equality_check(vector.y(), 0));


			//test2
			vector.x(1);
			vector.y(-1);

			Assert::IsTrue(equality_check(transformTo(vector, e1, e2).x(), 0));
			Assert::IsTrue(equality_check(transformTo(vector, e1, e2).y(), sqrt(2)));
			
			vector.transformTo(e1, e2);
			Assert::IsTrue(equality_check(vector.x(), 0));
			Assert::IsTrue(equality_check(vector.y(), sqrt(2)));

			//test3
			e1.x(-1);
			e1.y(0);
			e2.x(0);
			e2.y(-1);
			vector.x(-3);
			vector.y(-2);

			Assert::IsTrue(equality_check(transformTo(vector, e1, e2).x(), 3.0));
			Assert::IsTrue(equality_check(transformTo(vector, e1, e2).y(), 2.0));
			
			vector.transformTo(e1, e2);
			Assert::IsTrue(equality_check(vector.x(), 3.0));
			Assert::IsTrue(equality_check(vector.y(), 2.0));
		}

		TEST_METHOD(Test_TransformFrom)
		{
			Vector e1(1, 0), e2(0, -1), vector;

			//test1
			vector.x(0);
			vector.y(1);
			Assert::IsTrue(equality_check(transformFrom(vector, e1, e2).x(), 0));
			Assert::IsTrue(equality_check(transformFrom(vector, e1, e2).y(), -1.0));

			vector.transformFrom(e1, e2);
			Assert::IsTrue(equality_check(vector.x(), 0));
			Assert::IsTrue(equality_check(vector.y(), -1.0));

			//test2
			e1.x(2);
			e1.y(1);
			e2.x(1);
			e2.y(2);
			vector.x(2);
			vector.y(3);

			Assert::IsTrue(equality_check(transformFrom(vector, e1, e2).x(), sqrt(5) / 3));
			Assert::IsTrue(equality_check(transformFrom(vector, e1, e2).y(), 4 * sqrt(5) / 3));

			vector.transformFrom(e1, e2);
			Assert::IsTrue(equality_check(vector.x(), sqrt(5) / 3));
			Assert::IsTrue(equality_check(vector.y(), 4 * sqrt(5) / 3));
		}
	};
}