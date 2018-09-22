// pre order travel
#define BinNodePosi(T) BinNode<T>*
template <typename T, typename VST>
void travPre_R(BinNodePosi(T) x, VST &visit){
	if(!x) return;
	visit(x->data);
	travPre_R(x->lChild, visit);
	travPre_R(x->rChild, visit);
}

template <typename T, typename VST>
void travPre_I(BinNodePosi(T) x, VST &visit){
	if(!x) return;
	stack<BinNodePosi(T)> stk;
	stk.push(x);
	while(!stk.empty()){
		BinNodePosi(T) tmp = stk.top();
		visit(tmp->data);
		stk.pop();
		if(tmp->rChild) stk.push(tmp->rChild);
		// first save right child, last handle it
		if(tmp->lChild) stk.push(tmp->lChild);
	}
}

/*-------------*/
template <typename T, typename VST>
static void visitAlongLeftBranch( 
	BinNodePosi(T) x;
	VST &visit;
	stack <BinNodePosi(T)> &stk)
{
	while(x){
		visit(x->data);
		stk.push(x->rChild);
			// maybe push nullptr
		x = x->lChild;
	}
}
template <typename T, typename VST>
void travPre_I2(BinNodePosi(T) x, VST &visit){
	if(!x) return;
	stack<BinNodePosi(T)> stk;
	while(true){
		visitAlongLeftBranch(x, visit, stk); //visit left chain
		if(stk.empty()) break;
		x = stk.top(); stk.pop(); // enter a new subtree
	}
}
