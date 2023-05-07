
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

static string NullString = "null";
class ListNode
{
public:
	ListNode* Prev;
	ListNode* Next;
	ListNode* Rand;
	string Data;
};

class ListRand
{
public:
	ListNode* Head;
	ListNode* Tail;
	int Count;

	void Serialize(ofstream& writeStream)
	{
		writeStream << Count << endl;

		ListNode* node = Head;
		while (node != nullptr)
		{
			WriteNodeDataInFile(writeStream, node);
			node = node->Next;
		}

		node = Head;
		while (node != nullptr)
		{
			WriteNodeDataInFile(writeStream, node->Prev);
			WriteNodeDataInFile(writeStream, node->Next);
			WriteNodeDataInFile(writeStream, node->Rand);

			node = node->Next;
		}
	}

	void WriteNodeDataInFile(ofstream& writeStream, ListNode* node)
	{
		if (node != nullptr)
			writeStream << node->Data << endl;
		else
			writeStream << NullString << endl;
	}

	void Deserialize(ifstream& readStream)
	{
		readStream >> Count;

		if (Count == 0)
			return;

		vector<ListNode*> nodes(Count);
		map<string, ListNode*> dataToNode;

		for (int i = 0; i < Count; i++)
		{
			string data;
			readStream >> data;

			nodes[i] = new ListNode();
			nodes[i]->Data = data;

			dataToNode[data] = nodes[i];
		}

		for (int i = 0; i < Count; i++)
		{
			string prevData, nextData, randData;
			readStream >> prevData >> nextData >> randData;

			if (prevData != NullString)
				nodes[i]->Prev = dataToNode[prevData];

			if (nextData != NullString)
				nodes[i]->Next = dataToNode[nextData];

			if (randData != NullString)
				nodes[i]->Rand = dataToNode[randData];

		}

		Head = nodes[0];
		Tail = nodes[Count - 1];
	}

};


static bool IsIdentical(ListNode* a, ListNode* b)
{

	while (a != nullptr && b != nullptr)
	{
		if (a->Data != b->Data)
			return false;

		if (a->Prev != nullptr && b->Prev != nullptr && a->Prev->Data != b->Prev->Data)
			return false;

		if (a->Next != nullptr && b->Next != nullptr && a->Next->Data != b->Next->Data)
			return false;

		a = a->Next;
		b = b->Next;

	}

	return (a == nullptr && b == nullptr);
}

int main()
{
	ListNode* node1 = new ListNode();
	node1->Data = "node1";

	ListNode* node2 = new ListNode();
	node2->Data = "node2";
	node2->Prev = node1;

	ListNode* node3 = new ListNode();
	node3->Data = "node3";
	node3->Prev = node2;
	node3->Rand = node1;

	node1->Rand = node3;
	node1->Next = node2;

	node2->Next = node3;

	ListRand* list = new ListRand();
	list->Count = 3;
	list->Head = node1;
	list->Tail = node3;

	ofstream outfile("list.txt");
	list->Serialize(outfile);

	ifstream infile("list.txt");
	ListRand* newList = new ListRand();
	newList->Deserialize(infile);

	cout << IsIdentical(newList->Head, list->Head);

	return 0;
}










