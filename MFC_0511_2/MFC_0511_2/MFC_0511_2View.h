
// MFC_0511_2View.h : CMFC_0511_2View 类的接口
//

#pragma once

class CMFC_0511_2Set;

class CMFC_0511_2View : public CRecordView
{
protected: // 仅从序列化创建
	CMFC_0511_2View();
	DECLARE_DYNCREATE(CMFC_0511_2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC_0511_2_FORM };
#endif
	CMFC_0511_2Set* m_pSet;

// 特性
public:
	CMFC_0511_2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFC_0511_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // MFC_0511_2View.cpp 中的调试版本
inline CMFC_0511_2Doc* CMFC_0511_2View::GetDocument() const
   { return reinterpret_cast<CMFC_0511_2Doc*>(m_pDocument); }
#endif

