
// MFC_0511_2View.h : CMFC_0511_2View ��Ľӿ�
//

#pragma once

class CMFC_0511_2Set;

class CMFC_0511_2View : public CRecordView
{
protected: // �������л�����
	CMFC_0511_2View();
	DECLARE_DYNCREATE(CMFC_0511_2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC_0511_2_FORM };
#endif
	CMFC_0511_2Set* m_pSet;

// ����
public:
	CMFC_0511_2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFC_0511_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long num;
	CString ID;
	CString name;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	void foo(CImage & img, int & sx, int & sy, int & w, int & h);
};

#ifndef _DEBUG  // MFC_0511_2View.cpp �еĵ��԰汾
inline CMFC_0511_2Doc* CMFC_0511_2View::GetDocument() const
   { return reinterpret_cast<CMFC_0511_2Doc*>(m_pDocument); }
#endif

