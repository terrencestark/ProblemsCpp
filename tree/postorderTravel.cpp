// postorder travel
#define BinNodePosi(T) BinNode<T>*

/*-------------*/
template <typename T, typename VST>
void travPost_R(BinNodePosi(T) x, VST &visit){
	if(!x) return;
	travPost_R(x->lChild, visit);
	travPost_R(x->rChild, visit);
	visit(x->data);
}

/*-------------*/
template <typename T, typename VST>
void travPost_I(BinNodePosi(T) x, VST &visit){
	if(!x) return;
	stack<BinNodePosi(T)> stk;
	stack<BinNodePosi(T)> ret;
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
template <typename T>
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
		x = stk.top()->lChild;  // check each left subtree
		stk.pop();
	}
	while(!ret.empty()){
		visit(ret.top()->data);
		ret.pop();
	}
}

// get a vector | or use visit class
template <typename T>
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
template <typename T>
void travPost_I2(BinNodePosi(T) x, vector<T> &result){
	if(!x) return;
	stack<BinNodePosi(T)> stk;
	stack<BinNodePosi(T)> ret;
	while(true){
		saveAlongRightBranch(x, stk, ret);
		if(stk.empty()) break;
		x = stk.top()->lChild;  // check each left subtree
		stk.pop();
	}
	while(!ret.empty()){
		result.push_back(ret.top()->data);
		ret.pop();
	}
}

// get a vector | or use visit class
template <typename T>
void travPost_I3(BinNodePosi(T) x, vector<T> &ret){
	ret.clear();
	if(!x) return;
	stack<BinNodePosi(T)> stk;
	stack<BinNodePosi(T)> tmp;
	while(!stk.empty()||x){  
	// mind the x, when pop root, x point to left subtree
		if(x){
			// right chain
			stk.push(x);
			tmp.push(x);
			x = x->rChild;
		}else{
			x = stk.top()->lChild;
			stk.pop();
		}
	}
	// reverse
	ret.reserve(tmp.size());
	while(!tmp.empty()){
		ret.push_back(tmp.top()->data);
		tmp.pop();
	}
}