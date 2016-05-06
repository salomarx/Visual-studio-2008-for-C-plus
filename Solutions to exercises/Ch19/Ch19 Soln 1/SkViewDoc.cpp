// SkViewDoc.cpp : implementation of the CSkViewDoc class
//

#include "stdafx.h"
#include "DllImports.h"
#include "SkView.h"

#include "SkViewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSkViewDoc

IMPLEMENT_DYNCREATE(CSkViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CSkViewDoc, CDocument)
END_MESSAGE_MAP()


// CSkViewDoc construction/destruction

CSkViewDoc::CSkViewDoc()
{
	// TODO: add one-time construction code here

}

CSkViewDoc::~CSkViewDoc()
{
   POSITION aPosition = m_ElementList.GetHeadPosition();
   while(aPosition)
      delete m_ElementList.GetNext(aPosition);

   m_ElementList.RemoveAll();
}

BOOL CSkViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CSkViewDoc serialization

void CSkViewDoc::Serialize(CArchive& ar)
{
  m_ElementList.Serialize(ar);

  if (ar.IsStoring())
  {
    // TODO: add storing code here
  }
  else
  {
    ar >> m_Color
       >> m_Element
       >> m_PenWidth
       >> m_DocSize;
  }
}

// Get the rectangle enclosing the entire document
CRect CSkViewDoc::GetDocExtent()
{
  CRect DocExtent(0,0,1,1);            // Initial document extent
  CRect ElementBound(0,0,0,0);         // Space for element bounding rectangle

  POSITION aPosition = m_ElementList.GetHeadPosition();

  while(aPosition)                     // Loop through all the elements in the list
  {
    // Get the bounding rectangle for the element
    ElementBound=(m_ElementList.GetNext(aPosition))->GetBoundRect();

    // Make coordinates of document extent the outer limits
    DocExtent.UnionRect(DocExtent, ElementBound);
  }
  DocExtent.NormalizeRect();
  return DocExtent;
}

// CSkViewDoc diagnostics

#ifdef _DEBUG
void CSkViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSkViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSkViewDoc commands

BOOL CSkViewDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
  POSITION aPosition = m_ElementList.GetHeadPosition();
  while(aPosition)
    delete m_ElementList.GetNext(aPosition);

  m_ElementList.RemoveAll();
  if (!CDocument::OnOpenDocument(lpszPathName))
   return FALSE;

  // TODO:  Add your specialized creation code here

  return TRUE;
}
