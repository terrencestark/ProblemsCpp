// inorder travel
#define BinNodePosi(T) BinNode<T>*

/*-------------*/
template <typename T, typename VST>
void travIn_R(BinNodePosi(T) x, VST &visit){
	if(!x) return;
	travPre_R(x->lChild, visit);
	visit(x->data);
	travPre_R(x->rChild, visit);
}

/*-------------*/
template <typename T, typename VST>
static void goAlongLeftBranch( 
	BinNodePosi(T) x,
	stack <BinNodePosi(T)> &stk)
{
	while(x){
		stk.push(x);
		x = x->lChild;
	}
}
template <typename T, typename VST>
void travIn_I(BinNodePosi(T) x, VST &visit){
	if(!x) return;
	stack<BinNodePosi(T)> stk;
	while(true){
		goAlongLeftBranch(x, stk);
		if(stk.empty()) break;
		BinNodePosi(T) tmp = stk.top(); stk.pop();
		visit(tmp->data);
		x = tmp->rChild; // give pointer to rChild
	}
}
