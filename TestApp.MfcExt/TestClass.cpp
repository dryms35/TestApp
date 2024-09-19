#include "pch.h"
#include "TestClass.h"


CString CTestClass::GetData()
{
	Microsoft::Data::SqlClient::SortOrder order = Microsoft::Data::SqlClient::SortOrder::Ascending;

	return _T("SqlClient SortOrder is ") + order.ToString() + _T(".");
}