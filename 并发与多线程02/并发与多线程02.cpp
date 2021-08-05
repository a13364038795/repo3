# include<iostream>
# include<thread>
# include<windows.h>
using namespace std;
//自己创建的线程从函数开始运行
class TA
{
public:
	TA(int i) :m_a(i) 
		//等价于 m_a=i;
	{
		cout << "TA构造函数被执行" << endl;
	};
	TA(const TA& ta) :m_a(ta.m_a)
		//等价于 this->m_a=m_a;
	{
		cout << "TA拷贝构造函数被执行" << endl;
	}
	~TA()
	{
		cout << "~TA析构函数被执行" << endl;
	}
	void operator()()  //不能带参数
	{
		//cout << "我的线程operator()开始执行了" << endl;
		//cout << "我的线程operator()执行结束了" << endl;
		cout << "m_a1的值为" << m_a <<endl;
		//一旦主线程执行完，m_a中的值就被释放了，
		//所以无法打印m_a中的值
		//要解决这个BUG可以让构造函数的参数不要带引用
		//直接赋值
		cout << "m_a2的值为" << m_a<< endl;
		cout << "m_a3的值为" << m_a<< endl;
		cout << "m_a4的值为" << m_a<< endl;
		cout << "m_a5的值为" << m_a<< endl;
		cout << "m_a6的值为" << m_a<< endl;
	}
	int m_a;

};
void MyPrint()
{
	cout << "自己创建的线程开始执行1" << endl;
	cout << "自己创建的线程执行结束1" << endl;
	cout << "自己创建的线程开始执行2" << endl;
	cout << "自己创建的线程执行结束2" << endl;
}
int main()
{
	//thread mytobj(MyPrint);    //mytobj我的线程对象
	//if (mytobj.joinable())
	//{
	//	cout << "可以使用join或者detach" << endl;
	//}
	//else
	//{
	//	cout<< "不可以使用join或者detach" << endl;
	//}
	////创建了线程，线程的入口是MyPrint();
	////mytobj.join();
	////计入汇合，就是阻塞，阻塞主线程，让主线程等待子进程执行完毕
	////然后子线程和主线程汇合
	//mytobj.detach();
	////传统的多线程程序主线程要等待子线程执行完，但也有例外
	////如detach 一旦detach之后，与这个主线程相关联的thread对象
	////就会失去与主线程的关联
	////失去关联的子线程相当于被C++运行时库接管，当子线程运行
	////完毕后，由运行时库清理该线程相关的资源（守护线程）
	//cout << "主线程收尾，最终安全退出1" << endl;
	//Sleep(500);
	//cout << "主线程收尾，最终安全退出2" << endl;
	//cout << "主线程收尾，最终安全退出3" << endl;
	//int myi = 6;
	//TA ta(myi);
	//thread mtobj2(ta);
	//mtobj2.join();
	////mtobj2.detach();
	//cout << "主线程结束" << endl;
	auto mylamthread = []() {     //不捕获变量，没有参数
		cout << "自己创建lambda线程开始执行" << endl;
		cout << "自己创建lambda线程执行结束" << endl;
	};
	thread mytobj(mylamthread);
	mytobj.join();
	cout << "主线程结束" << endl;
	return 0;
}