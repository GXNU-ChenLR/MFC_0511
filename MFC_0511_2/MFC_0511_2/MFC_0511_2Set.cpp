
// MFC_0511_2Set.cpp : CMFC_0511_2Set ���ʵ��
//

#include "stdafx.h"
#include "MFC_0511_2.h"
#include "MFC_0511_2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_0511_2Set ʵ��

// ���������� 2020��5��11��, 11:22

IMPLEMENT_DYNAMIC(CMFC_0511_2Set, CRecordset)

CMFC_0511_2Set::CMFC_0511_2Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = 0;
	m_1 = L"";
	m_2 = L"";
	m_3 = L"";
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFC_0511_2Set::GetDefaultConnect()
{
	return _T("DBQ=C:\\Users\\Bug\\\x5b66\x751f\x4fe1\x606f.mdb;");
	//DSN=\x6570\x636e\x6e90_\x5b66\x751f\x4fe1\x606f2;
	//DefaultDir=C:\\Users\\Bug\\Source\\Repos;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;
}

CString CMFC_0511_2Set::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��]");
}

void CMFC_0511_2Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[���]"), column1);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Text(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Text(pFX, _T("[�ֶ�3]"), m_3);

}
/////////////////////////////////////////////////////////////////////////////
// CMFC_0511_2Set ���

#ifdef _DEBUG
void CMFC_0511_2Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFC_0511_2Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

