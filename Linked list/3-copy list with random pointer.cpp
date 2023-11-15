/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution 
{
public:
  unordered_map<Node*, Node*> myMap;

  Node* copyRandomList(Node* head) 
  {
    if (head == NULL)
    {
        return NULL;
    }
    if (myMap.find(head) != myMap.end())
    {
        return myMap[head];

    }
      
    Node* newNode = new Node(head->val);
    myMap[head] = newNode;
    newNode->next = copyRandomList(head->next);
    newNode->random = copyRandomList(head->random);
    
    return newNode;
  }
}; 
