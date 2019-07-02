# 一起来学习数据结构与算法吧

## 一些常用经典算法和数据结构的回顾

### 首先是最经典的排序问题

+ 排序
  + 选择排序(Selection Sort)复杂度O(n^2)
  > 找到最小的元素然后与当前位置交换
  ![选择排序](./static/selection-sort.png)
  
  + 插入排序(Insertion Sort)复杂度O(n^2)
  > 找到合适的位置然后插入
  ![插入排序](./static/insertion-sort.png)

  + 改进的插入排序(取消了交换操作)
  > 将当前位置的元素先拿出 然后逐个与之前的元素比较 如果小于 就将之前的元素后移 在与前一位比较
  ![插入排序改进](./static/insertion-sort-advanced.png)

  + 冒泡排序(Bubble Sort)
  + 希尔排序(Shell Sort)
  + 归并排序(Merge Sort)复杂度O(n*logn)
  > 先不断的二分
  ![归并排序](./static/merge-sort.png)
  > 归并过程
  ![归并排序](./static/merge-sort-detail.png)