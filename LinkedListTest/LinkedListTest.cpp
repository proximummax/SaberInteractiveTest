#include "pch.h"
#include "CppUnitTest.h"
#include "../SaberTest/SaberTest.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListTest
{
	TEST_CLASS(LinkedListTest)
	{
	public:
		
		TEST_METHOD(SameListCompare)
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

			ListRand* list2 = new ListRand();
			list2->Count = 3;
			list2->Head = node1;
			list2->Tail = node3;

			Assert::AreEqual(true, IsIdentical(list2->Head, list->Head));
		}
		TEST_METHOD(AnotherListsCompare)
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
			list->Head = node3;
			list->Tail = node1;

			ListRand* list2 = new ListRand();
			list2->Count = 3;
			list2->Head = node1;
			list2->Tail = node3;

			Assert::AreEqual(false, IsIdentical(list2->Head, list->Head));
		}
		TEST_METHOD(AnotherFiles)
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

			ifstream infile("list123.txt");
			ListRand* newList = new ListRand();
			newList->Deserialize(infile);

			Assert::AreEqual(false, IsIdentical(newList->Head, list->Head));
		}
		TEST_METHOD(CompareAfterDeserialize_1)
		{
			ListNode* node1 = new ListNode();
			node1->Data = "node1";

			ListNode* node2 = new ListNode();
			node2->Data = "node2";
			node2->Prev = node1;
			node2->Rand = node2;

			ListRand* list = new ListRand();
			list->Count = 2;
			list->Head = node1;
			list->Tail = node2;

			ofstream outfile("list.txt");
			list->Serialize(outfile);

			ifstream infile("list.txt");
			ListRand* newList = new ListRand();
			newList->Deserialize(infile);

			Assert::AreEqual(true, IsIdentical(newList->Head, list->Head));
		}
		TEST_METHOD(CompareAfterDeserialize_2)
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

			Assert::AreEqual(true, IsIdentical(newList->Head, list->Head));
		}
	};
}
