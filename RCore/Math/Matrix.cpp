#include "Matrix.h"

namespace Ray
{
	const Matrix33 Matrix33::Identity = Matrix33(1.0f,0.0f,0.0f,
												 0.0f,1.0f,0.0f,
												 0.0f,0.0f,1.0f);

	const Matrix33 Matrix33::Zero =     Matrix33(0.0f,0.0f,0.0f,
											     0.0f,0.0f,0.0f,
											     0.0f,0.0f,0.0f);

	const Matrix44 Matrix44::Identity = Matrix44(1.0f,0.0f,0.0f,0.0f,
												 0.0f,1.0f,0.0f,0.0f,
												 0.0f,0.0f,1.0f,0.0f,
												 0.0f,0.0f,0.0f,1.0f);

	const Matrix44 Matrix44::Zero     = Matrix44(0.0f,0.0f,0.0f,0.0f,
												 0.0f,0.0f,0.0f,0.0f,
												 0.0f,0.0f,0.0f,0.0f,
												 0.0f,0.0f,0.0f,0.0f);
};// end of Ray
