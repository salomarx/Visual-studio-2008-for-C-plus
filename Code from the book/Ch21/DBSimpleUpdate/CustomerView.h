// CustomerView.h : header file

#pragma once

class CCustomerSet;

class CCustomerView : public CRecordView
{
  //DECLARE_DYNCREATE(CCustomerView)
public:
  CCustomerView();  
  virtual ~CCustomerView();

public:
  enum { IDD = IDD_CUSTOMER_FORM };// Form Data
  CCustomerSet* m_pSet;


// Operations
public:
  CCustomerSet* GetRecordset(); 

#ifdef _DEBUG
  virtual void AssertValid() const;
  virtual void Dump(CDumpContext& dc) const;
#endif

protected:
  virtual void DoDataExchange(CDataExchange* pDX);
public:
  virtual CRecordset* OnGetRecordset();
public:
  virtual void OnInitialUpdate();
public:
  // Stores order date
  CTime m_OrderDate;
public:
  // Stores date order required
  CTime m_RequiredDate;
public:
  DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnSelectproducts();
public:
  afx_msg void OnCancel();
public:
  long m_NewOrderID;
public:
  void SetNewOrderID(void);
};
