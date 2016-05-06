// Elements.h
// Defines element types
#pragma once

using namespace System;
using namespace System::Drawing;

namespace CLRSketcher 
{
  enum class LineStyle{SOLID, DOTTED, DASHED};

  // The base class for all elements
  public ref class Element abstract
  {
  protected:
    Color color;
    System::Drawing::Rectangle boundRect;
    Pen^ pen;
    LineStyle lineStyle;

  public:
    virtual void Draw(Graphics^ g) abstract;

	// Sets the line drawing pattern for a pen
	void setPenPattern(Pen^ pen, LineStyle lineStyle)
	{
        array<float>^ dottedPattern = { 2.0f, 2.0f};
        array<float>^ dashedPattern = { 8.0f, 3.0f};
		if(lineStyle == LineStyle::DOTTED)
          pen->DashPattern = dottedPattern;
		else if(lineStyle == LineStyle::DASHED)
          pen->DashPattern = dashedPattern;
 	}
  };

  // The class defining a line element
  public ref class Line : Element
  {
    protected:
      Point start;
      Point end;

    public:
      // Constructor
      Line(Color color, LineStyle lineStyle, Point start, Point end)
      {
        pen = gcnew Pen(color);
        this->color = color;
   	    setPenPattern(pen, lineStyle);
        this->start = start;
        this->end = end;
        boundRect = System::Drawing::Rectangle(Math::Min(start.X, end.X),
                                               Math::Min(start.Y, end.Y),
                            Math::Abs(start.X - end.X), Math::Abs(start.Y - end.Y));
      }

      // Function to draw a line
      virtual void Draw(Graphics^ g) override
      {
        g->DrawLine(pen, start, end);
      }
    };

  // The class defining a rectangle element
  public ref class Rectangle : Element
  {
  protected:
    Point topleft;
    int width;
    int height;

  public:
    Rectangle(Color color, LineStyle lineStyle, Point p1, Point p2)
    {
      pen = gcnew Pen(color);
      this->color = color;
 	  setPenPattern(pen, lineStyle);
     topleft = Point(Math::Min(p1.X, p2.X), Math::Min(p1.Y,p2.Y));
      width = Math::Abs(p1.X - p2.X);
      height = Math::Abs(p1.Y - p2.Y);
      boundRect = System::Drawing::Rectangle(topleft, Size(width, height));
    }

        virtual void Draw(Graphics^ g) override
    {
      g->DrawRectangle(pen, topleft.X, topleft.Y, width, height);
    }
  };

  // The class defining a circle element
  public ref class Circle : Element
  {
  protected:
    Point topleft;
    int width;
    int height;

  public:
    Circle(Color color, LineStyle lineStyle, Point center, Point circum)
    {
      pen = gcnew Pen(color);
      this->color = color;
	  setPenPattern(pen, lineStyle);
      int radius = safe_cast<int>(Math::Sqrt(
                  (center.X-circum.X)*(center.X-circum.X) +
                                 (center.Y-circum.Y)*(center.Y-circum.Y)));
      topleft = Point(center.X - radius, center.Y - radius);
      width = height = 2*radius;
      boundRect = System::Drawing::Rectangle(topleft, Size(width, height));
   }

    virtual void Draw(Graphics^ g) override
    {
      g->DrawEllipse(pen, topleft.X, topleft.Y, width, height);
    }
  };

  // The class defining a rectangle element
  public ref class Ellipse : Element
  {
  protected:
    Point topleft;
    int width;
    int height;

  public:
    Ellipse(Color color, LineStyle lineStyle, Point p1, Point p2)
    {
      pen = gcnew Pen(color);
      this->color = color;
	  setPenPattern(pen, lineStyle);

      topleft = Point(Math::Min(p1.X, p2.X), Math::Min(p1.Y,p2.Y));
      width = Math::Abs(p1.X - p2.X);
      height = Math::Abs(p1.Y - p2.Y);
      boundRect = System::Drawing::Rectangle(topleft, Size(width, height));
    }

        virtual void Draw(Graphics^ g) override
    {
      g->DrawEllipse(pen, topleft.X, topleft.Y, width, height);
    }
  };
}
