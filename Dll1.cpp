// MathLibrary.cpp : Defines the exported functions for the DLL.
#include "stdafx.h"
#include <iostream>
#include <utility>
#include <limits.h>
#include "Dll1.h"
#include <vector>
#include <map>

int moreNumber(std::vector<int> args)
{
	int a;
	std::vector<int> countafterint;
	std::vector<int> afint;
	afint.push_back(args[0]);
	std::multimap<int, int> value_count;
	for (int i = 0; i < args.size(); ++i) {
		value_count.insert(std::pair<int, int>(args[i], 1));
	}
	int maxcount = 0;
	int key_of_max = 0;

	for (auto it = value_count.begin(); it != value_count.end(); ++it) {
		std::cout << it->first << ": "<< it->second << " count: " << value_count.count(it->first) << std::endl;
		if (value_count.count(it->first) > maxcount) {
			maxcount = value_count.count(it->first);
			key_of_max = it->first;
		}
	}
	std::cout << "maxcount: " << maxcount << std::endl;
	std::cout << "key: " << key_of_max << std::endl;
	return key_of_max;
	/*countafterint.push_back(1);
	for (unsigned int i = 1; i < args.size(); i++)
	{
		if (args[i] == args[0])
		{
			countafterint[0]++;
		}
	}
	for (unsigned int i = 1; i < args.size(); i++)
	{
		bool flag = true;
		for (unsigned int j = 0; j < afint.size(); j++)
		{
			if (args[i] == afint[j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			afint.push_back(args[i]);
			countafterint.push_back(1);
			for (unsigned int j = i + 1; j < args.size(); j++)
			{
				if (args[j] == args[i])
				{
					countafterint[countafterint.size() - 1]++;
				}
			}
		}
	}
	int indexmax = 0;
	int maxcount = countafterint[0];
	for (unsigned int i = 1; i < countafterint.size(); i++)
	{
		if (maxcount < countafterint[i])
		{
			indexmax = i;
			maxcount = countafterint[i];
		}
	}
	return afint[indexmax];
	*/
}