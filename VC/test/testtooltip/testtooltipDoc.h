// testtooltipDoc.h : interface of the CTesttooltipDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTTOOLTIPDOC_H__4173E17F_0B98_44A3_A903_1297931EFFAB__INCLUDED_)
#define AFX_TESTTOOLTIPDOC_H__4173E17F_0B98_44A3_A903_1297931EFFAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTesttooltipDoc : public CDocument
{
protected: // create from serialization only
	CTesttooltipDoc();
	DECLARE_DYNCREATE(CTesttooltipDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTesttooltipDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTesttooltipDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTesttooltipDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTTOOLTIPDOC_H__4173E17F_0B98_44A3_A903_1297931EFFAB__INCLUDED_)
