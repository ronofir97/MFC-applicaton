#pragma once

#include "stdafx.h"

class Shape : public CObject
{
protected:
	CPoint start;
	CPoint end;

public:
	Shape() {}

	Shape(const CPoint& start, const CPoint& end);

	void setStart(const CPoint& start);

	void setEnd(const CPoint& end);

	virtual void draw(CDC* dc , COLORREF * penColor) const = 0;

	virtual void clear(CDC* dc , COLORREF * penColor) const = 0;

	virtual ~Shape() {}

	virtual void Serialize(CArchive& archive);

	virtual bool IsIndie(const CPoint& point) const;

};
