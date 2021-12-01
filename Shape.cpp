#include "stdafx.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Shape.h"
#include "Triangular.h"
#include "MagenDavid.h"
#include "Hourglass.h"

IMPLEMENT_SERIAL(myRectangle, Shape, 1)

IMPLEMENT_SERIAL(myTriangular, Shape, 1)

IMPLEMENT_SERIAL(myMagendavid, myTriangular, 1)

IMPLEMENT_SERIAL(myHourglass, myTriangular, 1)

IMPLEMENT_SERIAL(Circle, Shape, 1)



Shape::Shape(const CPoint& start, const CPoint& end) {
	this->start = start;
	this->end = end;
}

void Shape::setStart(const CPoint& start) {
	this->start = start;
}

void Shape::setEnd(const CPoint& end) {
	this->end = end;
}

void Shape::Serialize(CArchive& archive)
{
	CObject::Serialize(archive);

	if (archive.IsStoring()) {
		archive << start;
		archive << end;
	}
	else {
		archive >> start;
		archive >> end;
	}
}

bool Shape::IsIndie(const CPoint& point) const {
	bool contain = false;
	if ((start.x < end.x && point.x > start.x && point.x < end.x) ||
		(start.x > end.x && point.x < start.x&& point.x > end.x)) {
		if ((start.y < end.y && point.y > start.y && point.y < end.y) ||
			(start.y > end.y && point.y < start.y && point.y > end.y)) {
			return true;
		}
	}
	return false;
}

