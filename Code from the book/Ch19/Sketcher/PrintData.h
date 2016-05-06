#pragma once

class CPrintData
{
  public:
    UINT m_nWidths;                    // Page count for the width of the document
    UINT m_nLengths;                   // Page count for the length of the document
    CPoint m_DocRefPoint;              // Top left corner of the document contents
    CString m_DocTitle;                // The name of the document
};
