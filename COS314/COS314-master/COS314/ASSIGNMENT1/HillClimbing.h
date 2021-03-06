#ifndef HILLCLIMBING_H
#define HILLCLIMBING_H

class HillClimbing
{
private:
	long goalStateInt;
	long startStateInt;
	std::string goalState;
	std::string startState;
	bool* close;
	Node* head;
	
	
	
public:

		HillClimbing()
		{
			close = new bool[999999999];
			for(int i = 0; i < 999999999; i++)
			{
				close[i] = false;
			}
		}
	void stringToMatrix(int** matrix, std::string s, int* x0,int* y0)
	{
		matrix[0][0] = s[0] -48;
		matrix[0][1] = s[1] -48;
		matrix[0][2] = s[2] -48;
		matrix[1][0] = s[3]-48;
		matrix[1][1] = s[4] -48;
		matrix[1][2] = s[5] -48;
		matrix[2][0] = s[6]-48;
		matrix[2][1] = s[7] -48;
		matrix[2][2] = s[8] -48;
	
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				if(matrix[i][j] == 0)
				{
					*x0 = i;
					*y0 = j;
					return;
				}
	}
	
	std::string matrixToString(int** matrix)
	{
		string temp = "";
	
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
			{
				temp = temp+std::to_string(matrix[i][j]);
			}
			
		return temp;
	}
	
	int levelF( string child)
	{
		int score = 0;
		for(int i = 0; i < 9; i++)
		{
			if(goalState[i] != child[i])
				score++;
			
		}
		return score;
	}

int manHatDist(int** matrixCurrent, int** matrixGoal)
{
	int x = 0;
	// for(int i = 0; i < 3; i++)
	// {
	// 	for(int j = 0; j < 3; j++)
	// 	{
	// 		if(matrixCurrent[i][j] != matrixGoal[i][j])
	// 		{
	// 			x++;
	// 		}
	// 	}
	// }


	int total = 0;
	for(int n = 1; n < 9; n++)
	{
		int x1, y1;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if(matrixCurrent[i][j] == n)
				{
					x1 = i;
					y1 = j;
				}
			}

		}

		int x2, y2;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if(matrixGoal[i][j] == n)
				{
					x2 = i;
					y2 = j;
				}
			}

		}

		x1 = x1 - x2;
		y1 = y1 - y2;
		if(x1 < 0)
			x1 = x1 * (-1);
		if(y1 < 0)
			y1 = y1 * (-1);
		//cout<<"\n"<<x1<<" "<<y1<<endl;
		
		total = total + x1 + y1;
	}

	return total + x;

}


		void clear()
		{
			for(int i = 0; i < 999999999; i++)
			{
				close[i] = false;
			}
		}

		void solve(std::string startS, std::string goalS, std::string minMoves)
		{
			clear();
			startStateInt = stoi(startS);
			goalStateInt = stoi(goalS);
			startState = startS;
			goalState = goalS;
			//from here you need to go breadth first by creating new nodes

			StackQueue* children = new StackQueue();
			Node* nodeptr = new Node(startS);
			head = nodeptr;
			children->addBack(nodeptr);
			int** matrix = new int*[3];
			for(int i = 0; i < 3; i++)
			{
				matrix[i] = new int[3];
			}

			int a, b;
			int** matrixGoal = new int*[3];
			for(int i = 0; i < 3; i++)
			{
				matrixGoal[i] = new int[3];
			}
			 stringToMatrix(matrixGoal, goalS, &a, &b);
			 //cout<<"eroorCVGHGVB\n";
	
			int x, y;
			
			int temp = 0;
			int atemp = 0;
		
			while(nodeptr->name != goalState )
			{
			
				nodeptr = children->removeFront();
				
				if(nodeptr == NULL)
				{
					cout<<"broken\n";
					break;
				}
		
				stringToMatrix(matrix, nodeptr->name, &x, &y);
					int order[4];
				for(int i = 0; i < 4; i++)
					order[i]=-1;

				if(x-1 >= 0)
				{
					

					int temp = matrix[x][y];
					matrix[x][y] = matrix[x-1][y];
					matrix[x-1][y] = temp;
					
					string childString = matrixToString(matrix);
					atemp = stoi(childString);
					
					int l = manHatDist(matrix, matrixGoal);
			
					order[0] = l; 
					
					temp = matrix[x][y];
					matrix[x][y] = matrix[x-1][y];
					matrix[x-1][y] = temp;	
				}
				if(x+1 < 3)
				{
					int temp = matrix[x][y];
					matrix[x][y] = matrix[x+1][y];
					matrix[x+1][y] = temp;
					
					string childString = matrixToString(matrix);
					atemp = stoi(childString);
					int l = manHatDist(matrix, matrixGoal);
					order[1] = l; 
				
					temp = matrix[x][y];
					matrix[x][y] = matrix[x+1][y];
					matrix[x+1][y] = temp;
				}
				if(y-1 >= 0)
				{
					int temp = matrix[x][y];
					matrix[x][y] = matrix[x][y-1];
					matrix[x][y-1] = temp;
					
					string childString = matrixToString(matrix);
					atemp = stoi(childString);
					int l = manHatDist(matrix, matrixGoal);
					order[2] = l; 
		
					temp = matrix[x][y];
					matrix[x][y] = matrix[x][y-1];
					matrix[x][y-1] = temp;
				}
				if(y+1 < 3)
				{
					int temp = matrix[x][y];
					matrix[x][y] = matrix[x][y+1];
					matrix[x][y+1] = temp;
					
					string childString = matrixToString(matrix);
					atemp = stoi(childString);
					int l = manHatDist(matrix, matrixGoal);
					order[3] = l; 
				
					temp = matrix[x][y];
					matrix[x][y] = matrix[x][y+1];
					matrix[x][y+1] = temp;
				}

				for(int j = 0; j < 4; j++)
				{
					int p = -1;
					int value = -1;
					for(int i = 0; i < 4; i++)
					{
						//cout<<order[i]<<" ";
						if(order[i] > value && order[i]!=-1)
						{
							value = order[i];
							p = i;
						}
					}
					//cout<<"p: "<<p;
					//cout<<endl;
					if(p == -1)
					{
						break;
					}
					else
						order[p] = -1;

				if(x-1 >= 0 && p ==0)
				{
					temp = matrix[x][y];
					matrix[x][y] = matrix[x-1][y];
					matrix[x-1][y] = temp;
					
					string s = matrixToString(matrix);
					atemp = stoi(s);
					if(close[atemp] == false)
					{
						Node* t = new Node(s);
						nodeptr->up = t;
						t->parent = nodeptr;
						children->addFront(t);
						close[atemp] = true;
					}
					
					temp = matrix[x][y];
					matrix[x][y] = matrix[x-1][y];
					matrix[x-1][y] = temp;
					
					
				}
				if(x+1 < 3 && p ==1)
				{
					temp = matrix[x][y];
					matrix[x][y] = matrix[x+1][y];
					matrix[x+1][y] = temp;
					
					string s = matrixToString(matrix);
					atemp = stoi(s);
					if(close[atemp] == false)
					{
						Node* t = new Node(s);
						nodeptr->down = t;
						t->parent = nodeptr;
						children->addFront(t);
						close[atemp] = true;
					}
					
					temp = matrix[x][y];
					matrix[x][y] = matrix[x+1][y];
					matrix[x+1][y] = temp;
	
				
				}
				if(y-1 >= 0 && p ==2)
				{
					temp = matrix[x][y];
					matrix[x][y] = matrix[x][y-1];
					matrix[x][y-1] = temp;
					
					string s = matrixToString(matrix);
					atemp = stoi(s);
					if(close[atemp] == false)
					{
						Node* t = new Node(s);
						nodeptr->left = t;
						t->parent = nodeptr;
						children->addFront(t);
						close[atemp] = true;
					}
				
					temp = matrix[x][y];
					matrix[x][y] = matrix[x][y-1];
					matrix[x][y-1] = temp;
				}
				if(y+1 < 3 && p ==3)
				{
					temp = matrix[x][y];
					matrix[x][y] = matrix[x][y+1];
					matrix[x][y+1] = temp;
					
					string s = matrixToString(matrix);
					atemp = stoi(s);
					if(close[atemp] == false)
					{
						Node* t = new Node(s);
						nodeptr->right = t;
						t->parent = nodeptr;
						children->addFront(t);
						close[atemp] = true;
					}
					
					temp = matrix[x][y];
					matrix[x][y] = matrix[x][y+1];
					matrix[x][y+1] = temp;
				}
				
			}

		}

			cout<<"found";
		
			printMatrix(nodeptr);
			
			
	}


	void printMatrix(Node* p)
		{
				int move = 0;
				StackQueue* stack = new StackQueue();
				int totalNode = p->nem;
				
				while(p != head)
				{
					move++;
					stack->addFront(p);
					p = p->parent;
				}
				stack->addFront(p);
				cout<<p->name<<", Nodes created: "<<totalNode<<", Moves: "<<move<<endl;
				p = stack->removeFront();
				while(p != NULL)
				{
					for(int i = 0; i < 9; i++)
					{	
							//comment in to print changes
							// cout<<p->name[i]<<" ";
							//  if(i == 2)
							// 	 cout<<endl;
							//  if(i == 5)
							// 	 cout<<endl;
							//  if(i == 8)
							// 	 cout<<endl;
						
					}
					// cout<<endl;	
					p = stack->removeFront();
				}
				
				
		}
	
};

#endif
