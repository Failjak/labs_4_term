#include <queue>
#include <stack>
#include <iostream>
#include <string>


class LogisticsCompany
{
private:
    std::string title;

    std::queue <std::string> orders;
    std::stack <std::string> transport;

public:
    LogisticsCompany();
    LogisticsCompany(const LogisticsCompany &);

    // queue handling
    void addOrder(std::string order);
    void printOrders();
    void changeOrder(int index, std::string new_order);

    // stack handling
    void addTransport(std::string);
    void printTransports();
    void changeTransport(int index, std::string new_transport);
};

LogisticsCompany::LogisticsCompany()
{
    this->orders.push("order 1");
    this->orders.push("order 2");
    this->orders.push("order 3");
    this->orders.push("order 4");
    this->orders.push("order 5");
    this->orders.push("order 6");
    this->orders.push("order 7");

    this->transport.push("car-1");
    this->transport.push("bus");
    this->transport.push("car-2");
}

LogisticsCompany::LogisticsCompany(const LogisticsCompany & obj)
{
    orders = obj.orders;
    transport = obj.transport;
}

void LogisticsCompany::addOrder(std::string order)
{
    orders.push(order);
}

void printQueue(std::queue<std::string> q)
{
	while (!q.empty()){
		std::cout <<" "<< q.front() << std::endl;
		q.pop();
	}
	std::cout << std::endl;
}


void LogisticsCompany::printOrders()
{
    std::queue <std::string> o(orders);
    printQueue(o);
    std::cout<<"Queue size after printing the elements: " << orders.size() << std::endl;
}

void LogisticsCompany::changeOrder(int index, std::string new_order)
{
        std::queue <std::string> new_orders;
        std::string tmp_order;

        int i = 1;
        while(!orders.empty())
        {   
            std::cout << "hui" << std::endl;
            tmp_order = orders.front();
            orders.pop();

            if (i == index)
                new_orders.push(new_order);
                continue;

            new_orders.push(tmp_order);
            i++;
        }

        new_orders.swap(orders);
}

void LogisticsCompany::addTransport(std::string tr)
{
    transport.push(tr);
}

void PrintStack(std::stack<std::string> s)
{
    if (s.empty())
        return;
     
    std::string x = s.top();
 
    s.pop();
 
    PrintStack(s);
    std::cout << x << std::endl;
 
    s.push(x);
}

void LogisticsCompany::printTransports()
{
    std::stack <std::string> tmp(transport);
    PrintStack(tmp);
}

void LogisticsCompany::changeTransport(int index, std::string new_tr)
{
        std::stack <std::string> new_transports;
        std::string tmp_tr;

        for (int i; i < transport.size(); i++)
        {   
            tmp_tr = orders.front();
            orders.pop();

            if (i == index)
                new_transports.push(tmp_tr);
            else
                new_transports.push(tmp_tr);
        }

        transport.swap(new_transports);
}