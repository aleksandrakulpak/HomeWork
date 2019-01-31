// ProgramDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Program.h"
#include "ProgramDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProgramDlg dialog



CProgramDlg::CProgramDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_PROGRAM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProgramDlg::DoDataExchange(CDataExchange* pDX)
{
	fg = true;

	SetWindowTextW(L"Program");

	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CProgramDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CProgramDlg message handlers

BOOL CProgramDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);                 // Set big icon
	SetIcon(m_hIcon, FALSE);                // Set small icon

											// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CProgramDlg::OnPaint()
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
		CClientDC dc(this);
		GetClientRect(&rc);

		hNew = CreateFont(28, 0, 0, 0, FW_NORMAL, 0, 0, 0,
			ANSI_CHARSET, OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE,
			L"Trebuchet Ms");
		hold = (HFONT)SelectObject(dc, hNew);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		RH = abs(rc.left - rc.right);
		RW = abs(rc.top - rc.bottom);
		cx = RH / 2;
		cy = RW / 2;

		cf = RGB(0, 0, 0);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);


		// TODO
		double xf, yf, a, b;
		int xmax = rc.right;
		int ymax = rc.bottom;
		
		a = -15; b = 5;

		x1 = 0;
		xf = a + x1 * (b - a) / xmax;
		yf = MyF1(xf);
		y1 = yf * xmax / (b - a);
		y1 = ymax / 2 - y1;
		dc.MoveTo(x1 - cx / 2, y1);

		cf = RGB(255, 0, 0);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		
		cf = RGB(0, 0, 0);
		KWD(cx + 100, 20, 220);
		x1 = cx + 100;
		y1 = 20;
		int dd = 220;
		for (k = 0; k < 8; k++)
		{
			KWD(x1 + k * 10, y1 + k * 10, dd - k * 20 * sqrt(2));
		}

		SelectObject(dc, hOldPen);
		DeleteObject(hPenOxy);
		DeleteObject(hNew);
		hold = (HFONT)SelectObject(dc, hbk);
		CDialog::OnPaint();
	}


