#pragma once


// CTextDialog dialog

class CTextDialog : public CDialog
{
	DECLARE_DYNAMIC(CTextDialog)

public:
	CTextDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTextDialog();

// Dialog Data
	enum { IDD = IDD_TEXT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  // Store a text string entered in the edit box in the text dialog
  CString m_TextString;
};
