// ScaleDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Sketcher.h"
#include "ScaleDialog.h"


// CScaleDialog dialog

IMPLEMENT_DYNAMIC(CScaleDialog, CDialog)

CScaleDialog::CScaleDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CScaleDialog::IDD, pParent)
  , m_Scale(0)
{

}

CScaleDialog::~CScaleDialog()
{
}

void CScaleDialog::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  DDX_LBIndex(pDX, IDC_SCALELIST, m_Scale);
	DDV_MinMaxInt(pDX, m_Scale, 0, 7);
}


BEGIN_MESSAGE_MAP(CScaleDialog, CDialog)
END_MESSAGE_MAP()


// CScaleDialog message handlers

BOOL CScaleDialog::OnInitDialog()
{
  CDialog::OnInitDialog();

  CListBox* pListBox = static_cast<CListBox*>(GetDlgItem(IDC_SCALELIST));
  pListBox->AddString(_T("Scale 1"));
  pListBox->AddString(_T("Scale 2"));
  pListBox->AddString(_T("Scale 3"));
  pListBox->AddString(_T("Scale 4"));
  pListBox->AddString(_T("Scale 5"));
  pListBox->AddString(_T("Scale 6"));
  pListBox->AddString(_T("Scale 7"));
  pListBox->AddString(_T("Scale 8"));
  pListBox->SetCurSel(m_Scale-1);

  return TRUE;  // return TRUE unless you set the focus to a control
  // EXCEPTION: OCX Property Pages should return FALSE
}
