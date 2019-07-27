//
// created by 3zz.
//

#include <iostream>
#include <cassert>

using namespace std;

// 顺序查找表
template <typename Key, typename Value>
class SequenceST
{

private:
  struct Node
  {
    Key key;
    Value value;
    Node *next;

    Node(Key key, Value value)
    {
      this->key = key;
      this->value = value;
      this->next = NULL;
    }
  };
  Node *head;
  int count;

public:
  // 构造函数
  SequenceST()
  {
    head = NULL;
    count = 0;
  }
  ~SequenceST()
  {
    while (head != NULL)
    {
      Node *node = head;
      head = head->next;
      delete node;
      count--;
    }
    assert(head == NULL && count == 0);
  }

  // 返回顺序查找表中的节点个数
  int size()
  {
    return count;
  }

  // 返回顺序查找表是否为空
  bool isEmpty()
  {
    return count == 0;
  }

  // 向顺序查找表中插入一个新的(key, value)数据对
  void insert(Key key, Value value)
  {
    // 查找一下整个顺序表，看看是否存在相同大小的key
    Node *node = head;
    while (node != NULL)
    {
      // 如果在顺序表中查找到了相同大小key的节点
      // 那么当前节点则不需要插入，将该key所对应的值更新为新value之后返回
      if (key == node->key)
      {
        node->value = value;
        return;
      }
      node = node->next;
    }
    // 如果顺序链表中没有相同大小的key， 则创建新节点，将新节点直接插在表头
    Node *newNode = new Node(key, value);
    newNode->next = head;
    head = newNode;
    count++;
  }

  // 查看顺序查找表中是否包含键值对为key的节点
  bool contain(Key key)
  {
    Node *node = head;
    while (node != NULL)
    {
      if (key == node->key)
        return true;
      node = node->next;
    }
    return false;
  }

  // 在顺序查找表中查找key所对应的value，若value不存在，则返回NULL
  Value *search(Key key)
  {
    Node *node = head;
    while (head != NULL)
    {
      if (key == node->key)
        return &(node->value);
      node = node->next;
    }
    return NULL;
  }

  // 在顺序查找表中删除(key, value)所对应的节点
  void remove(Key key)
  {
    if (head == NULL)
      return;

    // 如果待删除的节点就是头结点，需要特殊处理
    if (key == head->key)
    {
      Node *delNode = head;
      head = head->next;
      delete delNode;
      count--;
      return;
    }

    Node *node = head;
    while (node->next != NULL && node->next->key != key)
      node = node->next;

    if (node->next != NULL)
    {
      Node *delNode = node->next;
      node->next = delNode->next;
      delete delNode;
      count--;
      return;
    }
  }
};