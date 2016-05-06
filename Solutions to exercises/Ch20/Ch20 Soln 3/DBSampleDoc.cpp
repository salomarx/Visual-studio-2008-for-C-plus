// DBSampleDoc.cpp : implementation of the CDBSampleDoc class
//

#include "stdafx.h"
#include "DBSample.h"

#include "ProductSet.h"
#include "DBSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDBSampleDoc

IMPLEMENT_DYNCREATE(CDBSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CDBSampleDoc, CDocument)
END_MESSAGE_MAP()


// CDBSampleDoc construction/destruction

CDBSampleDoc::CDBSampleDoc()
{
	// TODO: add one-time construction code here

}

CDBSampleDoc::~CDBSampleDoc()
{
}

BOOL CDBSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CDBSampleDoc diagnostics

#ifdef _DEBUG
void CDBSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDBSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDBSampleDoc commands
