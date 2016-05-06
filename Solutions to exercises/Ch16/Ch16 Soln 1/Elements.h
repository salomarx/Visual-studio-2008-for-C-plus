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
      // Virtual draw operation
      virtual void Draw(CDC* pDC,CElement* pElement=0) {}
      virtual void Move(CSize& aSize){}  // Move an element
      CRect GetBoundRect();       // Get the bounding rectangle for an element

   protected:
      CElement();                        // Here to prevent it being called
};

class CLine :
  public CElement
{
   public:
      ~CLine(void);
      // Function to display a line
      virtual void Draw(CDC* pDC, CElement* pElement=0);     

      // Constructor for a line object
      CLine(CPoint Start, CPoint End, COLORREF aColor);

      // Function to move an element
      virtual void Move(CSize& aSize);

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
      // Function to display a line
      virtual void Draw(CDC* pDC, CElement* pElement=0);     

      // Constructor for a rectangle object
      CRectangle(CPoint Start, CPoint End, COLORREF aColor);

      // Function to move an element
      virtual void Move(CSize& aSize);

   protected:
      CRectangle(void);                // Default constructor - should not be used
};

class CCircle :
  public CElement
{
   public:
      ~CCircle(void);
      // Function to display a line
      virtual void Draw(CDC* pDC, CElement* pElement=0);     

      // Constructor for a circle object
      CCircle(CPoint Start, CPoint End, COLORREF aColor);

      // Function to move an element
      virtual void Move(CSize& aSize);

   protected:
      CCircle(void);                   // Default constructor - should not be used
};

class CCurve :
  public CElement
{
   public:
      ~CCurve(void);
      // Function to display a line
      virtual void Draw(CDC* pDC, CElement* pElement=0);     

      // Constructor for a curve object
      CCurve(CPoint FirstPoint, CPoint SecondPoint, COLORREF aColor);

      void AddSegment(CPoint& aPoint);    //Add a segment to the curve

      // Function to move an element
      virtual void Move(CSize& aSize);

   protected:
      CCurve(void);                    // Default constructor - should not be used
  CList<CPoint, CPoint&> m_PointList;  // Type safe point list
};


