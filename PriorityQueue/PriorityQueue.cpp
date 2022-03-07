
#include <iostream>
#include "Queue.h"

int main()
{
    Queue queue;
    queue.push(10, Priority::low);
    queue.push(1, Priority::low);
    queue.push(20, Priority::high);
    queue.push(2, Priority::high);
    queue.push(99, Priority::medium);
    queue.push(90, Priority::medium);
    queue.push(9, Priority::medium);
    
    queue.pop();

    std::cout << queue << "\n" << queue.empty() << "\n" << queue.size() << "\n" << queue.size_high() << "\n" << queue.size_low() << "\n" << queue.size_medium() << "\n";
    std::cout << queue.front_priority()<< "\n" << queue.front_value() << std::endl;
    queue.clear();
    std::cout << queue.empty();
}
