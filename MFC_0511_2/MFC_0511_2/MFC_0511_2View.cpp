
// MFC_0511_2View.cpp : CMFC_0511_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFC_0511_2View ����/����

CMFC_0511_2View::CMFC_0511_2View()
	: CRecordView(IDD_MFC_0511_2_FORM)
	, num(0)
	, ID(_T(""))
	, name(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMFC_0511_2View::~CMFC_0511_2View()
{
}

void CMFC_0511_2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
}

BOOL CMFC_0511_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFC_0511_2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC_0511_2Set;
	CRecordView::OnInitialUpdate();

}


// CMFC_0511_2View ���

#ifdef _DEBUG
void CMFC_0511_2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC_0511_2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC_0511_2Doc* CMFC_0511_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0511_2Doc)));
	return (CMFC_0511_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0511_2View ���ݿ�֧��
CRecordset* CMFC_0511_2View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC_0511_2View ��Ϣ�������


void CMFC_0511_2View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
}


void CMFC_0511_2View::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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