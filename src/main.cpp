//#include <boost/asio/io_service.hpp>
//#include <boost/asio/steady_timer.hpp>
#include <chrono>
#include <iostream>

//#include <deque>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/read.hpp>
#include <boost/asio/serial_port.hpp>
#include <boost/asio/buffer.hpp>
//#include <boost/date_time/posix_time/posix_time_types.hpp>

using namespace boost::asio;
using namespace std;

std::array<char, 4096> bytes;
//serial_port *serialPort;

void read_handler(
        const boost::system::error_code& ec,
        std::size_t bytes_transferred
        )
{
    if (!ec) {
        cout << bytes_transferred << "bytes transferred" << endl;
        std::cout.write(bytes.data(), bytes_transferred);
 //       serialPort->async_read_some(buffer(bytes), read_handler);
    }
}



int main()
{
    io_context iocontext;
    iocontext.run();

    string serialDeviceName("/dev/ttyACM0");
    serial_port serialPort(iocontext, serialDeviceName);

    if (!serialPort.is_open())
    {
        cerr << "Failed to open serial port" << endl;
        return 0;
    }

    cout << "Opened " << serialDeviceName << " successfully." << endl;
    serial_port_base::baud_rate baud_option(115200);
    serialPort.set_option(baud_option);

    // Start an asynchronous read and call read_complete when it completes or fails
 //   serialPort.async_read_some(boost::asio::buffer(receive_buffer));

  //  serialPort->async_read(boost::asio::buffer(bytes), read_handler);
    cout << "get ready to read" << endl;

  //  while (true)
   //     async_read(serialPort, boost::asio::buffer(bytes), boost::asio::transfer_at_least(1), read_handler);

    int recvlen = boost::asio::read(serialPort,boost::asio::buffer(bytes, 4096));
    cout << "recvlen = " << recvlen << endl;

    cout << "issued async_read" << endl;

    cout << "Bye." << endl;
    return 0;
}
