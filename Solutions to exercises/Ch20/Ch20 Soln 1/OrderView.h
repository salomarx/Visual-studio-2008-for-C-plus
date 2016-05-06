#pragma once

class COrderSet;           // Declare the class name
class CDBSampleDoc;        // Declare the class name

// COrderView form view

class COrderView : public CRecordView
{
  DECLARE_DYNCREATE(COrderView)

protected:
  virtual ~COrderView(){}
  virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
  virtual void OnInitialUpdate();

public:
  enum { IDD = IDD_ORDERS_FORM };
  COrderSet* m_pSet;

  // Inline function definition
  CDBSampleDoc* GetDocument() const
  {
    return reinterpret_cast<CDBSampleDoc*>(m_pDocument);
  }

  COrderSet* GetRecordset();
  virtual CRecordset* OnGetRecordset();
  COrderView();           // constructor now public


#ifdef _DEBUG
  virtual void AssertValid() const;
  virtual void Dump(CDumpContext& dc) const;
#endif
public:
  DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnProducts();
protected:
  virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
public:
  afx_msg void OnCustomer();
};
