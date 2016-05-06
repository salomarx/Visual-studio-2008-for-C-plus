// Elements.cpp : implementation file
//

#include "stdafx.h"
#include "Sketcher.h" 
#include "Elements.h"
#include <math.h>

// CElement

CElement::CElement()
: m_PenStyle(0)
{
}

CElement::~CElement()
{
}

// Get the bounding rectangle for an element
CRect CElement::GetBoundRect()
{
   CRect BoundingRect;                 // Object to store bounding rectangle
   BoundingRect = m_EnclosingRect;     // Store the enclosing rectangle

   // Increase the rectangle by the pen width
   BoundingRect.InflateRect(m_Pen, m_Pen);
   return BoundingRect;                // Return the bounding rectangle
}

// CElement member functions

CLine::CLine(void)
{
}

CLine::~CLine(void)
{
}

// CLine class constructor
CLine::CLine(CPoint Start, CPoint End, COLORREF aColor, int penStyle)
{
   m_StartPoint = Start;               // Set line start point
   m_EndPoint = End;                   // Set line end point
   m_Color = aColor;                   // Set line color
   m_Pen = 1;                          // Set pen width
   m_PenStyle = penStyle;              // Set the pen style

   // Define the enclosing rectangle
   m_EnclosingRect = CRect(Start, End);
   m_EnclosingRect.NormalizeRect();
}

// Draw a CLine object
void CLine::Draw(CDC* pDC)
{
   // Create a pen for this object and
   // initialize it to the object color and line width of 1 pixel
   CPen aPen;
   if(!aPen.CreatePen(m_PenStyle, m_Pen, m_Color))
   {
      // Pen creation failed. Abort the program
      AfxMessageBox(_T("Pen creation failed drawing a line"), MB_OK);
      AfxAbort();
   }

   CPen* pOldPen = pDC->SelectObject(&aPen);  // Select the pen

   // Now draw the line
   pDC->MoveTo(m_StartPoint);
   pDC->LineTo(m_EndPoint);

   pDC->SelectObject(pOldPen);                // Restore the old pen
}

CRectangle::CRectangle(void)
{
}

CRectangle::~CRectangle(void)
{
}

// CRectangle class constructor
CRectangle:: CRectangle(CPoint Start, CPoint End, COLORREF aColor, int penStyle)
{
   m_Color = aColor;          // Set rectangle color
   m_Pen = 1;                 // Set pen width
   m_PenStyle = penStyle;     // Set the pen style

   // Define the enclosing rectangle 
   m_EnclosingRect = CRect(Start, End);
   m_EnclosingRect.NormalizeRect();
}

// Draw a CRectangle object
void CRectangle::Draw(CDC* pDC)
{
   // Create a pen for this object and
   // initialize it to the object color and line width of 1 pixel
   CPen aPen;
   if(!aPen.CreatePen(m_PenStyle, m_Pen, m_Color))
   {
      // Pen creation failed
      AfxMessageBox(_T("Pen creation failed drawing a rectangle"), MB_OK);
      AfxAbort();
   }

   // Select the pen
   CPen* pOldPen = pDC->SelectObject(&aPen);
   // Select the brush
   CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);

   // Now draw the rectangle
   pDC->Rectangle(m_EnclosingRect);

   pDC->SelectObject(pOldBrush);       // Restore the old brush
   pDC->SelectObject(pOldPen);         // Restore the old pen
}

CCircle::CCircle(void)
{
}

CCircle::~CCircle(void)
{
}

// Constructor for a circle object
CCircle::CCircle(CPoint Start, CPoint End, COLORREF aColor, int penStyle)
{
   // First calculate the radius
   // We use floating point because that is required by 
   // the library function (in math.h) for calculating a square root.
   long Radius = static_cast<long> (sqrt(
                  static_cast<double>((End.x-Start.x)*(End.x-Start.x)+
                                      (End.y-Start.y)*(End.y-Start.y))));

   // Now calculate the rectangle enclosing
   // the circle assuming the MM_TEXT mapping mode
   m_EnclosingRect = CRect(Start.x-Radius, Start.y-Radius,
                           Start.x+Radius, Start.y+Radius);

   m_Color = aColor;                   // Set the color for the circle
   m_Pen = 1;                          // Set pen width to 1
   m_PenStyle = penStyle;     // Set the pen style
}

// Draw a circle
void CCircle::Draw(CDC* pDC)
{
   // Create a pen for this object and
   // initialize it to the object color and line width of 1 pixel
   CPen aPen;
   if(!aPen.CreatePen(m_PenStyle, m_Pen, m_Color))
   {
      // Pen creation failed
      AfxMessageBox(_T("Pen creation failed drawing a circle"), MB_OK);
      AfxAbort();
   }

   CPen* pOldPen = pDC->SelectObject(&aPen);  // Select the pen

   // Select a null brush
   CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);

   // Now draw the circle
   pDC->Ellipse(m_EnclosingRect);

   pDC->SelectObject(pOldPen);                // Restore the old pen
   pDC->SelectObject(pOldBrush);              // Restore the old brush
}

CCurve::CCurve(void)
{
}

CCurve::~CCurve(void)
{
}

// Constructor for a curve object
CCurve::CCurve(COLORREF aColor, int penStyle)
{
   m_Color = aColor;
   m_EnclosingRect = CRect(0,0,0,0);
   m_Pen = 1;
   m_PenStyle = penStyle;     // Set the pen style
}

// Draw a curve
void CCurve::Draw(CDC* pDC)
{
}

// Constructor for an ellipse object
CEllipse:: CEllipse(CPoint Start, CPoint End, COLORREF Color, int penStyle)
{
   m_Color = Color;           // Set ellipse color
   m_Pen = 1;                 // Set pen width
   m_PenStyle = penStyle;     // Set the pen style

   // Define the enclosing rectangle 
   // Change to draw an ellipse from the center
//   m_EnclosingRect = CRect(Start, End);
   m_EnclosingRect = CRect(Start - (End-Start), End);

   m_EnclosingRect.NormalizeRect();
}

// Draw an ellipse
void CEllipse::Draw(CDC* pDC)
{
   // Create a pen for this object and
   // initialize it to the object color and line width of 1 pixel
   CPen aPen; 
   if(!aPen.CreatePen(m_PenStyle, m_Pen, m_Color))
   {                                          // Pen creation failed
      AfxMessageBox(_T("Pen creation failed drawing an ellipse"), MB_OK);
      AfxAbort();
   }

   CPen* pOldPen = pDC->SelectObject(&aPen);  // Select the pen

   // Select a null brush
   CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);

   // Now draw the ellipse
   pDC->Ellipse(m_EnclosingRect);

   pDC->SelectObject(pOldPen);                // Restore the old pen
   pDC->SelectObject(pOldBrush);              // Restore the old brush
}
