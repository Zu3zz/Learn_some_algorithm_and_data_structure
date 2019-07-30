#include <iostream>
#include <vector>
#include <string>
#include "SequenceSearchTree.h"
#include "FileOps.h"

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
};

// 测试二分搜索树和顺序查找表之间的性能差距
// 二分搜索树的性能远远优于顺序查找表
int main()
{

  // 使用圣经作为我们的测试用例
  string filename = "bible.txt";
  vector<string> words;
  if (FileOps::readFile(filename, words))
  {

    cout << "There are totally " << words.size() << " words in " << filename << endl;
    cout << endl;

    // 测试 BST
    time_t startTime = clock();

    // 统计圣经中所有词的词频
    // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
    // 在这里只做性能测试用
    BST<string, int> bst = BST<string, int>();
    for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++)
    {
      int *res = bst.search(*iter);
      if (res == NULL)
        bst.insert(*iter, 1);
      else
        (*res)++;
    }

    // 输出圣经中god一词出现的频率
    if (bst.contain("god"))
      cout << "'god' : " << *bst.search("god") << endl;
    else
      cout << "No word 'god' in " << filename << endl;

    time_t endTime = clock();

    cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
    cout << endl;

    // 测试顺序查找表 SST
    startTime = clock();

    // 统计圣经中所有词的词频
    // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
    // 在这里只做性能测试用
    SequenceST<string, int> sst = SequenceST<string, int>();
    for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++)
    {
      int *res = sst.search(*iter);
      if (res == NULL)
        sst.insert(*iter, 1);
      else
        (*res)++;
    }

    // 输出圣经中god一词出现的频率
    if (sst.contain("god"))
      cout << "'god' : " << *sst.search("god") << endl;
    else
      cout << "No word 'god' in " << filename << endl;

    endTime = clock();

    cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
  }

  return 0;
}