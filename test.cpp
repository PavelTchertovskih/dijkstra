#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "graph.h"
using namespace std;
TEST(dijkstra_test, test_00)
{
	directed_graph<string, unsigned int> g;
	stringstream ss;
	ss << "S Moscow" << endl;
	ss << "Moscow Novosibirsk 7" << endl;
	ss << "Moscow Toronto 9" << endl;
	ss << "Moscow Krasnoyarsk 14" << endl;
	ss << "Novosibirsk Toronto 10" << endl;
	ss << "Novosibirsk Omsk 15" << endl;
	ss << "Omsk Toronto  11" << endl;
	ss << "Toronto Krasnoyarsk 2" << endl;
	ss << "Krasnoyarsk Kiev 9" << endl;
	ss << "Kiev Omsk  6";
	//g.read(ss);
	ss >> g;
	//g.print();
	g.calculate_shortest_paths();
	//g.print_shortest_paths(cout);
	stringstream out;
	g.print_shortest_paths(out);
	stringstream ch;
	ch << "Kiev {Moscow, Toronto, Krasnoyarsk, Kiev} - 20" << endl;
	ch << "Krasnoyarsk {Moscow, Toronto, Krasnoyarsk} - 11" << endl;
	ch << "Novosibirsk {Moscow, Novosibirsk} - 7" << endl;
	ch << "Omsk {Moscow, Novosibirsk, Omsk} - 22" << endl;
	ch << "Toronto {Moscow, Toronto} - 9" << endl;
	while (out.good())
	{
		string s1, s2;
		getline(ch, s1);
		getline(out, s2);
		EXPECT_TRUE(s1 == s2);
	}
}
TEST(dijkstra_test, test_01)
{
	graph<string, unsigned int> g;
	stringstream ss;
	ss << "S Moscow" << endl;
	ss << "Moscow Novosibirsk 7" << endl;
	ss << "Moscow Toronto 9" << endl;
	ss << "Moscow Krasnoyarsk 14" << endl;
	ss << "Novosibirsk Toronto 10" << endl;
	ss << "Novosibirsk Omsk 15" << endl;
	ss << "Omsk Toronto  11" << endl;
	ss << "Toronto Krasnoyarsk 2" << endl;
	ss << "Krasnoyarsk Kiev 9" << endl;
	ss << "Kiev Omsk  6";
	//g.read(ss);
	ss >> g;
	//g.print();
	g.calculate_shortest_paths();
	//g.print_shortest_paths(cout);
	stringstream out;
	g.print_shortest_paths(out);
	stringstream ch;
	ch << "Kiev {Moscow, Toronto, Krasnoyarsk, Kiev} - 20" << endl;
	ch << "Krasnoyarsk {Moscow, Toronto, Krasnoyarsk} - 11" << endl;
	ch << "Novosibirsk {Moscow, Novosibirsk} - 7" << endl;
	ch << "Omsk {Moscow, Toronto, Omsk} - 20" << endl;
	ch << "Toronto {Moscow, Toronto} - 9";
	while (out.good())
	{
		string s1, s2;
		getline(ch, s1);
		getline(out, s2);
		EXPECT_TRUE(s1 == s2);
	}
}
TEST(dijkstra_test, test_02)
{
	directed_graph<string, unsigned int> g;
	stringstream ss;
	ss << "S 1" << endl;
	ss << "1 2 10" << endl;
	ss << "2 1 10" << endl;
	ss << "1 3 18" << endl;
	ss << "1 4 8" << endl;
	ss << "2 3 16" << endl;
	ss << "2 4 9" << endl;
	ss << "2 5 21" << endl;
	ss << "3 5 15" << endl;
	ss << "4 1 7" << endl;
	ss << "4 6 12" << endl;
	ss << "5 6 23" << endl;
	ss << "6 3 15" << endl;
	ss >> g;
	//g.print();
	g.calculate_shortest_paths();
	//g.print_shortest_paths(cout);
	stringstream out;
	g.print_shortest_paths(out);
	stringstream ch;
	ch << "2 {1, 2} - 10" << endl;
	ch << "3 {1, 3} - 18" << endl;
	ch << "4 {1, 4} - 8" << endl;
	ch << "5 {1, 2, 5} - 31" << endl;
	ch << "6 {1, 4, 6} - 20" << endl;
	while (out.good())
	{
		string s1, s2;
		getline(ch, s1);
		getline(out, s2);
		EXPECT_TRUE(s1 == s2);
	}
}
TEST(dijkstra_test, test_03)
{
	graph<string, unsigned int> g;
	stringstream ss;
	ss << "S 1" << endl;
	ss << "1 2 10" << endl;
	ss << "1 3 18" << endl;
	ss << "1 4 8" << endl;
	ss << "2 3 16" << endl;
	ss << "2 4 9" << endl;
	ss << "2 5 21" << endl;
	ss << "3 5 15" << endl;
	ss << "4 6 12" << endl;
	ss << "5 6 23" << endl;
	ss << "6 3 15" << endl;
	ss >> g;
	//print();
	g.calculate_shortest_paths();
	//g.print_shortest_paths(cout);
	stringstream out;
	g.print_shortest_paths(out);
	stringstream ch;
	ch << "2 {1, 2} - 10" << endl;
	ch << "3 {1, 3} - 18" << endl;
	ch << "4 {1, 4} - 8" << endl;
	ch << "5 {1, 2, 5} - 31" << endl;
	ch << "6 {1, 4, 6} - 20" << endl;
	while (out.good())
	{
		string s1, s2;
		getline(ch, s1);
		getline(out, s2);
		EXPECT_TRUE(s1 == s2);
	}
}
TEST(dijkstra_test, test_04)
{
	directed_graph<string, unsigned int> g;
	stringstream ss;
	ss << "S 1" << endl;
	ss << "1 2 7" << endl;
	ss << "1 3 9" << endl;
	ss << "1 6 14" << endl;
	ss << "2 3 10" << endl;
	ss << "2 4 15" << endl;
	ss << "3 6 2" << endl;
	ss << "3 4 11" << endl;
	ss << "4 5 6" << endl;
	ss << "6 5 9" << endl;
	ss >> g;
	g.calculate_shortest_paths();
	//g.print_shortest_paths(cout);
	stringstream out;
	g.print_shortest_paths(out);
	stringstream ch;
	ch << "2 {1, 2} - 7" << endl;
	ch << "3 {1, 3} - 9" << endl;
	ch << "4 {1, 3, 4} - 20" << endl;
	ch << "5 {1, 3, 6, 5} - 20" << endl;
	ch << "6 {1, 3, 6} - 11" << endl;
	while (out.good())
	{
		string s1, s2;
		getline(ch, s1);
		getline(out, s2);
		EXPECT_TRUE(s1 == s2);
	}
}
TEST(dijkstra_test, test_05)
{
	graph<string, unsigned int> g;
	stringstream ss;
	ss << "S 1" << endl;
	ss << "1 2 7" << endl;
	ss << "1 3 9" << endl;
	ss << "1 6 14" << endl;
	ss << "2 3 10" << endl;
	ss << "2 4 15" << endl;
	ss << "3 6 2" << endl;
	ss << "3 4 11" << endl;
	ss << "4 5 6" << endl;
	ss << "6 5 9" << endl;
	ss >> g;
	g.calculate_shortest_paths();
	//g.print_shortest_paths(cout);
	stringstream out;
	g.print_shortest_paths(out);
	stringstream ch;
	ch << "2 {1, 2} - 7" << endl;
	ch << "3 {1, 3} - 9" << endl;
	ch << "4 {1, 3, 4} - 20" << endl;
	ch << "5 {1, 3, 6, 5} - 20" << endl;
	ch << "6 {1, 3, 6} - 11" << endl;
	while (out.good())
	{
		string s1, s2;
		getline(ch, s1);
		getline(out, s2);
		EXPECT_TRUE(s1 == s2);
	}
}
int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
