#include <iostream>
#include <cstring>
using namespace std;

class LLIST{
    public:
        LLIST()
        {
            next = NULL;
        }
        int m_data;
        LLIST *next;
};

class Slist{
    public:
        unsigned int m_l;//元素个数
        LLIST *m_head;//头结点
        LLIST *m_last;//尾节点
        LLIST *m_node;//临时节点
    public:
        Slist()
        {
            m_l = 0;
            m_head = NULL;
            m_last = NULL;
            m_node = NULL;
        }
        void add(int x)//表尾添加元素
        {
            m_node = new LLIST;
            m_node->m_data = x;
            if(m_last == NULL)
            {
                m_head = m_node;
                m_last = m_node;
            }
            else
            {
                m_last->next = m_last;
                m_last = m_node;
            }
            m_l++;
        }
        void inserthead(int x)
        {
            m_node = new LLIST;
            m_node->m_data = x;
            m_node->next = m_head;
            m_head = m_node;
        }
        void removetail()
        {
            m_node = m_head;
            while(m_node != m_last)
            {
                m_node = m_node->next;
            }
            if(m_node == m_last)
            {
                m_last = m_node;
                delete m_node;
                m_node = NULL;
            }
        }
        void removehead()
        {
            m_node = m_head;
            m_head = m_node->next;
            if(m_head->next == NULL)
                m_last = NULL;
            delete m_node;
        }
};

class QUE{
    public:
		Slist list;
        QUE(void)
        {
            list.m_head = NULL;
            list.m_last = NULL;
        }
        ~QUE(void)
        {
            while(list.m_head != NULL)
            {
                list.m_node = list.m_head;
                list.m_head = list.m_head->next;
            }
        }
        void inq()
        {
            list.m_node = list.m_head;
            list.m_head = list.m_head->next;
            if(list.m_head == NULL)
                list.m_last = NULL;
        }
        void outq()
        {
            LLIST *p = new LLIST;
            //p->m_data = value;
            p->next = NULL;
            if(list.m_last != NULL)
            {
                list.m_last->next = p;
            }
            else
            {
                list.m_head = p;
            }
            list.m_last = p;
        }
        void show()
        {
            list.m_node = list.m_head;
            while(list.m_node != NULL)
            {
                cout<<list.m_node->m_data<<'\t';
                list.m_node = list.m_node->next;
            }
            cout<<endl;
        }
};

int main(void)
{
    Slist list;
    list.inserthead(25);
    list.add(10);
    list.add(11);
    list.add(12);
    list.removetail();
    list.removehead();

    QUE queue;
    queue.inq();
    queue.outq();
    queue.show();
}
