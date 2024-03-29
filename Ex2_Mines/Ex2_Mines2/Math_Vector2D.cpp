#include "Math_Vector2D.h"

Vector2D::Vector2D()
{
}

Vector2D::Vector2D(int X, int Y)
	: x(X),
	  y(Y)
{
}

int Vector2D::getX()
{
	return x;
}

int Vector2D::getY() 
{
	return y;
}

void Vector2D::setX(int newValue) 
{
	x = newValue;
	return;
}

void Vector2D::setY(int newValue) 
{
	y = newValue;
	return;
}

void Vector2D::setXY(int X, int Y)
{
	x = X;
	y = Y;
	return;
}

void Vector2D::resetVector()
{
	x = 0;
	y = 0;
	return;
}

void Vector2D::correctVector()
{
	x -= 1;
	y -= 1;
	return;
}
