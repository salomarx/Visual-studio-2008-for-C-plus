// ProductView.h : header file
#pragma once

class CProductSet;

class CProductView : public CRecordView
{
//   DECLARE_DYNCREATE(CProductView)
public:
   CProductView();
  virtual ~CProductView();


public:
   enum { IDD = IDD_PRODUCT_FORM };     // Form Data
   CProductSet* m_pSet;


// Operations
public:
   CProductSet* GetRecordset();


// Implementation
protected:
#ifdef _DEBUG
   virtual void AssertValid() const;
   virtual void Dump(CDumpContext& dc) const;
#endif
   virtual void DoDataExchange(CDataExchange* pDX);
public:
  virtual void OnInitialUpdate();
public:
  virtual CRecordset* OnGetRecordset();
public:
  DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnSelectproduct();
public:
  afx_msg void OnDone();
public:
  long m_OrderID;
public:
  CString m_CustomerName;
public:
  int m_Quantity;
public:
  float m_Discount;
public:
  void InitializeView(void);
public:
  bool m_OrderAdded;
public:
  double m_TotalValue;
};
