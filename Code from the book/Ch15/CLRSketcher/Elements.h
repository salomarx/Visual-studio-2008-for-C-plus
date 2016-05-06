// Elements.h
// Defines element types
#pragma once

using namespace System;
using namespace System::Drawing;

namespace CLRSketcher 
{
  // The base class for all elements
  public ref class Element abstract
  {
  protected:
    Point position;
    Color color;
    System::Drawing::Rectangle boundRect;
    Pen^ pen;

  public:
    virtual void Draw(Graphics^ g) abstract;
  };

  // The class defining a line element
  public ref class Line : Element
  {
    protected:
      Point end;

    public:
      // Constructor
      Line(Color color, Point start, Point end)
      {
        pen = gcnew Pen(color);
        this->color = color;
        position = start;
        this->end = end;
        boundRect = System::Drawing::Rectangle(Math::Min(position.X, end.X),
                                               Math::Min(position.Y, end.Y),
                       Math::Abs(position.X - end.X), Math::Abs(position.Y - end.Y));

        // Provide for lines that are horizontal or vertical      
        if(boundRect.Width < 2) boundRect.Width = 2;
        if(boundRect.Height < 2) boundRect.Height = 2;
      }

      // Function to draw a line
      virtual void Draw(Graphics^ g) override
      {
        g->DrawLine(pen, position, end);
      }
    };

  // The class defining a rectangle element
  public ref class Rectangle : Element
  {
  protected:
    int width;
    int height;

  public:
    Rectangle(Color color, Point p1, Point p2)
    {
      pen = gcnew Pen(color);
      this->color = color;
      position = Point(Math::Min(p1.X, p2.X), Math::Min(p1.Y,p2.Y));
      width = Math::Abs(p1.X - p2.X);
      height = Math::Abs(p1.Y - p2.Y);
      boundRect = System::Drawing::Rectangle(position, Size(width, height));
    }

        virtual void Draw(Graphics^ g) override
    {
      g->DrawRectangle(pen, position.X, position.Y, width, height);
    }
  };

  // The class defining a circle element
  public ref class Circle : Element
  {
  protected:
    int width;
    int height;

  public:
    Circle(Color color, Point center, Point circum)
    {
      pen = gcnew Pen(color);
      this->color = color;
      int radius = safe_cast<int>(Math::Sqrt(
                  (center.X-circum.X)*(center.X-circum.X) +
                                 (center.Y-circum.Y)*(center.Y-circum.Y)));
      position = Point(center.X - radius, center.Y - radius);
      width = height = 2*radius;
      boundRect = System::Drawing::Rectangle(position, Size(width, height));
   }

    virtual void Draw(Graphics^ g) override
    {
      g->DrawEllipse(pen, position.X, position.Y, width,height);
    }
  };

}
