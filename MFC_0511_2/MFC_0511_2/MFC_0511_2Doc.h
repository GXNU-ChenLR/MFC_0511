
// MFC_0511_2Doc.h : CMFC_0511_2Doc 类的接口
//


#pragma once
#include "MFC_0511_2Set.h"


class CMFC_0511_2Doc : public CDocument
{
protected: // 仅从序列化创建
	CMFC_0511_2Doc();
	DECLARE_DYNCREATE(CMFC_0511_2Doc)

// 特性
public:
	CMFC_0511_2Set m_MFC_0511_2Set;

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMFC_0511_2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
