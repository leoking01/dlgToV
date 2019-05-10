// zydview.cpp : 实现文件
//

#include "stdafx.h"
#include "dlgtoview.h"
#include "zydview.h"


// zydview

IMPLEMENT_DYNCREATE(zydview, CScrollView)

zydview::zydview()
{

}

zydview::~zydview()
{
}


BEGIN_MESSAGE_MAP(zydview, CScrollView)
END_MESSAGE_MAP()


// zydview 绘图

void zydview::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void zydview::OnDraw(CDC* pDC)
{
	//CDocument* pDoc = GetDocument();
	CBitmap BK;
	BK.LoadBitmap(IDB_BITMAP1);
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);
	MemDC.SelectObject(&BK);
	BITMAP bm;
	BK.GetBitmap(&bm);

	pDC->BitBlt(0, 0, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

	CRect m_Rect;
	GetClientRect(&m_Rect);
	m_Rect.bottom += 100;
	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = bm.bmWidth;
	sizeTotal.cy = bm.bmHeight;
	SetScrollSizes(MM_TEXT, CSize(1000,1000));

	// TODO: 在此添加绘制代码
}


// zydview 诊断

#ifdef _DEBUG
void zydview::AssertValid() const
{
	CScrollView::AssertValid();
}

#ifndef _WIN32_WCE
void zydview::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif
#endif //_DEBUG


// zydview 消息处理程序
