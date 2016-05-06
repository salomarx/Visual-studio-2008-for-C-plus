// SketcherDoc.h : interface of the CSketcherDoc class
//


#pragma once
 

class CSketcherDoc : public CDocument
{
protected: // create from serialization only
	CSketcherDoc();
	DECLARE_DYNCREATE(CSketcherDoc)

// Attributes
public:

// Operations
public:
      unsigned int GetElementType()    // Get the element type
         { return m_Element; }
      COLORREF GetElementColor()       // Get the element color
         { return m_Color; }

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CSketcherDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnColorBlack();
public:
  afx_msg void OnColorRed();
public:
  afx_msg void OnColorGreen();
public:
  afx_msg void OnColorBlue();
public:
  afx_msg void OnElementLine();
public:
  afx_msg void OnElementRectangle();
public:
  afx_msg void OnElementCircle();
public:
  afx_msg void OnElementCurve();
protected:
  // Current element type
  unsigned int m_Element;
  COLORREF m_Color;                    // Current drawing color
public:
  afx_msg void OnUpdateColorBlack(CCmdUI *pCmdUI);
public:
  afx_msg void OnUpdateColorGreen(CCmdUI *pCmdUI);
public:
  afx_msg void OnUpdateColorRed(CCmdUI *pCmdUI);
public:
  afx_msg void OnUpdateColorBlue(CCmdUI *pCmdUI);
public:
  afx_msg void OnUpdateElementLine(CCmdUI *pCmdUI);
public:
  afx_msg void OnUpdateElementRectangle(CCmdUI *pCmdUI);
public:
  afx_msg void OnUpdateElementCircle(CCmdUI *pCmdUI);
public:
  afx_msg void OnUpdateElementCurve(CCmdUI *pCmdUI);
public:
  afx_msg void OnElementEllipse();
public:
  afx_msg void OnUpdateElementEllipse(CCmdUI *pCmdUI);
protected:
  int m_PenStyle;
public:

  int GetPenStyle(void)
  {
    return m_PenStyle;
  }
public:
  afx_msg void OnPenstyleSolid();
public:
  afx_msg void OnUpdatePenstyleSolid(CCmdUI *pCmdUI);
public:
  afx_msg void OnPenstyleDashed();
public:
  afx_msg void OnUpdatePenstyleDashed(CCmdUI *pCmdUI);
public:
  afx_msg void OnPenstyleDotted();
public:
  afx_msg void OnUpdatePenstyleDotted(CCmdUI *pCmdUI);
public:
  afx_msg void OnPenstyleDashdotted();
public:
  afx_msg void OnUpdatePenstyleDashdotted(CCmdUI *pCmdUI);
public:
  afx_msg void OnPenstyleDashdotdotted();
public:
  afx_msg void OnUpdatePenstyleDashdotdotted(CCmdUI *pCmdUI);
};


