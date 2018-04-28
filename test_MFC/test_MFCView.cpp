
// test_MFCView.cpp : Ctest_MFCView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Ctest_MFCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Ctest_MFCView ����/����

Ctest_MFCView::Ctest_MFCView()
{
	// TODO: �ڴ˴���ӹ������

}

Ctest_MFCView::~Ctest_MFCView()
{
}

BOOL Ctest_MFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctest_MFCView ����

void Ctest_MFCView::OnDraw(CDC* /*pDC*/)
{
	Ctest_MFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Ctest_MFCView ��ӡ


void Ctest_MFCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Ctest_MFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Ctest_MFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Ctest_MFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// Ctest_MFCView ���

#ifdef _DEBUG
void Ctest_MFCView::AssertValid() const
{
	CView::AssertValid();
}

void Ctest_MFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctest_MFCDoc* Ctest_MFCView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest_MFCDoc)));
	return (Ctest_MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// Ctest_MFCView ��Ϣ�������
