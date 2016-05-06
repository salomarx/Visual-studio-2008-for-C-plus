// SkViewDoc.h : interface of the CSkViewDoc class
//


#pragma once


class CSkViewDoc : public CDocument
{
protected: // create from serialization only
	CSkViewDoc();
	DECLARE_DYNCREATE(CSkViewDoc)

// Attributes
public:
protected:
  COLORREF m_Color;
  unsigned int m_Element;
  CTypedPtrList<CObList, CElement*> m_ElementList;
  int m_PenWidth;
  CSize m_DocSize;

// Operations
public:
  POSITION GetListHeadPosition()
     { return m_ElementList.GetHeadPosition(); }
  CElement* GetNext(POSITION& aPos)
     { return m_ElementList.GetNext(aPos); }
  CRect GetDocExtent();                    // Get the bounding rectangle for the whole document

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CSkViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
  virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
};


