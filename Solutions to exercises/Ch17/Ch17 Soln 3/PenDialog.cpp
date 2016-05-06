// PenDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Sketcher.h"
#include "PenDialog.h"


// CPenDialog dialog

IMPLEMENT_DYNAMIC(CPenDialog, CDialog)

CPenDialog::CPenDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CPenDialog::IDD, pParent)
 
  , m_PenWidth(0)
{

}

CPenDialog::~CPenDialog()
{
}

void CPenDialog::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  DDX_CBIndex(pDX, IDC_PENWIDTH, m_PenWidth);
}


BEGIN_MESSAGE_MAP(CPenDialog, CDialog)
END_MESSAGE_MAP()


// CPenDialog message handlers

BOOL CPenDialog::OnInitDialog()
{
  CDialog::OnInitDialog();

  // Initialize ComboBox
  CComboBox* pCBox = (CComboBox*)GetDlgItem(IDC_PENWIDTH);
  pCBox->AddString(_T("Pen Width 0"));     // Add the strings to the box
  pCBox->AddString(_T("Pen Width 1"));
  pCBox->AddString(_T("Pen Width 2"));
  pCBox->AddString(_T("Pen Width 3"));
  pCBox->AddString(_T("Pen Width 4"));
  pCBox->AddString(_T("Pen Width 5"));
  pCBox->SetCurSel(m_PenWidth);        // Highlight the current pen width

  return TRUE;  // return TRUE unless you set the focus to a control
  // EXCEPTION: OCX Property Pages should return FALSE
}

