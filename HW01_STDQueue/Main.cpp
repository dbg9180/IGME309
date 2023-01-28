#include "Main.h"
#include "Queue.h"

template <typename T> 
void Print(std::deque<T> a_queue)
{
	//std::cout << "Begining of queue......." << std::endl;
	//uint count = a_queue.size();
	//for (uint i = 0; i < count; ++i)
	//{
	//	std::cout << a_queue[i];
	//	std::cout << std::endl;
	//}
	//std::cout << "End of queue............" << std::endl;
}

void wrapper()
{
	//INT QUEUE
	Queue<int>* intQueue = new Queue<int>();
	intQueue->Push(4);
	intQueue->Push(5);
	intQueue->Print();
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		intQueue->Push(rand() % 100);
	}
	intQueue->Print();
	for (int i = 0; i < 5; i++)
	{
		intQueue->Pop();
		intQueue->Print();
	}
	 //test copy constructor
	Queue<int>* intQueueCopy = new Queue<int>(*intQueue);
	intQueueCopy->Print();
	intQueueCopy->Push(120);
	intQueueCopy->Pop();
	intQueueCopy->Print();

	//copy over the original
	delete intQueueCopy;
	intQueueCopy = nullptr;

	intQueueCopy = intQueue;
	intQueueCopy->Print();

	delete intQueue;
	intQueue = nullptr;

	//Test with Alberto Class
	cout << "ALBERTO CLASS" << endl;

	Queue<AlbertoClass>* AlbertoQueue = new Queue<AlbertoClass>();
	for (uint i = 0; i < 40; i++)
	{
		AlbertoClass alberto(i);
		AlbertoQueue->Push(alberto);
	}
	AlbertoQueue->Print();
	//test copy constructor
	Queue<AlbertoClass>* AlbertoQueueCopy = new Queue<AlbertoClass>(*AlbertoQueue);
	AlbertoQueueCopy->Print();
	AlbertoClass alberto(41);
	AlbertoQueueCopy->Push(alberto);
	AlbertoQueueCopy->Pop();
	AlbertoQueueCopy->Print();

	//copy over the original
	delete AlbertoQueueCopy;
	AlbertoQueueCopy = nullptr;

	AlbertoQueueCopy = AlbertoQueue;
	AlbertoQueueCopy->Print();

	delete AlbertoQueue;
	AlbertoQueue = nullptr;

}

int main(void)
{
	wrapper();
	if (_CrtDumpMemoryLeaks())
	{
		cout << "MEMORY LEAKS" << endl;
	}

	//std::deque<int> myQueue;
	////Push elements
	//myQueue.push_back(0);
	//std::cout << "	just pushed +++++" << std::endl;
	//myQueue.push_back(1);
	//std::cout << "	just pushed +++++" << std::endl;
	//myQueue.push_back(2);
	//std::cout << "	just pushed +++++" << std::endl;
	////Print queue
	//Print<int>(myQueue);
	////pop an element
	//myQueue.pop_front();
	//std::cout << "		just popped -----" << std::endl;
	////add elements
	//myQueue.push_back(3);
	//std::cout << "	just pushed +++++" << std::endl;
	//myQueue.push_back(4);
	//std::cout << "	just pushed +++++" << std::endl;
	//myQueue.push_back(5);
	//std::cout << "	just pushed +++++" << std::endl;
	////Print queue
	//Print<int>(myQueue);
	//myQueue.pop_front();
	//std::cout << "		just popped -----" << std::endl;
	//myQueue.pop_front();
	//std::cout << "		just popped -----" << std::endl;
	////Print queue
	//Print<int>(myQueue);
	////clear queue
	//uint count = myQueue.size();
	//for (uint i = 0; i < count; ++i)
	//{
	//	myQueue.pop_front();
	//	std::cout << "		just popped -----" << std::endl;
	//}
	////Print queue
	//Print<int>(myQueue);

	////Complex Data usage
	//std::deque<Foo> myFooQueue;
	//for (uint i = 0; i < 10; ++i)
	//{
	//	Foo foo(i);
	//	myFooQueue.push_back(foo);
	//	std::cout << "	just pushed +++++" << std::endl;
	//	if (i % 2 == 0)
	//	{
	//		myFooQueue.pop_front();
	//		std::cout << "		just popped -----" << std::endl;
	//	}
	//}

	//std::deque<AlbertoClass> myAlbertoQueue;
	//for (uint i = 30; i < 40; ++i)
	//{
	//	AlbertoClass alberto(i);
	//	myAlbertoQueue.push_back(alberto);
	//	std::cout << "	just pushed +++++" << std::endl;
	//}
	//std::cout << "	Content" << std::endl;
	//for (uint i = 0; i < 10; ++i)
	//{
	//	std::cout << myAlbertoQueue[i] << std::endl;
	//}

	std::cout << "Press Enter to finish." << std::endl;
	
	getchar();
}