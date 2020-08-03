#include "ListNode.h"

template <typename T> class List { //列表模板类
private:
    int _size; ListNodePosi header; ListNodePosi trailer; //规模,头哨兵,尾哨兵
protected:
    void init(); //列表创建时的初始化
    int clear(); //清除所有节点
    void copyNodes(ListNodePosi,int); //复制列表中自位置p起的n项
    void merge(ListNodePosi&,int,List<T>&,ListNodePosi,int); //归并
    void mergeSort(ListNodePosi&,int); //对从p开始连续的n个节点归并排序
    void selectionSort(ListNodePosi,int); //对从p开始连续的n个节点选择排序
    void insertionSort(ListNodePosi,int); //对从p开始连续的n个节点插入排序
public:
// 构造函数
    List(){init();} //默认
    List(List<T> const& L); //整体复制列表L
    List(List<T> const& L,Rank r,int n); //复制列表L中自第r项起的n项
    List(ListNodePosi p,int n); //复制列表中自位置p起的n项
// 析构函数
    ~List(); //释放(包含头,尾哨兵在内的)所有节点
// 只读访问接口
    Rank size() const {} //规模
    bool empty() const {} //判空
    T& operator[](Rank r) const; //重载,支持循秩访问(效率低)
    ListNodePosi first() const {} //首节点位置
    ListNodePosi last() const {} //末节点位置
    bool valid(ListNodePosi p) //判断位置p是否对外合法
    {} //将头尾节点等同于nullptr
    int disordered() const; //判断列表是否以排序
    ListNodePosi find(T const& e) const //无序列表查找
    {}
    ListNodePosi fine(T const& e,int n,ListNodePosi p) const; //无序区间查找
    ListNodePosi search(T const& e) const //有序列表查找
    {}
    ListNodePosi search(T const& e,int n,ListNodePosi p) const; //有序区间查找
    ListNodePosi selectMax(ListNodePosi p,int n); //在p及其n-1个后继中选出最大者
    ListNodePosi selectMax(){} //整体最大者
// 可写访问接口
    ListNodePosi insertAsFirst(T const& e); //将e当作首节点插入
    ListNodePosi insertAsLast(T const& e); //将e当作末节点插入
    ListNodePosi insertA(ListNodePosi p,T const& e); //将e当作p的后继插入
    ListNodePosi insertB(ListNodePosi p,T const& e); //将e当作p的前驱插入
    T remove(ListNodePosi p); //删除合法位置p处的节点,返回被删除节点
    void merge(List<T> &L){} //全列表归并
    void sort(){} //列表整体排序
    int deduplicate(); //无序去重
    void reverse(); //前后倒置(习题)
// 遍历
    void traverse( void(*)(T&)); //遍历,依次实施visit操作(函数指针,只读或局部性修改)
    template <typename VST>
    void traverse(VST&); //遍历,依次实施visit操作(函数对象,可全局性修改)
};
