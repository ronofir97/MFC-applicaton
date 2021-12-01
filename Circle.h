#pragma once

#include "Shape.h"

class Circle : public Shape
{
public:
	DECLARE_SERIAL(Circle)

	Circle() {}

	Circle(const CPoint& start, const CPoint& end) :Shape(start, end) {
	}

	void draw(CDC* dc , COLORREF * penColor) const {
		CPen pen(PS_SOLID, 5, *penColor);
		CPen* old = dc->SelectObject(&pen);
		dc->Ellipse(start.x, start.y, end.x, end.y);
		dc->SelectObject(old);
	}

	void clear(CDC* dc, COLORREF * penColor) const {
		CPen pen(PS_SOLID, 5, *penColor);
		CPen* old = dc->SelectObject(&pen);
		dc->SetROP2(R2_NOTXORPEN);
		dc->Ellipse(start.x, start.y, end.x, end.y);
		dc->SelectObject(old);
		dc->SetROP2(R2_COPYPEN);
	}

	virtual void Serialize(CArchive& archive)
	{
		Shape::Serialize(archive);
	}

};