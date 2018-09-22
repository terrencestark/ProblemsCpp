// postorder travel
#define BinNodePosi(T) BinNode<T>*

/*-------------*/
template <typename T, typename VST>
void travPost_R(BinNodePosi(T) x, VST &visit){
	if(!x) return;
	travPre_R(x->lChild, visit);
	travPre_R(x->rChild, visit);
	visit(x->data);
}

/*-------------*/
template <typename T, typename VST>
void travPost_I(BinNodePosi(T) x, VST &visit){
	if(!x) return;
	stack<BinNodePosi(T)> stk;
	stack<BinNodePosi> ret;
	stk.push(x);
	while(!stk.empty()){
		BinNodePosi(T) x = stk.top();
		ret.push(x);
		stk.pop();
		if(x->lChild){
			stk.push(x->lChild);
		}
		if(x->rChild){
			stk.push(x->rChild);
		}
	}
	while(!ret.empty()){
		visit(ret.top()->data);
		ret.pop();
	}
}

/*-------------*/
template <typename T, typename VST>
static void saveAlongRightBranch( 
	BinNodePosi(T) x,
	stack <BinNodePosi(T)> &stk,
	stack <BinNodePosi(T)> &ret)
{
	while(x){
		stk.push(x);
		ret.push(x);
		x = x->rChild;
	}
}
template <typename T, typename VST>
void travPost_I2(BinNodePosi(T) x, VST &visit){
	if(!x) return;
	stack<BinNodePosi(T)> stk;
	stack<BinNodePosi(T)> ret;
	while(true){
		saveAlongRightBranch(x, stk, ret);
		if(stk.empty()) break;
		x = stk.top()->lChild;
		while(!x){
			stk.pop();
			x = stk.top()->lChild;
		}	
	}
	while(!ret.empty()){
		visit(ret.top()->data);
		ret.pop();
	}
}
