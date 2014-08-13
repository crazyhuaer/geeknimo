// testtooltipView.cpp : implementation of the CTesttooltipView class
//

#include "stdafx.h"
#include "testtooltip.h"

#include "testtooltipDoc.h"
#include "testtooltipView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTesttooltipView

IMPLEMENT_DYNCREATE(CTesttooltipView, CView)

BEGIN_MESSAGE_MAP(CTesttooltipView, CView)
	//{{AFX_MSG_MAP(CTesttooltipView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTesttooltipView construction/destruction

CTesttooltipView::CTesttooltipView()
{
	// TODO: add construction code here

}

CTesttooltipView::~CTesttooltipView()
{
}

BOOL CTesttooltipView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTesttooltipView drawing

void CTesttooltipView::OnDraw(CDC* pDC)
{
	CTesttooltipDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTesttooltipView printing

BOOL CTesttooltipView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTesttooltipView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTesttooltipView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTesttooltipView diagnostics

#ifdef _DEBUG
void CTesttooltipView::AssertValid() const
{
	CView::AssertValid();
}

void CTesttooltipView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTesttooltipDoc* CTesttooltipView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTesttooltipDoc)));
	return (CTesttooltipDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTesttooltipView message handlers
