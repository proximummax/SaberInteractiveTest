
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
	return 0;
}










