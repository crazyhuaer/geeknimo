// testtooltipView.h : interface of the CTesttooltipView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTTOOLTIPVIEW_H__B796CB1C_AF94_4FF6_A6D6_14C401704B2B__INCLUDED_)
#define AFX_TESTTOOLTIPVIEW_H__B796CB1C_AF94_4FF6_A6D6_14C401704B2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTesttooltipView : public CView
{
protected: // create from serialization only
	CTesttooltipView();
	DECLARE_DYNCREATE(CTesttooltipView)

// Attributes
public:
	CTesttooltipDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTesttooltipView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTesttooltipView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTesttooltipView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in testtooltipView.cpp
inline CTesttooltipDoc* CTesttooltipView::GetDocument()
   { return (CTesttooltipDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTTOOLTIPVIEW_H__B796CB1C_AF94_4FF6_A6D6_14C401704B2B__INCLUDED_)
