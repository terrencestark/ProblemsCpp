// get a tree case
# define BinNodePosi(T) BinNode<T>*

template <typename T>
struct BinNode{
    T data;
    BinNodePosi(T) lChild;
    BinNodePosi(T) rChild;
    BinNode(T val):data(val),lChild(nullptr),rChild(nullptr){}
};

template <typename T>
BinNodePosi(T) getCase(){
    BinNodePosi(T) n1=new BinNode<T>(1);
    BinNodePosi(T) n2=new BinNode<T>(2);
    BinNodePosi(T) n3=new BinNode<T>(3);
    BinNodePosi(T) n4=new BinNode<T>(4);
    BinNodePosi(T) n5=new BinNode<T>(5);
    BinNodePosi(T) n6=new BinNode<T>(6);
    BinNodePosi(T) n7=new BinNode<T>(7);
    BinNodePosi(T) n8=new BinNode<T>(8);
    BinNodePosi(T) n9=new BinNode<T>(9);
    n1->lChild = n2;
    n1->rChild = n3;
    n2->lChild = n6;
    n2->rChild = n5;
    n3->lChild = n4;
    n4->lChild = n8;
    n4->rChild = n9;
    n5->lChild = n7;
    // 1 2 3 6 5 4 ^ ^ ^ 7 ^ 8 9 ^ ^
    return n1;
}

int main()
{
    BinNodePosi(int) root = getCase<int>();
    // TODO with BinTree
    return 0;
}
