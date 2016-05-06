// Elements.h
// Defines element types
#pragma once
#include <cliext/vector>

using namespace System;
using namespace System::Drawing;
using namespace cliext;
using namespace System::Runtime::Serialization;

namespace CLRSketcher 
{
  // The base class for all elements
  [Serializable]
  public ref class Element abstract
  {
  protected:
    Point position;
    Color color;
    System::Drawing::Rectangle boundRect;
    [NonSerialized]
    Pen^ pen;
    float penWidth;
    Color highlightColor;

  public:
    [OnDeserialized]
    void CreatePen(StreamingContext context)
    {
      pen = gcnew Pen(color, penWidth);
    }

    property System::Drawing::Rectangle Bound
    {
      System::Drawing::Rectangle get() 
      { 
        int width = safe_cast<int>(penWidth);
        return System::Drawing::Rectangle::Inflate(boundRect,width,width);
      }
    }

    bool highlighted;

    Element() : highlighted(false), highlightColor(Color::Magenta) {}

    virtual void Draw(Graphics^ g) abstract;

    // Determines if this element is under the cursor
    bool Hit(Point p)
    {
      return boundRect.Contains(p);
    }

    // Move an element
    void Move(int dx, int dy)
    {
      position.Offset(dx, dy);
      boundRect.X += dx;
      boundRect.Y += dy;
    }
  };

  // The class defining a line element
  [Serializable]
  public ref class Line : Element
  {
    protected:
      Point end;

    public:
      // Constructor
      Line(Color color, Point start, Point end, float penWidth)
      {
        this->penWidth = penWidth;
        pen = gcnew Pen(color, penWidth);
        this->color = color;
        position = start;
        this->end = end;
        boundRect = System::Drawing::Rectangle(Math::Min(position.X, end.X),
                                               Math::Min(position.Y, end.Y),
                            Math::Abs(position.X - end.X), Math::Abs(position.Y - end.Y));
        if(boundRect.Width < 2) boundRect.Width = 2;
        if(boundRect.Height < 2) boundRect.Height = 2;
      }

      // Function to draw a line
      virtual void Draw(Graphics^ g) override
      {
        pen->Color = highlighted ? highlightColor : color;
        g->TranslateTransform(safe_cast<float>(position.X), safe_cast<float>(position.Y));
        g->DrawLine(pen, 0, 0, end.X-position.X, end.Y-position.Y);
        g->ResetTransform();
      }
    };

  // The class defining a rectangle element
 [Serializable]
 public ref class Rectangle : Element
  {
  protected:
    int width;
    int height;

  public:
    Rectangle(Color color, Point p1, Point p2, float penWidth)
    {
      this->penWidth = penWidth;
      pen = gcnew Pen(color, penWidth);
      this->color = color;
      position = Point(Math::Min(p1.X, p2.X), Math::Min(p1.Y,p2.Y));
      width = Math::Abs(p1.X - p2.X);
      height = Math::Abs(p1.Y - p2.Y);
      boundRect = System::Drawing::Rectangle(position, Size(width, height));
    }

    virtual void Draw(Graphics^ g) override
    {
      pen->Color = highlighted ? highlightColor : color;
      g->TranslateTransform(safe_cast<float>(position.X), safe_cast<float>(position.Y));
      g->DrawRectangle(pen, 0, 0, width, height);
      g->ResetTransform();
    }
  };

  // The class defining a circle element
 [Serializable]
  public ref class Circle : Element
  {
  protected:
    int width;
    int height;

  public:
    Circle(Color color, Point center, Point circum, float penWidth)
    {
      this->penWidth = penWidth;
      pen = gcnew Pen(color, penWidth);
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
      pen->Color = highlighted ? highlightColor : color;
      g->TranslateTransform(safe_cast<float>(position.X), safe_cast<float>(position.Y));
      g->DrawEllipse(pen, 0, 0, width,height);
      g->ResetTransform();
    }
  };

  // The class defining a curve element
 [Serializable]
  public ref class Curve : Element
  {
  private:
    [NonSerialized]
    vector<Point>^ points;
    array<Point>^ pointsArray;

  public:
    Curve(Color color, Point p1, Point p2, float penWidth) : pointsArray(nullptr)
    {
      this->penWidth = penWidth;
      pen = gcnew Pen(color, penWidth);
      this->color = color;
      points = gcnew vector<Point>();
      position = p1;
      points->push_back(Point(p2.X-position.X, p2.Y-position.Y));

      // Find the minimum and maximum coordinates
      int minX = p1.X < p2.X ? p1.X : p2.X;
      int minY = p1.Y < p2.Y ? p1.Y : p2.Y;
      int maxX = p1.X > p2.X ? p1.X : p2.X;
      int maxY = p1.Y > p2.Y ? p1.Y : p2.Y;
      int width = Math::Max(2, maxX - minX);
      int height = Math::Max(2, maxY - minY);
      boundRect = System::Drawing::Rectangle(minX, minY, width, height);
    }

      [OnSerializing]
    void VectorToArray(StreamingContext context)
    {
      pointsArray = points->to_array();
    }

    [OnDeserialized]
    void ArrayToVector(StreamingContext context)
    {
      points = gcnew vector<Point>(pointsArray);
      pointsArray = nullptr;
    }

    void Add(Point p)
    {
      points->push_back(Point(p.X-position.X, p.Y-position.Y));

      // Modify the bounding rectangle to accommodate the new point
      if(p.X < boundRect.X)
      {
        boundRect.Width = boundRect.Right - p.X;
        boundRect.X = p.X;
      }
      else if(p.X > boundRect.Right)
        boundRect.Width = p.X - boundRect.Left;

      if(p.Y < boundRect.Y)
      {
        boundRect.Height = boundRect.Bottom - p.Y;
        boundRect.Y = p.Y;
      }
      else if(p.Y > boundRect.Bottom)
        boundRect.Height = p.Y - boundRect.Top;
    }

    virtual void Draw(Graphics^ g) override
    {
      pen->Color = highlighted ? highlightColor : color;
     g->TranslateTransform(safe_cast<float>(position.X), safe_cast<float>(position.Y));
      Point previous = Point(0,0);
      for each(Point p in points)
      {
        g->DrawLine(pen, previous, p);
        previous = p;
      }
      g->ResetTransform();
    }
  };

  // The class defining a text element
 [Serializable]
  public ref class TextElement : Element
  {
    private:
      String^ text;
      [NonSerialized]
      SolidBrush^ brush;
      Font^ font;

    public:
      [OnDeserialized]
      void CreateBrush(StreamingContext context)
      {
        brush = gcnew SolidBrush(color);
      }


      TextElement(Color color, Point p, String^ text, Font^ font)
      {
        this->color = color;
        brush = gcnew SolidBrush(color);
        position = p;
        penWidth = 1;
        this->text = text;
        this->font = font;
        int height = font->Height;
        int width = height*text->Length;
     boundRect = System::Drawing::Rectangle(position, Size(width, height));
      }

      virtual void Draw(Graphics^ g) override
      {
        brush->Color = highlighted ? highlightColor : color;
        g->TranslateTransform(safe_cast<float>(position.X), safe_cast<float>(position.Y));
        g->DrawString(text, font, brush, 0, 0);
        g->ResetTransform();
      }
  };

  }
