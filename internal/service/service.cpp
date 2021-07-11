#include "service.h"

#include <boost/asio.hpp>

#include <thread>
#include <string>

using boost::asio::ip::tcp;

class Service : public IService {
public:
    Service();
    ~Service();
public:
    void Start(ServiceParams* serviceParams);
    void Listening();
    void Stop();
private:
    bool is_working = true;
private:
    boost::asio::io_service service;
    boost::asio::ip::tcp::acceptor acceptors;

    void do_listen();
    void do_read(char * buff, const std::error_code & err, size_t bytes);
    void do_write();
};

IService* NewService() {
    return new Service();
}

// service class implementation
Service::Service() {}
Service::~Service() {}

void Service::Start(ServiceParams* serviceParams) {
    // регистрируем конечную точку для приема входящих соединений
    this->acceptors = boost::asio::ip::tcp::acceptor(this->service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), serviceParams->port));
}

void Service::Listening() {
    std::thread thr(do_listen, this);
    thr.detach();
}

void Service::do_listen(Service*& srvThis) {
    char buff[1024];
    for (;;) {
        if (!this->is_working) {
            break;
        }
        boost::asio::ip::tcp::socket tmp_sock(srvThis->service);
        srvThis->acceptors.accept(tmp_sock);

        int bytes = read(tmp_sock, boost::asio::buffer(buff), boost::bind(srvThis->do_read,buff,std::placeholders::_1,std::placeholders::_2));
		std::string msg(buff, bytes);
		tmp_sock.write_some(boost::asio::buffer(msg));

		tmp_sock.close();
    }
}

void Service::Stop() {
    this->is_working = false;
}