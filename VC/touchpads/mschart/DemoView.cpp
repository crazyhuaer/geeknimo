// DemoView.cpp : implementation of the CDemoView class
//

#include "stdafx.h"
#include "Demo.h"

#include "DemoDoc.h"
#include "DemoView.h"

#include "VcPlot.h"
#include "VcAxis.h"
#include "VcValueScale.h"
#include "VcSeriesCollection.h"
#include "VcSeries.h"
#include "VcPen.h"
#include "VcCategoryScale.h"
#include "VcColor.h"
#include "VcDataGrid.h"
#include "VcBackdrop.h"
#include "VcFill.h"
#include "VcBrush.h"
#include "VcDataPoints.h"
#include "VcDataPoint.h"
#include "VcDataPointLabel.h"
#include "VcAxisTitle.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoView

IMPLEMENT_DYNCREATE(CDemoView, CView)

BEGIN_MESSAGE_MAP(CDemoView, CView)
	//{{AFX_MSG_MAP(CDemoView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_CHART_LINE, OnChartLine)
	ON_COMMAND(ID_CHART_COMBI, OnChartCombi)
	ON_COMMAND(ID_CHART_PIE, OnChartPie)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView construction/destruction

CDemoView::CDemoView()
{
	// TODO: add construction code here

}

CDemoView::~CDemoView()
{
}

BOOL CDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView drawing

void CDemoView::OnDraw(CDC* pDC)
{
	CDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView diagnostics

#ifdef _DEBUG
void CDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemoDoc* CDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoDoc)));
	return (CDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoView message handlers

int CDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	CRect rc;
	GetClientRect(&rc);
	if(!m_Chart.Create("mschart", WS_CHILD| WS_VISIBLE, rc, this, 10))
		return -1;
	
	InitChart();
	DrawChart();

	return 0;
}

void CDemoView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	if( m_Chart.GetSafeHwnd() )
		m_Chart.MoveWindow( 0, 0, cx, cy );	
}

void CDemoView::InitChart()
{
	// 设置标题
	m_Chart.SetTitleText("mschart 示例 by thinkry@263.net");

	// 下面两句改变背景色
	m_Chart.GetBackdrop().GetFill().SetStyle(1);
	m_Chart.GetBackdrop().GetFill().GetBrush().GetFillColor().Set(255, 255, 255);

	// 显示图例
	m_Chart.SetShowLegend(TRUE);
	m_Chart.SetColumn(1);
	m_Chart.SetColumnLabel((LPCTSTR)"1号机");
	m_Chart.SetColumn(2);
	m_Chart.SetColumnLabel((LPCTSTR)"2号机");
	m_Chart.SetColumn(3);
	m_Chart.SetColumnLabel((LPCTSTR)"3号机");

	// 栈模式
	m_Chart.SetStacking(FALSE);

	// Y轴设置
	VARIANT var;
	m_Chart.GetPlot().GetAxis(1,var).GetValueScale().SetAuto(FALSE);	// 不自动标注Y轴刻度
	m_Chart.GetPlot().GetAxis(1,var).GetValueScale().SetMaximum(100);	// Y轴最大刻度
	m_Chart.GetPlot().GetAxis(1,var).GetValueScale().SetMinimum(0);		// Y轴最小刻度
	m_Chart.GetPlot().GetAxis(1,var).GetValueScale().SetMajorDivision(5);	// Y轴刻度5等分
	m_Chart.GetPlot().GetAxis(1,var).GetValueScale().SetMinorDivision(1);	// 每刻度一个刻度线
	m_Chart.GetPlot().GetAxis(1,var).GetAxisTitle().SetText("小时");	// Y轴名称

	// 3条曲线
	m_Chart.SetColumnCount(3); 

	// 线色
	m_Chart.GetPlot().GetSeriesCollection().GetItem(1).GetPen().GetVtColor().Set(0, 0, 255);
	m_Chart.GetPlot().GetSeriesCollection().GetItem(2).GetPen().GetVtColor().Set(255, 0, 0);
	m_Chart.GetPlot().GetSeriesCollection().GetItem(3).GetPen().GetVtColor().Set(0, 255, 0);

	// 线宽(对点线图有效)
	m_Chart.GetPlot().GetSeriesCollection().GetItem(1).GetPen().SetWidth(50);
	m_Chart.GetPlot().GetSeriesCollection().GetItem(2).GetPen().SetWidth(100);
	m_Chart.GetPlot().GetSeriesCollection().GetItem(3).GetPen().SetWidth(2);

	// 数据点类型显示数据值的模式(对柱柱状图和点线图有效)
	// 0: 不显示	1: 显示在柱状图外
	// 2: 显示在柱状图内上方	3: 显示在柱状图内中间	4: 显示在柱状图内下方
	m_Chart.GetPlot().GetSeriesCollection().GetItem(1).GetDataPoints().GetItem(-1).GetDataPointLabel().SetLocationType(1);
	m_Chart.GetPlot().GetSeriesCollection().GetItem(2).GetDataPoints().GetItem(-1).GetDataPointLabel().SetLocationType(1);
	m_Chart.GetPlot().GetSeriesCollection().GetItem(3).GetDataPoints().GetItem(-1).GetDataPointLabel().SetLocationType(1);
}

void CDemoView::DrawChart()
{
	int nRowCount = 6;
	m_Chart.SetRowCount(nRowCount);

	VARIANT var;
	m_Chart.GetPlot().GetAxis(0,var).GetCategoryScale().SetAuto(FALSE);			// 不自动标注X轴刻度
	m_Chart.GetPlot().GetAxis(0,var).GetCategoryScale().SetDivisionsPerLabel(1);// 每刻度一个标注
	m_Chart.GetPlot().GetAxis(0,var).GetCategoryScale().SetDivisionsPerTick(1); // 每刻度一个刻度线
	m_Chart.GetPlot().GetAxis(0,var).GetAxisTitle().SetText("日期");			// X轴名称

	char buf[32];
	srand( (unsigned)time( NULL ) );

	for(int row = 1; row <= nRowCount; ++row)
	{
		m_Chart.SetRow(row);
		sprintf(buf, "%d号", row);

		m_Chart.SetRowLabel((LPCTSTR)buf);
		m_Chart.GetDataGrid().SetData(row, 1, rand() * 100 / RAND_MAX, 0);
		m_Chart.GetDataGrid().SetData(row, 2, rand() * 100 / RAND_MAX, 0);
		m_Chart.GetDataGrid().SetData(row, 3, rand() * 100 / RAND_MAX, 0);
    }

	m_Chart.Refresh();	
}

void CDemoView::OnChartLine() 
{
	m_Chart.SetChartType(3);
	DrawChart();
}

void CDemoView::OnChartCombi() 
{
	m_Chart.SetChartType(1);	
	DrawChart();
}

void CDemoView::OnChartPie() 
{
	m_Chart.SetChartType(14);
	DrawChart();
}

