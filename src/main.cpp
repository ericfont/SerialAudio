//#include <boost/asio/io_service.hpp>
//#include <boost/asio/steady_timer.hpp>
#include <chrono>
#include <iostream>

//#include <deque>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>
#include <boost/asio/buffer.hpp>
//#include <boost/date_time/posix_time/posix_time_types.hpp>

using namespace boost::asio;
using namespace std;

void read_handler(
    const boost::system::error_code& ec,
    std::size_t bytes_transferred)
{
    cout << bytes_transferred << "bytes transferred" << endl;
}

int main()
{
    cout << "get ready" << endl;
    io_context iocontext;
    iocontext.run();

    string serialDeviceName("/dev/ttyACM0");
    serial_port serialPort(iocontext, serialDeviceName);

    if (!serialPort.is_open())
    {
        cerr << "Failed to open serial port" << endl;
        return 0;
    }

    cout << "Open " << serialDeviceName << " successfully." << endl;
    serial_port_base::baud_rate baud_option(9600);
    serialPort.set_option(baud_option);

    char receive_buffer[128];
    // Start an asynchronous read and call read_complete when it completes or fails
 //   serialPort.async_read_some(boost::asio::buffer(receive_buffer));

    serialPort.async_read_some(boost::asio::buffer(receive_buffer, 128), read_handler);

    return 0;
}
