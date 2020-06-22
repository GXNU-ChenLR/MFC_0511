
// MFC_0511_2Set.cpp : CMFC_0511_2Set 类的实现
//

#include "stdafx.h"
#include "MFC_0511_2.h"
#include "MFC_0511_2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_0511_2Set 实现

// 代码生成在 2020年5月11日, 11:22

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
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CMFC_0511_2Set::GetDefaultConnect()
{
	return _T("DBQ=C:\\Users\\Bug\\\x5b66\x751f\x4fe1\x606f.mdb;");
	//DSN=\x6570\x636e\x6e90_\x5b66\x751f\x4fe1\x606f2;
	//DefaultDir=C:\\Users\\Bug\\Source\\Repos;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;
}

CString CMFC_0511_2Set::GetDefaultSQL()
{
	return _T("[学生信息表]");
}

void CMFC_0511_2Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[编号]"), column1);
	RFX_Text(pFX, _T("[字段1]"), m_1);
	RFX_Text(pFX, _T("[字段2]"), m_2);
	RFX_Text(pFX, _T("[字段3]"), m_3);

}
/////////////////////////////////////////////////////////////////////////////
// CMFC_0511_2Set 诊断

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

