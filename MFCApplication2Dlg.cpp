
// MFCApplication2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#include "Shape.h"
#include "Triangular.h"
#include "Rectangle.h"
#include "Circle.h"
#include "MagenDavid.h"
#include "Hourglass.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
	
public:
	CAboutDlg();
	
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	
// Implementation
protected:

	DECLARE_MESSAGE_MAP()
public:

};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

END_MESSAGE_MAP()


// CMFCApplication2Dlg dialog



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
	, myCheckBtn(TRUE)
	, RecBut(true)
	, Cirb(false)
	, TriBut(false)
	, MagenBut(false)
	, HourBut(false)
	, update(false)
{
		m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
		lButtonDown = FALSE;
		currentShape = NULL;
		isSelected = FALSE;

	}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, PenColorBut);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON3, BKGcolorbut);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication2Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication2Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication2Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication2Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication2Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication2Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON2, &CMFCApplication2Dlg::OnBnClickedMfccolorbutton2)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON3, &CMFCApplication2Dlg::OnBnClickedMfccolorbutton3)
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_MFCLINK1, &CMFCApplication2Dlg::OnBnClickedMfclink1)
END_MESSAGE_MAP()


// CMFCApplication2Dlg message handlers

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
	
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		CDialogEx::OnPaint();
		
		drawAllShapes(&dc);

		if (isSelected) {
			currentShape->draw(&dc , &penColor);
		}
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication2Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	//set lbutton pressed = true
	
	lButtonDown = TRUE;
	if (isSelected) {
		isSelected = false;
		Invalidate();
	}
	//paint the line on the screen
	UpdateData(TRUE);
	if (RecBut) {
		currentShape = new myRectangle(point, point);
	}
	if(Cirb){
		currentShape = new Circle (point, point);
	}
	if (TriBut)
	{
		currentShape = new myTriangular(point, point);
	}
	if (MagenBut)
	{
		currentShape = new myMagendavid(point, point);
	}
	if (HourBut)
	{
		currentShape = new myHourglass(point, point);
	}
	if (!update)
	{
		CClientDC dc(this);
		currentShape->draw(&dc, &penColor);
	}
}

void CMFCApplication2Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	//check if lbutton is pressed
	if (lButtonDown && !update) {
		//set the end point of the line to the point of the mouse
		CClientDC dc(this);
		currentShape->clear(&dc , &penColor);
		currentShape->setEnd(point);
		drawAllShapes(&dc);
		currentShape->draw(&dc , &penColor);
	}
	if (update)
	{
		CClientDC dc(this);
		currentShape->clear(&dc, &penColor);
		currentShape->setEnd(point);
			drawAllShapes(&dc);
			currentShape->draw(&dc, &penColor);
	}
	CDialogEx::OnMouseMove(nFlags, point);
	//Invalidate();
}

void CMFCApplication2Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	//check if lbutton is pressed
	if (lButtonDown && !update) {
		//set the end point of the line to the point of the mouse
		CClientDC dc(this);
		currentShape->clear(&dc, &penColor);
		currentShape->setEnd(point);
		//draw the line
		shapes.Add(currentShape);
		drawAllShapes(&dc);
	}
	if (update)
	{
		CClientDC dc(this);
		currentShape->clear(&dc, &penColor);
		currentShape->setEnd(point);
		//draw the line
		drawAllShapes(&dc);

	}
	update = FALSE;
	lButtonDown = FALSE;
	CDialogEx::OnLButtonUp(nFlags, point);
	Invalidate();
}

void CMFCApplication2Dlg::drawAllShapes(CDC* dc) {
	int max = shapes.GetCount();
	for (int i = 0; i < max; i++) {
		Shape* tShape = shapes[i];
		tShape->draw(dc,&penColor);
	}
}

void CMFCApplication2Dlg::remove()
{
	shapes.RemoveAll();
	Invalidate();
}

void CMFCApplication2Dlg::OnBnClickedButton1()//save btn
{
	const TCHAR czFilter[] = _T("Shape files (*.shape)|*.shape|All Files (*.*)|*.*||");
	CFileDialog fDialog(FALSE, _T("shape"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, czFilter, this);

	if (fDialog.DoModal() == IDOK) {
		CString fileName = fDialog.GetPathName();
		CFile file(fileName, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		shapes.Serialize(ar);
		ar.Close();
		file.Close();
	}
}

void CMFCApplication2Dlg::OnBnClickedButton2()//load btn
{
	const TCHAR czFilter[] = _T("Shape files (*.shape)|*.shape|All Files (*.*)|*.*||");
	CFileDialog fDialog(TRUE, _T("shape"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, czFilter, this);

	if (fDialog.DoModal() == IDOK) {
		CString fileName = fDialog.GetPathName();
		CFile file(fileName, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		shapes.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}

void CMFCApplication2Dlg::OnBnClickedButton3()// rectangle btn
{
	RecBut = true;
	MagenBut = false;
	Cirb = false;
	TriBut = false;
	HourBut = false;
	UpdBtn = false;
}

void CMFCApplication2Dlg::OnBnClickedButton4()// circle btn
{
	Cirb = true;
	MagenBut = false;
	RecBut = false;
	TriBut = false;
	HourBut = false;

}


void CMFCApplication2Dlg::OnBnClickedButton5()// triangle btn
{
	TriBut = true;
	MagenBut = false;
	RecBut = false;
	Cirb = false;
	HourBut = false;
}


void CMFCApplication2Dlg::OnBnClickedButton6() // clear
{
	remove();
}


void CMFCApplication2Dlg::OnBnClickedButton7() // Hourglass btn
{
	MagenBut = false;
	RecBut = false;
	Cirb = false;
	TriBut = false;
	HourBut = true;
}

void CMFCApplication2Dlg::OnBnClickedButton8()// magen david btn
{
	MagenBut = true;
	RecBut = false;
	Cirb = false;
	TriBut = false;
	HourBut = false;
}

void CMFCApplication2Dlg::OnBnClickedButton9() //clear last  
{
	int index = shapes.GetCount();

	if (index != 0)
	{
		CClientDC dc(this);
		delete[] shapes[index - 1];
		shapes.SetSize(index - 1);
		Invalidate();
		drawAllShapes(&dc);
	}
}

void CMFCApplication2Dlg::OnBnClickedMfccolorbutton1()
{
	// TODO: Add your control notification handler code here

}

void CMFCApplication2Dlg::OnBnClickedMfccolorbutton2()
{
	penColor = PenColorBut.GetColor();
}

void CMFCApplication2Dlg::OnBnClickedMfccolorbutton3()
{
	COLORREF bkgcolor = BKGcolorbut.GetColor();
	this->SetBackgroundColor(bkgcolor);
}

void CMFCApplication2Dlg::OnRButtonDown(UINT nFlags, CPoint point)// update btn
{
	//update = true;
	bool flag = false;
	int max = shapes.GetCount();
	if (max > -1)
	{
		for (int i = max - 1; i > -1; i--) {
			if (shapes[i]->IsIndie(point)) {
				currentShape = shapes[i];
				flag = true;
				break;
			}
		}
	}
	if (!flag)
	{
		update = false;
	}
	else
	{
		currentShape->setEnd(point);
		Invalidate();
	}

	CDialogEx::OnRButtonDown(nFlags, point);
}

void CMFCApplication2Dlg::OnBnClickedMfclink1()
{
	// TODO: Add your control notification handler code here
}
