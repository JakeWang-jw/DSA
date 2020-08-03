typedef int Rank; //秩
#define ListNodePosi(T) ListNode<T>* //列表节点位置

template <typename t> struct ListNode{ //列表节点模板类(以双向链表形式实现)
// 成员
    T data; ListNodePosi pred; ListNodePosi succ;
// 构造函数
    ListNode() {} //针对header和trailer的构造
    ListNode(T e,ListNodePosi p=nullptr,ListNodePosi s=nullptr)
        : data(e),pred(p),succ(s){} //默认构造器
// 操作接口
    ListNodePosi insertAsPred(T const& e); //紧靠当前节点之前插入新节点
    ListNodePosi insertAsSucc(T const& e); //紧随当前节点之后插入新节点
};
