#include"stdio.h"
#include"stdlib.h"
#define Maxsize 10
struct QueueSequential
{
	int Data[Maxsize];
	int Front;
	int Rear;
};
struct QueueSequential MyQueue;
typedef struct QueueSequential * PointerToQueue;
PointerToQueue CreateQueue()
{
	PointerToQueue Ptr = (PointerToQueue)malloc(sizeof(struct QueueSequential));
	Ptr->Front = -1;
	Ptr->Rear = -1;
	return Ptr;
}
PointerToQueue InsertQueue(PointerToQueue Ptr, int K)
{
	
	Ptr->Rear++;
	Ptr->Data[Ptr->Rear] = K;
	
	return Ptr;
}

int DeleteQueue(PointerToQueue Ptr)
{
	int tmp;
	tmp = Ptr->Data[Ptr->Front+1];
	Ptr->Front++;
	return tmp;

}
struct MyTree 
{
	int Left;
	int Right;

};

struct MyTree TreeArray[Maxsize];

int BuildTree()
{
	int N,Root;
	scanf("%d",&N);
	if (N == 0) 
	{
		Root = -1;
		return Root;
	}
	bool check[Maxsize] = { NULL };
	int cnt1 = 0;
	char cl, cr;
	for (cnt1 = 0; cnt1 < N; cnt1++)
	{
		scanf("\n %c %c",&cl,&cr);
		if (cl != '-')
		{
			TreeArray[cnt1].Left = cl - '0';
			check[TreeArray[cnt1].Left] = true;
		}
		else
			TreeArray[cnt1].Left = -1;
		if (cr != '-')
		{

			TreeArray[cnt1].Right = cr - '0';
			check[TreeArray[cnt1].Right] = true;

		}
		else
			TreeArray[cnt1].Right = -1;

	}
	int cnt2 = 0;
	for (cnt2 = 0; cnt2 < N; cnt2++)
	{
		if (check[cnt2] == false)
			break;
	}
	Root = cnt2;
	return Root;
}

bool IsEmptyQueue(PointerToQueue Ptr)
{
	if (Ptr->Front == Ptr->Rear)
		return true;
	else
		return false;
}
void MyTreePrint(int tmp, int & Print_IfIs1)
{
	if ((TreeArray[tmp].Left == -1) && (TreeArray[tmp].Right == -1))
	{
		if (Print_IfIs1 == 0)
		{
			Print_IfIs1 = 1;
		}
		else
		{
			printf(" ");
		}

		printf("%d", tmp);
	}
}
void Traversal(int Root)
{
	if (Root == -1)
	{
		
	}
	else
	{
		//根入队
		PointerToQueue Ptr;
		Ptr = CreateQueue();
		Ptr = InsertQueue(Ptr, Root);
		//出1入2
		int Flag = 0;
		while (!IsEmptyQueue(Ptr))
		{
			int tmp1;
			
			tmp1 = DeleteQueue(Ptr);
			MyTreePrint(tmp1, Flag);
			int TreeArray_tmp1_Left = TreeArray[tmp1].Left;
			int TreeArray_tmp1_Right = TreeArray[tmp1].Right;
			if (TreeArray[tmp1].Left != -1)
			{
				
				Ptr = InsertQueue(Ptr,TreeArray_tmp1_Left);
			}
			if (TreeArray[tmp1].Right != -1)
			{

				Ptr = InsertQueue(Ptr, TreeArray_tmp1_Right);
			}
			

		}



	}
}
int main()
{
	int Root = -1;
	Root=BuildTree();
	Traversal(Root);
	system("pause");
	return 0;
}