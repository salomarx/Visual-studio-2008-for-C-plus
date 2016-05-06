#pragma once

// CElement command target

class CElement : public CObject
{
   protected:
      COLORREF m_Color;                  // Color of an element
      CRect m_EnclosingRect;             // Rectangle enclosing an element
      int m_Pen;                         // Pen width

   public:
      virtual ~CElement();               // Virtual destructor
      virtual void Draw(CDC* pDC) {}     // Virtual draw operation

      CRect GetBoundRect();       // Get the bounding rectangle for an element

   protected:
      CElement();                        // Here to prevent it being called
};

class CLine :
  public CElement
{
   public:
      ~CLine(void);
      virtual void Draw(CDC* pDC);     // Function to display a line

      // Constructor for a line object
      CLine(CPoint Start, CPoint End, COLORREF aColor);

   protected:
      CPoint m_StartPoint;             // Start point of line
      CPoint m_EndPoint;               // End point of line

      CLine(void);                     // Default constructor - should not be used
};

class CRectangle :
  public CElement
{
   public:
      ~CRectangle(void);
      virtual void Draw(CDC* pDC);     // Function to display a rectangle

      // Constructor for a rectangle object
      CRectangle(CPoint Start, CPoint End, COLORREF aColor);

   protected:
      CRectangle(void);                // Default constructor - should not be used
};

class CCircle :
  public CElement
{
   public:
      ~CCircle(void);
      virtual void Draw(CDC* pDC);     // Function to display a circle

      // Constructor for a circle object
      CCircle(CPoint Start, CPoint End, COLORREF aColor);

   protected:
      CCircle(void);                   // Default constructor - should not be used
};

class CCurve :
  public CElement
{
   public:
      ~CCurve(void);
      virtual void Draw(CDC* pDC); // Function to display a curve

      // Constructor for a curve object
      CCurve(COLORREF aColor);

   protected:
      CCurve(void);                    // Default constructor - should not be used
};


