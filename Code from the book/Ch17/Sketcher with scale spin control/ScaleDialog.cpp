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
  DDX_Text(pDX, IDC_SCALE, m_Scale);
	DDV_MinMaxInt(pDX, m_Scale, 1, 8);
}


BEGIN_MESSAGE_MAP(CScaleDialog, CDialog)
END_MESSAGE_MAP()


// CScaleDialog message handlers

BOOL CScaleDialog::OnInitDialog()
{
  CDialog::OnInitDialog();

   // First get a pointer to the spin control
   CSpinButtonCtrl* pSpin;
   pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_SCALE);

   // If you have not checked the auto buddy option in
   // the spin control's properties, set the buddy control here

   // Set the spin control range
   pSpin->SetRange(1, 8);

  return TRUE;  // return TRUE unless you set the focus to a control
  // EXCEPTION: OCX Property Pages should return FALSE
}
