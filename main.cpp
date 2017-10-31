#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class LLIST{
    public:
        int m_data;
        LLIST *m_next;
		LLIST(int data):m_data(data), m_next(NULL)
		{}
};

class Slist{
    private:
        LLIST *m_head;//头结点
        LLIST *m_last;//尾节点
    public:
        Slist(void)
        {
            m_head = new LLIST(0);
            m_last = m_head;
        }
		~Slist(void)
		{
			LLIST *tmp;
			for(tmp = m_head; tmp; tmp = tmp->m_next)
			{
				delete tmp;
			}
		}
        void instail(LLIST *node)//表尾添加一个节点
        {
			if(m_head == m_last)
			{
				m_head->m_next = node;
				m_last = node;
			}
            else
            {
                m_last->m_next = node;
                m_last = node;
            }
        }
        LLIST *inshead(void)//从头部获得节点
        {
			return m_head->m_next;
        }
        void removetail(void)//删除尾部节点
        {
            LLIST *tmp = m_last;
            if(tmp != m_head)
            {
                delete tmp;
            }
        }
        void removehead()//删除头结点
        {
            LLIST *tmp = m_head->m_next;
			if(m_head != m_last)
			{
				if(tmp = m_last)
				{
					delete tmp;
					m_last = m_head;
				}
				else
				{
					m_head->m_next = tmp->m_next;
					delete tmp;
				}
			}
        }
		void travel(void)
		{
			LLIST *tmp;
			if(m_head == m_last)
			  cout<<"链表为空";
			else
			  for(tmp = m_head->m_next; tmp; tmp = tmp->m_next)
			  {
				  cout<<tmp->m_data<<"\t";
			  }
			cout<<endl;
		}
};

class QUE{
	private:
		Slist m_list;//类里保存数据的地方
    public:
        void inq(LLIST *node)//入队
        {
            m_list.instail(node);
        }
        LLIST *outq(void)
        {
            LLIST *tmp = new LLIST(0);
			if(m_list.inshead())
			  memcpy(tmp, m_list.inshead(), sizeof(LLIST));
            m_list.removehead();
			return tmp;
        }
        void travel(void)
        {
			m_list.travel();
        }
};

int main(void)
{
    QUE queue;
	LLIST *n1 = new LLIST(1);
	LLIST *n2 = new LLIST(10);
	LLIST *n3 = new LLIST(23);
	LLIST *n4 = new LLIST(89);
    queue.inq(n1);
    queue.inq(n2);
    queue.inq(n3);
    queue.inq(n4);
	queue.travel();

    //queue.outq();
	cout<<"出队后"<<endl;
	queue.outq();
	queue.travel();
	cout<<"入队后"<<endl;
	//queue.travel();
	LLIST *n5 = new LLIST(54);
	queue.inq(n5);
	queue.travel();
}
