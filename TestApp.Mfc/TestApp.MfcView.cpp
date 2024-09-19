
// TestApp.MfcView.cpp : implementation of the CTestAppMfcView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestApp.Mfc.h"
#endif

#include "TestApp.MfcDoc.h"
#include "TestApp.MfcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestAppMfcView

IMPLEMENT_DYNCREATE(CTestAppMfcView, CView)

BEGIN_MESSAGE_MAP(CTestAppMfcView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTestAppMfcView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTestAppMfcView construction/destruction

CTestAppMfcView::CTestAppMfcView() noexcept
{
	// TODO: add construction code here

}

CTestAppMfcView::~CTestAppMfcView()
{
}

BOOL CTestAppMfcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTestAppMfcView drawing

void CTestAppMfcView::OnDraw(CDC* /*pDC*/)
{
	CTestAppMfcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTestAppMfcView printing


void CTestAppMfcView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTestAppMfcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestAppMfcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestAppMfcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTestAppMfcView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestAppMfcView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestAppMfcView diagnostics

#ifdef _DEBUG
void CTestAppMfcView::AssertValid() const
{
	CView::AssertValid();
}

void CTestAppMfcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestAppMfcDoc* CTestAppMfcView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestAppMfcDoc)));
	return (CTestAppMfcDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestAppMfcView message handlers
