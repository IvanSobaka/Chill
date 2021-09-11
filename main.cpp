using namespace std;

Class subvector
{
private:
    int *mas;
    unsigned int top;
    unsigned int capacity;

public:
    bool init (subvector *qv)
    {
        qv->mas = NULL;
        qv->top = 0;
        qv->capacity = 0;
        return 1;
    }
    bool resize(subvector *qv, unsigned int new_capacity)
    {
        qv->capacity = new_capacity;
        int *new_mas = new int[new_capacity];
        if (qv->top > 0)
        {
            for (int i = 0; i < qv->top; ++i)
            {
                *(new_mas + i) = *(qv->mas + i);
            }
        }
        if(qv->mas)
            delete[] qv->mas;
        qv->mas = new_mas;
        return 1;
    }
    bool push_back(subvector *qv, int d)
    {
        while (qv->top >= qv->capacity)
        {
            if (qv->capacity == 0)
            {
                resize(qv, 1);
            }
            else
            {
                resize(qv, qv->capacity + 2);
            }
        }
        *(qv->mas + qv->top) = d;
        qv->top += 1;
        return 1;
    }
    int pop_back(subvector *qv)
    {
        if (qv->top == 0)
        {
            return 0;
        }
        else
        {
            --qv->top;
            return *(qv->mas + qv->top);
        }
    }
    void shrink_to_fit(subvector *qv)
    {
        resize(qv, qv->top);
    }
    void clear(subvector *qv)
    {
        qv->top = 0;
    }
    void destructor(subvector *qv)
    {
        delete[] qv->mas;
        init(qv);
    }
};
