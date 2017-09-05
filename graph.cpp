#include <iostream>
#include <string>
#include "graph.h"
using std::cout;
using std::endl;
using std::string;
template class 
	directed_graph<string, unsigned int>;
template istream& operator>><string, unsigned int>
	(istream& os, directed_graph <string, unsigned int>& g);
template <typename V, typename E> 
	void directed_graph<V, E>::add_edge(const V& v1, const V& v2, const E& e)
{
	auto ret_v1 = content.insert(pair<V, Node_data> (v1, {}));
	auto ret_v2 = content.insert(pair<V, Node_data> (v2, {}));
	ret_v1.first->second.neighbours.push_back(pair<typename map<V, Node_data>::iterator, E> (ret_v2.first, e));
}
template <typename V, typename E>
	void directed_graph<V, E>::print() const
{
	if (start == content.end())
	{
		cout << "no start node specified" << endl;
	}
	else
	{
		cout << "start node is " << start->first << endl;;
	}
	for(auto& i: content)
	{
		cout << "<" << i.first << ">" << " (path_length = " << i.second.path_length;
		cout << ", color = " << i.second.color << "):";
		for(auto& j: i.second.neighbours)
		{
			cout << " <" << j.first->first << "> (" << j.second << ")";
		}
		cout << endl;
	}
}
template <typename V, typename E>
	directed_graph<V, E>::directed_graph()
{
	start = content.end();
}
template <typename V, typename E>
	 void directed_graph<V, E>::specify_start_node(const V& s)
{
	auto ret = content.insert(pair<V, Node_data> (s, {}));
	start = ret.first;
}
/*template <typename V, typename E>
	void directed_graph<V, E>::read(istream& is)*/
template<typename V, typename E>
	istream& operator>>(istream& is, directed_graph<V, E>& g)
{	/* format
	* S Moscow
	* Moscow Novosibirsk 7
	* Moscow Toronto 9
	* Moscow Krasnoyarsk 14
	* Novosibirsk Toronto 10
	* Novosibirsk Omsk 15
	* Omsk Toronto  11
	* Toronto Krasnoyarsk 2
	*Krasnoyarsk Kiev 9
	*Kiev Omsk  6*/
	char c;
	is >> c;
	if (c == 'S')
	{
		V s;
		is >> s;
		g.specify_start_node(s);
	}
	else
	{
		string s;
		getline (is, s);
	}
	while (is.good())
	{
		V v1, v2;
		E e;
		is >> v1;
		is >> v2;
		is >> e;
		V nil;
		if (v1 != nil && v2 != nil)
		{
			g.add_edge(v1, v2, e);
		}
	}
	return is;
}
template <typename V, typename E>
	void directed_graph<V, E>::visit(list<typename map<V, Node_data>::iterator>& tmp)
{
	auto n = tmp.begin();
	//E len = (*n)->second.path_length;
	for (auto i = tmp.begin()++; i != tmp.end(); ++i)
	{
		if ((*i)->second.path_length < (*n)->second.path_length)
		{
			n = i;
			//len = (*n)->second.path_length;
		}
	}
	(*n)->second.color = 2;
	for (auto& i: (*n)->second.neighbours)
	{
		if (i.first->second.color == 2) continue;
		if (i.first->second.color == 0 || 
				i.first->second.path_length > (*n)->second.path_length + i.second)
		{
			i.first->second.color = 1;
			tmp.push_back(i.first);
			i.first->second.path_length = (*n)->second.path_length + i.second;
			i.first->second.path = (*n)->second.path;
			i.first->second.path.push_back(i.first);
		}
	}
	tmp.erase(n);
}
template <typename V, typename E>
	void directed_graph<V, E>::calculate_shortest_paths()
{
	if (start == content.end()) return;
	list<typename map<V, Node_data>::iterator> tmp;
	tmp.push_back(start);
	/*E nil;
	start->second.path_length = nil;*/
	start->second.path.push_back(start);
	start->second.color = 1;
	/*for (auto& i: start->second.neighbours)
	{
		tmp.push_back(i.first);
	}*/
	while (!tmp.empty())
	{
		visit(tmp);
	}
}
template <typename V, typename E>
	void directed_graph<V, E>::print_shortest_paths(ostream& os) const
{
	for (auto i = content.begin(); i != content.end(); ++i)
	{	
		if (i == start) continue;
		os << i->first << " ";
		if (i->second.color == 0)
		{
			os << "is unreachable" << endl;
			continue;
		}
		auto j = i->second.path.begin();
		os << "{" << (*j)->first << ", ";
		++j;
		for (;;)
		{
			if (j == i->second.path.end())
			{
				os << "} ";
				break;
			}
			os << (*j)->first;
			++j;
			if (j != i->second.path.end())
			{
				os << ", ";
			}
		}
		/*for (auto& j: i->second.path)
		{
			os << j->first << " ";
		}*/
		os << "- " << i->second.path_length << endl;
	}
}
template class 
	graph<string, unsigned int>;
template istream& operator>><string, unsigned int>
	(istream& os, graph <string, unsigned int>& g);
template <typename V, typename E> 
	void graph<V, E>::add_edge(const V& v1, const V& v2, const E& e)
{
	auto ret_v1 = directed_graph<V, E>::content.insert(pair<V, typename directed_graph<V, E>::Node_data> (v1, {}));
	auto ret_v2 = directed_graph<V, E>::content.insert(pair<V, typename directed_graph<V, E>::Node_data> (v2, {}));
	ret_v1.first->second.neighbours.push_back(pair<typename map<V, typename directed_graph<V, E>::Node_data>::iterator, E> (ret_v2.first, e));
	ret_v2.first->second.neighbours.push_back(pair<typename map<V, typename directed_graph<V, E>::Node_data>::iterator, E> (ret_v1.first, e));
}
template<typename V, typename E>
	istream& operator>>(istream& is, graph<V, E>& g)
{	
	char c;
	is >> c;
	if (c == 'S')
	{
		V s;
		is >> s;
		g.specify_start_node(s);
	}
	else
	{
		string s;
		getline (is, s);
	}
	while (is.good())
	{
		V v1, v2;
		E e;
		is >> v1;
		is >> v2;
		is >> e;
		V nil;
		if (v1 != nil && v2 != nil)
		{
			g.add_edge(v1, v2, e);
		}
	}
	return is;
}
