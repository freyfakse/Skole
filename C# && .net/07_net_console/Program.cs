using System;

namespace ConsoleApplication
{
    public class Program
    {
        public static void Main(string[] args)
        {
            Bank bank = new Bank("Scotland National");

            if (bank.AddCustomer(new Customer("Knut", "Awesome Street 42")))
                Console.WriteLine("Knut was added successfully.");

            if (bank.AddCustomer(new Customer("Lise", "Skolegata 13")))
                Console.WriteLine("Lisa was added successfully.");
        }
    }
}
