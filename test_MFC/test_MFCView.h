
// test_MFCView.h : Ctest_MFCView ��Ľӿ�
//

#pragma once


class Ctest_MFCView : public CView
{
protected: // �������л�����
	Ctest_MFCView();
	DECLARE_DYNCREATE(Ctest_MFCView)

// ����
public:
	Ctest_MFCDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Ctest_MFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // test_MFCView.cpp �еĵ��԰汾
inline Ctest_MFCDoc* Ctest_MFCView::GetDocument() const
   { return reinterpret_cast<Ctest_MFCDoc*>(m_pDocument); }
#endif

