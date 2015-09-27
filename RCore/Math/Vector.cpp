#include "stdafx.h"
#include "Vector.h"

namespace Ray
{
	// Vector2
	const Vector2 Vector2::Zero = Vector2(0.0f,0.0f);
	const Vector2 Vector2::Uint_X = Vector2(1.0f,0.0f);
	const Vector2 Vector2::Uint_Y = Vector2(0.0f,1.0f);

	// Vector3
	const Vector3 Vector3::Zero = Vector3(0.0f,0.0f,0.0f);
	const Vector3 Vector3::Uint_X = Vector3(1.0f,0.0f,0.0f);
	const Vector3 Vector3::Uint_Y = Vector3(0.0f,1.0f,0.0f);
	const Vector3 Vector3::Uint_Z = Vector3(0.0f,0.0f,1.0f);

	const Vector4 Vector4::Zero   = Vector4(0.0f,0.0f,0.0f,0.0f);
	const Vector4 Vector4::Uint_X = Vector4(1.0f,0.0f,0.0f,0.0f);
	const Vector4 Vector4::Uint_Y = Vector4(0.0f,1.0f,0.0f,0.0f);
	const Vector4 Vector4::Uint_Z = Vector4(0.0f,0.0f,1.0f,0.0f);
	const Vector4 Vector4::Uint_W = Vector4(0.0f,0.0f,0.0f,1.0f);
};
