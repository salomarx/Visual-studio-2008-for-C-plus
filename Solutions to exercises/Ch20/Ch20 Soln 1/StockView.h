// CStockView record view
#pragma once

class CStockSet;
class CDBSampleDoc;

class CStockView : public CRecordView
{
  DECLARE_DYNCREATE(CStockView)

public:
  enum { IDD = IDD_STOCK_FORM };
  CStockSet* m_pSet;

public:
  CStockView();  
  CStockSet* GetRecordset();
  virtual CRecordset* OnGetRecordset();

  protected:
  virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
  virtual ~CStockView(){}

#ifdef _DEBUG
  virtual void AssertValid() const;
  virtual void Dump(CDumpContext& dc) const;
#endif

public:
  DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnProducts();
public:
  virtual void OnInitialUpdate();
};
