// Sketch.h
// Defines a sketch
#pragma once
#include <cliext/list>
#include "Elements.h"

using namespace System;
using namespace cliext;

namespace CLRSketcher 
{
 public ref class Sketch
  {
  private:
    list<Element^>^ elements;

  public:
    Sketch()
    {
      elements = gcnew list<Element^>();
    }

    void Add(Element^ element)
    {
      elements->push_back(element);
    }

    void Draw(Graphics^ g)
    {
      for each(Element^ element in elements)
        element->Draw(g);
    }
 };
}