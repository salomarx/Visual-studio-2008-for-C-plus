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

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  virtual BOOL OnInitDialog();
public:
  int m_PenWidth;
};
