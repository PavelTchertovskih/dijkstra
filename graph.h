#ifndef GRAPH_H
#define GRAPH_H
#include <map>
#include <list>
#include <istream>
#include <ostream>
using std::map;
using std::list;
using std::pair;
using std::istream;
using std::ostream;
template<typename V, typename E>
	class directed_graph;
template<typename V, typename E>
	istream& operator>>(istream& os, directed_graph<V, E>& g);
template<typename V, typename E> 
	class directed_graph
{
protected:
	struct Node_data;
	map<V, Node_data> content;
	typename map<V, Node_data>::iterator start;
	struct Node_data
	{
		list<pair<typename map<V, Node_data>::iterator, E>> neighbours;
		//V verticle;
		E path_length;
		list<typename map<V, Node_data>::iterator> path;
		//int unvisited_edges_count;
		int color;
	};
	void visit(list<typename map<V, Node_data>::iterator>&);
public:
	friend istream& operator>><V, E>(istream& os, directed_graph<V, E>& g);
	void add_edge(const V&, const V&, const E&);
	void specify_start_node(const V&);
	void print() const;
	//void read(istream&);
	void calculate_shortest_paths();
	void print_shortest_paths(ostream&) const;
	directed_graph();
};
template<typename V, typename E>
	istream& operator>>(istream& os, directed_graph<V, E>& g);
template<typename V, typename E>
	class graph/*: public directed_graph<V,E>*/;
template<typename V, typename E>
	istream& operator>>(istream& os, graph<V, E>& g);
template<typename V, typename E>
	class graph: public directed_graph<V, E>
{
public:
	friend istream& operator>><V,E>(istream& os, graph<V, E>& g);
	void add_edge(const V&, const V&, const E&);
};
#endif
