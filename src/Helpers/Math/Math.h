#pragma once

namespace Math
{
	class Vec3d
	{
	public:
		Vec3d(double x, double y, double z) : dX(x), dY(y), dZ(z) {}

		void SetX(double x) { dX = x; }
		void SetY(double y) { dY = y; }
		void SetZ(double z) { dZ = z; }

		double GetX() { return dX; }
		double GetY() { return dY; }
		double GetZ() { return dZ; }
	private:
		double dX, dY, dZ;
	};

	class VecRotation
	{
	public:
		VecRotation(float RotationYaw, float RotationPitch) : m_RotationYaw(RotationYaw), m_RotationPitch(RotationPitch) {}

		void SetYaw(float x) { m_RotationYaw = x; }
		void SetPitch(float y) { m_RotationPitch = y; }

		float GetYaw() { return m_RotationYaw; }
		float GetPitch() { return m_RotationPitch; }
	private:
		float m_RotationYaw;
		float m_RotationPitch;
	};

	double CropAngle180(double angle);
}