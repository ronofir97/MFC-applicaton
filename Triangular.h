#pragma once

#include "Shape.h"

class myTriangular : public Shape
{
public:
	DECLARE_SERIAL(myTriangular)

	myTriangular() {}

	myTriangular(const CPoint& start, const CPoint& end) :Shape(start, end) {
		
		
	}
	void draw(CDC* dc , COLORREF * penColor) const {
	
		CPoint point1(start.x + (end.x - start.x) / 2, start.y);
		CPoint point2(end.x, end.y);
		CPoint point3(start.x, end.y);
		drawTrian(dc, point1, point2, point3 , penColor);
	}

	void drawTrian(CDC* dc , CPoint point1 , CPoint point2  , CPoint point3 , COLORREF * penColor) const {
		CPen pen(PS_SOLID, 5,*penColor);
		CPen* old = dc->SelectObject(&pen);
		CPoint Pt[3];
		Pt[0] = point1;
		Pt[1] = point2;
		Pt[2] = point3;
		dc->Polygon(Pt, 3);
		dc->SelectObject(old);
	}

	void clear(CDC *dc , COLORREF * penColor) const
	{
		CPoint point1(start.x + (end.x - start.x) / 2, start.y);
		CPoint point2(end.x, end.y);
		CPoint point3(start.x, end.y);
		clearTrian(dc, point1, point2, point3 , penColor);

	}
 void clearTrian(CDC* dc, CPoint point1, CPoint point2, CPoint point3, COLORREF * penColor) const {
	 CPen pen(PS_SOLID, 5, *penColor);
	 CPen* old = dc->SelectObject(&pen);
		dc->SetROP2(R2_NOTXORPEN);
		CPoint Pt[3];
		Pt[0] = point1;
		Pt[1] = point2;
		Pt[2] = point3;
		dc->Polygon(Pt, 3);
		dc->SetROP2(R2_COPYPEN);
		
	}

	virtual void Serialize(CArchive& archive)
	{
		Shape::Serialize(archive);
	}

};