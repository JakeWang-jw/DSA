#include "Vector.h" //引入向量
#include "Graph.h" //引入图ADT

template <typename Tv> struct Vertex { //顶点对象
	Tv data; int inDegree, outDegree;VStatus status; //数据,出入度数,状态
	int dTIme,fTime; //时间标签
	int parent;int priority; //在遍历树中的父节点,优先级数
	Vertex(Tv const& d=(Tv)0): //构造新顶点
		data(d),inDegree(0),outDegree(0),status(UNDISCOVERED),
		dTime(-1),fTime(-1),parent(-1),priority(INT_MAX){} //赞不考虑权重溢出
};

template <typename Te> struct Edge{ //边对象
	Te data;int weight;EType type; //数据,权重,类型
	Edge(Te const& d,int w):data(d),weight(w),type(UNDETERMINED){} //暂不考虑权重溢出
};

template <typename Tv,typename Te> //顶点类型,边类型
class GraphMatrix:public Graph<Tv,Te>{ //基于向量,以邻接矩阵形式实现的图
private: 
	Vector<Vertex <Tv>> V; //顶点集(向量)
	Vector<Vector<Edge<Te>*>> E; //边集(邻接矩阵)
public: 
	GraphMatrix(){n=e=0;} //构造
	~GraphMatrix(){ //析构
//		for(int i=0;i<e;i++)
//			delete E[i];
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				delete E[j][k];
	}
// 顶点的基本操作:查询第i个顶点(0<=i<n)
	virtual Tv& vertex(int i){return V[i].data; } //数据
	virtual int inDegree(int i){return V[i].indegree; } //入度
	virtual int outDegree(int i){return V[i].outDegree; } //出度
	virtual int firstNbr(int i){for(int j=0;j<n;j++) if(E[i][j]) return j;}  //首个邻接顶点
	virtual int nextNbr(int i,int j) //相对于顶点j的下一邻接顶点(改用邻接表可提高效率)
	{for(int k=0;k!=i,k<n;k++) if(E[j][k]) return k;} //逆向线性试探
	virtual VStatus& status(int i){return V[i].status; } //状态
	virtual int& dTIme(int i){return V[i].dTime; } //时间标签dTime
	virtual int& fTIme(int i){return V[i].fTime;} //时间标签fTime
	virtual int& parent(int i){return V[i].parent;} //在遍历树中的父亲
	virtual int& priority(int i){return V[i].priority;} //在遍历树中的优先级数
 //顶点的动态操作
	virtual int insert(Tv const& vertex){ //插入顶点,返回编号
//		V.insert(vertex);
//		Vector<Edge<Te>*> temp;
//		for(int i=0;i<n;i++)
//		{
//			temp.insert(nullptr);
//		}
//		E.insert(temp);
//		return n-1;
		for(int j=0;j<n;j++) E[j].insert(nullptr);n++;
		E.insert(Vector<Edge<Te>*>(n,n,(Edge<Te>*)nullptr));
		return V.insert(Vertex<Tv>(vertex));
	} 
	virtual Tv remove(int i){ //删除第i个顶点及其关联边(0<=i<n)
//		for(int j=0;j<n;j++) V[j].remove(i);
//		return E.remove(i);
		for(int j=0;j<n;j++)
			if(exists(i,j))	{delete E[i][j];V[j].inDegree--;e--;}
		Tv vbak=vertex(i);
		V.remove(i); n--;
		E.remove(i);
		for(int j=0;j<n;j++)
			if(Edge<Te>* etemp=E[j].remove(i)){delete etemp;V[j].outDegree--;e--;}
	} 
// 顶点的动态操作
	virtual bool exists(int i,int j) //边(i,j)是否存在
	{//return E[i][j];
		return (0<=i) && (i<n) && (0<=j) && (j<n) && E[i][j] != nullptr;}
// 边的基本操作:查询顶点i与j之间的联边(0<=j,j<n且exists(i,j))	
	virtual EType& type(int i,int j){return E[i][j]->type;} //边(i,j)的类型
	virtual Te& edge(int i,int j){return E[i][j]->data;} //边(i,j)的数据
	virtual int& weight(int i, int j){return E[i][j]->weight;} //边(i,j)的权重
// 边的动态操作
	virtual void insert(Te const& edge,int w,int i,int j){ //插入权重为w的边e=(i,j)
		if(exists(i,j)) return;
		E[i][j]=new Edge<Te>(edge,w);e++;
		V[i].outDegree++;V[j].inDegree++;
	}
	virtual Te remove(int i,int j){ //删除顶点i和j之间的联边(exists(i,j))
		Te ebak=edge(i,j);delete E[i][j]; E[i][j]=nullptr;
		e--;V[i].outDegree--;V[j].inDegree--;
		return ebak;
	}
};

template <typename T>
void Graph<Tv,Te>:BFS(int,int &)
{
	
}
