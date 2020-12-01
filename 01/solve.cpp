#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <utility>

std::pair<int,int> sum( std::vector<int> v, int value)
{
	for( int x : v )
	{
		if( x > value ) continue;

		auto f = ( value - x); 
		auto y = std::find(std::begin(v), std::end(v), f);
		if( y != std::end(v) )
		{

			return std::make_pair(x,f);
		}
		else
			continue;
	}
	return std::make_pair(0,0);
}


int main(int argc,char**argv)
{
	std::ifstream input;
	std::string line;
	input.open("input.sorted",std::ifstream::in);

	std::vector<int> v;

	while( std::getline(input,line) )
	{
		v.push_back( std::stoi(line) );
	}
	input.close();
	std::pair<int,int> part1 = sum(v,2020);
	std::cout << "Part1: " << part1.first << " + " << part1.second << " = " << part1.first + part1.second << " : " << part1.first << " x " << part1.second << " = " << part1.first * part1.second <<  "\n";
	std::vector<int> part2;

	for( int x : v )
	{
		auto f = (2020 -x );
		auto y = sum(v,f);
		if( y.first == 0 )
			continue;
		else
		{
			part2.push_back(x);
			part2.push_back(y.first);
			part2.push_back(y.second);

		}
	}

	std::cout << "Part2: " << part2[0] << " + " << part2[1] << " + " << part2[2] << " = " << part2[0] + part2[1] + part2[2] << " : " << part2[0]*part2[1]*part2[2] << "\n";


	return 0;
}
