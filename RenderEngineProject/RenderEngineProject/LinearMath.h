#pragma once

#include <memory.h>
#include<math.h>

#include"Vector4D.h"
#include"Matrix4x4.h"
#include"Vector3D.h"
#include"Vertex.h"

namespace RenderEngine
{
	const double PI = 3.14159;
	const float EPSILON = 0.00001f;

	///////////////////////////////////////////////////
	//Vector maths
	///////////////////////////////////////////////////

	//Dot Product
	float DotProduct(Vector3D& operand, Vector3D& operand2);

	//Cross product answer will be written to Vec4 Dest
	void CrossProduct(Vector3D& Dest,const Vector3D& operand, const Vector3D& operand2);

	//Dot Product
	float DotProduct(Vector4D& operand, Vector4D& operand2);

	//Cross product answer will be written to Vec4 Dest
	void CrossProduct(Vector4D& Dest,const Vector4D& operand, const Vector4D& operand2);

	//Get the length of a vector.
	float GetLength(Vector3D& vector);

	//Compute transform axis from object position and target point
	void LookAtToAxis(const Vector3D& position,const Vector3D& target,
					  Vector3D& left,Vector3D&upDir, Vector3D& forward);

	// compute transform axis from object position, target and up direction
	void LookAtToAxes(const Vector3D& pos, const Vector3D& target, const Vector3D& upDir,
					  Vector3D& left, Vector3D& up, Vector3D& forward);

	///////////////////////////////////////////////////
	//Matrix maths
	///////////////////////////////////////////////////

	void MultiMat4x4(Matrix4x4& dest,const Matrix4x4& operand, const Matrix4x4& operand2);

	void ScaleMatrix(Matrix4x4& matrix,float xScale,float yScale, float zScale);

	void TranslationMatrix(Matrix4x4& matrix,float xTrans,float yTrans,float zTrans);

	void RotationXMatrix(Matrix4x4& matrix,float xRot);

	void RotationYMatrix(Matrix4x4& matrix,float yRot);

	void RotationZMatrix(Matrix4x4& matrix,float zRot);

	void MakeIdentity(Matrix4x4& matrix);

	///////////////////////////////////////////////////
	//Vector * Matrix maths
	///////////////////////////////////////////////////

	Vector3D Vec3MultiMat4x4(Matrix4x4& matrix,const Vector3D& vector);

	Vector4D Vec3Vec4MultiMat4x4(Matrix4x4& matrix,const Vector3D& vector);

	Vector4D Vec4MultiMat4x4(Matrix4x4& matrix,const Vector4D& vector);

	void Vec3MultiMat4x4(Vector3D& dest, Matrix4x4& matrix,const Vector3D& vector);

	void Vec4MultiMat4x4(Vector4D& dest, Matrix4x4& matrix, const Vector4D& vector);


	//functions from internet forgot source...
	#undef min
	#undef max

	template<class T>
	inline T max(T a, T b)
	{
		return a > b ? a : b;
	}

	template<class T>
	inline T min(T a, T b) 
	{
		return a < b ? a : b;
	}

	template<class T>
	inline T max(T a, T b, T c)
	{
		return a > b ? (a > c ? a : c) : (b > c ? b : c);
	}

	template<class T>
	inline T min(T a, T b, T c)
	{
		return a < b ? (a < c ? a : c) : (b < c ? b : c);
	}


	//Code from internet forgot from where..
	inline int iround(float x)
	{
		int t;

		__asm
		{
			fld   x
			fistp t
		}

		return t;
	}

	inline int ifloor(float x)
	{
		const float h = 0.5f;

		int t;

		__asm
		{
			fld   x
			fsub	h
			fistp t
		}

		return t;
	}

	inline int ceilFix4(int x)
	{
		return (x + 0xF) & 0xFFFFFFF0;
	}

	inline int ceilInt4(int x)
	{
		return (x + 0xF) >> 4;
	}

	// Mathematically correct flooring divide
	inline int floorDiv(int a, int b)
	{
		if(b == 0)
		{
			return 0x80000000;   // Prevent exception
		}

		int q;   // Quotient
		int r;   // Remainder

		if(a >= 0)
		{
			q = a / b;
		}
		else
		{
			q = -(-a / b);
			r = -a % b;

			if(r)
			{
				q--;
			}
		}

		return q;
	}

	// Mathematically correct ceiling divide
	inline int ceilDiv(int a, int b)
	{
		if(b == 0)
		{
			return 0x80000000;   // Prevent exception
		}

		a += - 1 + b;

		int q;   // Quotient
		int r;   // Remainder

		if(a >= 0)
		{
			q = a / b;
		}
		else
		{
			q = -(-a / b);
			r = -a % b;

			if(r)
			{
				q--;
			}
		}

		return q;
	}

	// Mathematically correct flooring modulo
	inline int floorMod(int a, int b)
	{
		if(b == 0)
		{
			return 0x80000000;   // Prevent exception
		}

		int r;   // Remainder

		if(a >= 0)
		{
			r = a % b;
		}
		else
		{
			r = -a % b;

			if(r)
			{
				r = b - r;
			}
		}

		return r;
	}

	// Mathematically correct ceiling modulo
	inline int ceilMod(int a, int b)
	{
		if(b == 0)
		{
			return 0x80000000;   // Prevent exception
		}

		a += - 1 + b;

		int r;   // Remainder

		if(a >= 0)
		{
			r = a % b;
		}
		else
		{
			r = -a % b;

			if(r)
			{
				r = b - r;
			}
		}

		return r + 1 - b;
	}
}