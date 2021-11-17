#include <iostream>
#include <vector>

class Heap
{
    int value;
    std::vector <int> body;

public:
    Heap();
    Heap(std::vector <int> bod);

    int get_value(){return value;}
    std::vector <int>  get_body(){return body;}

    void set_value(int val){value = val;}

    int siftUp(int ID);
    int siftDown(int ID);

    int add(int newElem);

    int takeFirst();

    int changePriority(int ID, int newPrior);

    void postCreatedSorting();

    void printHeap();

};

Heap::Heap()
{
    value = 0;
    std::vector <int> bod (0);
    body = bod;
}

Heap::Heap(std::vector <int> bod)
{
    value = bod.size();
    body = bod;
}

int Heap::siftUp(int ID)
{
    int IDnow = ID;

    while(IDnow > 0 && body[IDnow] > body[(IDnow - 1) / 2]);
    {
        std::swap(body[IDnow], body[(IDnow - 1) / 2]);
        IDnow = (IDnow - 1) / 2;
    }


    return IDnow;

}

int Heap::siftDown(int ID)
{
    int IDnow = ID;

    for(int i = 0; i > -1; i ++)
    {
        if(IDnow >= value / 2)
            break;

        if(value % 2 == 1 || IDnow < (value - 1) / 2)
        {
            if(body[IDnow] < body[2 * IDnow + 1] || body[IDnow] < body[2 * IDnow + 2])
            {
                if(body[2 * IDnow + 1] >= body[2 * IDnow + 2])
                {
                    std::swap(body[2 * IDnow + 1], body[IDnow]);
                    IDnow = 2 * IDnow + 1;
                }

                else
                {
                    std::swap(body[2 * IDnow + 2], body[IDnow]);
                    IDnow = 2 * IDnow + 2;
                }


            }
            else
                break;
        }
        else
        {
            if(body[IDnow] < body[2 * IDnow + 1])
            {
                std::swap(body[2 * IDnow + 1], body[IDnow]);
                IDnow = 2 * IDnow + 1;
            }
            else
                break;
        }
    }

    return IDnow;
}


int Heap::add(int newElem)
{
    value ++;

    if(body.size() < value)
        body.push_back(newElem);
    else
        body[value - 1] = newElem;

    return siftUp(value - 1);
}

int Heap::takeFirst()
{
    value --;
    std::swap(body[0], body[value]);

    return siftDown(0);
}

int Heap::changePriority(int ID, int newPrior)
{
    body[ID] = newPrior;

    int u, d;

    u = siftUp(ID);
    d = siftDown(ID);

    if(u == ID && d != ID)
        return d;

    if(d == ID && u != ID)
        return u;

    if(u == ID && d == ID)
        return ID;

    return -1;
}

void Heap::postCreatedSorting()
{
    for(int i = value - 1; i --; i >= 0)
        siftDown(i);
}

void Heap::printHeap()
{
    for(int i = 0; i < value; i ++)
        std::cout << body[i] << " ";
}


int main()
{
    std::vector <int> withHeap;

    int n;

    std::cin >> n;

    for(int i = 0; i < n; i ++)
    {
        int a;
        std::cin >> a;
        withHeap.push_back(a);
    }

    Heap workSpace(withHeap);

    int reqs;

    std::cin >> reqs;

    for(int i = 0; i < reqs; i ++)
    {

        int index, priorityDelta;
        std::cin >> index >> priorityDelta;

        std::cout << workSpace.changePriority(index - 1, workSpace.get_body()[index - 1] + priorityDelta);

    }

    workSpace.printHeap();




    return 0;
}

