/**
 * PROG: 不一样的循环队列
 */
#include <cstdio>
#include <cstring>
#include <memory.h>

const int MAX_COMMAND_SIZE = 8;
const int MAX_QUEUE_SIZE = 100004;

class Queue
{
public:
    Queue(int size);
    ~Queue();

    bool IsEmpty();
    bool IsFull();
    bool push(int element);
    bool pop();
    int query(int k);

private:
    int m_front;
    int m_rear;
    int m_size;
    int m_element[MAX_QUEUE_SIZE];
};

Queue::Queue(int size)
{
    m_rear = 0;
    m_front = 0;
    m_size = size + 1;
    memset(m_element, 0, sizeof(m_element));
}

Queue::~Queue()
{
    //
}

bool Queue::IsEmpty()
{
    return (m_front == m_rear);
}

bool Queue::IsFull()
{
    return (((m_rear+1)%m_size) == m_front);
}

bool Queue::push(int element)
{
    if (IsFull())
    {
        return false;
    }
    else
    {
        m_element[m_rear] = element;
        m_rear = (m_rear + 1) % m_size;
		return true;
    }
}

bool Queue::pop()
{
    if (IsEmpty())
    {
        return false;
    }
    else
    {
        m_element[m_front] = 0;
        m_front = (m_front + 1) % m_size;
		return true;
    }
}

int Queue::query(int k)
{
    if (k<=0 || k>m_size || k>(m_rear-m_front))
    {
        return -1;
    }
    else
    {
        int index = (m_front + k - 1) % m_size;
        return m_element[index];
    }
}

int main(void)
{
    int nCommand, nQueueSize, element;
    char szCommand[MAX_COMMAND_SIZE] = {0};
    while (~scanf("%d %d", &nCommand, &nQueueSize))
    {
        Queue queue(nQueueSize);
        for (int i=0; i<nCommand; ++i)
        {
            scanf("%s", szCommand);
            if (0 == strcmp("Push", szCommand))
            {
                scanf("%d", &element);
                if (!queue.push(element))
                {
                    printf("failed\n");
                }
            }
            else if (0 == strcmp("Pop", szCommand))
            {
                if (!queue.pop())
                {
                    printf("failed\n");
                }
            }
            else if (0 == strcmp("Query", szCommand))
            {
                scanf("%d", &element);
                int ret = queue.query(element);
                if (-1 == ret)
                {
                    printf("failed\n");
                }
                else
                {
                    printf("%d\n", ret);
                }
            }
            else if (0 == strcmp("Isempty", szCommand))
            {
                if (queue.IsEmpty())
                {
                    printf("yes\n");
                }
                else
                {
                    printf("no\n");
                }
            }
            else if (0 == strcmp("Isfull", szCommand))
            {
                if (queue.IsFull())
                {
                    printf("yes\n");
                }
                else
                {
                    printf("no\n");
                }
            }
        }// end of for
    }
    return 0;
}
