using System;

namespace ConsoleApplication
{
    public class Customer
    {
        public Customer(string name)
        {
            this.name = name;
            this.address = "Homeless";
        }

        public Customer(string name, string address)
        {
            this.name = name;
            this.address = address;
        }

        public void print()
        {
            Console.WriteLine(name + " lives at " + address);
        }

        public int id;
        public string name;
        public string address;
    }
}
