#include "Rectangle.h"

Rectangle::Rectangle():width(0),height(0)
{
}

Rectangle::Rectangle(float width, float height):width(width),height(height)
{
}

Rectangle::Rectangle(const Rectangle & rect)
{
	width = rect.width;
	height = rect.height;
}

Rectangle::Rectangle(float width):width(width),height(width)
{	//构建正方形
}
