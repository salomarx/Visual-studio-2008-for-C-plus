// A push-down stack to store Box objects
class CStack
{
private:
  // Defines items to store in the stack
  struct CItem
  {
    CBox* pBox;                        // Pointer to the object in this node
    CItem* pNext;                      // Pointer to next item in the stack or null

    // Constructor
    CItem(CBox* pB, CItem* pN): pBox(pB), pNext(pN){}
  };

  CItem* pTop;                         // Pointer to item that is at the top

public:
  // Push a Box object on to the stack
  void Push(CBox* pBox)
  {
    pTop = new CItem(pBox, pTop);      // Create new Item and make it the top
  }

  // Pop an  object off the stack
  CBox* Pop()
  {  
    if(pTop == 0)                      // If the stack is empty
      return 0;                        // return null

    CBox* pBox = pTop->pBox;           // Get box from item
    CItem* pTemp = pTop;               // Save address of the top Item
    pTop = pTop->pNext;                // Make next item the top 
    delete pTemp;                      // Delete old top Item from the heap
    return pBox;
  }
};
