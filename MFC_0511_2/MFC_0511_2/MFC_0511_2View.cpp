
// MFC_0511_2View.cpp : CMFC_0511_2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_0511_2.h"
#endif

#include "MFC_0511_2Set.h"
#include "MFC_0511_2Doc.h"
#include "MFC_0511_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_0511_2View

IMPLEMENT_DYNCREATE(CMFC_0511_2View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC_0511_2View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_0511_2View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_0511_2View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CMFC_0511_2View 构造/析构

CMFC_0511_2View::CMFC_0511_2View()
	: CRecordView(IDD_MFC_0511_2_FORM)
	, num(0)
	, ID(_T(""))
	, name(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFC_0511_2View::~CMFC_0511_2View()
{
}

void CMFC_0511_2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
}

BOOL CMFC_0511_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFC_0511_2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC_0511_2Set;
	CRecordView::OnInitialUpdate();

}


// CMFC_0511_2View 诊断

#ifdef _DEBUG
void CMFC_0511_2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC_0511_2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC_0511_2Doc* CMFC_0511_2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0511_2Doc)));
	return (CMFC_0511_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0511_2View 数据库支持
CRecordset* CMFC_0511_2View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC_0511_2View 消息处理程序


void CMFC_0511_2View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	
}


void CMFC_0511_2View::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s = m_pSet->m_3;
	CImage img;
	//CClientDC dc(this);
	//dc.TextOutW(100, 100, s);
	img.Load(s);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);

	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
}

void  CMFC_0511_2View::foo(CImage& img, int &sx, int& sy, int& w, int& h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
}