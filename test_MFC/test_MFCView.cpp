
// test_MFCView.cpp : Ctest_MFCView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "test_MFC.h"
#endif

#include "test_MFCDoc.h"
#include "test_MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest_MFCView

IMPLEMENT_DYNCREATE(Ctest_MFCView, CView)

BEGIN_MESSAGE_MAP(Ctest_MFCView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Ctest_MFCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Ctest_MFCView 构造/析构

Ctest_MFCView::Ctest_MFCView()
{
	// TODO: 在此处添加构造代码

}

Ctest_MFCView::~Ctest_MFCView()
{
}

BOOL Ctest_MFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctest_MFCView 绘制

void Ctest_MFCView::OnDraw(CDC* /*pDC*/)
{
	Ctest_MFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Ctest_MFCView 打印


void Ctest_MFCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Ctest_MFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Ctest_MFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Ctest_MFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void Ctest_MFCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Ctest_MFCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Ctest_MFCView 诊断

#ifdef _DEBUG
void Ctest_MFCView::AssertValid() const
{
	CView::AssertValid();
}

void Ctest_MFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctest_MFCDoc* Ctest_MFCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest_MFCDoc)));
	return (Ctest_MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// Ctest_MFCView 消息处理程序
