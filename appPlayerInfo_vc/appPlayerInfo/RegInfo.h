#pragma once

class CRegInfo
{
public:
	CRegInfo(void);
	~CRegInfo(void);

public:
	CString IsExistMOMOInfo(LPCTSTR szKey);
	CString IsExistNoxInfo(LPCTSTR szKey);
	CString IsExistMEmuInfo(LPCTSTR szKey);

};
