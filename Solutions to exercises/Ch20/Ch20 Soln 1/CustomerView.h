// CCustomerView record view
#pragma once

class CCustomerSet;
class CDBSampleDoc;

class CCustomerView : public CRecordView
{
  DECLARE_DYNCREATE(CCustomerView)

public:
  enum { IDD = IDD_CUSTOMER_FORM };
  CCustomerSet* m_pSet;


public:
  CCustomerView();  
  CCustomerSet* GetRecordset();
  virtual CRecordset* OnGetRecordset();

  protected:
  virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
  virtual void OnInitialUpdate();
  virtual void OnActivateView(BOOL bActivate, CView* pActivateView,
                                                     CView* pDeactiveView);

// Implementation
protected:
  virtual ~CCustomerView(){}

#ifdef _DEBUG
  virtual void AssertValid() const;
  virtual void Dump(CDumpContext& dc) const;
#endif

public:
  DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnOrders();
public:
  afx_msg void OnProducts();
};
