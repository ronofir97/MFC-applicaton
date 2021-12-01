#pragma once

#include "Triangular.h"

class myMagendavid : public myTriangular
{
public:
	DECLARE_SERIAL(myMagendavid)

	myMagendavid() {}

	myMagendavid(const CPoint& start, const CPoint& end) :myTriangular(start, end) {


	}

	void draw(CDC* dc, COLORREF * penColor) const {
		
		CPoint point1(start.x + (end.x - start.x) / 2, start.y);
		CPoint point2(end.x, (start.y-end.y)/4  + end.y);
		CPoint point3(start.x, (start.y - end.y) / 4 + end.y);
		drawTrian(dc, point1, point2, point3 ,penColor );
		CPoint point4(start.x + (end.x - start.x) / 2, end.y);
		CPoint point5(start.x, start.y -(start.y-end.y)/4);
		CPoint point6(end.x, start.y - (start.y - end.y) / 4);
		drawTrian(dc, point4, point5, point6 , penColor);
	
	}

	void clear(CDC* dc , COLORREF * penColor) const {
		
		CPoint point1(start.x + (end.x - start.x) / 2, start.y);
		CPoint point2(end.x, (start.y - end.y) / 4 + end.y);
		CPoint point3(start.x, (start.y - end.y) / 4 + end.y);
		clearTrian(dc, point1, point2, point3, penColor);
		CPoint point4(start.x + (end.x - start.x) / 2, end.y);
		CPoint point5(start.x, start.y - (start.y - end.y) / 4);
		CPoint point6(end.x, start.y - (start.y - end.y) / 4);
		clearTrian(dc, point4, point5, point6 , penColor);
		
	}

	virtual void Serialize(CArchive& archive)
	{
		Shape::Serialize(archive);
	}

};
