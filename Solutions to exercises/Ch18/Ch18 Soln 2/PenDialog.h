#pragma once


// CPenDialog dialog

class CPenDialog : public CDialog
{
	DECLARE_DYNAMIC(CPenDialog)

public:
	CPenDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CPenDialog();

// Dialog Data
	enum { IDD = IDD_PENWIDTH_DLG };

  // Data stored in the dialog
public:
   int m_PenWidth;                     // Record the pen width

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  virtual BOOL OnInitDialog();
public:
  afx_msg void OnPenwidth0();
public:
  afx_msg void OnPenwidth1();
public:
  afx_msg void OnPenwidth2();
public:
  afx_msg void OnPenwidth3();
public:
  afx_msg void OnPenwidth4();
public:
  afx_msg void OnPenwidth5();
};
