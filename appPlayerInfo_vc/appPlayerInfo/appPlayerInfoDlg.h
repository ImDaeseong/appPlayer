#pragma once

class CappPlayerInfoDlg : public CDialog
{
public:
	CappPlayerInfoDlg(CWnd* pParent = NULL);	// standard constructor

	enum { IDD = IDD_APPPLAYERINFO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

protected:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
