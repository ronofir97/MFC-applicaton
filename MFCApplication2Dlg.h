
// MFCApplication2Dlg.h : header file
//

#pragma once

#include "Shape.h"

// CMFCApplication2Dlg dialog
class CMFCApplication2Dlg : public CDialogEx
{
	// Construction
	bool lButtonDown;
	bool update;

	CTypedPtrArray<CObArray, Shape*> shapes;
	Shape* currentShape;

	bool isSelected; //indicate that a shape was selected uysing right click
	COLORREF brushColor = (RGB(255, 255, 255));
	void drawAllShapes(CDC* dc);
	void remove();
	CMFCColorButton PenColorBut;
	COLORREF penColor;
	
public:
	CMFCApplication2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	BOOL myCheckBtn;

	bool RecBut;
	bool Cirb;
	bool TriBut;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	bool MagenBut;
	bool HourBut;
	afx_msg void OnBnClickedButton9();
	bool UpdBtn;
	afx_msg void OnBnClickedMfccolorbutton1();
	afx_msg void OnBnClickedMfccolorbutton2();

	CMFCColorButton BKGcolorbut;
	afx_msg void OnBnClickedMfccolorbutton3();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedMfclink1();
};
