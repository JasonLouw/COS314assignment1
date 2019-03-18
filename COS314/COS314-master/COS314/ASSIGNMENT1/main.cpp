#include "BreadthFirst.h"
#include "HillClimbing.h"
#include "aStar.h"
using namespace std;

int main()
{
	string testData[20][3] = {
			{"123804765","134862705","5"},
			{"123804765","281043765","9"},
			{"123804765","281463075","12"},
			{"134805726","123804765","6"},
			{"231708654","123804765","14"},
			{"231804765","123804765","16"},
			{"123804765","231804765","16"},
			{"283104765","123804765","4"},
			{"876105234","123804765","28"},
			{"867254301","123456780","31"},
			{"647850321","123456780","31"},
			{"123804765","567408321","30"},
			{"806547231","012345678","30"},
			{"641302758","012345678","14"},
			{"158327064","012345678","12"},
			{"328451670","012345678","12"},
			{"035428617","012345678","10"},
			{"725310648","012345678","15"},
			{"412087635","123456780","17"},
			{"162573048","123456780","10"}
		};
		

		//  cout<<"---BREADTH FIRST SEARCHING---\n";
		//  BreadthFirst a;
		//  for(int i = 0; i<20; i++)
		//  {
		//   std::cout<<i<<": ";
		//  a.solve(testData[i][0],testData[i][1],testData[i][2]);
		//  }
		//  cout<<"---BREADTH FIRST SEARCHING END---\n";
		
		
		// cout<<"---HILL CLIMBING SEARCH---\n";
		// HillClimbing b;

		// for(int i = 0; i<20; i++)
		// {
		//  std::cout<<i<<": ";
		// b.solve(testData[i][0],testData[i][1],testData[i][2]);
		// }
		// 	cout<<"---HILL CLIMBING SEARCH END---\n";


		cout<<"---A* SEARCH---\n";
		aStar c;

		for(int i = 0; i<20; i++)
		{
		 	std::cout<<i<<": ";
			c.solve(testData[i][0],testData[i][1],testData[i][2]);
		}
		cout<<"---A* SEARCH END---\n";
	
	//~ for(int i = 0; i < 20; i++)
	//~ {
		//~ for(int j = 0; j < 3; j++)
		//~ {
			//~ cout<<testData[i][j]<<",";
		//~ }
		//~ cout<<endl;
	//~ }
	
	return 0;
}
