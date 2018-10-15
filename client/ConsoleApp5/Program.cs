using System;
using System.Net.Sockets;
using System.Text;

namespace ConsoleApp5
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            int portNumber = 8085;
            string hostName = "192.168.1.106";
            try
            {
                TcpClient client = new TcpClient(hostName, portNumber);
                NetworkStream networkStream = client.GetStream();
                String message = "ezt kuld el";
                //byte[] bytes = new byte[1024];
                //int bytesRead = networkStream.Read(bytes, 0, bytes.Length);
                //Console.WriteLine(Encoding.ASCII.GetString(bytes, 0, bytesRead));
                byte[] messageBytes = Encoding.ASCII.GetBytes(message); // a UTF-8 encoder would be 'better', as this is the standard for network communications

                int length = messageBytes.Length;
                byte[] lengthBytes = System.BitConverter.GetBytes(length);

                if (System.BitConverter.IsLittleEndian)
                {
                    Array.Reverse(lengthBytes);
                }

                // send length
                networkStream.Write(lengthBytes, 0, lengthBytes.Length);

                // send message
                networkStream.Write(messageBytes, 0, length);
                client.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
            Console.ReadKey();

        }
    }

}
