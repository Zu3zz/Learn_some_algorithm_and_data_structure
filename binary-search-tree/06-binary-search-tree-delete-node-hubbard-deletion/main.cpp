#include <iostream>
#include <queue>

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
    Node(Node *node)
    {
      this->key = node->key;
      this->value = node->value;
      this->left = node->left;
      this->right = node->right;
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
  // 层序遍历
  void levelOrder()
  {
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
      Node *node = q.front();
      q.pop();

      cout << node->key << endl;

      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
  }
  // 寻找最小的键值
  Key minimum()
  {
    assert(count != 0);
    Node *minNode = minimum(root);
    return minNode->key;
  }
  // 寻找最大的键值
  Key maximum()
  {
    assert(count != 0);
    Node *maxNode = maximum(root);
    return maxNode->key;
  }
  // 从二叉树中删除最小值所在的节点
  void removeMin()
  {
    if (root)
      root = removeMin(root);
  }
  // 从二叉树中删除键值为key的节点
  void remove(Key key)
  {
    root = remove(root, key);
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
  // 释放以node为根的二分搜索树的所有节点
  // 采用后续遍历的递归算法
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
  // 在以node为根的二叉搜索树中，返回最小键值的节点
  Node *minimum(Node *node)
  {
    if (node->left == NULL)
      return node;
    return minimum(node->left);
  }

  // 在以node为根的二叉搜索树中，返回最大键值的节点
  Node *maximum(Node *node)
  {
    if (node->right == NULL)
      return node;
    return maximum(node->right);
  }

  // 删除掉以node为根的二分搜索树中的最小节点
  // 返回删除节点后新的二分搜索树的根
  Node *removeMin(Node *node)
  {
    if (node->left == NULL)
    {
      Node *rightNode = node->right;
      delete Node;
      count--;
      return rightNode;
    }
    node->left = removeMin(node->left);
    return node;
  }
  // 删除掉以node为根的二分搜索树中的最大节点
  // 返回删除节点后新的二分搜索树的根
  Node *removeMax(Node *node)
  {
    if (node->right == NULL)
    {
      Node *leftNode = node->left;
      delete Node;
      count--;
      return leftNode;
    }
    node->right = removeMax(node->right);
    return node;
  }
  // 删除掉以node为根的二分搜索树中键值为key的节点
  // 返回删除节点后新的二分搜索树的根
  Node *remove(Node *node, Key key)
  {
    if (node == = NULL)
      return NULL;
    if (key < node->key)
    {
      node->left = remove(node->left, key);
      return node;
    }
    else if
    {
      node->right = remove(node->right, key);
      return node;
    }
    else
    { // key == node->key
      if (node->left == NULL)
      {
        Node *rightNode = node->right;
        delete node;
        count--;
        return rightNode;
      }
      if (node->right == NULL)
      {
        Node *leftNode = node->left;
        delete node;
        count--;
        return leftNode;
      }
      // node->left != NULL && node->right != NULL
      Node *successor = new Node(minimum(node->right));
      count++;

      successor->right = removeMin(node->right);
      successor->left = node->left;

      delete node;
      count--;
      
      return successor;
    }
  }
};

// 测试二分搜索树的前中后序遍历以及层序遍历
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

  // 测试二分搜索树的层序遍历 levelOrder
  cout << "levelOrder: " << endl;
  bst.levelOrder();
  cout << endl;

  return 0;
}