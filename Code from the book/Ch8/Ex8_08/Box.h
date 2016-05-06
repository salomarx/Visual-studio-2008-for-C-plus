#pragma once

class CBox
{
public:
 CBox(double lv = 1.0, double wv = 1.0, double hv = 1.0);public:
public:
 ~CBox(void);

private:
   // Length of a box in inches
   double m_Length;
   // Width of a box in inches
   double m_Width;
   // Height of a box in inches
   double m_Height;
public:
   double GetHeight(void)
   {
     return m_Height;
   }
public:

  double GetWidth(void)
  {
    return m_Width;
  }
public:

  double GetLength(void)
  {
    return m_Length;
  }
public:

  double Volume(void) const
  {
    return m_Length*m_Width*m_Height;
  }
public:
  // Overloaded addition operator
  CBox operator+(const CBox& aBox) const;
public:
  // Multiply a box by an integer
  CBox operator*(int n) const;
public:
  // Divide one box into another
  int operator/(const CBox& aBox) const;
};
