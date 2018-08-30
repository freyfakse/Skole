using System.Collections.Generic;

namespace ConsoleApplication
{
    public class Bank
    {
        public Bank(string name)
        {
            this.name = name;
            this.customers = new List<Customer>();
        }

        public bool AddCustomer(Customer customer)
        {
            if (customer.name == "" || customer.address == "")
                return false;

            this.customers.Add(customer);
            return true;
        }
        public string name;
        private List<Customer> customers;
    }
}
