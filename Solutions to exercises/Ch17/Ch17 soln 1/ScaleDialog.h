#pragma once


// CScaleDialog dialog

class CScaleDialog : public CDialog
{
	DECLARE_DYNAMIC(CScaleDialog)

public:
	CScaleDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CScaleDialog();

// Dialog Data
	enum { IDD = IDD_SCALE_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  // Stores current drawing scale
  int m_Scale;
public:
  virtual BOOL OnInitDialog();
public:
  afx_msg void OnBnClickedScale1();
public:
  afx_msg void OnBnClickedScale2();
public:
  afx_msg void OnBnClickedScale3();
public:
  afx_msg void OnBnClickedScale4();
public:
  afx_msg void OnBnClickedScale5();
public:
  afx_msg void OnBnClickedScale6();
public:
  afx_msg void OnBnClickedScale7();
public:
  afx_msg void OnBnClickedScale8();
};
