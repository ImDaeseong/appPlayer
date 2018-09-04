#include "StdAfx.h"
#include "RegInfo.h"

#define REG_BUFF_SIZE_A 1024

CRegInfo::CRegInfo(void)
{
}

CRegInfo::~CRegInfo(void)
{
}

CString CRegInfo::IsExistMOMOInfo(LPCTSTR szKey)
{
	char szBuffer [MAX_PATH + 1] = {0, };
	DWORD dwCount = 0;

	CRegKey regKey;

	if (regKey.Open(HKEY_CURRENT_USER, _T("SOFTWARE\\NOXGAMES\\MOMO"), KEY_READ) != ERROR_SUCCESS)
		return "";

	dwCount = REG_BUFF_SIZE_A + 1;

	if (ERROR_SUCCESS != regKey.QueryStringValue(szKey, szBuffer, &dwCount))
	{
		regKey.Close();
		return "";
	}

	regKey.Close();

	return (CString)szBuffer;
}


CString CRegInfo::IsExistNoxInfo(LPCTSTR szKey)
{
	char szBuffer [MAX_PATH + 1] = {0, };
	DWORD dwCount = 0;

	CRegKey regKey;

	if (regKey.Open(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\Nox"), KEY_READ) != ERROR_SUCCESS)
		return "";

	dwCount = REG_BUFF_SIZE_A + 1;

	if (ERROR_SUCCESS != regKey.QueryStringValue(szKey, szBuffer, &dwCount))
	{
		regKey.Close();
		return "";
	}

	regKey.Close();

	return (CString)szBuffer;
}


CString CRegInfo::IsExistMEmuInfo(LPCTSTR szKey)
{
	char szBuffer [MAX_PATH + 1] = {0, };
	DWORD dwCount = 0;

	CRegKey regKey;

	if (regKey.Open(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\MEmu"), KEY_READ) != ERROR_SUCCESS)
		return "";

	dwCount = REG_BUFF_SIZE_A + 1;

	if (ERROR_SUCCESS != regKey.QueryStringValue(szKey, szBuffer, &dwCount))
	{
		regKey.Close();
		return "";
	}

	regKey.Close();

	return (CString)szBuffer;
}