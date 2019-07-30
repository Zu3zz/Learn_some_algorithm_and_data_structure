#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename Key, typename Value>
class BST
{

private:
  struct Node
  {
    Key key;
    Value value;
    Node *left;
    Node *right;

    Node(Key key, Value value)
    {
      this->key = key;
      this->value = value;
      this->left = this->right = NULL;
    }
  };
  Node *root;
  int count;

public:
  BST()
  {
    root = NULL;
    count = 0;
  }
  ~BST()
  {
    // TODO: ~BST()
    destroy(root);
  }
  int size()
  {
    return count;
  }
  bool isEmpty()
  {
    return count == 0;
  }
  // 插入一个节点
  void insert(Key key, Value value)
  {
    root = insert(root, key, value);
  }
  /** insert非递归实现 TODO
   * 需要使用一个帮助函数 search
   * void insert(Key key, Value value){
   * Node *rt = root;
   * bool flag = true;
   * while(flag){
   *   if(rt->value == value)
    }
  */
  // 是否包含含有这个值的子节点
  bool contain(Key key)
  {
    return contain(root, key);
  }
  Value *search(Key key)
  {
    return search(root, key);
  }
  // 前序遍历
  void preOrder()
  {
    preOrder(root);
  }
  // 中序遍历
  void inOrder()
  {
    inOrder(root);
  }
  // 后序遍历
  void postOrder()
  {
    postOrder(root);
  }

private:
  // 向以node为跟的二叉搜索树
  // 返回插入新节点之后二叉搜索树的根
  Node *insert(Node *node, Key key, Value value)
  {
    if (node == NULL)
    {
      count++;
      return new Node(key, value);
    }
    if (key == node->key)
      node->value = value;
    else if (key < node->key)
      node->left = insert(node->left, key, value);
    else // key > node->key
      node->right = insert(node->right, key, value);
    return node;
  }
  bool contain(Node *node, Key key)
  {
    // 递归到底的情况
    if (node == NULL)
      return false;
    if (key == node->key)
      return true;
    else if (key < node->key)
      return contain(node->left, key);
    else // key > node->key
      return contain(node->right, key);
  }

  // 在以node为根的二叉搜索树中寻找key所对应的value
  Value *search(Node *node, Key key)
  {
    if (node == NULL)
      return NULL;
    if (key == node->key)
      return &(node->value);
    else if (key < node->key)
      return search(node->left, key);
    else // key>node->key
      return search(node->right, key);
  }
  // 对以node为根的二叉搜索树进行前序遍历
  void preOrder(Node *node)
  {
    if (node != NULL)
    {
      cout << node->key << endl;
      preOrder(node->left);
      preOrder(node->right);
    }
  }
  // 对以node为根的二叉搜索树进行中序遍历
  void inOrder(Node *node)
  {
    if (node != NULL)
    {
      inOrder(node->left);
      cout << node->key << endl;
      inOrder(node->right);
    }
  }
  // 对以node为根的二叉搜索树进行后序遍历
  void postOrder(Node *node)
  {
    if (node != NULL)
    {
      postOrder(node->left);
      postOrder(node->right);
      cout << node->key << endl;
    }
  }
  void destroy(Node *node)
  {
    if (node != NULL)
    {
      destroy(node->left);
      destroy(node->right);
      delete node;
      count--;
    }
  }
};

int main()
{

  srand(time(NULL));
  BST<int, int> bst = BST<int, int>();

  // 取n个取值范围在[0...m)的随机整数放进二分搜索树中
  int N = 10;
  int M = 100;
  for (int i = 0; i < N; i++)
  {
    int key = rand() % M;
    // 为了后续测试方便,这里value值取和key值一样
    int value = key;
    cout << key << " ";
    bst.insert(key, value);
  }
  cout << endl;

  // 测试二分搜索树的size()
  cout << "size: " << bst.size() << endl
       << endl;

  // 测试二分搜索树的前序遍历 preOrder
  cout << "preOrder: " << endl;
  bst.preOrder();
  cout << endl;

  // 测试二分搜索树的中序遍历 inOrder
  cout << "inOrder: " << endl;
  bst.inOrder();
  cout << endl;

  // 测试二分搜索树的后序遍历 postOrder
  cout << "postOrder: " << endl;
  bst.postOrder();
  cout << endl;

  return 0;
}