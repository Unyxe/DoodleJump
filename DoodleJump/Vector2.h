#pragma once
class Vector2
{
	bool operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}
	bool operator!=(const Vector2& other) const
	{
		return x != other.x || y != other.y;
	}
	Vector2 operator+(const Vector2& other) const
	{
		return { x + other.x, y + other.y };
	}
	Vector2 operator-(const Vector2& other) const
	{
		return { x - other.x, y - other.y };
	}
	Vector2 operator*(const double& scalar) const
	{
		return { x * scalar, y * scalar };
	}
	Vector2 operator/(const double& scalar) const
	{
		return { x / scalar, y / scalar };
	}
public:
	double x;
	double y;
};

