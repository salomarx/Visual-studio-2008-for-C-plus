// Elements.cpp : implementation file
//

#include "stdafx.h"
#include "Sketcher.h"
#include "Elements.h"
#include "OurConstants.h"
#include <math.h>

// CElement

CElement::CElement()
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
CLine::CLine(CPoint Start, CPoint End, COLORREF aColor)
{
   m_StartPoint = Start;               // Set line start point
   m_EndPoint = End;                   // Set line end point
   m_Color = aColor;                   // Set line color
   m_Pen = 1;                          // Set pen width

   // Define the enclosing rectangle
   m_EnclosingRect = CRect(Start, End);
   m_EnclosingRect.NormalizeRect();
}

// Draw a CLine object
void CLine::Draw(CDC* pDC, CElement* pElement)
{
   // Create a pen for this object and
   // initialize it to the object color and line width of 1 pixel
   CPen aPen;
   COLORREF aColor = m_Color;             // Initialize with element color
   if(this == pElement)                   // This element selected?
      aColor = SELECT_COLOR;              // Set highlight color
   if(!aPen.CreatePen(PS_SOLID, m_Pen, aColor))
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

void CLine::Move(CSize& aSize)
{
  m_StartPoint += aSize;               // Move the start point
  m_EndPoint += aSize;                 // and the end point
  m_EnclosingRect += aSize;            // Move the enclosing rectangle
}

CRectangle::CRectangle(void)
{
}

CRectangle::~CRectangle(void)
{
}

// CRectangle class constructor
CRectangle:: CRectangle(CPoint Start, CPoint End, COLORREF aColor)
{
   m_Color = aColor;          // Set rectangle color
   m_Pen = 1;                 // Set pen width

   // Define the enclosing rectangle 
   m_EnclosingRect = CRect(Start, End);
   m_EnclosingRect.NormalizeRect();
}

// Draw a CRectangle object
void CRectangle::Draw(CDC* pDC, CElement* pElement)
{
   // Create a pen for this object and
   // initialize it to the object color and line width of 1 pixel
   CPen aPen;
   COLORREF aColor = m_Color;             // Initialize with element color
   if(this == pElement)                   // This element selected?
      aColor = SELECT_COLOR;              // Set highlight color
   if(!aPen.CreatePen(PS_SOLID, m_Pen, aColor))
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

void CRectangle::Move(CSize& aSize)
{
  m_EnclosingRect+= aSize;             // Move the rectangle
}

CCircle::CCircle(void)
{
}

CCircle::~CCircle(void)
{
}

// Constructor for a circle object
CCircle::CCircle(CPoint Start, CPoint End, COLORREF aColor)
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
}

// Draw a circle
void CCircle::Draw(CDC* pDC, CElement* pElement)
{
   // Create a pen for this object and
   // initialize it to the object color and line width of 1 pixel
   CPen aPen;
   COLORREF aColor = m_Color;             // Initialize with element color
   if(this == pElement)                   // This element selected?
      aColor = SELECT_COLOR;              // Set highlight color
   if(!aPen.CreatePen(PS_SOLID, m_Pen, aColor))
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

void CCircle::Move(CSize& aSize)
{
  m_EnclosingRect+= aSize;             // Move rectangle defining the circle
}

CCurve::CCurve(void)
{
}

CCurve::~CCurve(void)
{
}

// Constructor for a curve object
CCurve::CCurve(CPoint FirstPoint,CPoint SecondPoint, COLORREF aColor)
{
   m_PointList.AddHead(FirstPoint);    // Add the 1st point to the list
   m_PointList.AddHead(SecondPoint);   // Add the 2nd point to the list
   m_Color = aColor;                   // Store the color
   m_Pen = 1;                          // Set the pen width

   // Construct the enclosing rectangle assuming MM_TEXT mode
   m_EnclosingRect = CRect(FirstPoint, SecondPoint);
   m_EnclosingRect.NormalizeRect();
}

void CCurve::AddSegment(CPoint& aPoint)
{
   m_PointList.AddHead(aPoint);                // Add the point to the end

   // Modify the enclosing rectangle for the new point
   m_EnclosingRect = CRect(min(aPoint.x, m_EnclosingRect.left),
                           min(aPoint.y, m_EnclosingRect.top),
                           max(aPoint.x, m_EnclosingRect.right),
                           max(aPoint.y, m_EnclosingRect.bottom));
}

// Draw a curve
void CCurve::Draw(CDC* pDC, CElement* pElement)
{
   // Create a pen for this object and
   // initialize it to the object color and line width of 1 pixel
   CPen aPen;
   COLORREF aColor = m_Color;             // Initialize with element color
   if(this == pElement)                   // This element selected?
      aColor = SELECT_COLOR;              // Set highlight color
   if(!aPen.CreatePen(PS_SOLID, m_Pen, aColor))
   {
      // Pen creation failed. Close the program
      AfxMessageBox(_T("Pen creation failed drawing a curve"), MB_OK);
      AfxAbort();
   }

   CPen* pOldPen = pDC->SelectObject(&aPen);  // Select the pen

   // Now draw the curve
   // Get the position in the list of the first element
   POSITION aPosition = m_PointList.GetTailPosition();

   // As long as it's good, move to that point
   if(aPosition)
      pDC->MoveTo(m_PointList.GetPrev(aPosition));

   // Draw a segment for each of the following points
   while(aPosition)
      pDC->LineTo(m_PointList.GetPrev(aPosition));

   pDC->SelectObject(pOldPen);         // Restore the old pen
}

void CCurve::Move(CSize& aSize)
{
  m_EnclosingRect += aSize;            // Move the rectangle

  // Get the 1st element position
  POSITION aPosition = m_PointList.GetHeadPosition();

  while(aPosition)
    m_PointList.GetNext(aPosition) += aSize; // Move each pt in the list
}
