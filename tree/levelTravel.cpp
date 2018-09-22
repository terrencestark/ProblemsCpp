// level travel
#define BinNodePosi(T) BinNode<T>*

// visit with a object function
template <typename T, typename VST>
void travLevel_I(BinNodePosi(T) x, VST &visit){
	if(!x) return;
	queue<BinNodePosi(T)> que;
	que.push(x);
	while(!que.empty()){
		x = que.front();que.pop();
		visit(x->data);
		if(x->lChild) que.push(x->lChild);
		if(x->rChild) que.push(x->rChild);
	}
}

template <typename T>
struct VST{
    void operator()(T data);
};

template <typename T>
void VST<T>::operator()(T data){
    cout << ">" << data << endl;
}

// get a vector result
template <typename T>
void travLevel_I(BinNodePosi(T) x, vector<T> &ret){
	ret.clear();
	if(!x) return;
	queue<BinNodePosi(T)> que;
	que.push(x);
	while(!que.empty()){
		x = que.front();que.pop();
		ret.push_back(x->data);
		if(x->lChild) que.push(x->lChild);
		if(x->rChild) que.push(x->rChild);
	}
}

