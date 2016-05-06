// Sketch.h
// Defines a sketch
#pragma once
#include <cliext/list>
#include "Elements.h"

using namespace System;
using namespace cliext;
using namespace System::Runtime::Serialization;

namespace CLRSketcher 
{
  [Serializable]
 public ref class Sketch
  {
  private:
    [NonSerialized]
    list<Element^>^ elements;
    array<Element^>^ elementArray;

  public:
    bool Saved;

  public:
    Sketch() : elementArray(nullptr), Saved(false)
    {
    elements = gcnew list<Element^>();
    }

    [OnSerializing]
    void ListToArray(StreamingContext context)
    {
      elementArray = elements->to_array();
    }

    [OnDeserialized]
    void ArrayToList(StreamingContext context)
    {
      elements = gcnew list<Element^>(elementArray);
      elementArray = nullptr;
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

    // Determines which element is under the cursor
    Element^ HitElement(Point p)
    {
      for each(Element^ element in elements)
      {
        if(element->Hit(p))
          return element;
      }
      return nullptr;
    }

    // Delete an element
    Element^ Delete(Element^ element)
    {
      elements->remove(element);
      return element;
    }
 };
}
