
// MFC_0511_2Doc.h : CMFC_0511_2Doc ��Ľӿ�
//


#pragma once
#include "MFC_0511_2Set.h"


class CMFC_0511_2Doc : public CDocument
{
protected: // �������л�����
	CMFC_0511_2Doc();
	DECLARE_DYNCREATE(CMFC_0511_2Doc)

// ����
public:
	CMFC_0511_2Set m_MFC_0511_2Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFC_0511_2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
