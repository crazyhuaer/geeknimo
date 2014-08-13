// testtooltipDoc.cpp : implementation of the CTesttooltipDoc class
//

#include "stdafx.h"
#include "testtooltip.h"

#include "testtooltipDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTesttooltipDoc

IMPLEMENT_DYNCREATE(CTesttooltipDoc, CDocument)

BEGIN_MESSAGE_MAP(CTesttooltipDoc, CDocument)
	//{{AFX_MSG_MAP(CTesttooltipDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTesttooltipDoc construction/destruction

CTesttooltipDoc::CTesttooltipDoc()
{
	// TODO: add one-time construction code here

}

CTesttooltipDoc::~CTesttooltipDoc()
{
}

BOOL CTesttooltipDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTesttooltipDoc serialization

void CTesttooltipDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTesttooltipDoc diagnostics

#ifdef _DEBUG
void CTesttooltipDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTesttooltipDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTesttooltipDoc commands
