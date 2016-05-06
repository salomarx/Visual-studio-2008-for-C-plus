#pragma once

// CElement command target

class CElement : public CObject
{
   DECLARE_SERIAL(CElement)
   protected:
      COLORREF m_Color;                     // Color of an element
      CRect m_EnclosingRect;                // Rectangle enclosing an element
      int m_Pen;                            // Pen width

   public:
      virtual ~CElement();                   // Virtual destructor
      // Virtual draw operation
      virtual void Draw(CDC* pDC,CElement* pElement=0) {}
      virtual void Move(CSize& aSize){}      // Move an element
      CRect GetBoundRect();                  // Get the bounding rectangle for an element
      virtual void Serialize(CArchive& ar);  // Serialize function for the class

   protected:
      CElement();                            // Here to prevent it being called
};

class CLine :
  public CElement
{
   DECLARE_SERIAL(CLine)
   public:
      ~CLine(void);
      // Function to display a line
      virtual void Draw(CDC* pDC, CElement* pElement=0);     

      // Constructor for a line object
      CLine(CPoint Start, CPoint End, COLORREF aColor, int PenWidth);

      // Function to move an element
      virtual void Move(CSize& aSize);
      virtual void Serialize(CArchive& ar);  // Serialize function for the class

   protected:
      CPoint m_StartPoint;             // Start point of line
      CPoint m_EndPoint;               // End point of line

      CLine(void);                     // Default constructor - should not be used
};

class CRectangle :
  public CElement
{
   DECLARE_SERIAL(CRectangle)
   public:
      ~CRectangle(void);
      // Function to display a line
      virtual void Draw(CDC* pDC, CElement* pElement=0);     

      // Constructor for a rectangle object
      CRectangle(CPoint Start, CPoint End, COLORREF aColor, int PenWidth);

      // Function to move an element
      virtual void Move(CSize& aSize);
      virtual void Serialize(CArchive& ar);  // Serialize function for the class

   protected:
      CRectangle(void);                // Default constructor - should not be used
};

class CCircle :
  public CElement
{
   DECLARE_SERIAL(CCircle)
   public:
      ~CCircle(void);
      // Function to display a line
      virtual void Draw(CDC* pDC, CElement* pElement=0);     

      // Constructor for a circle object
      CCircle(CPoint Start, CPoint End, COLORREF aColor, int PenWidth);

      // Function to move an element
      virtual void Move(CSize& aSize);
      virtual void Serialize(CArchive& ar);  // Serialize function for the class

   protected:
      CCircle(void);                   // Default constructor - should not be used
};

class CCurve :
  public CElement
{
   DECLARE_SERIAL(CCurve)
   public:
      ~CCurve(void);
      // Function to display a line
      virtual void Draw(CDC* pDC, CElement* pElement=0);     

      // Constructor for a curve object
      CCurve(CPoint FirstPoint, CPoint SecondPoint, COLORREF aColor, int PenWidth);

      void AddSegment(CPoint& aPoint);       //Add a segment to the curve

      // Function to move an element
      virtual void Move(CSize& aSize);
      virtual void Serialize(CArchive& ar);  // Serialize function for the class

   protected:
      CCurve(void);                          // Default constructor - should not be used
      CList<CPoint, CPoint&> m_PointList;    // Type safe point list
};

// Class defining a text object
class CText: public CElement
{
  DECLARE_SERIAL(CText)
  public:
    // Function to display a text element
    virtual void Draw(CDC* pDC, CElement* pElement=0);

    // Constructor for a text element
    CText(CPoint Start, CPoint End, CString aString, COLORREF aColor);
    virtual void Move(CSize& aSize);       // Move a text element
    virtual void Serialize(CArchive& ar);  // Serialize function for the class
  protected:
    CPoint m_StartPoint;                   // position of a text element
    CString m_String;                      // Text to be displayed
    CText(){}                              // Default constructor
};

