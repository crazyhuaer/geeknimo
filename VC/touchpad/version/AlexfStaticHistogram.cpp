/////////////////////////////////////////////////////////////////////////////
// Copyright (C) 1999 by Alexander Fedorov
// All rights reserved
//
// Distribute and use freely, except:
// 1. Don't alter or remove this notice.
// 2. Mark the changes you made
//
// Send bug reports, bug fixes, enhancements, requests, etc. to:
//    alexander.fedorov@usa.net
// updated by FNA - Fred Ackers - aqiruse@gmail.com
/////////////////////////////////////////////////////////////////////////////

// AlexfStaticHistogram.cpp : implementation file

#include "stdafx.h"
#include "version.h"
#include "AlexfStaticHistogram.h"
 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
 
/////////////////////////////////////////////////////////////////////////////
// CAlexfStaticHistogram

CAlexfStaticHistogram::CAlexfStaticHistogram()
{
	m_dDataWidth = 2;
	m_bOK = FALSE;
	m_lTextLines = 0;
	m_lTextWidth = 0;
	m_lStack = 0;
	m_dMaxValue = 100;
	m_bTextLeft = TRUE;
	m_bNeedFullRedraw = FALSE;
	m_bMotionLToR = TRUE;
	m_clr = GetSysColor(COLOR_BTNHIGHLIGHT);//FNA
	m_clrBack = GetSysColor(COLOR_BTNFACE); //FNA

	m_lArraySize = GetSystemMetrics(SM_CXSCREEN);
	m_pdArray = new DOUBLE[m_lArraySize];
	if (!m_pdArray) return;
	ZeroMemory(m_pdArray, m_lArraySize * sizeof(DOUBLE));
	m_bOK = TRUE;
}
 
CAlexfStaticHistogram::~CAlexfStaticHistogram()
{
	if (m_pdArray) delete [] m_pdArray;
}
 

BEGIN_MESSAGE_MAP(CAlexfStaticHistogram, CStatic)
	//{{AFX_MSG_MAP(CAlexfStaticHistogram)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
 
/////////////////////////////////////////////////////////////////////////////
// CAlexfStaticHistogram message handlers

void CAlexfStaticHistogram::OnPaint() 
{
	if (!m_bOK)
	{
		CStatic::OnPaint();
		return;
	}
	CPaintDC dc(this); // device context for painting
	CRect cr;
	GetClientRect(&cr);
	if (m_bNeedFullRedraw)
	{
		m_bNeedFullRedraw = FALSE;
		dc.FillRect(cr, & CBrush(GetSysColor(COLOR_BTNFACE)));
	}
	CRect cr1(cr);

	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(GetSysColor(COLOR_BTNTEXT));
	int hh = 0;
	//if (m_lTextLines != 0) hh = cr.Width() / m_lTextLines;
	if (m_lTextLines != 0) hh = cr.Width() / 8 -1;
	cr1.top = cr.bottom - 15;
	dc.FillRect(cr1, & CBrush(GetSysColor(COLOR_BTNFACE)));
	cr1.right = cr1.left + hh;
	CFont* pOldFont = dc.SelectObject(GetFont());
	int i=0;//FNA - fix for VS2005
	//for (i = 0; i < m_lTextLines; i++)
	for (i = 0; i < 9; i++)
	{
		dc.DrawText(text[i], (LPRECT)&cr1,
			DT_WORDBREAK);
		cr1.OffsetRect(hh, 0);
	}
	dc.SelectObject(pOldFont);

/******************************/


// graph
	/************************************************************************/
	/* Neo Add                                                              */
	/************************************************************************/
	cr.bottom = cr.bottom - 15;
	//////////////////////////////////////////////////////////////////////////
	if (m_dMaxValue == 0) return;

	cr1 = cr;
	cr1.left = 0;
	cr1.right = m_dDataWidth;

	i = 0;
	cr1.bottom -= 1;
	int h = cr.Height() - 2;
	//int nOffset = (int)((cr.right-cr.left)/m_lStack+0.5f);//FNA - Changed Offset to display in as much of full space as possible
	//int nOffset = (int)((cr.right-cr.left)/m_lStack+0.5f);
	//int nOffset = (int)((cr.right-cr.left - m_lTextLines*m_dDataWidth)/(m_lTextLines -1));
	int nOffset = 0;
	if (m_lTextLines != 0) nOffset =(int) (cr.Width() / (m_lTextLines) - (m_dDataWidth - 1) - 0.5);
	

	while (TRUE)
	{
		int h1 = 0;
		if (m_dMaxValue != 0) h1 = (int)((DOUBLE) h * m_pdArray[i] / m_dMaxValue);
		if (h1 > h) h1 = h;
		cr1.top = cr.top;
		cr1.bottom = cr.bottom - h1;
		dc.FillRect(cr1, & CBrush(m_clrBack));

		cr1.top = cr.bottom - h1;
		cr1.bottom = cr.bottom;
		dc.FillRect(cr1, & CBrush(m_clr));//FNA - Changed to custom Color

		cr1.OffsetRect(m_dDataWidth+nOffset, 0);

		if (i == m_lTextLines) break;//FNA - was looping infinitely with new offset

		i++;
	
		//if (cr1.left > cr.left) break;
	}
	// Do not call CStatic::OnPaint() for painting messages
}
 
BOOL CAlexfStaticHistogram::Add(DOUBLE dValue)
{
	if (!m_bOK) return FALSE;
	//m_lStack++;
	if (m_lStack >= m_lArraySize) m_lStack = 0;
	m_pdArray[m_lStack++] = dValue;
	this->RedrawWindow();
	return TRUE;
}

BOOL CAlexfStaticHistogram::UPDATE(int dIndex,DOUBLE dValue)
{
	if (!m_bOK) return FALSE;
	if (dIndex > m_lStack || dIndex < 0)
	{
		return FALSE;
	} 
	else
	{
		if (dValue > m_dMaxValue)
		{
			m_pdArray[dIndex] = m_dMaxValue;
		} 
		else
		{
			m_pdArray[dIndex] = dValue;
		}
		
	}
	return TRUE;
}
 
BOOL CAlexfStaticHistogram::SetTextLeft(BOOL bSet)
{
	if (!m_bOK) return FALSE;
	m_bTextLeft = bSet;
	m_bNeedFullRedraw = TRUE;
	this->RedrawWindow();
	return TRUE;
}
 
BOOL CAlexfStaticHistogram::SetTextWidth(LONG lWidth)
{
	if (!m_bOK) return FALSE;
	m_lTextWidth = lWidth;
	m_bNeedFullRedraw = TRUE;
	this->RedrawWindow();
	return TRUE;
}
 
BOOL CAlexfStaticHistogram::SetTextLines(LONG lLines)
{
	if (!m_bOK) return FALSE;
	m_lTextLines = lLines;
	m_bNeedFullRedraw = TRUE;
	this->RedrawWindow();
	return TRUE;
}
 
BOOL CAlexfStaticHistogram::SetMotionLtoR(BOOL bSet)
{
	if (!m_bOK) return FALSE;
	m_bMotionLToR = bSet;
	m_bNeedFullRedraw = TRUE;
	this->RedrawWindow();
	return TRUE;
}
 
BOOL CAlexfStaticHistogram::SetMaxValue(DOUBLE dValue)
{
	if (!m_bOK) return FALSE;
	m_dMaxValue = dValue;
	m_bNeedFullRedraw = TRUE;
	this->RedrawWindow();
	return TRUE;
}

void CAlexfStaticHistogram::SetDataWidth(int dWidth)
{
	m_dDataWidth = dWidth;
}

void CAlexfStaticHistogram::Initialization()
{
	
	SetBackColor(RGB(0,255,255));
	SetMotionLtoR(FALSE);
	SetTextWidth(3);
	SetDataWidth(4);
	SetColor(RGB(255,0,0));
	
	SetTextLines(64);  // Set number of text lines (0 - none)
	text[0] = "0";   // Set text (too easy to create special
	text[1] = "8";  // function for that)
	text[2] = "16";
	text[3] = "24";
	text[4] = "32";
	text[5] = "40";
	text[6] = "48";
	text[7] = "56";
	text[8] = "64";

	for (int i = 0; i < 64; i++)
	{
		this->Add(0);
	}
	
}

void CAlexfStaticHistogram::Initialization(COLORREF rgbBackColor,int dTextWidth,int dDataWidth,COLORREF rgbColor,int dTextLines)
{

	CString	sTemp;

	SetBackColor(rgbBackColor);
	SetMotionLtoR(FALSE);
	SetTextWidth(dTextWidth);
	SetDataWidth(dDataWidth);
	SetColor(rgbColor);
	
	SetTextLines(dTextLines);  // Set number of text lines (0 - none)

	for (int i = 0; i <= dTextLines/8; i++)
	{
		sTemp.Format("%d",8*i);
		text[i] = sTemp;
	}

	for (i = 0; i < dTextLines; i++)
	{
		this->Add(0);
	}

}

