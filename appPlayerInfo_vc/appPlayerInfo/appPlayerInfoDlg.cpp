#include "stdafx.h"
#include "appPlayerInfo.h"
#include "appPlayerInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CappPlayerInfoDlg::CappPlayerInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CappPlayerInfoDlg::IDD, pParent)
{
}

void CappPlayerInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CappPlayerInfoDlg, CDialog)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &CappPlayerInfoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CappPlayerInfoDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CappPlayerInfoDlg::OnBnClickedButton3)
END_MESSAGE_MAP()

BOOL CappPlayerInfoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;  
}

void CappPlayerInfoDlg::OnPaint()
{
	CPaintDC dc(this);
}

//[MOMO]¾ÛÇÃ·¹ÀÌ¾î
void CappPlayerInfoDlg::OnBnClickedButton1()
{
	CRegInfo reginfo;
	CString strInstallDir = reginfo.IsExistMOMOInfo("InstallDir");
	if(strInstallDir.IsEmpty())
		return;

	CString strAppExe;
	strAppExe.Format("%s\\dnplayer.exe", strInstallDir);
	if(!::PathFileExists(strAppExe))
		return;
	
	HINSTANCE hInstance = ::ShellExecute(NULL, "open", strAppExe, NULL, NULL, SW_SHOW);		
}

CString GetFilePath(CString strFilename)
{
	int nPos = strFilename.ReverseFind('\\');
	if(nPos > 0)
		return strFilename.Left(nPos);

	return strFilename;
}

void CappPlayerInfoDlg::OnBnClickedButton2()
{
	CRegInfo reginfo;
	CString strInstallDir = reginfo.IsExistNoxInfo("UninstallString");
	if(strInstallDir.IsEmpty())
		return;

	CString strAppExe;
	strAppExe.Format("%s\\Nox.exe", GetFilePath(strInstallDir));
	if(!::PathFileExists(strAppExe))
		return;
	
	HINSTANCE hInstance = ::ShellExecute(NULL, "open", strAppExe, NULL, NULL, SW_SHOW);	
}

void CappPlayerInfoDlg::OnBnClickedButton3()
{
	CRegInfo reginfo;
	CString strInstallDir = reginfo.IsExistMEmuInfo("InstallLocation");
	if(strInstallDir.IsEmpty())
		return;

	CString strAppExe;
	strAppExe.Format("%s\\MEmu\\MEmuConsole.exe", strInstallDir);
	if(!::PathFileExists(strAppExe))
		return;
	
	HINSTANCE hInstance = ::ShellExecute(NULL, "open", strAppExe, "MEmu", NULL, SW_SHOW);	
}
