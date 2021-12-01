#pragma once

#include "Triangular.h"

class myHourglass : public myTriangular
{
public:
	DECLARE_SERIAL(myHourglass)

	myHourglass() {}

	myHourglass(const CPoint& start, const CPoint& end) :myTriangular(start, end) {


	}

	void draw(CDC* dc , COLORREF * penColor) const {
		
		CPoint point1(start.x + (end.x - start.x) / 2, start.y + (end.y - start.y) / 2);
		CPoint point2(end.x, end.y);
		CPoint point3(start.x, end.y);
		drawTrian(dc, point1, point2, point3 , penColor);
		CPoint point4(start.x + (end.x - start.x) / 2, start.y + (end.y - start.y) / 2);
		CPoint point5(start.x, start.y);
		CPoint point6(end.x, start.y);
		drawTrian(dc, point4, point5, point6 , penColor);
		
	}

	void clear(CDC* dc, COLORREF * penColor) const {
		
		CPoint point1(start.x + (end.x - start.x) / 2, start.y + (end.y - start.y) / 2);
		CPoint point2(end.x, end.y);
		CPoint point3(start.x, end.y);
		clearTrian(dc, point1, point2, point3 , penColor);
		CPoint point4(start.x + (end.x - start.x) / 2, start.y + (end.y - start.y) / 2);
		CPoint point5(start.x, start.y);
		CPoint point6(end.x, start.y);
		clearTrian(dc, point4, point5, point6 , penColor);
	}

	virtual void Serialize(CArchive& archive)
	{
		Shape::Serialize(archive);
	}

};
