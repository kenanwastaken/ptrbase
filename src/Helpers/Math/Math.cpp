#include "Math.h"

double Math::CropAngle180(double angle)
{
	while (angle <= -180.0) angle += 360.0;
	while (angle > 180.0) angle -= 360.0;
	return angle;
}
