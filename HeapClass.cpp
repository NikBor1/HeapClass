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
    int get_body(){return body;}

    void set_value(int val){value = val;}

    void siftUp(int ID);
    void siftDown(int ID);

    void add(int newElem);

    void takeFirst();

    void changePriority(int ID, int newPrior);

    void postCreatedSorting();

};

Heap::Heap()
{
    value = 0;
    std:vector <int> bod (0);
    body = bod;
}

Heap::Heap(std::vector <int> bod)
{
    value = bod.size();
    body = bod;
}

void Heap::siftUp(int ID)
{
    int IDnow = ID;

    while(IDnow > 0 && body[IDnow] > body[(IDnow - 1) / 2]);
        std::swap(body[IDnow], body[(IDnow - 1) / 2]);

}

void Heap::siftDown(int ID)
{
    int IDnow = ID;

    for(int i = 0; i > -1; i ++);
    {
        if(IDnow >= value / 2)
            break;

        if(value % 2 == 1 || IDnow < (value - 1) / 2)
        {
            if(body[IDnow] < body[2 * IDnow + 1] || body[IDnow] < body[2 * IDnow + 2]);
            {
                if(body[2 * IDnow + 1] >= body[2 * IDnow + 2])
                    std::swap(body[2 * IDnow + 1], body[IDnow]);
                else
                    std::swap(body[2 * IDnow + 2], body[IDnow]);
            }
            else
                break;
        }
        else
        {
            if(body[IDnow] < body[2 * IDnow + 1])
                std::swap(body[2 * IDnow + 1], body[IDnow]);
            else
                break;
        }
    }

}


void Heap::add(int newElem)
{
    value ++;

    if(body.size() < value)
        body.push_back(newElem);
    else
        body[value - 1] = newElem;

    siftUp(value - 1);
}

void Heap::takeFirst()
{
    value --;
    std::swap(body[0], body[value]);

    siftDown(0);
}

void Heap::changePriority(int ID, int newPrior)
{
    body[ID] = newPrior;

    siftUp(ID);
    siftDown(ID);
}

void Heap::postCreatedSorting()
{
    for(int i = value - 1; i --; i >= 0)
        siftDown(i);
}


int main()
{


    return 0;
}

